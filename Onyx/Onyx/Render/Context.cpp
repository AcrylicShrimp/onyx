
/*
	2019.05.04
	Created by AcrylicShrimp.
*/

#include "Context.h"

#ifdef min
#undef min
#endif

#ifdef max
#undef max
#endif

namespace Onyx::Render
{
	Context::Context(ContextManager *pContextManager, Display::Window *pWindow) :
		pContextManager{pContextManager},
		pWindow{pWindow},
		sDevice{pContextManager},
		sSurface{pContextManager, pWindow},
		sSwapchain{&this->sDevice, &this->sSurface}
	{
		assert(this->pContextManager);

		std::vector<const char *> sPhysicalDeviceExtensionList
		{
			VK_KHR_SWAPCHAIN_EXTENSION_NAME
		};

		if (!this->sDevice.selectPhysicalDevice(sPhysicalDeviceExtensionList, [this](const Device::Attribute &sDeviceAttribute)
		{
			bool bGraphicsQueue{false};

			for (const auto &vkQueueFamily : sDeviceAttribute.sQueueFamilyList)
				if (vkQueueFamily.queueCount != 0 && vkQueueFamily.queueFlags & VkQueueFlagBits::VK_QUEUE_GRAPHICS_BIT)
				{
					bGraphicsQueue = true;
					break;
				}

			if (!bGraphicsQueue)
				return false;

			bool bPresentQueue{false};

			for (std::uint32_t nIndex{0}, nMaxIndex{static_cast<std::uint32_t>(sDeviceAttribute.sQueueFamilyList.size())}; nIndex < nMaxIndex; ++nIndex)
				if (sDeviceAttribute.sQueueFamilyList[nIndex].queueCount != 0)
				{
					VkBool32 vkSurfaceSupport;

					if (vkGetPhysicalDeviceSurfaceSupportKHR(sDeviceAttribute.vkDevice, nIndex, this->sSurface.vulkanSurface(), &vkSurfaceSupport) != VkResult::VK_SUCCESS)
						throw std::runtime_error{"unable to query surface support of physical device"};

					if (vkSurfaceSupport)
					{
						bPresentQueue = true;
						break;
					}
				}

			if (!bPresentQueue)
				return false;

			if (!this->sSurface.isCompatiblePhysicalDevice(sDeviceAttribute.vkDevice))
				return false;

			if (!this->sSwapchain.isCompatiblePhysicalDevice(sDeviceAttribute.vkDevice))
				return false;

			return true;
		}))
			throw std::runtime_error{"no suitable physical device detected"};

		this->sSurface.findFormat(this->sDevice.vulkanPhysicalDevice());

		const auto &sPhysicalDeviceAttribute{this->sDevice.physicalDeviceAttribute()};
		const auto &sQueueFamilyList{sPhysicalDeviceAttribute.sQueueFamilyList};

		for (std::uint32_t nIndex{0}, nMaxIndex{static_cast<std::uint32_t>(sQueueFamilyList.size())}; nIndex < nMaxIndex; ++nIndex)
			if (sQueueFamilyList[nIndex].queueCount != 0 && sQueueFamilyList[nIndex].queueFlags & VkQueueFlagBits::VK_QUEUE_GRAPHICS_BIT)
			{
				this->nGraphicsFamily = nIndex;
				break;
			}

		for (std::uint32_t nIndex{0}, nMaxIndex{static_cast<std::uint32_t>(sQueueFamilyList.size())}; nIndex < nMaxIndex; ++nIndex)
			if (sQueueFamilyList[nIndex].queueCount != 0)
			{
				VkBool32 vkSurfaceSupport;

				if (vkGetPhysicalDeviceSurfaceSupportKHR(sPhysicalDeviceAttribute.vkDevice, nIndex, this->sSurface.vulkanSurface(), &vkSurfaceSupport) != VkResult::VK_SUCCESS)
					throw std::runtime_error{"unable to query surface support of physical device"};

				if (vkSurfaceSupport)
				{
					this->nPresentFamily = nIndex;
					break;
				}
			}

		this->sDevice.createDeviceInstance(sPhysicalDeviceExtensionList, std::unordered_set<std::uint32_t>
		{
			this->nGraphicsFamily,
			this->nPresentFamily
		});
		this->sSwapchain.createSwapchainInstance();

		vkGetDeviceQueue(this->sDevice.vulkanDevice(), this->nGraphicsFamily, 0, &this->vkGraphicsQueue);
		vkGetDeviceQueue(this->sDevice.vulkanDevice(), this->nPresentFamily, 0, &this->vkPresentQueue);

		VkCommandPoolCreateInfo vkCommandPoolCreateInfo
		{
			VkStructureType::VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO,
			nullptr,
			VkCommandPoolCreateFlagBits::VK_COMMAND_POOL_CREATE_TRANSIENT_BIT |
			VkCommandPoolCreateFlagBits::VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT,
			this->nGraphicsFamily
		};

		if (vkCreateCommandPool(this->sDevice.vulkanDevice(), &vkCommandPoolCreateInfo, nullptr, &this->vkCommandPool) != VkResult::VK_SUCCESS)
			throw std::runtime_error{"unable to create command pool"};

		this->sGraphicsCommandBufferList.resize(this->sSwapchain.vulkanImageViewList().size());
		this->sPresentCommandBufferList.resize(this->sSwapchain.vulkanImageViewList().size());

		VkCommandBufferAllocateInfo vkGraphicsCommandBufferAllocateInfo
		{
			VkStructureType::VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO,
			nullptr,
			this->vkCommandPool,
			VkCommandBufferLevel::VK_COMMAND_BUFFER_LEVEL_PRIMARY,
			static_cast<std::uint32_t>(this->sGraphicsCommandBufferList.size())
		};
		VkCommandBufferAllocateInfo vkPresentCommandBufferAllocateInfo
		{
			VkStructureType::VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO,
			nullptr,
			this->vkCommandPool,
			VkCommandBufferLevel::VK_COMMAND_BUFFER_LEVEL_PRIMARY,
			static_cast<std::uint32_t>(this->sPresentCommandBufferList.size())
		};

		if (vkAllocateCommandBuffers(this->sDevice.vulkanDevice(), &vkGraphicsCommandBufferAllocateInfo, this->sGraphicsCommandBufferList.data()) != VkResult::VK_SUCCESS ||
			vkAllocateCommandBuffers(this->sDevice.vulkanDevice(), &vkPresentCommandBufferAllocateInfo, this->sPresentCommandBufferList.data()) != VkResult::VK_SUCCESS)
			throw std::runtime_error{"unable to allocate command buffer"};

		VkSemaphoreCreateInfo vkSemaphoreCreateInfo
		{
			VkStructureType::VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO,
			nullptr,
			0
		};

		if (vkCreateSemaphore(this->sDevice.vulkanDevice(), &vkSemaphoreCreateInfo, nullptr, &this->vkSemaphoreAfterRendering) != VkResult::VK_SUCCESS ||
			vkCreateSemaphore(this->sDevice.vulkanDevice(), &vkSemaphoreCreateInfo, nullptr, &this->vkSemaphoreAfterOwnershipTransferred) != VkResult::VK_SUCCESS ||
			vkCreateSemaphore(this->sDevice.vulkanDevice(), &vkSemaphoreCreateInfo, nullptr, &this->vkSemaphoreAfterPresentation) != VkResult::VK_SUCCESS)
			throw std::runtime_error{"unable to create semaphore"};
	}

	Context::~Context() noexcept
	{
		vkDestroySemaphore(this->sDevice.vulkanDevice(), this->vkSemaphoreAfterRendering, nullptr);
		vkDestroySemaphore(this->sDevice.vulkanDevice(), this->vkSemaphoreAfterOwnershipTransferred, nullptr);
		vkDestroySemaphore(this->sDevice.vulkanDevice(), this->vkSemaphoreAfterPresentation, nullptr);
		vkDestroyCommandPool(this->sDevice.vulkanDevice(), this->vkCommandPool, nullptr);
	}

	void Context::render(VkPipeline vkPipeline, VkRenderPass vkRenderPass, const std::vector<VkFramebuffer> &sFramebuffer)
	{
		std::uint32_t nImageIndex;

		if (vkAcquireNextImageKHR(this->sDevice.vulkanDevice(), this->sSwapchain.vulkanSwapchain(), std::numeric_limits<std::uint64_t>::max(), this->vkSemaphoreAfterPresentation, VK_NULL_HANDLE, &nImageIndex) != VkResult::VK_SUCCESS)
			throw std::runtime_error{"unable to acquire next image"};

		VkCommandBufferBeginInfo vkGraphicsCommandBufferBeginInfo
		{
			VkStructureType::VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO,
			nullptr,
			VkCommandBufferUsageFlagBits::VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT,
			nullptr
		};
		VkCommandBufferBeginInfo vkPresentCommandBufferBeginInfo
		{
			VkStructureType::VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO,
			nullptr,
			VkCommandBufferUsageFlagBits::VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT,
			nullptr
		};

		if (vkBeginCommandBuffer(this->sGraphicsCommandBufferList[nImageIndex], &vkGraphicsCommandBufferBeginInfo) != VkResult::VK_SUCCESS ||
			vkBeginCommandBuffer(this->sPresentCommandBufferList[nImageIndex], &vkPresentCommandBufferBeginInfo) != VkResult::VK_SUCCESS)
			throw std::runtime_error{"unable to begin command buffer"};

		{
			VkImageMemoryBarrier vkGraphicsImageMemoryBarrier
			{
				VkStructureType::VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER,
				nullptr,
				0,
				VkAccessFlagBits::VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT,
				VkImageLayout::VK_IMAGE_LAYOUT_UNDEFINED,
				VkImageLayout::VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL,
				VK_QUEUE_FAMILY_IGNORED,
				VK_QUEUE_FAMILY_IGNORED,
				this->sSwapchain.vulkanImageList()[nImageIndex],
				VkImageSubresourceRange
				{
					VkImageAspectFlagBits::VK_IMAGE_ASPECT_COLOR_BIT,
					0,
					VK_REMAINING_MIP_LEVELS,
					0,
					VK_REMAINING_ARRAY_LAYERS
				}
			};

			vkCmdPipelineBarrier(
				this->sGraphicsCommandBufferList[nImageIndex],
				VkPipelineStageFlagBits::VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT,
				VkPipelineStageFlagBits::VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT,
				0,
				0, nullptr,
				0, nullptr,
				1, &vkGraphicsImageMemoryBarrier);
		}

		VkClearValue vkClearValue
		{
			.0f, .0f, .0f, .0f
		};

		VkRenderPassBeginInfo vkRenderPassBeginInfo
		{
			VkStructureType::VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO,
			nullptr,
			vkRenderPass,
			sFramebuffer[nImageIndex],
			VkRect2D{{0, 0}, this->sSwapchain.vulkanExtent()},
			1,
			&vkClearValue
		};

		vkCmdBeginRenderPass(this->sGraphicsCommandBufferList[nImageIndex], &vkRenderPassBeginInfo, VkSubpassContents::VK_SUBPASS_CONTENTS_INLINE);

		//TODO : Render something
		vkCmdBindPipeline(this->sGraphicsCommandBufferList[nImageIndex], VkPipelineBindPoint::VK_PIPELINE_BIND_POINT_GRAPHICS, vkPipeline);
		vkCmdDraw(this->sGraphicsCommandBufferList[nImageIndex], 3, 1, 0, 0);

		vkCmdEndRenderPass(this->sGraphicsCommandBufferList[nImageIndex]);

		{
			VkImageMemoryBarrier vkGraphicsImageMemoryBarrier
			{
				VkStructureType::VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER,
				nullptr,
				VkAccessFlagBits::VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT,
				0,
				VkImageLayout::VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL,
				VkImageLayout::VK_IMAGE_LAYOUT_PRESENT_SRC_KHR,
				this->nGraphicsFamily,
				this->nPresentFamily,
				this->sSwapchain.vulkanImageList()[nImageIndex],
				VkImageSubresourceRange
				{
					VkImageAspectFlagBits::VK_IMAGE_ASPECT_COLOR_BIT,
					0,
					VK_REMAINING_MIP_LEVELS,
					0,
					VK_REMAINING_ARRAY_LAYERS
				}
			};
			VkImageMemoryBarrier vkPresentImageMemoryBarrier
			{
				VkStructureType::VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER,
				nullptr,
				0,
				0,
				VkImageLayout::VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL,
				VkImageLayout::VK_IMAGE_LAYOUT_PRESENT_SRC_KHR,
				this->nGraphicsFamily,
				this->nPresentFamily,
				this->sSwapchain.vulkanImageList()[nImageIndex],
				VkImageSubresourceRange
				{
					VkImageAspectFlagBits::VK_IMAGE_ASPECT_COLOR_BIT,
					0,
					VK_REMAINING_MIP_LEVELS,
					0,
					VK_REMAINING_ARRAY_LAYERS
				}
			};

			vkCmdPipelineBarrier(
				this->sGraphicsCommandBufferList[nImageIndex],
				VkPipelineStageFlagBits::VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT,
				VkPipelineStageFlagBits::VK_PIPELINE_STAGE_BOTTOM_OF_PIPE_BIT,
				0,
				0, nullptr,
				0, nullptr,
				1, &vkGraphicsImageMemoryBarrier);
			vkCmdPipelineBarrier(
				this->sPresentCommandBufferList[nImageIndex],
				VkPipelineStageFlagBits::VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT,
				VkPipelineStageFlagBits::VK_PIPELINE_STAGE_BOTTOM_OF_PIPE_BIT,
				0,
				0, nullptr,
				0, nullptr,
				1, &vkPresentImageMemoryBarrier);
		}

		if (vkEndCommandBuffer(this->sGraphicsCommandBufferList[nImageIndex]) != VkResult::VK_SUCCESS ||
			vkEndCommandBuffer(this->sPresentCommandBufferList[nImageIndex]) != VkResult::VK_SUCCESS)
			throw std::runtime_error{"unable to end command buffer"};

		VkPipelineStageFlags vkGraphicsWaitStageFlag{VkPipelineStageFlagBits::VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT};
		VkPipelineStageFlags vkPresentWaitStageFlag{VkPipelineStageFlagBits::VK_PIPELINE_STAGE_ALL_COMMANDS_BIT};

		VkSubmitInfo vkGraphisSubmitInfo
		{
			VkStructureType::VK_STRUCTURE_TYPE_SUBMIT_INFO,
			nullptr,
			1,
			&this->vkSemaphoreAfterPresentation,
			&vkGraphicsWaitStageFlag,
			1,
			&this->sGraphicsCommandBufferList[nImageIndex],
			1,
			&this->vkSemaphoreAfterRendering
		};
		VkSubmitInfo vkPresentSubmitInfo
		{
			VkStructureType::VK_STRUCTURE_TYPE_SUBMIT_INFO,
			nullptr,
			1,
			&this->vkSemaphoreAfterRendering,
			&vkPresentWaitStageFlag,
			1,
			&this->sPresentCommandBufferList[nImageIndex],
			1,
			&this->vkSemaphoreAfterOwnershipTransferred
		};

		if (vkQueueSubmit(this->vkGraphicsQueue, 1, &vkGraphisSubmitInfo, VK_NULL_HANDLE) != VkResult::VK_SUCCESS ||
			vkQueueSubmit(this->vkPresentQueue, 1, &vkPresentSubmitInfo, VK_NULL_HANDLE) != VkResult::VK_SUCCESS)
			throw std::runtime_error{"unable to submit to graphics queue"};

		auto vkSwapchain{this->sSwapchain.vulkanSwapchain()};

		VkPresentInfoKHR vkPresentationInfo
		{
			VkStructureType::VK_STRUCTURE_TYPE_PRESENT_INFO_KHR,
			nullptr,
			1,
			&this->vkSemaphoreAfterOwnershipTransferred,
			1,
			&vkSwapchain,
			&nImageIndex,
			nullptr
		};

		if (vkQueuePresentKHR(this->vkPresentQueue, &vkPresentationInfo) != VkResult::VK_SUCCESS)
			throw std::runtime_error{"unable to queue present"};
	}
}