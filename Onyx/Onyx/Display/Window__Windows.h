
/*
	2019.05.05
	Created by AcrylicShrimp.
*/

#include "../Platform.h"

#if __ONYX_PLATFORM_WINDOWS

#ifndef _CLASS_ONYX_DISPLAY_WINDOW__WINDOWS_H

#define _CLASS_ONYX_DISPLAY_WINDOW__WINDOWS_H

#define __ONYX_DISPLAY_WINDOW_SUPPORTED 1

#include <cstddef>
#include <cstdint>
#include <functional>
#include <string>
#include <string_view>
#include <tuple>
#include <unordered_map>

#define WIN32_LEAN_AND_MEAN 1
#define NOMINMAX 1
#include <Windows.h>

namespace Onyx::Display
{
	class Window__Windows final : public Window
	{
	private:
		static std::unordered_map<HWND, Window__Windows *> sWindowMap;

	public:
		const std::wstring sClassName;

	private:
		HWND hWindow;

	public:
		Window__Windows(Onyx *pInstance, std::string_view sId);
		Window__Windows(const Window__Windows &sSrc) = delete;
		virtual ~Window__Windows() noexcept;

	public:
		Window__Windows &operator=(const Window__Windows &sSrc) = delete;

	public:
		inline HWND windowHandle() const;
		virtual bool create(Style eStyle, std::wstring_view sTitle) override;
		virtual void destroy() override;
		virtual void loopEvent() override;
		virtual bool loopEventAvailable() override;
		virtual void setTitle(std::wstring_view sTitle) override;
		virtual void setVisibility(Visibility eVisibility) override;

	private:
		std::tuple<bool, LRESULT> handleEvent(UINT nMessage, WPARAM nWParam, LPARAM nLParam);
		static LRESULT CALLBACK handleEvent(HWND hWindow, UINT nMessage, WPARAM nWParam, LPARAM nLParam);
	};

	inline HWND Window__Windows::windowHandle() const
	{
		return this->hWindow;
	}

	using WindowType = Window__Windows;
}

#endif

#endif