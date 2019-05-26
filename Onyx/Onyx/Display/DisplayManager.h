
/*
	2019.05.05
	Created by AcrylicShrimp.
*/

#ifndef _CLASS_ONYX_DISPLAY_DISPLAYMANAGER_H

#define _CLASS_ONYX_DISPLAY_DISPLAYMANAGER_H

#include "../Manager.h"

#include "Window.h"

#include <memory>
#include <string>
#include <unordered_map>

namespace Onyx::Display
{
	class DisplayManager final : public Manager
	{
	private:
		std::unordered_map<std::string, std::unique_ptr<Window>> sWindowMap;
		
	public:
		DisplayManager(Onyx *pInstance);
		DisplayManager(const DisplayManager &sSrc) = delete;
		~DisplayManager() noexcept = default;
		
	public:
		DisplayManager &operator=(const DisplayManager &sSrc) = delete;
		
	public:
		Window *createWindow(const std::string &sId);
		void destroyWindow(const std::string &sId);
		Window *getWindow(const std::string &sId);
		const Window *getWindow(const std::string &sId) const;
	};
}

#endif