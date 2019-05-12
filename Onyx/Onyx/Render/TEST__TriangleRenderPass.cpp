
/*
	2019.05.08
	Created by AcrylicShrimp.
*/

#include "TEST__TriangleRenderPass.h"

namespace Onyx::Render
{
	TEST__TriangleRenderPass::TEST__TriangleRenderPass(Context *pContext) :
		pContext{pContext}
	{
		assert(this->pContext);

		auto fReadBinary{[](std::string_view sPath)
		{
			std::ifstream sInput{sPath.data(), std::ios_base::ate | std::ios_base::binary};
			std::vector<char> sResult(static_cast<std::size_t>(sInput.tellg()));

			sInput.seekg(0).read(sResult.data(), static_cast<std::streamsize>(sResult.size()));

			return sResult;
		}};

		auto sVertexShaderBinary{fReadBinary("vert.spv")};
		auto sFragmentShaderBinary{fReadBinary("frag.spv")};

		VkShaderModule vkVertexShaderModule;
		VkShaderModule vkFragmentShaderModule;

		VkShaderModuleCreateInfo vkVertexShaderModuleCreateInfo
		{
			VkStructureType::VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO,
			nullptr,
			0,
			sVertexShaderBinary.size(),
			reinterpret_cast<std::uint32_t *>(sVertexShaderBinary.data())
		};
		VkShaderModuleCreateInfo vkFragmentShaderModuleCreateInfo
		{
			VkStructureType::VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO,
			nullptr,
			0,
			sFragmentShaderBinary.size(),
			reinterpret_cast<std::uint32_t *>(sFragmentShaderBinary.data())
		};

		if (vkCreateShaderModule(this->pContext->device().vulkanDevice(), &vkVertexShaderModuleCreateInfo, nullptr, &vkVertexShaderModule) != VkResult::VK_SUCCESS ||
			vkCreateShaderModule(this->pContext->device().vulkanDevice(), &vkFragmentShaderModuleCreateInfo, nullptr, &vkFragmentShaderModule) != VkResult::VK_SUCCESS)
			throw std::runtime_error{"unable to create shader module"};
		
		VkPipelineShaderStageCreateInfo vkVertexShaderStageCreateInfo
		{
			VkStructureType::VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO,
			nullptr,
			0,
			VkShaderStageFlagBits::VK_SHADER_STAGE_VERTEX_BIT,
			vkVertexShaderModule,
			"main",
			nullptr
		};
		VkPipelineShaderStageCreateInfo vkFragmentShaderStageCreateInfo
		{
			VkStructureType::VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO,
			nullptr,
			0,
			VkShaderStageFlagBits::VK_SHADER_STAGE_FRAGMENT_BIT,
			vkFragmentShaderModule,
			"main",
			nullptr
		};
		VkPipelineShaderStageCreateInfo vShaderStageCreateInfoArray[]
		{
			vkVertexShaderStageCreateInfo,
			vkFragmentShaderStageCreateInfo
		};
		VkPipelineVertexInputStateCreateInfo vkVertexInputStateCreateInfo
		{
			VkStructureType::VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_STATE_CREATE_INFO,
			nullptr,
			0,
			0,
			nullptr,
			0,
			nullptr
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
			VkCullModeFlagBits::VK_CULL_MODE_BACK_BIT,
			VkFrontFace::VK_FRONT_FACE_CLOCKWISE,
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
		VkPipelineLayoutCreateInfo vkLayoutCreateInfo
		{
			VkStructureType::VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO,
			nullptr,
			0,
			0,
			nullptr,
			0,
			nullptr
		};

		if (vkCreatePipelineLayout(this->pContext->device().vulkanDevice(), &vkLayoutCreateInfo, nullptr, &this->vkPipelineLayout) != VkResult::VK_SUCCESS)
			std::runtime_error{"unable to create pipeline layout"};

		VkAttachmentDescription vkAttachmentDescription
		{
			0,
			this->pContext->surface().vulkanSurfaceFormat().format,
			VkSampleCountFlagBits::VK_SAMPLE_COUNT_1_BIT,
			VkAttachmentLoadOp::VK_ATTACHMENT_LOAD_OP_CLEAR,
			VkAttachmentStoreOp::VK_ATTACHMENT_STORE_OP_STORE,
			VkAttachmentLoadOp::VK_ATTACHMENT_LOAD_OP_DONT_CARE,
			VkAttachmentStoreOp::VK_ATTACHMENT_STORE_OP_DONT_CARE,
			VkImageLayout::VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL,
			VkImageLayout::VK_IMAGE_LAYOUT_PRESENT_SRC_KHR
		};
		VkAttachmentReference vkAttachmentReference
		{
			0,
			VkImageLayout::VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL
		};
		VkSubpassDescription vkSubpassDescription
		{
			0,
			VkPipelineBindPoint::VK_PIPELINE_BIND_POINT_GRAPHICS,
			0,
			nullptr,
			1,
			&vkAttachmentReference,
			nullptr,
			nullptr,
			0,
			nullptr
		};
		VkRenderPassCreateInfo vkRenderPassCreateInfo
		{
			VkStructureType::VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO,
			nullptr,
			0,
			1,
			&vkAttachmentDescription,
			1,
			&vkSubpassDescription,
			0,
			nullptr
		};

		if (vkCreateRenderPass(this->pContext->device().vulkanDevice(), &vkRenderPassCreateInfo, nullptr, &this->vkRenderPass) != VkResult::VK_SUCCESS)
			std::runtime_error{"unable to create render pass"};

		VkGraphicsPipelineCreateInfo vkGraphicsPipelineCreateInfo
		{
			VkStructureType::VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_CREATE_INFO,
			nullptr,
			0,
			2,
			vShaderStageCreateInfoArray,
			&vkVertexInputStateCreateInfo,
			&vkInputAssemblyStateCreateInfo,
			nullptr,
			&vkViewportStateCreateInfo,
			&vkRasterizationStateCreateInfo,
			&vkMultisampleStateCreateInfo,
			nullptr,
			&vkColorBlendStateCreateInfo,
			nullptr,
			this->vkPipelineLayout,
			this->vkRenderPass,
			0,
			VK_NULL_HANDLE,
			-1
		};

		if (vkCreateGraphicsPipelines(this->pContext->device().vulkanDevice(), VK_NULL_HANDLE, 1, &vkGraphicsPipelineCreateInfo, nullptr, &this->vkPipeline) != VkResult::VK_SUCCESS)
			std::runtime_error{"unable to create render pass"};

		vkDestroyShaderModule(this->pContext->device().vulkanDevice(), vkVertexShaderModule, nullptr);
		vkDestroyShaderModule(this->pContext->device().vulkanDevice(), vkFragmentShaderModule, nullptr);

		this->sFramebufferList.resize(this->pContext->swapchain().vulkanImageList().size());

		for (std::size_t nIndex{0}, nMaxIndex{this->sFramebufferList.size()}; nIndex < nMaxIndex; ++nIndex)
		{
			VkImageView vkAttachmentArray[]
			{
				this->pContext->swapchain().vulkanImageViewList()[nIndex]
			};

			VkFramebufferCreateInfo vkFramebufferCreateInfo
			{
				VkStructureType::VK_STRUCTURE_TYPE_FRAMEBUFFER_CREATE_INFO,
				nullptr,
				0,
				this->vkRenderPass,
				1,
				vkAttachmentArray,
				this->pContext->swapchain().vulkanExtent().width,
				this->pContext->swapchain().vulkanExtent().height,
				1
			};

			if (vkCreateFramebuffer(this->pContext->device().vulkanDevice(), &vkFramebufferCreateInfo, nullptr, &this->sFramebufferList[nIndex]) != VkResult::VK_SUCCESS)
				throw std::runtime_error{"unable to create framebuffer"};
		}
	}
	
	TEST__TriangleRenderPass::~TEST__TriangleRenderPass() noexcept
	{
		vkDeviceWaitIdle(this->pContext->device().vulkanDevice());

		for (auto vkFramebuffer : this->sFramebufferList)
			vkDestroyFramebuffer(this->pContext->device().vulkanDevice(), vkFramebuffer, nullptr);

		vkDestroyPipeline(this->pContext->device().vulkanDevice(), this->vkPipeline, nullptr);
		vkDestroyPipelineLayout(this->pContext->device().vulkanDevice(), this->vkPipelineLayout, nullptr);
		vkDestroyRenderPass(this->pContext->device().vulkanDevice(), this->vkRenderPass, nullptr);
	}
}