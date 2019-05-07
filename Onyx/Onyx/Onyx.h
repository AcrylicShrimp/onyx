
/*
	2019.05.04
	Created by AcrylicShrimp.
*/

#ifndef _CLASS_ONYX_ONYX_H

#define _CLASS_ONYX_ONYX_H

#include "Platform.h"
#include "Version.h"
#include "./Display/DisplayManager.h"
#include "./Render/ContextManager.h"

#include <cstdint>
#include <iterator>
#include <memory>

namespace Onyx
{
	class Onyx final
	{
	public:
		const Version sVersion;
		const Version sApplicationVersion;
		Display::DisplayManager sDisplayMgr;
		Render::ContextManager sContextMgr;
		
	public:
		Onyx(Version sApplicationVersion);
		Onyx(const Onyx &sSrc) = delete;
		~Onyx() noexcept;
		
	public:
		Onyx &operator=(const Onyx &sSrc) = delete;
	};
}

#endif