
/*
	2019.05.12
	Created by AcrylicShrimp.
*/

#include "RenderingManager.h"

#include "./Context.h"
#include "./Material.h"

namespace Onyx::Render
{
	RenderingManager::RenderingManager(Context *pContext) :
		SubContextManager{pContext}
	{
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
			throw std::runtime_error{"unable to create render pass"};

		this->sFinalFramebufferList.resize(this->pContext->swapchain().vulkanImageList().size());

		for (std::size_t nIndex{0}, nMaxIndex{this->sFinalFramebufferList.size()}; nIndex < nMaxIndex; ++nIndex)
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

			if (vkCreateFramebuffer(this->pContext->device().vulkanDevice(), &vkFramebufferCreateInfo, nullptr, &this->sFinalFramebufferList[nIndex]) != VkResult::VK_SUCCESS)
				throw std::runtime_error{"unable to create framebuffer"};
		}
	}

	RenderingManager::~RenderingManager()
	{
		vkDeviceWaitIdle(this->pContext->device().vulkanDevice());

		for (auto vkFramebuffer : this->sFinalFramebufferList)
			vkDestroyFramebuffer(this->pContext->device().vulkanDevice(), vkFramebuffer, nullptr);

		vkDestroyRenderPass(this->pContext->device().vulkanDevice(), this->vkRenderPass, nullptr);
	}

	void RenderingManager::render(std::uint32_t nImageIndex, VkCommandBuffer vkCommandBuffer, const Material &sMaterial)
	{
		VkClearValue vkClearValue
		{
			.21f, .64f, 1.f, .0f
		};
		VkRenderPassBeginInfo vkRenderPassBeginInfo
		{
			VkStructureType::VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO,
			nullptr,
			vkRenderPass,
			this->sFinalFramebufferList[nImageIndex],
			VkRect2D{{0, 0}, this->pContext->swapchain().vulkanExtent()},
			1,
			&vkClearValue
		};

		vkCmdBeginRenderPass(vkCommandBuffer, &vkRenderPassBeginInfo, VkSubpassContents::VK_SUBPASS_CONTENTS_INLINE);

		vkCmdBindDescriptorSets(vkCommandBuffer, VkPipelineBindPoint::VK_PIPELINE_BIND_POINT_GRAPHICS, this->pContext->uniformMgr().vulkanPipelineLayout(), 0, 1, &this->pContext->uniformMgr().vulkanDescriptorSetList()[nImageIndex], 0, nullptr);
		vkCmdBindPipeline(vkCommandBuffer, VkPipelineBindPoint::VK_PIPELINE_BIND_POINT_GRAPHICS, sMaterial.vulkanPipeline());

		auto vkBuffer{sMaterial.pMesh->vulkanBuffer()};
		VkDeviceSize nOffset{0};

		vkCmdBindVertexBuffers(vkCommandBuffer, 0, 1, &vkBuffer, &nOffset);
		vkCmdDraw(vkCommandBuffer, sMaterial.pMesh->length(), 1, 0, 0);

		vkCmdEndRenderPass(vkCommandBuffer);
	}
}