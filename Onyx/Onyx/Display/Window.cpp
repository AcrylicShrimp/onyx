
/*
	2019.05.05
	Created by AcrylicShrimp.
*/

#include "Window.h"

namespace Onyx::Display
{
	Window::Window(Onyx *pInstance, std::string_view sId) :
		pInstance{pInstance},
		sId{sId}
	{
		assert(this->pInstance);
	}
}