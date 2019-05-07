
/*
	2019.05.05
	Created by AcrylicShrimp.
*/

#include "../Platform.h"

#if __ONYX_PLATFORM_WINDOWS

#include "Window.h"
#include "Window__Windows.h"

#include "../Onyx.h"

namespace Onyx::Display
{
	std::unordered_map<HWND, Window__Windows *> Window__Windows::sWindowMap;

	Window__Windows::Window__Windows(Onyx *pInstance, std::string_view sId) :
		Window(pInstance, sId),
		sClassName{std::wstring{pInstance->sApplicationVersion.sName.cbegin(), pInstance->sApplicationVersion.sName.cend()} + L"::" + std::wstring{sId.cbegin(), sId.cend()}},
		hWindow{nullptr}
	{
		//Empty.
	}
	
	Window__Windows::~Window__Windows() noexcept
	{
		this->destroy();
	}

	bool Window__Windows::create(Style eStyle, std::wstring_view sTitle)
	{
		if (this->hWindow)
			return false;

		DWORD nStyle;
		DWORD nExStyle;

		switch (eStyle)
		{
			case Style::ContentOnly:
			nStyle = WS_POPUP;
			nExStyle = 0;
			break;

			case Style::Title:
			nStyle = WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU;
			nExStyle = WS_EX_OVERLAPPEDWINDOW;
			break;

			case Style::TitleResizable:
			nStyle = WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_THICKFRAME;
			nExStyle = WS_EX_OVERLAPPEDWINDOW;
			break;

			case Style::Standard:
			nStyle = WS_OVERLAPPEDWINDOW;
			nExStyle = WS_EX_OVERLAPPEDWINDOW;
			break;

			default:
			return false;
		}

		/*
			FIXME : Generate class name more nicely here.
		*/
		WNDCLASSW sClass
		{
			CS_OWNDC,
			&Window__Windows::handleEvent,
			0,
			0,
			::GetModuleHandleW(nullptr),
			::LoadIconW(nullptr, reinterpret_cast<LPCWSTR>(IDI_APPLICATION)),
			::LoadCursorW(nullptr, reinterpret_cast<LPCWSTR>(IDC_ARROW)),
			nullptr,
			nullptr,
			this->sClassName.c_str()
		};

		if (!::RegisterClassW(&sClass))
			return false;

		this->hWindow = ::CreateWindowExW(
			nExStyle,
			this->sClassName.c_str(),
			sTitle.data(),
			nStyle,
			0,
			0,
			CW_USEDEFAULT,
			CW_USEDEFAULT,
			nullptr,
			nullptr,
			::GetModuleHandleW(nullptr),
			nullptr
		);

		if (!this->hWindow)
		{
			this->destroy();
			return false;
		}

		Window__Windows::sWindowMap.emplace(this->hWindow, this);

		return true;
	}

	void Window__Windows::destroy()
	{
		::UnregisterClassW(this->sClassName.c_str(), ::GetModuleHandleW(nullptr));
		::DestroyWindow(this->hWindow);

		Window__Windows::sWindowMap.erase(this->hWindow);

		this->hWindow = nullptr;
	}

	void Window__Windows::loopEvent()
	{
		if (!this->hWindow)
			return;

		MSG sMessage;

		while (::GetMessageW(&sMessage, nullptr, 0, 0))
		{
			::TranslateMessage(&sMessage);
			::DispatchMessageW(&sMessage);
		}
	}

	bool Window__Windows::loopEventAvailable()
	{
		if (!this->hWindow)
			return false;

		MSG sMessage;

		while (::PeekMessageW(&sMessage, nullptr, 0, 0, PM_REMOVE))
		{
			if (sMessage.message == WM_QUIT)
				return false;

			::TranslateMessage(&sMessage);
			::DispatchMessageW(&sMessage);
		}

		return true;
	}

	void Window__Windows::setTitle(std::wstring_view sTitle)
	{
		::SetWindowTextW(this->hWindow, sTitle.data());
	}

	void Window__Windows::setVisibility(Visibility eVisibility)
	{
		int nVisibility;

		switch (eVisibility)
		{
			case Visibility::Invisible:
			nVisibility = SW_HIDE;
			break;

			case Visibility::VisibleDefault:
			nVisibility = SW_SHOWDEFAULT;
			break;

			case Visibility::VisibleMinimized:
			nVisibility = SW_SHOWMINIMIZED;
			break;

			case Visibility::VisibleMaximized:
			nVisibility = SW_SHOWMAXIMIZED;
			break;

			default:
			return;
		}

		ShowWindow(this->hWindow, nVisibility);
	}

	std::tuple<bool, LRESULT> Window__Windows::handleEvent(UINT nMessage, WPARAM nWParam, LPARAM nLParam)
	{
		switch (nMessage)
		{
			case WM_ERASEBKGND:
			return std::make_tuple(true, 1);
			case WM_PAINT:
			{
				::ValidateRect(this->hWindow, nullptr);
			}
			return std::make_tuple(true, 0);
			case WM_MOVE:
			case WM_MOVING:
			case WM_SIZE:
			case WM_SIZING:
			{
				RECT sWindowRect;
				RECT sClientRect;

				::GetWindowRect(hWindow, &sWindowRect);
				::GetClientRect(hWindow, &sClientRect);

				this->sOuterRegion.nMinX = sWindowRect.left;
				this->sOuterRegion.nMinY = sWindowRect.top;
				this->sOuterRegion.nMaxX = sWindowRect.right;
				this->sOuterRegion.nMaxY = sWindowRect.bottom;

				this->sInnerRegion.nMinX = sClientRect.left;
				this->sInnerRegion.nMinY = sClientRect.top;
				this->sInnerRegion.nMaxX = sClientRect.right;
				this->sInnerRegion.nMaxY = sClientRect.bottom;
			}
			return std::make_tuple(true, 0);
			case WM_CLOSE:
			{
				::PostQuitMessage(0);
			}
			return std::make_tuple(true, 0);
		}

		return std::make_tuple(false, 0);
	}

	LRESULT CALLBACK Window__Windows::handleEvent(HWND hWindow, UINT nMessage, WPARAM nWParam, LPARAM nLParam)
	{
		auto iIndex{Window__Windows::sWindowMap.find(hWindow)};

		if (iIndex == Window__Windows::sWindowMap.cend())
			return ::DefWindowProcW(hWindow, nMessage, nWParam, nLParam);

		auto sResult{iIndex->second->handleEvent(nMessage, nWParam, nLParam)};

		return std::get<0>(sResult) ? std::get<1>(sResult) : ::DefWindowProcW(hWindow, nMessage, nWParam, nLParam);
	}
}

#endif