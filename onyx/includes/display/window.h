
#ifndef _ONYX_DISPLAY_WINDOW_H

#define _ONYX_DISPLAY_WINDOW_H

#include "onyx/includes/common/platform.h"

#include <cassert>
#include <cstddef>
#include <cstdint>
#include <memory>
#include <string>

namespace onyx {
	class Onyx;
}

namespace onyx::display {
	class Window {
	public:
		enum class Style { ContentOnly, Title, TitleResizable, Standard };
		enum class Visibility { Invisible, VisibleDefault, VisibleMinimized, VisibleMaximized };

		struct Region {
			std::int32_t nMinX;
			std::int32_t nMinY;
			std::int32_t nMaxX;
			std::int32_t nMaxY;
		};

	public:
		Onyx *const		  pInstance;
		const std::string sId;

	protected:
		Region sOuterRegion;
		Region sInnerRegion;

	public:
		Window(Onyx *pInstance, std::string &&sId);
		Window(const Window &sRhs) = delete;
		virtual ~Window() noexcept = default;

	public:
		Window &operator=(const Window &sRhs) = delete;

	public:
		virtual bool create(Style eStyle, Region sRegion, const std::string &sTitle) = 0;
		virtual void destroy()														 = 0;
		virtual void loopEvent()													 = 0;
		virtual bool loopEventAvailable()											 = 0;
		virtual void setTitle(const std::string &sTitle)							 = 0;
		virtual void setVisibility(Visibility eVisibility)							 = 0;

	public:
		const Region &outerRegion() const noexcept
		{
			return this->sOuterRegion;
		}
		const Region &innerRegion() const noexcept
		{
			return this->sInnerRegion;
		}
	};
}	 // namespace onyx::display

#if __ONYX_PLATFORM_APPLE_OSX
#	include "onyx/includes/display/window__OSX.h"
#endif

#if __ONYX_PLATFORM_WINDOWS
#	include "onyx/includes/display/window__WINDOWS.h"
#endif

#endif