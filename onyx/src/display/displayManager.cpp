
#include "onyx/includes/display/displayManager.h"

#include <stdexcept>

namespace onyx::display {
	DisplayManager::DisplayManager(Onyx *pInstance) : Manager{pInstance}
	{
		// Empty.
	}

	Window *DisplayManager::createWindow(const std::string &sId)
	{
		auto iIndex{this->sWindowMap.find(sId)};

		if (iIndex != this->sWindowMap.cend()) return iIndex->second.get();

#if __ONYX_DISPLAY_WINDOW_SUPPORTED
		return this->sWindowMap.emplace(sId, std::unique_ptr<Window>{new WindowType{this->pInstance, std::string{sId}}})
			.first->second.get();
#else
		throw std::runtime_error{"window is not supported on this platform"};
#endif
	}

	void DisplayManager::destroyWindow(const std::string &sId)
	{
		auto pWindow{this->getWindow(sId)};

		if (!pWindow) return;

		// this->pInstance->sRenderManager.destroyContext(pWindow);
		this->sWindowMap.erase(sId);
	}

	Window *DisplayManager::getWindow(const std::string &sId)
	{
		auto iIndex{this->sWindowMap.find(sId)};

		return iIndex == this->sWindowMap.cend() ? nullptr : iIndex->second.get();
	}

	const Window *DisplayManager::getWindow(const std::string &sId) const
	{
		auto iIndex{this->sWindowMap.find(sId)};

		return iIndex == this->sWindowMap.cend() ? nullptr : iIndex->second.get();
	}
}	 // namespace onyx::display