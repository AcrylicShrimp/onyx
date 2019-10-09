
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
		std::vector<VkAttachmentDescription> sAttachmentDescription
		{
			VkAttachmentDescription
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
			},
			VkAttachmentDescription
			{
				0,
				VkFormat::VK_FORMAT_D32_SFLOAT,
				VkSampleCountFlagBits::VK_SAMPLE_COUNT_1_BIT,
				VkAttachmentLoadOp::VK_ATTACHMENT_LOAD_OP_CLEAR,
				VkAttachmentStoreOp::VK_ATTACHMENT_STORE_OP_DONT_CARE,
				VkAttachmentLoadOp::VK_ATTACHMENT_LOAD_OP_DONT_CARE,
				VkAttachmentStoreOp::VK_ATTACHMENT_STORE_OP_DONT_CARE,
				VkImageLayout::VK_IMAGE_LAYOUT_UNDEFINED,
				VkImageLayout::VK_IMAGE_LAYOUT_DEPTH_STENCIL_ATTACHMENT_OPTIMAL
			}
		};
		std::vector<VkAttachmentReference> sAttachmentReference
		{
			VkAttachmentReference
			{
				0,
				VkImageLayout::VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL
			},
			VkAttachmentReference
			{
				1,
				VkImageLayout::VK_IMAGE_LAYOUT_DEPTH_STENCIL_ATTACHMENT_OPTIMAL
		}
		};
		VkSubpassDescription vkSubpassDescription
		{
			0,
			VkPipelineBindPoint::VK_PIPELINE_BIND_POINT_GRAPHICS,
			0,
			nullptr,
			1,
			&sAttachmentReference[0],
			nullptr,
			&sAttachmentReference[1],
			0,
			nullptr
		};
		VkRenderPassCreateInfo vkRenderPassCreateInfo
		{
			VkStructureType::VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO,
			nullptr,
			0,
			static_cast<std::uint32_t>(sAttachmentDescription.size()),
			sAttachmentDescription.data(),
			1,
			&vkSubpassDescription,
			0,
			nullptr
		};

		if (vkCreateRenderPass(this->pContext->device().vulkanDevice(), &vkRenderPassCreateInfo, nullptr, &this->vkRenderPass) != VkResult::VK_SUCCESS)
			throw std::runtime_error{"unable to create render pass"};

		this->sFinalFramebufferList.resize(this->pContext->swapchain().vulkanImageList().size());
		this->sTransformBufferList.reserve(this->pContext->swapchain().vulkanImageList().size());

		for (std::size_t nIndex{0}, nMaxIndex{this->sFinalFramebufferList.size()}; nIndex < nMaxIndex; ++nIndex)
		{
			std::vector<VkImageView> sAttachmentArray
			{
				this->pContext->swapchain().vulkanImageViewList()[nIndex],
				this->pContext->swapchain().vulkanDepthImageViewList()[nIndex]
			};

			VkFramebufferCreateInfo vkFramebufferCreateInfo
			{
				VkStructureType::VK_STRUCTURE_TYPE_FRAMEBUFFER_CREATE_INFO,
				nullptr,
				0,
				this->vkRenderPass,
				static_cast<std::uint32_t>(sAttachmentArray.size()),
				sAttachmentArray.data(),
				this->pContext->swapchain().vulkanExtent().width,
				this->pContext->swapchain().vulkanExtent().height,
				1
			};

			if (vkCreateFramebuffer(this->pContext->device().vulkanDevice(), &vkFramebufferCreateInfo, nullptr, &this->sFinalFramebufferList[nIndex]) != VkResult::VK_SUCCESS)
				throw std::runtime_error{"unable to create framebuffer"};

			this->sTransformBufferList.emplace_back(this->pContext, Buffer::Usage::VertexBuffer, sizeof(float) * 16 * 32);
		}
	}

	RenderingManager::~RenderingManager()
	{
		vkDeviceWaitIdle(this->pContext->device().vulkanDevice());

		for (auto vkFramebuffer : this->sFinalFramebufferList)
			vkDestroyFramebuffer(this->pContext->device().vulkanDevice(), vkFramebuffer, nullptr);

		vkDestroyRenderPass(this->pContext->device().vulkanDevice(), this->vkRenderPass, nullptr);
	}

	void RenderingManager::render(
		std::uint32_t nImageIndex,
		VkCommandBuffer vkCommandBuffer,
		const std::vector<Transform::Mat44<float>> &sTransformList,
		const std::vector<std::tuple<Material *, Mesh *>> &sRenderableList)
	{
		VkDeviceSize nRequiredSize{sizeof(float) * 16 * sTransformList.size()};

		if (this->sTransformBufferList[nImageIndex].size() < nRequiredSize)
			this->sTransformBufferList[nImageIndex].resize(nRequiredSize);

		this->sTransformBufferList[nImageIndex].map([nRequiredSize, &sTransformList](void *pDestination)
			{
				std::memcpy(pDestination, sTransformList.data(), nRequiredSize);
			});

		std::vector<VkClearValue> sClearValue
		{
			VkClearValue{.0f, .0f, .0f, .0f},
			VkClearValue{1.f, 0}
		};
		VkRenderPassBeginInfo vkRenderPassBeginInfo
		{
			VkStructureType::VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO,
			nullptr,
			this->vkRenderPass,
			this->sFinalFramebufferList[nImageIndex],
			VkRect2D{{0, 0}, this->pContext->swapchain().vulkanExtent()},
			static_cast<std::uint32_t>(sClearValue.size()),
			sClearValue.data()
		};

		vkCmdBeginRenderPass(vkCommandBuffer, &vkRenderPassBeginInfo, VkSubpassContents::VK_SUBPASS_CONTENTS_INLINE);
		vkCmdBindDescriptorSets(vkCommandBuffer, VkPipelineBindPoint::VK_PIPELINE_BIND_POINT_GRAPHICS, this->pContext->uniformMgr().vulkanPipelineLayout(), 0, 1, &this->pContext->uniformMgr().vulkanDescriptorSetList()[nImageIndex], 0, nullptr);

		VkDeviceSize nTranformBufferOffset{0};

		for (const auto &sRenderable : sRenderableList)
		{
			vkCmdBindPipeline(vkCommandBuffer, VkPipelineBindPoint::VK_PIPELINE_BIND_POINT_GRAPHICS, std::get<0>(sRenderable)->vulkanPipeline());

			auto vkTransformBuffer{this->sTransformBufferList[nImageIndex].vulkanBuffer()};
			auto vkBuffer{std::get<1>(sRenderable)->buffer().vulkanBuffer()};
			VkDeviceSize nOffset{0};

			vkCmdBindVertexBuffers(vkCommandBuffer, 0, 1, &vkTransformBuffer, &nTranformBufferOffset);
			vkCmdBindVertexBuffers(vkCommandBuffer, 1, 1, &vkBuffer, &nOffset);

			vkCmdDraw(vkCommandBuffer, std::get<1>(sRenderable)->nVertexCount, 1, 0, 0);

			nTranformBufferOffset += sizeof(float) * 16;
		}

		vkCmdEndRenderPass(vkCommandBuffer);
	}
}