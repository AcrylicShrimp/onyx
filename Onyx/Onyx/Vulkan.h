
/*
	2019.05.06
	Created by AcrylicShrimp.
*/

#ifndef _ONYX_VULKAN_H

#define _ONYX_VULKAN_H

#include "./Platform.h"

#if __ONYX_PLATFORM_WINDOWS

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN 1
#endif

#ifndef VK_USE_PLATFORM_WIN32_KHR
#define VK_USE_PLATFORM_WIN32_KHR 1
#endif

#elif __ONYX_PLATFORM_APPLE_OSX

#ifndef VK_USE_PLATFORM_MACOS_MVK
#define VK_USE_PLATFORM_MACOS_MVK 1
#endif

#elif __ONYX_PLATFORM_APPLE_IOS

#ifndef VK_USE_PLATFORM_IOS_MVK
#define VK_USE_PLATFORM_IOS_MVK 1
#endif

#elif __ONYX_PLATFORM_ANDROID

#ifndef VK_USE_PLATFORM_ANDROID_KHR
#define VK_USE_PLATFORM_ANDROID_KHR 1
#endif

#endif

#include <vulkan/vulkan.h>

#endif