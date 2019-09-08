
/*
	2019.05.24
	Created by AcrylicShrimp.
*/

#include "Material.h"

namespace Onyx::Render
{
	Material::Material(Context *pContext, MeshLayout *pMeshLayout, Shader *pShader) :
		pContext{pContext},
		pMeshLayout{pMeshLayout},
		pShader{pShader}
	{
		assert(this->pContext);
		assert(this->pMeshLayout);
		assert(this->pShader);

		std::vector<VkVertexInputAttributeDescription> sVertexInputAttributeDescriptionList;
		sVertexInputAttributeDescriptionList.reserve(this->pMeshLayout->sAttributeList.size() + 4);

		for (const auto &sAttribute : this->pMeshLayout->sAttributeList)
			sVertexInputAttributeDescriptionList.emplace_back(
				VkVertexInputAttributeDescription
				{
					static_cast<uint32_t>(sVertexInputAttributeDescriptionList.size()),
					0,
					sAttribute.vkFormat,
					sAttribute.vkOffset
				});

		sVertexInputAttributeDescriptionList.emplace_back(
			VkVertexInputAttributeDescription
			{
				static_cast<uint32_t>(sVertexInputAttributeDescriptionList.size()),
				1,
				VkFormat::VK_FORMAT_R32G32B32A32_SFLOAT,
				sizeof(float) * 0
			});
		sVertexInputAttributeDescriptionList.emplace_back(
			VkVertexInputAttributeDescription
			{
				static_cast<uint32_t>(sVertexInputAttributeDescriptionList.size()),
				1,
				VkFormat::VK_FORMAT_R32G32B32A32_SFLOAT,
				sizeof(float) * 4
			});
		sVertexInputAttributeDescriptionList.emplace_back(
			VkVertexInputAttributeDescription
			{
				static_cast<uint32_t>(sVertexInputAttributeDescriptionList.size()),
				1,
				VkFormat::VK_FORMAT_R32G32B32A32_SFLOAT,
				sizeof(float) * 8
			});
		sVertexInputAttributeDescriptionList.emplace_back(
			VkVertexInputAttributeDescription
			{
				static_cast<uint32_t>(sVertexInputAttributeDescriptionList.size()),
				1,
				VkFormat::VK_FORMAT_R32G32B32A32_SFLOAT,
				sizeof(float) * 12
			});

		VkVertexInputBindingDescription vBindingDescription[]
		{
			{
				0,
				this->pMeshLayout->nStride,
				VkVertexInputRate::VK_VERTEX_INPUT_RATE_VERTEX
			},
			{
				1,
				sizeof(float) * 16,
				VkVertexInputRate::VK_VERTEX_INPUT_RATE_INSTANCE
			}
		};
		VkPipelineVertexInputStateCreateInfo vkVertexInputStateCreateInfo
		{
			VkStructureType::VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_STATE_CREATE_INFO,
			nullptr,
			0,
			2,
			vBindingDescription,
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

		auto sShaderStageCreateInfoList{pShader->generateShaderStageCreateInfoList()};

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
			nullptr,
			&vkColorBlendStateCreateInfo,
			nullptr,
			this->pContext->uniformMgr().vulkanPipelineLayout(),
			this->pContext->renderingMgr().vulkanRenderPass(),
			0,
			VK_NULL_HANDLE,
			-1
		};

		if (vkCreateGraphicsPipelines(this->pContext->device().vulkanDevice(), VK_NULL_HANDLE, 1, &vkPipelineCreateInfo, nullptr, &this->vkPipeline) != VkResult::VK_SUCCESS)
			throw std::runtime_error{"unable to create render pass"};
	}

	Material::~Material()
	{
		vkDeviceWaitIdle(this->pContext->device().vulkanDevice());
		vkDestroyPipeline(this->pContext->device().vulkanDevice(), this->vkPipeline, nullptr);
	}
}