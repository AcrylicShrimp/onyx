
#ifndef _ONYX_DISPLAY_WINDOW__OSX_H

#define _ONYX_DISPLAY_WINDOW__OSX_H

#define __ONYX_DISPLAY_WINDOW_SUPPORTED 1

#include <string>

namespace onyx::display {
	class Window__OSX final : public Window {
	private:
		const void *pWindow;

	public:
		Window__OSX(Onyx *pInstance, std::string &&sId);
		Window__OSX(const Window__OSX &sRhs) = delete;
		virtual ~Window__OSX() noexcept;

	public:
		virtual bool create(Style eStyle, Region sRegion, const std::string &sTitle) override;
		virtual void destroy() override;
		virtual void loopEvent() override;
		virtual bool loopEventAvailable() override;
		virtual void setTitle(const std::string &sTitle) override;
		virtual void setVisibility(Visibility eVisibility) override;
		const void * getMetalView() const;

	public:
		const void *window() const noexcept
		{
			return this->pWindow;
		}
	};

	using WindowType = Window__OSX;
}	 // namespace onyx::display

#endif