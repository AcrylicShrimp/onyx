
#ifndef _ONYX_DISPLAY_DISPLAYMANAGER_H

#define _ONYX_DISPLAY_DISPLAYMANAGER_H

#include "onyx/includes/common/manager.h"
#include "onyx/includes/display/window.h"

#include <memory>
#include <string>
#include <unordered_map>

namespace onyx::display {
	class DisplayManager final : public common::Manager {
	private:
		std::unordered_map<std::string, std::unique_ptr<Window>> sWindowMap;

	public:
		DisplayManager(Onyx *pInstance);
		DisplayManager(const DisplayManager &sRhs) = delete;
		~DisplayManager() noexcept				   = default;

	public:
		DisplayManager &operator=(const DisplayManager &sRhs) = delete;

	public:
		Window *	  createWindow(const std::string &sId);
		void		  destroyWindow(const std::string &sId);
		Window *	  getWindow(const std::string &sId);
		const Window *getWindow(const std::string &sId) const;
	};
}	 // namespace onyx::display

#endif