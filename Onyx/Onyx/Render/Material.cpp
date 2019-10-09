
/*
	2019.05.24
	Created by AcrylicShrimp.
*/

#include "Material.h"

#include "Context.h"

namespace Onyx::Render
{
	Material::Material(Context *pContext, const Shader *pShader, const MeshLayout *pMeshLayout, const std::unordered_map<std::uint32_t, std::uint32_t> &sLocationOffsetMapping) :
		pContext{pContext},
		pShader{pShader},
		pMeshLayout{pMeshLayout}
	{
		assert(this->pContext);
		assert(this->pShader);
		assert(this->pMeshLayout);

		std::vector<VkVertexInputAttributeDescription> sVertexInputAttributeDescriptionList
		{
			VkVertexInputAttributeDescription
			{
				0,
				0,
				VkFormat::VK_FORMAT_R32G32B32A32_SFLOAT,
				sizeof(float) * 0
			},
			VkVertexInputAttributeDescription
			{
				1,
				0,
				VkFormat::VK_FORMAT_R32G32B32A32_SFLOAT,
				sizeof(float) * 4
			},
			VkVertexInputAttributeDescription
			{
				2,
				0,
				VkFormat::VK_FORMAT_R32G32B32A32_SFLOAT,
				sizeof(float) * 8
			},
			VkVertexInputAttributeDescription
			{
				3,
				0,
				VkFormat::VK_FORMAT_R32G32B32A32_SFLOAT,
				sizeof(float) * 12
			}
		};

		auto iMeshLayoutMapEnd{this->pMeshLayout->layoutMap().cend()};
		auto iLocationOffsetMappingEnd{sLocationOffsetMapping.cend()};

		for (const auto &sPair : this->pShader->layout().layoutMap())
		{
			if (sPair.first >= 0 && sPair.first < 4)
				continue;

			auto iLocationOffsetMappingIndex{sLocationOffsetMapping.find(sPair.first)};

			if (iLocationOffsetMappingIndex == iLocationOffsetMappingEnd)
				throw std::runtime_error{"invalid location-offset mapping"};

			auto iMeshLayoutMapIndex{this->pMeshLayout->layoutMap().find(iLocationOffsetMappingIndex->second)};

			if (iMeshLayoutMapIndex == iMeshLayoutMapEnd)
				throw std::runtime_error{"invalid location-offset mapping"};

			if (iMeshLayoutMapIndex->second != sPair.second)
				throw std::runtime_error{"incompatible mesh layout"};

			sVertexInputAttributeDescriptionList.emplace_back(
				VkVertexInputAttributeDescription
				{
					sPair.first,
					1,
					sPair.second,
					iLocationOffsetMappingIndex->second
				}
			);
		}

		std::vector<VkVertexInputBindingDescription> sBindingDescriptionList
		{
			VkVertexInputBindingDescription
			{
				0,
				sizeof(float) * 16,
				VkVertexInputRate::VK_VERTEX_INPUT_RATE_INSTANCE
			},
			VkVertexInputBindingDescription
			{
				1,
				pMeshLayout->calcStride(),
				VkVertexInputRate::VK_VERTEX_INPUT_RATE_VERTEX
			}
		};
		VkPipelineVertexInputStateCreateInfo vkVertexInputStateCreateInfo
		{
			VkStructureType::VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_STATE_CREATE_INFO,
			nullptr,
			0,
			static_cast<std::uint32_t>(sBindingDescriptionList.size()),
			sBindingDescriptionList.data(),
			static_cast<std::uint32_t>(sVertexInputAttributeDescriptionList.size()),
			sVertexInputAttributeDescriptionList.data()
		};
		VkPipelineInputAssemblyStateCreateInfo vkInputAssemblyStateCreateInfo
		{
			VkStructureType::VK_STRUCTURE_TYPE_PIPELINE_INPUT_ASSEMBLY_STATE_CREATE_INFO,
			nullptr,
			0,
			VkPrimitiveTopology::VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST,
			VK_FALSE
		};
		VkViewport vkViewport
		{
			.0f,
			.0f,
			static_cast<float>(this->pContext->swapchain().vulkanExtent().width),
			static_cast<float>(this->pContext->swapchain().vulkanExtent().height),
			.0f,
			1.f
		};
		VkRect2D vkScissor
		{
			{0, 0},
			this->pContext->swapchain().vulkanExtent()
		};
		VkPipelineViewportStateCreateInfo vkViewportStateCreateInfo
		{
			VkStructureType::VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_STATE_CREATE_INFO,
			nullptr,
			0,
			1,
			&vkViewport,
			1,
			&vkScissor
		};
		VkPipelineRasterizationStateCreateInfo vkRasterizationStateCreateInfo
		{
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
			1.f
		};
		VkPipelineMultisampleStateCreateInfo vkMultisampleStateCreateInfo
		{
			VkStructureType::VK_STRUCTURE_TYPE_PIPELINE_MULTISAMPLE_STATE_CREATE_INFO,
			nullptr,
			0,
			VkSampleCountFlagBits::VK_SAMPLE_COUNT_1_BIT,
			VK_FALSE,
			1.f,
			nullptr,
			VK_FALSE,
			VK_FALSE
		};
		VkPipelineColorBlendAttachmentState vkColorBlendingAttachmentState
		{
			VK_FALSE,
			VkBlendFactor::VK_BLEND_FACTOR_ONE,
			VkBlendFactor::VK_BLEND_FACTOR_ZERO,
			VkBlendOp::VK_BLEND_OP_ADD,
			VkBlendFactor::VK_BLEND_FACTOR_ONE,
			VkBlendFactor::VK_BLEND_FACTOR_ZERO,
			VkBlendOp::VK_BLEND_OP_ADD,
			VkColorComponentFlagBits::VK_COLOR_COMPONENT_R_BIT |
			VkColorComponentFlagBits::VK_COLOR_COMPONENT_G_BIT |
			VkColorComponentFlagBits::VK_COLOR_COMPONENT_B_BIT |
			VkColorComponentFlagBits::VK_COLOR_COMPONENT_A_BIT
		};
		VkPipelineDepthStencilStateCreateInfo vkDepthStencilStateCreateInfo
		{
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
		VkPipelineColorBlendStateCreateInfo vkColorBlendStateCreateInfo
		{
			VkStructureType::VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_STATE_CREATE_INFO,
			nullptr,
			0,
			VK_FALSE,
			VkLogicOp::VK_LOGIC_OP_COPY,
			1,
			&vkColorBlendingAttachmentState,
			{.0f, .0f, .0f, .0f}
		};

		std::vector<VkPipelineShaderStageCreateInfo> sShaderStageCreateInfoList;

		for (const auto &sPair : pShader->stageMap())
			sShaderStageCreateInfoList.emplace_back(
				VkPipelineShaderStageCreateInfo
				{
					VkStructureType::VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO,
					nullptr,
					0,
					sPair.first == Shader::Stage::Vertex ? VkShaderStageFlagBits::VK_SHADER_STAGE_VERTEX_BIT : VkShaderStageFlagBits::VK_SHADER_STAGE_FRAGMENT_BIT,
					std::get<0>(sPair.second),
					std::get<1>(sPair.second).c_str(),
					nullptr
				}
			);

		VkGraphicsPipelineCreateInfo vkPipelineCreateInfo
		{
			VkStructureType::VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_CREATE_INFO,
			nullptr,
			0,
			static_cast<std::uint32_t>(sShaderStageCreateInfoList.size()),
			sShaderStageCreateInfoList.data(),
			&vkVertexInputStateCreateInfo,
			&vkInputAssemblyStateCreateInfo,
			nullptr,
			&vkViewportStateCreateInfo,
			&vkRasterizationStateCreateInfo,
			&vkMultisampleStateCreateInfo,
			&vkDepthStencilStateCreateInfo,
			&vkColorBlendStateCreateInfo,
			nullptr,
			this->pContext->uniformMgr().vulkanPipelineLayout(),
			this->pContext->renderingMgr().vulkanRenderPass(),
			0,
			VK_NULL_HANDLE,
			-1
		};

		if (vkCreateGraphicsPipelines(this->pContext->device().vulkanDevice(), VK_NULL_HANDLE, 1, &vkPipelineCreateInfo, nullptr, &this->vkPipeline) != VkResult::VK_SUCCESS)
			throw std::runtime_error{"unable to create pipeline"};
	}

	Material::~Material()
	{
		vkDeviceWaitIdle(this->pContext->device().vulkanDevice());
		vkDestroyPipeline(this->pContext->device().vulkanDevice(), this->vkPipeline, nullptr);
	}
}