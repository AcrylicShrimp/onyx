
/*
	2019.05.05
	Created by AcrylicShrimp.
*/

#include "Manager.h"

namespace Onyx
{
	Manager::Manager(Onyx *pInstance) :
		pInstance{pInstance}
	{
		assert(this->pInstance);
	}
}