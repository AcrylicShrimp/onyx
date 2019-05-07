
/*
	2019.05.06
	Created by AcrylicShrimp.
*/

#include "RenderTarget.h"

#include "Context.h"

#ifdef min
#undef min
#endif

#ifdef max
#undef max
#endif

namespace Onyx::Render
{
	RenderTarget::RenderTarget(Context *pContext, Display::Window *pWindow) :
		pContext{pContext},
		pWindow{pWindow},
		vkPresentQueue{VK_NULL_HANDLE},
		nPresentQueueIndex{0}
	{
		assert(this->pContext);

#if __ONYX_PLATFORM_WINDOWS
		VkWin32SurfaceCreateInfoKHR vkSurfaceCreateInfo
		{
			VkStructureType::VK_STRUCTURE_TYPE_WIN32_SURFACE_CREATE_INFO_KHR,
			nullptr,
			0,
			GetModuleHandle(nullptr),
			static_cast<Display::WindowType *>(this->pWindow)->windowHandle()
		};

		if (vkCreateWin32SurfaceKHR(this->pContext->pContextManager->vulkanInstance(), &vkSurfaceCreateInfo, nullptr, &this->vkSurface) != VkResult::VK_SUCCESS)
			throw std::runtime_error{"unable to create surface instance"};
#endif

		const auto &sPhysicalDeviceAttribute{this->pContext->vulkanPhysicalDeviceAttribute()};
		const auto &sQueuePropertiesList{this->pContext->vulkanPhysicalDeviceAttribute().sQueueFamilyList};

		auto bSurfaceSupport{false};

		for (std::uint32_t nIndex{0}, nMaxIndex{static_cast<std::uint32_t>(sQueuePropertiesList.size())}; nIndex < nMaxIndex; ++nIndex)
		{
			VkBool32 vkSurfaceSupport;

			if (vkGetPhysicalDeviceSurfaceSupportKHR(this->pContext->vulkanPhysicalDevice(), nIndex, this->vkSurface, &vkSurfaceSupport) != VkResult::VK_SUCCESS)
				throw std::runtime_error{"unable to query surface support of physical device"};

			if (vkSurfaceSupport)
			{
				bSurfaceSupport = true;
				this->nPresentQueueIndex = nIndex;

				break;
			}
		}

		if (!bSurfaceSupport)
			throw std::runtime_error{"no queue family supports surface"};

		//vkGetDeviceQueue(this->pContext->vulkanDevice(), this->nPresentQueueIndex, 0, &)

		std::uint32_t nSurfaceFormatCount;

		if (vkGetPhysicalDeviceSurfaceFormatsKHR(sPhysicalDeviceAttribute.vkDevice, this->vkSurface, &nSurfaceFormatCount, nullptr) != VkResult::VK_SUCCESS)
			throw std::runtime_error{"unable to query surface format of physical device"};

		if (!nSurfaceFormatCount)
			throw std::runtime_error{"no supported surface format detected"};

		std::vector<VkSurfaceFormatKHR> sSurfaceFormatList{nSurfaceFormatCount};

		if (vkGetPhysicalDeviceSurfaceFormatsKHR(sPhysicalDeviceAttribute.vkDevice, this->vkSurface, &nSurfaceFormatCount, sSurfaceFormatList.data()) != VkResult::VK_SUCCESS)
			throw std::runtime_error{"unable to query surface format of physical device"};

		auto bSurfaceFormat{false};

		for (auto vkSurfaceFormat : sSurfaceFormatList)
			if (vkSurfaceFormat.format == VkFormat::VK_FORMAT_UNDEFINED || vkSurfaceFormat.format == VkFormat::VK_FORMAT_B8G8R8A8_UNORM)
			{
				bSurfaceFormat = true;
				this->vkSurfaceFormat = vkSurfaceFormat;

				break;
			}

		if (!bSurfaceFormat)
			throw std::runtime_error{"no compatible surface format detected"};

		std::uint32_t nPresentModeCount;

		if (vkGetPhysicalDeviceSurfacePresentModesKHR(sPhysicalDeviceAttribute.vkDevice, this->vkSurface, &nPresentModeCount, nullptr) != VkResult::VK_SUCCESS)
			throw std::runtime_error{"unable to query present mode of physical device"};

		if (!nPresentModeCount)
			throw std::runtime_error{"no supported present mode detected"};

		std::vector<VkPresentModeKHR> sPresentModeList(nPresentModeCount);

		if (vkGetPhysicalDeviceSurfacePresentModesKHR(sPhysicalDeviceAttribute.vkDevice, this->vkSurface, &nPresentModeCount, sPresentModeList.data()) != VkResult::VK_SUCCESS)
			throw std::runtime_error{"unable to query present mode of physical device"};

		auto vkSelectedPresentMode{VkPresentModeKHR::VK_PRESENT_MODE_MAX_ENUM_KHR};

		for (auto vkPresentMode : sPresentModeList)
		{
			if (vkPresentMode == VkPresentModeKHR::VK_PRESENT_MODE_MAILBOX_KHR)
			{
				vkSelectedPresentMode = VkPresentModeKHR::VK_PRESENT_MODE_MAILBOX_KHR;
				break;
			}

			if (vkPresentMode == VkPresentModeKHR::VK_PRESENT_MODE_FIFO_KHR)
				vkPresentMode = VkPresentModeKHR::VK_PRESENT_MODE_FIFO_KHR;
		}

		if (vkSelectedPresentMode == VkPresentModeKHR::VK_PRESENT_MODE_MAX_ENUM_KHR)
			vkSelectedPresentMode = sPresentModeList.front();

		VkSurfaceCapabilitiesKHR vkSurfaceCapabilities;

		if (vkGetPhysicalDeviceSurfaceCapabilitiesKHR(sPhysicalDeviceAttribute.vkDevice, this->vkSurface, &vkSurfaceCapabilities) != VkResult::VK_SUCCESS)
			throw std::runtime_error{"unable to query surface capability of physical device"};

		if (vkSurfaceCapabilities.currentExtent.width == std::numeric_limits<std::uint32_t>::max())
		{
			auto nWidth{static_cast<uint32_t>(this->pWindow->innerRegion().nMaxX - this->pWindow->innerRegion().nMinX)};
			auto nHeight{static_cast<uint32_t>(this->pWindow->innerRegion().nMaxY - this->pWindow->innerRegion().nMinY)};

			vkSurfaceCapabilities.currentExtent.width = std::max(std::min(nWidth, vkSurfaceCapabilities.maxImageExtent.width), vkSurfaceCapabilities.minImageExtent.width);
			vkSurfaceCapabilities.currentExtent.height = std::max(std::min(nHeight, vkSurfaceCapabilities.maxImageExtent.height), vkSurfaceCapabilities.minImageExtent.height);
		}

		VkSwapchainCreateInfoKHR vkSwapchainCreateInfo
		{
			VkStructureType::VK_STRUCTURE_TYPE_SWAPCHAIN_CREATE_INFO_KHR,
			nullptr,
			0,
			this->vkSurface,
			vkSurfaceCapabilities.minImageCount + 1 < vkSurfaceCapabilities.maxImageCount ? vkSurfaceCapabilities.minImageCount + 1 : vkSurfaceCapabilities.maxImageCount,
			vkSurfaceFormat,
			vkSurfaceColorSpace,
			vkSurfaceCapabilities.currentExtent,
			1,
			VkImageUsageFlagBits::VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT,
			nGraphicsQueueIndex == nPresentQueueIndex ? VkSharingMode::VK_SHARING_MODE_EXCLUSIVE : VkSharingMode::VK_SHARING_MODE_CONCURRENT,
			nGraphicsQueueIndex == nPresentQueueIndex ? 0 : 2,
			nGraphicsQueueIndex == nPresentQueueIndex ? nullptr : std::vector<std::uint32_t>{nGraphicsQueueIndex, nPresentQueueIndex}.data(),
			vkSurfaceCapabilities.currentTransform,
			VkCompositeAlphaFlagBitsKHR::VK_COMPOSITE_ALPHA_OPAQUE_BIT_KHR,
			vkPresentMode,
			VK_TRUE,
			VK_NULL_HANDLE
		};

		if (vkCreateSwapchainKHR(this->vkDevice, &vkSwapchainCreateInfo, nullptr, &this->vkSwapchain) != VkResult::VK_SUCCESS)
			throw std::runtime_error{"unable to create swapchain"};
	}
	
	RenderTarget::~RenderTarget()
	{

	}
}