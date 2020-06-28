
#include "onyx/includes/render/core/material.h"

#include "onyx/includes/core/context.h"
#include "onyx/includes/core/deviceManager.h"
#include "onyx/includes/core/renderingManager.h"
#include "onyx/includes/core/swapchainManager.h"
#include "onyx/includes/render/core/shader.h"

#include <stdexcept>

namespace onyx::render::core {
	Material::Material(
		const ::onyx::core::Context *						  pContext,
		const Shader *										  pShader,
		std::uint32_t										  nStride,
		std::vector<std::tuple<std::uint32_t, std::uint32_t>> sLocationOffsetVec) :
		pContext{pContext},
		pShader{pShader}
	{
		VkPipelineLayoutCreateInfo sPipelineLayoutCreateInfo{
			VkStructureType::VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO,
			nullptr,
			0,
			0,
			nullptr,
			0,
			nullptr};

		if (vkCreatePipelineLayout(
				this->pContext->deviceMgr().vulkanDevice(),
				&sPipelineLayoutCreateInfo,
				nullptr,
				&this->sPipelineLayout)
			!= VkResult::VK_SUCCESS)
			throw std::runtime_error{"unable to create pipeline layout"};

		std::vector<VkVertexInputAttributeDescription> sVertexInputAttributeDescriptionList;
		auto										   iEnd{this->pShader->locationFormatMap().cend()};

		for (const auto &sLocationOffset: sLocationOffsetVec) {
			auto iIndex{this->pShader->locationFormatMap().find(std::get<0>(sLocationOffset))};

			if (iIndex == iEnd) throw std::runtime_error{"wrong location detected"};

			sVertexInputAttributeDescriptionList.emplace_back(VkVertexInputAttributeDescription{
				std::get<0>(sLocationOffset),
				0,
				iIndex->second,
				std::get<1>(sLocationOffset)});
		}

		std::vector<VkVertexInputBindingDescription> sBindingDescriptionList{
			VkVertexInputBindingDescription{0, nStride, VkVertexInputRate::VK_VERTEX_INPUT_RATE_VERTEX}};

		VkPipelineVertexInputStateCreateInfo sVertexInputStateCreateInfo{
			VkStructureType::VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_STATE_CREATE_INFO,
			nullptr,
			0,
			static_cast<std::uint32_t>(sBindingDescriptionList.size()),
			sBindingDescriptionList.data(),
			static_cast<std::uint32_t>(sVertexInputAttributeDescriptionList.size()),
			sVertexInputAttributeDescriptionList.data()};

		VkPipelineInputAssemblyStateCreateInfo sInputAssemblyStateCreateInfo{
			VkStructureType::VK_STRUCTURE_TYPE_PIPELINE_INPUT_ASSEMBLY_STATE_CREATE_INFO,
			nullptr,
			0,
			VkPrimitiveTopology::VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST,
			VK_FALSE};

		VkViewport sViewport{
			.0f,
			.0f,
			static_cast<float>(this->pContext->swapchainMgr().vulkanExtent().width),
			static_cast<float>(this->pContext->swapchainMgr().vulkanExtent().height),
			.0f,
			1.f};

		VkRect2D sScissor{{0, 0}, this->pContext->swapchainMgr().vulkanExtent()};

		VkPipelineViewportStateCreateInfo sViewportStateCreateInfo{
			VkStructureType::VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_STATE_CREATE_INFO,
			nullptr,
			0,
			1,
			&sViewport,
			1,
			&sScissor};

		VkPipelineRasterizationStateCreateInfo sRasterizationStateCreateInfo{
			VkStructureType::VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_CREATE_INFO,
			nullptr,
			0,
			VK_FALSE,
			VK_FALSE,
			VkPolygonMode::VK_POLYGON_MODE_FILL,
			VkCullModeFlagBits::VK_CULL_MODE_NONE,
			VkFrontFace::VK_FRONT_FACE_COUNTER_CLOCKWISE,
			VK_FALSE,
			.0f,
			.0f,
			.0f,
			1.f};

		VkPipelineMultisampleStateCreateInfo sMultisampleStateCreateInfo{
			VkStructureType::VK_STRUCTURE_TYPE_PIPELINE_MULTISAMPLE_STATE_CREATE_INFO,
			nullptr,
			0,
			VkSampleCountFlagBits::VK_SAMPLE_COUNT_1_BIT,
			VK_FALSE,
			1.f,
			nullptr,
			VK_FALSE,
			VK_FALSE};

		VkPipelineColorBlendAttachmentState sColorBlendingAttachmentState{
			VK_FALSE,
			VkBlendFactor::VK_BLEND_FACTOR_ONE,
			VkBlendFactor::VK_BLEND_FACTOR_ZERO,
			VkBlendOp::VK_BLEND_OP_ADD,
			VkBlendFactor::VK_BLEND_FACTOR_ONE,
			VkBlendFactor::VK_BLEND_FACTOR_ZERO,
			VkBlendOp::VK_BLEND_OP_ADD,
			VkColorComponentFlagBits::VK_COLOR_COMPONENT_R_BIT | VkColorComponentFlagBits::VK_COLOR_COMPONENT_G_BIT
				| VkColorComponentFlagBits::VK_COLOR_COMPONENT_B_BIT
				| VkColorComponentFlagBits::VK_COLOR_COMPONENT_A_BIT};

		VkPipelineDepthStencilStateCreateInfo sDepthStencilStateCreateInfo{
			VkStructureType::VK_STRUCTURE_TYPE_PIPELINE_DEPTH_STENCIL_STATE_CREATE_INFO,
			nullptr,
			0,
			VK_TRUE,
			VK_TRUE,
			VkCompareOp::VK_COMPARE_OP_LESS,
			VK_FALSE,
			VK_FALSE,
			VkStencilOpState{},
			VkStencilOpState{},
			.0f,
			1.f,
		};

		VkPipelineColorBlendStateCreateInfo sColorBlendStateCreateInfo{
			VkStructureType::VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_STATE_CREATE_INFO,
			nullptr,
			0,
			VK_FALSE,
			VkLogicOp::VK_LOGIC_OP_COPY,
			1,
			&sColorBlendingAttachmentState,
			{.0f, .0f, .0f, .0f}};

		VkPipelineShaderStageCreateInfo vShaderStageCreateInfo[]
			= {VkPipelineShaderStageCreateInfo{
				   VkStructureType::VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO,
				   nullptr,
				   0,
				   VkShaderStageFlagBits::VK_SHADER_STAGE_VERTEX_BIT,
				   std::get<0>(this->pShader->vertexShader().value()),
				   std::get<1>(this->pShader->vertexShader().value()).c_str(),
				   nullptr},

			   VkPipelineShaderStageCreateInfo{
				   VkStructureType::VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO,
				   nullptr,
				   0,
				   VkShaderStageFlagBits::VK_SHADER_STAGE_FRAGMENT_BIT,
				   std::get<0>(this->pShader->fragmentShader().value()),
				   std::get<1>(this->pShader->fragmentShader().value()).c_str(),
				   nullptr}};

		VkGraphicsPipelineCreateInfo sPipelineCreateInfo{
			VkStructureType::VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_CREATE_INFO,
			nullptr,
			0,
			2,
			vShaderStageCreateInfo,
			&sVertexInputStateCreateInfo,
			&sInputAssemblyStateCreateInfo,
			nullptr,
			&sViewportStateCreateInfo,
			&sRasterizationStateCreateInfo,
			&sMultisampleStateCreateInfo,
			&sDepthStencilStateCreateInfo,
			&sColorBlendStateCreateInfo,
			nullptr,
			this->sPipelineLayout,
			this->pContext->renderingMgr().renderPass(),
			0,
			VK_NULL_HANDLE,
			-1};

		if (vkCreateGraphicsPipelines(
				this->pContext->deviceMgr().vulkanDevice(),
				VK_NULL_HANDLE,
				1,
				&sPipelineCreateInfo,
				nullptr,
				&this->sPipeline)
			!= VkResult::VK_SUCCESS)
			throw std::runtime_error{"unable to create pipeline"};
	}

	Material::~Material() noexcept
	{
		vkDestroyPipeline(this->pContext->deviceMgr().vulkanDevice(), this->sPipeline, nullptr);
		vkDestroyPipelineLayout(this->pContext->deviceMgr().vulkanDevice(), this->sPipelineLayout, nullptr);
	}
}	 // namespace onyx::render::core