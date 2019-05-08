
/*
	2019.05.04
	Created by AcrylicShrimp.
*/

#ifndef _CLASS_ONYX_RENDER_CONTEXT_H

#define _CLASS_ONYX_RENDER_CONTEXT_H

#include "../Vulkan.h"
#include "../Display/Window.h"
#include "./Device.h"
#include "./Surface.h"
#include "./Swapchain.h"

#include <algorithm>
#include <cassert>
#include <cstdint>
#include <cstring>
#include <iterator>
#include <stdexcept>
#include <string>
#include <string_view>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

namespace Onyx::Render
{
	class ContextManager;

	class Context final
	{
	public:
		ContextManager *const pContextManager;
		Display::Window *const pWindow;

	private:
		Device sDevice;
		Surface sSurface;
		Swapchain sSwapchain;
		VkQueue vkGraphicsQueue;
		VkQueue vkPresentQueue;
		std::uint32_t nGraphicsFamily;
		std::uint32_t nPresentFamily;

	public:
		Context(ContextManager *pContextManager, Display::Window *pWindow);
		Context(const Context &sSrc) = delete;
		~Context() noexcept;

	public:
		Context &operator=(const Context &sSrc) = delete;

	public:

	};
}

#endif