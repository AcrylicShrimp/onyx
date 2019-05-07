
/*
	2019.05.06
	Created by AcrylicShrimp.
*/

#include "Swapchain.h"

#include "./Context.h"

#ifdef min
#undef min
#endif

#ifdef max
#undef max
#endif

namespace Onyx::Render
{
	Swapchain::Swapchain(Device *pDevice, Surface *pSurface) :
		pDevice{pDevice},
		pSurface{pSurface},
		vkSwapchain{VK_NULL_HANDLE},
		vkPresentMode{VkPresentModeKHR::VK_PRESENT_MODE_MAX_ENUM_KHR}
	{
		assert(this->pDevice);
		assert(this->pSurface);
	}
	
	Swapchain::~Swapchain()
	{
		for (auto vkImageView : this->sImageViewList)
			vkDestroyImageView(this->pDevice->vulkanDevice(), vkImageView, nullptr);

		vkDestroySwapchainKHR(this->pDevice->vulkanDevice(), this->vkSwapchain, nullptr);
	}

	bool Swapchain::isCompatiblePhysicalDevice(VkPhysicalDevice vkPhysicalDevice)
	{
		std::uint32_t nPresentModeCount;

		if (vkGetPhysicalDeviceSurfacePresentModesKHR(vkPhysicalDevice, this->pSurface->vulkanSurface(), &nPresentModeCount, nullptr) != VkResult::VK_SUCCESS)
			throw std::runtime_error{"unable to query present mode of physical device"};

		return nPresentModeCount != 0;
	}

	void Swapchain::createSwapchainInstance()
	{
		std::uint32_t nPresentModeCount;

		if (vkGetPhysicalDeviceSurfacePresentModesKHR(this->pDevice->vulkanPhysicalDevice(), this->pSurface->vulkanSurface(), &nPresentModeCount, nullptr) != VkResult::VK_SUCCESS)
			throw std::runtime_error{"unable to query present mode of physical device"};

		if (nPresentModeCount == 0)
			throw std::runtime_error{"no supported present mode found"};

		std::vector<VkPresentModeKHR> sPresentModeList(nPresentModeCount);

		if (vkGetPhysicalDeviceSurfacePresentModesKHR(this->pDevice->vulkanPhysicalDevice(), this->pSurface->vulkanSurface(), &nPresentModeCount, sPresentModeList.data()) != VkResult::VK_SUCCESS)
			throw std::runtime_error{"unable to query present mode of physical device"};

		for (auto vkPresentMode : sPresentModeList)
		{
			if (vkPresentMode == VkPresentModeKHR::VK_PRESENT_MODE_MAILBOX_KHR)
			{
				this->vkPresentMode = VkPresentModeKHR::VK_PRESENT_MODE_MAILBOX_KHR;
				break;
			}

			if (vkPresentMode == VkPresentModeKHR::VK_PRESENT_MODE_FIFO_KHR)
				vkPresentMode = VkPresentModeKHR::VK_PRESENT_MODE_FIFO_KHR;
		}

		if (this->vkPresentMode == VkPresentModeKHR::VK_PRESENT_MODE_MAX_ENUM_KHR)
			this->vkPresentMode = sPresentModeList.front();

		VkSurfaceCapabilitiesKHR vkSurfaceCapabilities;

		if (vkGetPhysicalDeviceSurfaceCapabilitiesKHR(this->pDevice->vulkanPhysicalDevice(), this->pSurface->vulkanSurface(), &vkSurfaceCapabilities) != VkResult::VK_SUCCESS)
			throw std::runtime_error{"unable to query surface capability of physical device"};

		if (vkSurfaceCapabilities.currentExtent.width == std::numeric_limits<std::uint32_t>::max())
		{
			auto nWidth{static_cast<uint32_t>(this->pSurface->pWindow->innerRegion().nMaxX - this->pSurface->pWindow->innerRegion().nMinX)};
			auto nHeight{static_cast<uint32_t>(this->pSurface->pWindow->innerRegion().nMaxY - this->pSurface->pWindow->innerRegion().nMinY)};

			vkSurfaceCapabilities.currentExtent.width = std::max(std::min(nWidth, vkSurfaceCapabilities.maxImageExtent.width), vkSurfaceCapabilities.minImageExtent.width);
			vkSurfaceCapabilities.currentExtent.height = std::max(std::min(nHeight, vkSurfaceCapabilities.maxImageExtent.height), vkSurfaceCapabilities.minImageExtent.height);
		}

		this->vkExtent = vkSurfaceCapabilities.currentExtent;

		VkSwapchainCreateInfoKHR vkSwapchainCreateInfo
		{
			VkStructureType::VK_STRUCTURE_TYPE_SWAPCHAIN_CREATE_INFO_KHR,
			nullptr,
			0,
			this->pSurface->vulkanSurface(),
			vkSurfaceCapabilities.minImageCount + 1 < vkSurfaceCapabilities.maxImageCount ? vkSurfaceCapabilities.minImageCount + 1 : vkSurfaceCapabilities.maxImageCount,
			this->pSurface->vulkanSurfaceFormat().format,
			this->pSurface->vulkanSurfaceFormat().colorSpace,
			vkSurfaceCapabilities.currentExtent,
			1,
			VkImageUsageFlagBits::VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT,
			VkSharingMode::VK_SHARING_MODE_EXCLUSIVE,
			0,
			nullptr,
			vkSurfaceCapabilities.currentTransform,
			VkCompositeAlphaFlagBitsKHR::VK_COMPOSITE_ALPHA_OPAQUE_BIT_KHR,
			vkPresentMode,
			VK_TRUE,
			VK_NULL_HANDLE
		};

		if (vkCreateSwapchainKHR(this->pDevice->vulkanDevice(), &vkSwapchainCreateInfo, nullptr, &this->vkSwapchain) != VkResult::VK_SUCCESS)
			throw std::runtime_error{"unable to create swapchain"};

		std::uint32_t nImageCount;

		if (vkGetSwapchainImagesKHR(this->pDevice->vulkanDevice(), this->vkSwapchain, &nImageCount, nullptr) != VkResult::VK_SUCCESS)
			throw std::runtime_error{"unable to query swapchain image of device"};

		this->sImageList.resize(nImageCount);
		
		if (vkGetSwapchainImagesKHR(this->pDevice->vulkanDevice(), this->vkSwapchain, &nImageCount, this->sImageList.data()) != VkResult::VK_SUCCESS)
			throw std::runtime_error{"unable to query swapchain image of device"};

		this->sImageViewList.reserve(this->sImageList.size());

		for (auto vkImage : this->sImageList)
		{
			VkImageViewCreateInfo vkImageViewCreateInfo
			{
				VkStructureType::VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO,
				nullptr,
				0,
				vkImage,
				VkImageViewType::VK_IMAGE_VIEW_TYPE_2D,
				this->pSurface->vulkanSurfaceFormat().format,
				VkComponentMapping
				{
					VK_COMPONENT_SWIZZLE_IDENTITY,
						VK_COMPONENT_SWIZZLE_IDENTITY,
						VK_COMPONENT_SWIZZLE_IDENTITY,
						VK_COMPONENT_SWIZZLE_IDENTITY
				},
				VkImageSubresourceRange
				{
					VkImageAspectFlagBits::VK_IMAGE_ASPECT_COLOR_BIT,
					0,
					1,
					0,
					1
				}
			};

			VkImageView vkImageView;

			if (vkCreateImageView(this->pDevice->vulkanDevice(), &vkImageViewCreateInfo, nullptr, &vkImageView) != VkResult::VK_SUCCESS)
				throw std::runtime_error("unable to create image view");

			this->sImageViewList.emplace_back(vkImageView);
		}
	}
}