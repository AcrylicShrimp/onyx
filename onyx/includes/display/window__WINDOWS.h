
#ifndef _ONYX_DISPLAY_WINDOW__WINDOWS_H

#define _ONYX_DISPLAY_WINDOW__WINDOWS_H

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

namespace onyx::display {
	class Window__Windows final : public Window {
	private:
		static std::unordered_map<HWND, Window__Windows *> sWindowMap;

	public:
		const std::string sClassName;

	private:
		HWND hWindow;

	public:
		Window__Windows(Onyx *pInstance, const std::string &sId);
		Window__Windows(const Window__Windows &sRhs) = delete;
		virtual ~Window__Windows() noexcept;

	public:
		Window__Windows &operator=(const Window__Windows &sRhs) = delete;

	public:
		virtual bool create(Style eStyle, Region sRegion, std::string_view sTitle) override;
		virtual void destroy() override;
		virtual void loopEvent() override;
		virtual bool loopEventAvailable() override;
		virtual void setTitle(std::string_view sTitle) override;
		virtual void setVisibility(Visibility eVisibility) override;

	private:
		std::tuple<bool, LRESULT> handleEvent(UINT nMessage, WPARAM nWParam, LPARAM nLParam);
		static LRESULT CALLBACK	  handleEvent(HWND hWindow, UINT nMessage, WPARAM nWParam, LPARAM nLParam);

	public:
		HWND windowHandle() const noexcept
		{
			return this->hWindow;
		}
	};

	using WindowType = Window__Windows;
}	 // namespace onyx::display

#endif