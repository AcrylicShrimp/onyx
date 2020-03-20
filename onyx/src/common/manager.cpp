
#include "onyx/includes/common/manager.h"

#include <cassert>

namespace onyx::common {
	Manager::Manager(Onyx *pInstance) : pInstance{pInstance}
	{
		assert(this->pInstance);
	}
}	 // namespace onyx