
/*
	2019.05.05
	Created by AcrylicShrimp.
*/

#include "Onyx.h"

int main()
{
	Onyx::Onyx sInstance{Onyx::Version{"test", 0, 0, 0}};

	auto pContext{sInstance.sContextMgr.createContext()};



	auto pWindow{sInstance.sDisplayMgr.createWindow("main")};
	pWindow->create(Onyx::Display::Window::Style::Standard, L"Onyx test");

	pWindow->setVisibility(Onyx::Display::Window::Visibility::VisibleDefault);
	pWindow->loopEvent();
	pWindow->setVisibility(Onyx::Display::Window::Visibility::Invisible);
	
	pWindow->destroy();
}