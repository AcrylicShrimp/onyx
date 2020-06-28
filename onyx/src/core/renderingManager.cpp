
#include "onyx/includes/core/renderingManager.h"

#include "onyx/includes/core/context.h"
#include "onyx/includes/render/core/material.h"
#include "onyx/includes/render/core/mesh.h"
#include "onyx/includes/render/core/shader.h"

#include <cstdint>

namespace onyx::core {
	RenderingManager::RenderingManager(Context *pContext) : PerContextManager{pContext}
	{
		// Empty.
	}

	RenderingManager::~RenderingManager() noexcept
	{
		// Empty.
	}

	void RenderingManager::init(const DeviceInfo &sDevice)
	{
		std::vector<VkAttachmentDescription> sAttachmentDescriptionVec{
			VkAttachmentDescription{0,
									this->pContext->surfaceMgr().vulkanSurfaceFormat().format,
									VkSampleCountFlagBits::VK_SAMPLE_COUNT_1_BIT,
									VkAttachmentLoadOp::VK_ATTACHMENT_LOAD_OP_CLEAR,
									VkAttachmentStoreOp::VK_ATTACHMENT_STORE_OP_STORE,
									VkAttachmentLoadOp::VK_ATTACHMENT_LOAD_OP_DONT_CARE,
									VkAttachmentStoreOp::VK_ATTACHMENT_STORE_OP_DONT_CARE,
									VkImageLayout::VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL,
									VkImageLayout::VK_IMAGE_LAYOUT_PRESENT_SRC_KHR},
			VkAttachmentDescription{0,
									VkFormat::VK_FORMAT_D32_SFLOAT,
									VkSampleCountFlagBits::VK_SAMPLE_COUNT_1_BIT,
									VkAttachmentLoadOp::VK_ATTACHMENT_LOAD_OP_CLEAR,
									VkAttachmentStoreOp::VK_ATTACHMENT_STORE_OP_DONT_CARE,
									VkAttachmentLoadOp::VK_ATTACHMENT_LOAD_OP_DONT_CARE,
									VkAttachmentStoreOp::VK_ATTACHMENT_STORE_OP_DONT_CARE,
									VkImageLayout::VK_IMAGE_LAYOUT_UNDEFINED,
									VkImageLayout::VK_IMAGE_LAYOUT_DEPTH_STENCIL_ATTACHMENT_OPTIMAL}};
		std::vector<VkAttachmentReference> sAttachmentReferenceVec{
			VkAttachmentReference{0, VkImageLayout::VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL},
			VkAttachmentReference{1, VkImageLayout::VK_IMAGE_LAYOUT_DEPTH_STENCIL_ATTACHMENT_OPTIMAL}};
		VkSubpassDescription   vkSubpassDescription{0,
													VkPipelineBindPoint::VK_PIPELINE_BIND_POINT_GRAPHICS,
													0,
													nullptr,
													1,
													&sAttachmentReferenceVec[0],
													nullptr,
													&sAttachmentReferenceVec[1],
													0,
													nullptr};
		VkRenderPassCreateInfo vkRenderPassCreateInfo{VkStructureType::VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO,
													  nullptr,
													  0,
													  static_cast<std::uint32_t>(sAttachmentDescriptionVec.size()),
													  sAttachmentDescriptionVec.data(),
													  1,
													  &vkSubpassDescription,
													  0,
													  nullptr};

		if (vkCreateRenderPass(
				this->pContext->deviceMgr().vulkanDevice(),
				&vkRenderPassCreateInfo,
				nullptr,
				&this->sRenderPass)
			!= VkResult::VK_SUCCESS)
			throw std::runtime_error{"unable to create render pass"};

		this->sFinalFramebufferVec.resize(this->pContext->swapchainMgr().vulkanImageVec().size());

		for (std::size_t nIndex{0}, nMaxIndex{this->sFinalFramebufferVec.size()}; nIndex < nMaxIndex; ++nIndex) {
			std::vector<VkImageView> sAttachmentArray{this->pContext->swapchainMgr().vulkanImageViewVec()[nIndex],
													  this->pContext->swapchainMgr().vulkanDepthImageView()};

			VkFramebufferCreateInfo vkFramebufferCreateInfo{VkStructureType::VK_STRUCTURE_TYPE_FRAMEBUFFER_CREATE_INFO,
															nullptr,
															0,
															this->sRenderPass,
															static_cast<std::uint32_t>(sAttachmentArray.size()),
															sAttachmentArray.data(),
															this->pContext->swapchainMgr().vulkanExtent().width,
															this->pContext->swapchainMgr().vulkanExtent().height,
															1};

			if (vkCreateFramebuffer(
					this->pContext->deviceMgr().vulkanDevice(),
					&vkFramebufferCreateInfo,
					nullptr,
					&this->sFinalFramebufferVec[nIndex])
				!= VkResult::VK_SUCCESS)
				throw std::runtime_error{"unable to create framebuffer"};
		}
	}

	void RenderingManager::fin()
	{
		// Empty.
	}

	void RenderingManager::render(
		const std::vector<std::tuple<const ::onyx::render::core::Material *, const ::onyx::render::core::Mesh *>>
			&sMaterialMeshVec)
	{
		auto sDevice{this->pContext->deviceMgr().vulkanDevice()};

		auto sSynchronizationObject{this->pContext->syncMgr().nextSynchronizationObject()};
		auto sGraphicsCommandBuffer{std::get<0>(sSynchronizationObject)};
		auto sPresentCommandBuffer{std::get<1>(sSynchronizationObject)};
		auto sAfterRenderingSemaphore{std::get<2>(sSynchronizationObject)};
		auto sAfterOwnershipTransferredSemaphore{std::get<3>(sSynchronizationObject)};
		auto sAfterPresentationSemaphore{std::get<4>(sSynchronizationObject)};
		auto sFence{std::get<5>(sSynchronizationObject)};

		vkWaitForFences(sDevice, 1, &sFence, VK_TRUE, std::numeric_limits<std::uint64_t>::max());
		vkResetFences(sDevice, 1, &sFence);

		std::uint32_t nImageIndex;

		if (vkAcquireNextImageKHR(
				sDevice,
				this->pContext->swapchainMgr().vulkanSwapchain(),
				std::numeric_limits<std::uint64_t>::max(),
				sAfterPresentationSemaphore,
				VK_NULL_HANDLE,
				&nImageIndex)
			!= VkResult::VK_SUCCESS)
			throw std::runtime_error{"unable to acquire next image"};

		VkCommandBufferBeginInfo sGraphicsCommandBufferBeginInfo{
			VkStructureType::VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO,
			nullptr,
			VkCommandBufferUsageFlagBits::VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT,
			nullptr};
		VkCommandBufferBeginInfo sPresentCommandBufferBeginInfo{
			VkStructureType::VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO,
			nullptr,
			VkCommandBufferUsageFlagBits::VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT,
			nullptr};

		if (vkBeginCommandBuffer(sGraphicsCommandBuffer, &sGraphicsCommandBufferBeginInfo) != VkResult::VK_SUCCESS
			|| vkBeginCommandBuffer(sPresentCommandBuffer, &sPresentCommandBufferBeginInfo) != VkResult::VK_SUCCESS)
			throw std::runtime_error{"unable to begin command buffer"};

		{
			VkImageMemoryBarrier sGraphicsImageMemoryBarrier{
				VkStructureType::VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER,
				nullptr,
				0,
				VkAccessFlagBits::VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT,
				VkImageLayout::VK_IMAGE_LAYOUT_UNDEFINED,
				VkImageLayout::VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL,
				VK_QUEUE_FAMILY_IGNORED,
				VK_QUEUE_FAMILY_IGNORED,
				this->pContext->swapchainMgr().vulkanImageVec()[nImageIndex],
				VkImageSubresourceRange{VkImageAspectFlagBits::VK_IMAGE_ASPECT_COLOR_BIT,
										0,
										VK_REMAINING_MIP_LEVELS,
										0,
										VK_REMAINING_ARRAY_LAYERS}};

			vkCmdPipelineBarrier(
				sGraphicsCommandBuffer,
				VkPipelineStageFlagBits::VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT,
				VkPipelineStageFlagBits::VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT,
				0,
				0,
				nullptr,
				0,
				nullptr,
				1,
				&sGraphicsImageMemoryBarrier);
		}

		// ##################################################
		// ## Rendering begin
		// ##################################################

		std::vector<VkClearValue> sClearValue{VkClearValue{.0f, .0f, .0f, .0f}, VkClearValue{1.f, 0}};
		VkRenderPassBeginInfo	  sRenderPassBeginInfo{VkStructureType::VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO,
												   nullptr,
												   this->sRenderPass,
												   this->sFinalFramebufferVec[nImageIndex],
												   VkRect2D{{0, 0}, this->pContext->swapchainMgr().vulkanExtent()},
												   static_cast<std::uint32_t>(sClearValue.size()),
												   sClearValue.data()};

		vkCmdBeginRenderPass(
			sGraphicsCommandBuffer,
			&sRenderPassBeginInfo,
			VkSubpassContents::VK_SUBPASS_CONTENTS_INLINE);

		for (const auto &sMaterialMesh: sMaterialMeshVec) {
			vkCmdBindPipeline(
				sGraphicsCommandBuffer,
				VkPipelineBindPoint::VK_PIPELINE_BIND_POINT_GRAPHICS,
				std::get<0>(sMaterialMesh)->pipeline());

			auto		 sBuffer{std::get<1>(sMaterialMesh)->buffer()};
			VkDeviceSize nOffset{0};
			vkCmdBindVertexBuffers(sGraphicsCommandBuffer, 0, 1, &sBuffer, &nOffset);

			vkCmdDraw(sGraphicsCommandBuffer, std::get<1>(sMaterialMesh)->count(), 1, 0, 0);
		}

		vkCmdEndRenderPass(sGraphicsCommandBuffer);

		// ##################################################
		// ## Rendering end
		// ##################################################

		{
			VkImageMemoryBarrier sGraphicsImageMemoryBarrier{
				VkStructureType::VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER,
				nullptr,
				VkAccessFlagBits::VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT,
				0,
				VkImageLayout::VK_IMAGE_LAYOUT_PRESENT_SRC_KHR,
				VkImageLayout::VK_IMAGE_LAYOUT_PRESENT_SRC_KHR,
				this->pContext->deviceMgr().graphicsQueueFamilyIndex(),
				this->pContext->deviceMgr().presentQueueFamilyIndex(),
				this->pContext->swapchainMgr().vulkanImageVec()[nImageIndex],
				VkImageSubresourceRange{VkImageAspectFlagBits::VK_IMAGE_ASPECT_COLOR_BIT,
										0,
										VK_REMAINING_MIP_LEVELS,
										0,
										VK_REMAINING_ARRAY_LAYERS}};
			VkImageMemoryBarrier sPresentImageMemoryBarrier{
				VkStructureType::VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER,
				nullptr,
				0,
				0,
				VkImageLayout::VK_IMAGE_LAYOUT_PRESENT_SRC_KHR,
				VkImageLayout::VK_IMAGE_LAYOUT_PRESENT_SRC_KHR,
				this->pContext->deviceMgr().graphicsQueueFamilyIndex(),
				this->pContext->deviceMgr().presentQueueFamilyIndex(),
				this->pContext->swapchainMgr().vulkanImageVec()[nImageIndex],
				VkImageSubresourceRange{VkImageAspectFlagBits::VK_IMAGE_ASPECT_COLOR_BIT,
										0,
										VK_REMAINING_MIP_LEVELS,
										0,
										VK_REMAINING_ARRAY_LAYERS}};

			vkCmdPipelineBarrier(
				sGraphicsCommandBuffer,
				VkPipelineStageFlagBits::VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT,
				VkPipelineStageFlagBits::VK_PIPELINE_STAGE_BOTTOM_OF_PIPE_BIT,
				0,
				0,
				nullptr,
				0,
				nullptr,
				1,
				&sGraphicsImageMemoryBarrier);
			vkCmdPipelineBarrier(
				sPresentCommandBuffer,
				VkPipelineStageFlagBits::VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT,
				VkPipelineStageFlagBits::VK_PIPELINE_STAGE_BOTTOM_OF_PIPE_BIT,
				0,
				0,
				nullptr,
				0,
				nullptr,
				1,
				&sPresentImageMemoryBarrier);
		}

		if (vkEndCommandBuffer(sGraphicsCommandBuffer) != VkResult::VK_SUCCESS
			|| vkEndCommandBuffer(sPresentCommandBuffer) != VkResult::VK_SUCCESS)
			throw std::runtime_error{"unable to end command buffer"};

		VkPipelineStageFlags sGraphicsWaitStageFlag{
			VkPipelineStageFlagBits::VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT};
		VkPipelineStageFlags sPresentWaitStageFlag{VkPipelineStageFlagBits::VK_PIPELINE_STAGE_ALL_COMMANDS_BIT};

		VkSubmitInfo sGraphisSubmitInfo{VkStructureType::VK_STRUCTURE_TYPE_SUBMIT_INFO,
										nullptr,
										1,
										&sAfterPresentationSemaphore,
										&sGraphicsWaitStageFlag,
										1,
										&sGraphicsCommandBuffer,
										1,
										&sAfterRenderingSemaphore};
		VkSubmitInfo sPresentSubmitInfo{VkStructureType::VK_STRUCTURE_TYPE_SUBMIT_INFO,
										nullptr,
										1,
										&sAfterRenderingSemaphore,
										&sPresentWaitStageFlag,
										1,
										&sPresentCommandBuffer,
										1,
										&sAfterOwnershipTransferredSemaphore};

		if (vkQueueSubmit(this->pContext->deviceMgr().graphicsQueue(), 1, &sGraphisSubmitInfo, VK_NULL_HANDLE)
				!= VkResult::VK_SUCCESS
			|| vkQueueSubmit(this->pContext->deviceMgr().presentQueue(), 1, &sPresentSubmitInfo, sFence)
				   != VkResult::VK_SUCCESS)
			throw std::runtime_error{"unable to submit to graphics queue"};

		auto sSwapchain{this->pContext->swapchainMgr().vulkanSwapchain()};

		VkPresentInfoKHR sPresentationInfo{VkStructureType::VK_STRUCTURE_TYPE_PRESENT_INFO_KHR,
										   nullptr,
										   1,
										   &sAfterOwnershipTransferredSemaphore,
										   1,
										   &sSwapchain,
										   &nImageIndex,
										   nullptr};

		if (vkQueuePresentKHR(this->pContext->deviceMgr().presentQueue(), &sPresentationInfo) != VkResult::VK_SUCCESS)
			throw std::runtime_error{"unable to queue present"};
	}
}	 // namespace onyx::core