#ifndef _ONYX_CORE_VULKAN_H

#define _ONYX_CORE_VULKAN_H

#include "onyx/includes/common/platform.h"

#if __ONYX_PLATFORM_WINDOWS

#	ifndef WIN32_LEAN_AND_MEAN
#		define WIN32_LEAN_AND_MEAN 1
#	endif

#	ifndef NOMINMAX
#		define NOMINMAX 1
#	endif

#	ifndef VK_USE_PLATFORM_WIN32_KHR
#		define VK_USE_PLATFORM_WIN32_KHR 1
#	endif

#elif __ONYX_PLATFORM_APPLE_OSX

#	ifndef VK_USE_PLATFORM_MACOS_MVK
#		define VK_USE_PLATFORM_MACOS_MVK 1
#	endif

#	ifndef VK_USE_PLATFORM_METAL_EXT
#		define VK_USE_PLATFORM_METAL_EXT 1
#	endif

#elif __ONYX_PLATFORM_APPLE_IOS

#	ifndef VK_USE_PLATFORM_IOS_MVK
#		define VK_USE_PLATFORM_IOS_MVK 1
#	endif

#	ifndef VK_USE_PLATFORM_METAL_EXT
#		define VK_USE_PLATFORM_METAL_EXT 1
#	endif

#elif __ONYX_PLATFORM_ANDROID

#	ifndef VK_USE_PLATFORM_ANDROID_KHR
#		define VK_USE_PLATFORM_ANDROID_KHR 1
#	endif

#endif

#include <vulkan/vulkan.h>

#endif