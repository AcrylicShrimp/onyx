
/*
	2019.05.05
	Created by AcrylicShrimp.
*/

#ifndef _CLASS_ONYX_DISPLAY_WINDOW_H

#define _CLASS_ONYX_DISPLAY_WINDOW_H

#include <cassert>
#include <cstddef>
#include <cstdint>
#include <memory>
#include <string>
#include <string_view>

namespace Onyx
{
	class Onyx;
}

namespace Onyx::Display
{
	class Window
	{
	public:
		enum class Style
		{
			ContentOnly,
			Title,
			TitleResizable,
			Standard
		};

		enum class Visibility
		{
			Invisible,
			VisibleDefault,
			VisibleMinimized,
			VisibleMaximized
		};

		struct Region
		{
			std::int32_t nMinX;
			std::int32_t nMinY;
			std::int32_t nMaxX;
			std::int32_t nMaxY;
		};

	public:
		Onyx *const pInstance;
		const std::string sId;

	protected:
		Region sOuterRegion;
		Region sInnerRegion;

	public:
		Window(Onyx *pInstance, std::string_view sId);
		Window(const Window &sSrc) = delete;
		virtual ~Window() noexcept = default;

	public:
		Window &operator=(const Window &sSrc) = delete;

	public:
		inline const Region &outerRegion() const noexcept;
		inline const Region &innerRegion() const noexcept;
		virtual bool create(Style eStyle, std::wstring_view sTitle) = 0;
		virtual void destroy() = 0;
		virtual void loopEvent() = 0;
		virtual bool loopEventAvailable() = 0;
		virtual void setTitle(std::wstring_view sTitle) = 0;
		virtual void setVisibility(Visibility eVisibility) = 0;
	};

	inline const Window::Region &Window::outerRegion() const noexcept
	{
		return this->sOuterRegion;
	}

	inline const Window::Region &Window::innerRegion() const noexcept
	{
		return this->sInnerRegion;
	}
}

#include "Window__Windows.h"

#if !__ONYX_DISPLAY_WINDOW_SUPPORTED

static_assert(false, "window not supported");

#endif

#endif