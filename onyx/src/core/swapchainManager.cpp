
#include "onyx/includes/core/swapchainManager.h"

#include "onyx/includes/core/context.h"
#include "onyx/includes/core/deviceInfo.h"
#include "onyx/includes/display/window.h"

#include <cstdint>

namespace onyx::core {
	SwapchainManager::SwapchainManager(Context *pContext) : PerContextManager{pContext}
	{
		this->pContext->deviceMgr().addExtension(VK_KHR_SWAPCHAIN_EXTENSION_NAME);
	}

	SwapchainManager::~SwapchainManager() noexcept
	{
		// Empty.
	}

	bool SwapchainManager::isCompatible(const DeviceInfo &sDevice)
	{
		std::uint32_t nPresentModeCount;

		if (vkGetPhysicalDeviceSurfacePresentModesKHR(
				sDevice.physicalDevice(),
				this->pContext->surfaceMgr().vulkanSurface(),
				&nPresentModeCount,
				nullptr)
			!= VkResult::VK_SUCCESS)
			throw std::runtime_error{"unable to query present mode of physical device"};

		return nPresentModeCount != 0;
	}

	void SwapchainManager::init(const DeviceInfo &sDevice)
	{
		std::uint32_t nPresentModeCount;

		if (vkGetPhysicalDeviceSurfacePresentModesKHR(
				sDevice.physicalDevice(),
				this->pContext->surfaceMgr().vulkanSurface(),
				&nPresentModeCount,
				nullptr)
			!= VkResult::VK_SUCCESS)
			throw std::runtime_error{"unable to query present mode of physical device"};

		std::vector<VkPresentModeKHR> sPresentModeVec(nPresentModeCount);

		if (vkGetPhysicalDeviceSurfacePresentModesKHR(
				sDevice.physicalDevice(),
				this->pContext->surfaceMgr().vulkanSurface(),
				&nPresentModeCount,
				sPresentModeVec.data())
			!= VkResult::VK_SUCCESS)
			throw std::runtime_error{"unable to query present mode of physical device"};

		for (auto ePresentMode: sPresentModeVec) {
			if (ePresentMode == VkPresentModeKHR::VK_PRESENT_MODE_MAILBOX_KHR) {
				this->ePresentMode = VkPresentModeKHR::VK_PRESENT_MODE_MAILBOX_KHR;
				break;
			}

			if (ePresentMode == VkPresentModeKHR::VK_PRESENT_MODE_FIFO_KHR)
				this->ePresentMode = VkPresentModeKHR::VK_PRESENT_MODE_FIFO_KHR;
		}

		if (this->ePresentMode == VkPresentModeKHR::VK_PRESENT_MODE_MAX_ENUM_KHR)
			this->ePresentMode = sPresentModeVec.front();

		VkSurfaceCapabilitiesKHR sSurfaceCapabilities;

		if (vkGetPhysicalDeviceSurfaceCapabilitiesKHR(
				sDevice.physicalDevice(),
				this->pContext->surfaceMgr().vulkanSurface(),
				&sSurfaceCapabilities)
			!= VkResult::VK_SUCCESS)
			throw std::runtime_error{"unable to query surface capability of physical device"};

		if (sSurfaceCapabilities.currentExtent.width == std::numeric_limits<std::uint32_t>::max()) {
			auto sInnerRegion{this->pContext->surfaceMgr().pWindow->innerRegion()};
			// auto nWidth{static_cast<uint32_t>(sInnerRegion.nMaxX -
			// sInnerRegion.nMinX)}; auto
			// nHeight{static_cast<uint32_t>(sInnerRegion.nMaxY - sInnerRegion.nMinY)};
			auto nWidth{static_cast<uint32_t>(800)};
			auto nHeight{static_cast<uint32_t>(800)};

			sSurfaceCapabilities.currentExtent.width = std::max(
				std::min(nWidth, sSurfaceCapabilities.maxImageExtent.width),
				sSurfaceCapabilities.minImageExtent.width);
			sSurfaceCapabilities.currentExtent.height = std::max(
				std::min(nHeight, sSurfaceCapabilities.maxImageExtent.height),
				sSurfaceCapabilities.minImageExtent.height);
		}

		this->sExtent = sSurfaceCapabilities.currentExtent;

		VkSwapchainCreateInfoKHR sSwapchainCreateInfo{
			VkStructureType::VK_STRUCTURE_TYPE_SWAPCHAIN_CREATE_INFO_KHR,
			nullptr,
			0,
			this->pContext->surfaceMgr().vulkanSurface(),
			static_cast<std::uint32_t>(
				!sSurfaceCapabilities.maxImageCount || 2 < sSurfaceCapabilities.maxImageCount
					? 2
					: sSurfaceCapabilities.maxImageCount),
			this->pContext->surfaceMgr().vulkanSurfaceFormat().format,
			this->pContext->surfaceMgr().vulkanSurfaceFormat().colorSpace,
			sSurfaceCapabilities.currentExtent,
			1,
			VkImageUsageFlagBits::VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT,
			VkSharingMode::VK_SHARING_MODE_EXCLUSIVE,
			0,
			nullptr,
			sSurfaceCapabilities.currentTransform,
			VkCompositeAlphaFlagBitsKHR::VK_COMPOSITE_ALPHA_OPAQUE_BIT_KHR,
			this->ePresentMode,
			VK_TRUE,
			VK_NULL_HANDLE};

		if (vkCreateSwapchainKHR(
				this->pContext->deviceMgr().vulkanDevice(),
				&sSwapchainCreateInfo,
				nullptr,
				&this->sSwapchain)
			!= VkResult::VK_SUCCESS)
			throw std::runtime_error{"unable to create swapchain"};

		std::uint32_t nImageCount;

		if (vkGetSwapchainImagesKHR(this->pContext->deviceMgr().vulkanDevice(), this->sSwapchain, &nImageCount, nullptr)
			!= VkResult::VK_SUCCESS)
			throw std::runtime_error{"unable to query swapchain image of device"};

		this->sImageVec.resize(nImageCount);

		if (vkGetSwapchainImagesKHR(
				this->pContext->deviceMgr().vulkanDevice(),
				this->sSwapchain,
				&nImageCount,
				this->sImageVec.data())
			!= VkResult::VK_SUCCESS)
			throw std::runtime_error{"unable to query swapchain image of device"};

		this->sImageViewVec.reserve(this->sImageVec.size());

		for (auto vkImage: this->sImageVec) {
			VkImageViewCreateInfo sImageViewCreateInfo{
				VkStructureType::VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO,
				nullptr,
				0,
				vkImage,
				VkImageViewType::VK_IMAGE_VIEW_TYPE_2D,
				this->pContext->surfaceMgr().vulkanSurfaceFormat().format,
				VkComponentMapping{VK_COMPONENT_SWIZZLE_IDENTITY,
								   VK_COMPONENT_SWIZZLE_IDENTITY,
								   VK_COMPONENT_SWIZZLE_IDENTITY,
								   VK_COMPONENT_SWIZZLE_IDENTITY},
				VkImageSubresourceRange{VkImageAspectFlagBits::VK_IMAGE_ASPECT_COLOR_BIT, 0, 1, 0, 1}};

			VkImageView sImageView;

			if (vkCreateImageView(
					this->pContext->deviceMgr().vulkanDevice(),
					&sImageViewCreateInfo,
					nullptr,
					&sImageView)
				!= VkResult::VK_SUCCESS)
				throw std::runtime_error("unable to create image view");

			this->sImageViewVec.emplace_back(sImageView);
		}

		// ##################################################
		// ## Depth image creation
		// ##################################################

		VkImageCreateInfo sDepthImageCreateInfo{VkStructureType::VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO,
												nullptr,
												0,
												VkImageType::VK_IMAGE_TYPE_2D,
												VkFormat::VK_FORMAT_D32_SFLOAT,
												VkExtent3D{this->sExtent.width, this->sExtent.height, 1},
												1,
												1,
												VkSampleCountFlagBits::VK_SAMPLE_COUNT_1_BIT,
												VkImageTiling::VK_IMAGE_TILING_OPTIMAL,
												VkImageUsageFlagBits::VK_IMAGE_USAGE_DEPTH_STENCIL_ATTACHMENT_BIT,
												VkSharingMode::VK_SHARING_MODE_EXCLUSIVE,
												0,
												nullptr,
												VkImageLayout::VK_IMAGE_LAYOUT_UNDEFINED};

		if (vkCreateImage(
				this->pContext->deviceMgr().vulkanDevice(),
				&sDepthImageCreateInfo,
				nullptr,
				&this->sDepthImage)
			!= VkResult::VK_SUCCESS)
			throw std::runtime_error("unable to create depth image");

		this->sDepthImageMemory
			= this->pContext->deviceMgr().allocateImageMemory(DeviceMemoryType::Local, this->sDepthImage);

		if (vkBindImageMemory(this->pContext->deviceMgr().vulkanDevice(), this->sDepthImage, this->sDepthImageMemory, 0)
			!= VkResult::VK_SUCCESS)
			throw std::runtime_error{"unable to bind image memory"};

		VkImageViewCreateInfo sDepthImageViewCreateInfo{
			VkStructureType::VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO,
			nullptr,
			0,
			this->sDepthImage,
			VkImageViewType::VK_IMAGE_VIEW_TYPE_2D,
			VkFormat::VK_FORMAT_D32_SFLOAT,
			VkComponentMapping{VK_COMPONENT_SWIZZLE_IDENTITY,
							   VK_COMPONENT_SWIZZLE_IDENTITY,
							   VK_COMPONENT_SWIZZLE_IDENTITY,
							   VK_COMPONENT_SWIZZLE_IDENTITY},
			VkImageSubresourceRange{VkImageAspectFlagBits::VK_IMAGE_ASPECT_DEPTH_BIT, 0, 1, 0, 1}};

		if (vkCreateImageView(
				this->pContext->deviceMgr().vulkanDevice(),
				&sDepthImageViewCreateInfo,
				nullptr,
				&this->sDepthImageView)
			!= VkResult::VK_SUCCESS)
			throw std::runtime_error("unable to create image view");
	}

	void SwapchainManager::fin()
	{
		// Empty.
	}
}	 // namespace onyx::core