
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
		//std::vector<VkFramebuffer> sFramebufferList;
		
	public:
		Swapchain(Device *pDevice, Surface *pSurface);
		Swapchain(const Swapchain &sSrc) = delete;
		~Swapchain() noexcept;
		
	public:
		Swapchain &operator=(const Swapchain &sSrc) = delete;
		
	public:
		bool isCompatiblePhysicalDevice(VkPhysicalDevice vkPhysicalDevice);
		void createSwapchainInstance();
	};
}

#endif