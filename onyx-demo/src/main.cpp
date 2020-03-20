
#include "onyx/includes/common/version.h"
#include "onyx/includes/onyx.h"

#include <iostream>

int main()
{
	onyx::Onyx sInstance{onyx::common::Version{"test", 0, 0, 1}};

	std::cout << "Engine initialized." << std::endl;
	std::cout << "Engine version: " << sInstance.sVersion.sName << " v" << sInstance.sVersion.nMajor << "."
			  << sInstance.sVersion.nMinor << "." << sInstance.sVersion.nPatch << std::endl;

	auto pWindow{sInstance.displayMgr().createWindow("main")};

	pWindow->create(onyx::display::Window::Style::Standard, onyx::display::Window::Region{0, 0, 200, 200}, "Test");

	auto sContext{sInstance.contextMgr().createContext(pWindow)};

	pWindow->setVisibility(onyx::display::Window::Visibility::VisibleDefault);

	while (pWindow->loopEventAvailable()) {}

	return 0;
}