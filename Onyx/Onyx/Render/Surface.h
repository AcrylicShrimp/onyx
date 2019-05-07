
/*
	2019.05.06
	Created by AcrylicShrimp.
*/

#ifndef _CLASS_ONYX_RENDER_SURFACE_H

#define _CLASS_ONYX_RENDER_SURFACE_H

#include "../Platform.h"
#include "../Vulkan.h"
#include "../Display/Window.h"

#include <cassert>
#include <stdexcept>
#include <vector>

namespace Onyx::Render
{
	class ContextManager;

	class Surface final
	{
	public:
		ContextManager *const pContextManager;
		Display::Window *const pWindow;

	private:
		VkSurfaceKHR vkSurface;
		VkSurfaceFormatKHR vkSurfaceFormat;
		
	public:
		Surface(ContextManager *pContextManager, Display::Window *pWindow);
		Surface(const Surface &sSrc) = delete;
		~Surface() noexcept;
		
	public:
		Surface &operator=(const Surface &sSrc) = delete;
		
	public:
		inline VkSurfaceKHR vulkanSurface() const noexcept;
		inline VkSurfaceFormatKHR vulkanSurfaceFormat() const noexcept;
		bool isCompatiblePhysicalDevice(VkPhysicalDevice vkPhysicalDevice);
		void findFormat(VkPhysicalDevice vkPhysicalDevice);
	};

	inline VkSurfaceKHR Surface::vulkanSurface() const noexcept
	{
		return this->vkSurface;
	}

	inline VkSurfaceFormatKHR Surface::vulkanSurfaceFormat() const noexcept
	{
		return this->vkSurfaceFormat;
	}
}

#endif