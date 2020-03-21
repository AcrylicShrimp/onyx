
#include "onyx/includes/common/platform.h"

#if __ONYX_PLATFORM_APPLE_OSX

#	include "onyx/includes/onyx.h"
#	include "onyx/includes/display/window.h"
#	include "onyx/includes/display/window__OSX.h"
#	include "onyx/includes/display/window__OSX__backend.h"

#	include <utility>

namespace onyx::display {
	Window__OSX::Window__OSX(Onyx *pInstance, std::string &&sId) : Window{pInstance, std::move(sId)}, pWindow{nullptr}
	{
		// Empty.
	}

	Window__OSX::~Window__OSX() noexcept
	{
		this->destroy();
	}

	bool Window__OSX::create(Style eStyle, Region sRegion, const std::string &sTitle)
	{
		if (this->pWindow) return false;

		::Style eOSXStyle;

		switch (eStyle) {
		case Style::ContentOnly: eOSXStyle = ::Style::ContentOnly; break;
		case Style::Title: eOSXStyle = ::Style::Title; break;
		case Style::TitleResizable: eOSXStyle = ::Style::TitleResizable; break;
		case Style::Standard: eOSXStyle = ::Style::Standard; break;
		default: return false;
		}

		this->pWindow
			= ::createWindow(eOSXStyle, sRegion.nMinX, sRegion.nMinY, sRegion.nMaxX, sRegion.nMaxY, sTitle.c_str());

		return true;
	}

	void Window__OSX::destroy()
	{
		if (!this->pWindow) return;

		::destroyWindow(this->pWindow);

		this->pWindow = nullptr;
	}

	void Window__OSX::loopEvent()
	{
		::loopEvent();
	}

	bool Window__OSX::loopEventAvailable()
	{
		::loopEventAvailable(this->pWindow);
		return true;
	}

	void Window__OSX::setTitle(const std::string &sTitle)
	{
		::setTitle(this->pWindow, sTitle.c_str());
	}

	void Window__OSX::setVisibility(Visibility eVisibility)
	{
		::Visibility eOSXVisibility;

		switch (eVisibility) {
		case Visibility::Invisible: eOSXVisibility = ::Visibility::Invisible; break;
		case Visibility::VisibleDefault: eOSXVisibility = ::Visibility::VisibleDefault; break;
		case Visibility::VisibleMinimized: eOSXVisibility = ::Visibility::VisibleMinimized; break;
		case Visibility::VisibleMaximized: eOSXVisibility = ::Visibility::VisibleMaximized; break;
		default: return;
		}

		::setVisibility(this->pWindow, eOSXVisibility);
	}

	const void *Window__OSX::getMetalView() const
	{
		return ::getMetalView(this->pWindow);
	}
}	 // namespace onyx::display

#endif