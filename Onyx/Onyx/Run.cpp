
/*
	2019.05.05
	Created by AcrylicShrimp.
*/

#include "Onyx.h"

int main()
{
	Onyx::Onyx sInstance{Onyx::Version{"test", 0, 0, 0}};

	auto pWindow{sInstance.sDisplayMgr.createWindow("main")};
	pWindow->create(Onyx::Display::Window::Style::Standard, L"Onyx test");

	auto pContext{sInstance.sContextMgr.createContext(pWindow)};

	pWindow->setVisibility(Onyx::Display::Window::Visibility::VisibleDefault);
	pWindow->loopEvent();
	pWindow->setVisibility(Onyx::Display::Window::Visibility::Invisible);

	pContext = nullptr;
	
	pWindow->destroy();
}