
/*
	2019.05.06
	Created by AcrylicShrimp.
*/

#ifndef _CLASS_ONYX_RENDER_RENDERTARGET_H

#define _CLASS_ONYX_RENDER_RENDERTARGET_H

#include "../Platform.h"
#include "../Vulkan.h"
#include "../Display/Window.h"

#include <cassert>
#include <cstdint>
#include <stdexcept>
#include <vector>
#include <Windows.h>

namespace Onyx::Render
{
	class Context;

	class RenderTarget final
	{
	public:
		Context *const pContext;
		Display::Window *const pWindow;

	private:
		VkSurfaceKHR vkSurface;
		VkSurfaceFormatKHR vkSurfaceFormat;
		VkSwapchainKHR vkSwapchain;
		VkQueue vkPresentQueue;
		std::uint32_t nPresentQueueIndex;
		std::vector<VkImage> sImageList;
		std::vector<VkImageView> sImageViewList;
		std::vector<VkFramebuffer> sFramebufferList;
		
	public:
		RenderTarget(Context *pContext, Display::Window *pWindow);
		RenderTarget(const RenderTarget &sSrc) = delete;
		~RenderTarget();
		
	public:
		RenderTarget &operator=(const RenderTarget &sSrc) = delete;
		
	public:
		std::uint32_t acquireImage(std::uint64_t nTimeout);
		void submitImage(std::uint32_t);
		std::vector<std::uint32_t> getImageList();
	};
}

#endif