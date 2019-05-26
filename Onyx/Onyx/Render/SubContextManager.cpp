
/*
	2019.05.25
	Created by AcrylicShrimp.
*/

#include "SubContextManager.h"

#include "Context.h"
#include "ContextManager.h"

namespace Onyx::Render
{
	SubContextManager::SubContextManager(Context *pContext) :
		Manager{pContext->pContextManager->pInstance},
		pContext{pContext}
	{
		assert(this->pContext);
	}
}