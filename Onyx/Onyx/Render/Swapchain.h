
/*
	2019.05.06
	Created by AcrylicShrimp.
*/

#ifndef _CLASS_ONYX_RENDER_SWAPCHAIN_H

#define _CLASS_ONYX_RENDER_SWAPCHAIN_H

#include "../Platform.h"
#include "../Vulkan.h"
#include "../Display/Window.h"
#include "./Device.h"
#include "./Surface.h"

#include <algorithm>
#include <cassert>
#include <cstdint>
#include <optional>
#include <stdexcept>
#include <vector>

namespace Onyx::Render
{
	class Swapchain final
	{
	public:
		Device *const pDevice;
		Surface *const pSurface;

	private:
		VkExtent2D vkExtent;
		VkSwapchainKHR vkSwapchain;
		VkPresentModeKHR vkPresentMode;
		std::vector<VkImage> sImageList;
		std::vector<VkImageView> sImageViewList;
		std::vector<VkImage> sDepthImageList;
		std::vector<VkImageView> sDepthImageViewList;
		std::vector<VkDeviceMemory> sDepthImageMemoryList;

	public:
		Swapchain(Device *pDevice, Surface *pSurface);
		Swapchain(const Swapchain &sSrc) = delete;
		~Swapchain() noexcept;

	public:
		Swapchain &operator=(const Swapchain &sSrc) = delete;

	public:
		inline VkExtent2D vulkanExtent() const noexcept;
		inline VkSwapchainKHR vulkanSwapchain() const noexcept;
		inline VkPresentModeKHR vulkanPresentMode() const noexcept;
		inline const std::vector<VkImage> &vulkanImageList() const noexcept;
		inline const std::vector<VkImageView> &vulkanImageViewList() const noexcept;
		inline const std::vector<VkImageView> &vulkanDepthImageViewList() const noexcept;
		bool isCompatiblePhysicalDevice(VkPhysicalDevice vkPhysicalDevice);
		void createSwapchainInstance();
	};

	inline VkExtent2D Swapchain::vulkanExtent() const noexcept
	{
		return this->vkExtent;
	}

	inline VkSwapchainKHR Swapchain::vulkanSwapchain() const noexcept
	{
		return this->vkSwapchain;
	}

	inline VkPresentModeKHR Swapchain::vulkanPresentMode() const noexcept
	{
		return this->vkPresentMode;
	}

	inline const std::vector<VkImage> &Swapchain::vulkanImageList() const noexcept
	{
		return this->sImageList;
	}

	inline const std::vector<VkImageView> &Swapchain::vulkanImageViewList() const noexcept
	{
		return this->sImageViewList;
	}

	inline const std::vector<VkImageView> &Swapchain::vulkanDepthImageViewList() const noexcept
	{
		return this->sDepthImageViewList;
	}
}

#endif