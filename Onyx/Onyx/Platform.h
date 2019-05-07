
/*
	2019.05.05
	Created by AcrylicShrimp.
*/

#ifndef _ONYX_PLATFORM_H

#define _ONYX_PLATFORM_H

#if _WIN32

#define __ONYX_PLATFORM_WINDOWS 1

#ifdef _WIN64

#define __ONYX_PLATFORM_WINDOWS64 1

#else

#define __ONYX_PLATFORM_WINDOWS32 1

#endif

#elif __APPLE__

#define __ONYX_PLATFORM_APPLE 1

#include "TargetConditionals.h"

#if TARGET_OS_OSX

#define __ONYX_PLATFORM_APPLE_OSX 1

#elif TARGET_OS_IOS

#define __ONYX_PLATFORM_APPLE_IOS 1

#if TARGET_OS_SIMULATOR

#define __ONYX_PLATFORM_APPLE_IOS_SIMULATOR 1

#endif

#endif

#elif __ANDROID__

#define __ONYX_PLATFORM_ANDROID 1

#elif __linux__

#define __ONYX_PLATFORM_LINUX 1

#elif __unix__

#define __ONYX_PLATFORM_UNIX 1

#endif

#endif