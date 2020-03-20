
#include "onyx/includes/display/window.h"

#include <utility>

namespace onyx::display {
	Window::Window(Onyx *pInstance, std::string &&sId) : pInstance{pInstance}, sId{std::move(sId)}
	{
		assert(this->pInstance);
	}
}	 // namespace onyx::display