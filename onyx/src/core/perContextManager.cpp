
#include "onyx/includes/core/perContextManager.h"

#include "onyx/includes/core/context.h"

namespace onyx::core {
	PerContextManager::PerContextManager(Context *pContext) : pContext{pContext}
	{
		pContext->registerPerContextMgr(this);
	}

	bool PerContextManager::isCompatible(const DeviceInfo &sDevice)
	{
		return true;
	}
}	 // namespace onyx::core