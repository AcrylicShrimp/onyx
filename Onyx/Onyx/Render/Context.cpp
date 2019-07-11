
/*
	2019.05.04
	Created by AcrylicShrimp.
*/

#include "Context.h"

#include "Object.h"

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
		sSwapchain{&this->sDevice, &this->sSurface},
		sSynchronizer{&this->sDevice, 3}
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
		this->sSynchronizer.createSynchronizationObject(this->nGraphicsFamily, this->nPresentFamily);

		vkGetDeviceQueue(this->sDevice.vulkanDevice(), this->nGraphicsFamily, 0, &this->vkGraphicsQueue);
		vkGetDeviceQueue(this->sDevice.vulkanDevice(), this->nPresentFamily, 0, &this->vkPresentQueue);

		this->pUniformMgr = std::make_unique<UniformManager>(this);
		this->pShaderMgr = std::make_unique<ShaderManager>(this);
		this->pRenderingMgr = std::make_unique<RenderingManager>(this);
		this->pMeshMgr = std::make_unique<MeshManager>(this);
	}

	Context::~Context() noexcept
	{
		vkDeviceWaitIdle(this->sDevice.vulkanDevice());
	}

	void Context::render(const Object &sObject)
	{
		auto sSynchronizationObject{this->sSynchronizer.sync()};
		auto sGraphicsCommandBuffer{std::get<0>(sSynchronizationObject)};
		auto sPresentCommandBuffer{std::get<1>(sSynchronizationObject)};
		auto sAfterRenderingSemaphore{std::get<2>(sSynchronizationObject)};
		auto sAfterOwnershipTransferredSemaphore{std::get<3>(sSynchronizationObject)};
		auto sAfterPresentationSemaphore{std::get<4>(sSynchronizationObject)};
		auto sFence{std::get<5>(sSynchronizationObject)};

		vkWaitForFences(this->sDevice.vulkanDevice(), 1, &sFence, VK_TRUE, std::numeric_limits<std::uint64_t>::max());
		vkResetFences(this->sDevice.vulkanDevice(), 1, &sFence);

		std::uint32_t nImageIndex;

		if (vkAcquireNextImageKHR(this->sDevice.vulkanDevice(), this->sSwapchain.vulkanSwapchain(), std::numeric_limits<std::uint64_t>::max(), sAfterPresentationSemaphore, VK_NULL_HANDLE, &nImageIndex) != VkResult::VK_SUCCESS)
			throw std::runtime_error{"unable to acquire next image"};

		this->pUniformMgr->updateUniform(nImageIndex);

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

		if (vkBeginCommandBuffer(sGraphicsCommandBuffer, &vkGraphicsCommandBufferBeginInfo) != VkResult::VK_SUCCESS ||
			vkBeginCommandBuffer(sPresentCommandBuffer, &vkPresentCommandBufferBeginInfo) != VkResult::VK_SUCCESS)
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
				sGraphicsCommandBuffer,
				VkPipelineStageFlagBits::VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT,
				VkPipelineStageFlagBits::VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT,
				0,
				0, nullptr,
				0, nullptr,
				1, &vkGraphicsImageMemoryBarrier);
		}

		this->pRenderingMgr->render(nImageIndex, sGraphicsCommandBuffer, sObject);

		{
			VkImageMemoryBarrier vkGraphicsImageMemoryBarrier
			{
				VkStructureType::VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER,
				nullptr,
				VkAccessFlagBits::VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT,
				0,
				VkImageLayout::VK_IMAGE_LAYOUT_PRESENT_SRC_KHR,
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
				VkImageLayout::VK_IMAGE_LAYOUT_PRESENT_SRC_KHR,
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
				sGraphicsCommandBuffer,
				VkPipelineStageFlagBits::VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT,
				VkPipelineStageFlagBits::VK_PIPELINE_STAGE_BOTTOM_OF_PIPE_BIT,
				0,
				0, nullptr,
				0, nullptr,
				1, &vkGraphicsImageMemoryBarrier);
			vkCmdPipelineBarrier(
				sPresentCommandBuffer,
				VkPipelineStageFlagBits::VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT,
				VkPipelineStageFlagBits::VK_PIPELINE_STAGE_BOTTOM_OF_PIPE_BIT,
				0,
				0, nullptr,
				0, nullptr,
				1, &vkPresentImageMemoryBarrier);
		}

		if (vkEndCommandBuffer(sGraphicsCommandBuffer) != VkResult::VK_SUCCESS ||
			vkEndCommandBuffer(sPresentCommandBuffer) != VkResult::VK_SUCCESS)
			throw std::runtime_error{"unable to end command buffer"};

		VkPipelineStageFlags vkGraphicsWaitStageFlag{VkPipelineStageFlagBits::VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT};
		VkPipelineStageFlags vkPresentWaitStageFlag{VkPipelineStageFlagBits::VK_PIPELINE_STAGE_ALL_COMMANDS_BIT};

		VkSubmitInfo vkGraphisSubmitInfo
		{
			VkStructureType::VK_STRUCTURE_TYPE_SUBMIT_INFO,
			nullptr,
			1,
			&sAfterPresentationSemaphore,
			&vkGraphicsWaitStageFlag,
			1,
			&sGraphicsCommandBuffer,
			1,
			&sAfterRenderingSemaphore
		};
		VkSubmitInfo vkPresentSubmitInfo
		{
			VkStructureType::VK_STRUCTURE_TYPE_SUBMIT_INFO,
			nullptr,
			1,
			&sAfterRenderingSemaphore,
			&vkPresentWaitStageFlag,
			1,
			&sPresentCommandBuffer,
			1,
			&sAfterOwnershipTransferredSemaphore
		};

		if (vkQueueSubmit(this->vkGraphicsQueue, 1, &vkGraphisSubmitInfo, VK_NULL_HANDLE) != VkResult::VK_SUCCESS ||
			vkQueueSubmit(this->vkPresentQueue, 1, &vkPresentSubmitInfo, sFence) != VkResult::VK_SUCCESS)
			throw std::runtime_error{"unable to submit to graphics queue"};

		auto vkSwapchain{this->sSwapchain.vulkanSwapchain()};

		VkPresentInfoKHR vkPresentationInfo
		{
			VkStructureType::VK_STRUCTURE_TYPE_PRESENT_INFO_KHR,
			nullptr,
			1,
			&sAfterOwnershipTransferredSemaphore,
			1,
			&vkSwapchain,
			&nImageIndex,
			nullptr
		};

		if (vkQueuePresentKHR(this->vkPresentQueue, &vkPresentationInfo) != VkResult::VK_SUCCESS)
			throw std::runtime_error{"unable to queue present"};
	}
}