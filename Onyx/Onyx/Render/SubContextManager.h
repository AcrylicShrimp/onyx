
/*
	2019.05.25
	Created by AcrylicShrimp.
*/

#ifndef _CLASS_ONYX_RENDER_SUBCONTEXTMANAGER_H

#define _CLASS_ONYX_RENDER_SUBCONTEXTMANAGER_H

#include "../Manager.h"

#include <cassert>

namespace Onyx::Render
{
	class Context;

	class SubContextManager : public Manager
	{
	public:
		Context *const pContext;
		
	public:
		SubContextManager(Context *pContext);
		SubContextManager(const SubContextManager &sSrc) noexcept = default;
		~SubContextManager() noexcept = default;
		
	public:
		SubContextManager &operator=(const SubContextManager &sSrc) = default;
	};
}

#endif