
/*
	2019.05.05
	Created by AcrylicShrimp.
*/

#include "DisplayManager.h"

namespace Onyx::Display
{
	DisplayManager::DisplayManager(Onyx *pInstance) :
		Manager{pInstance}
	{
		//Empty.
	}
	
	Window *DisplayManager::createWindow(const std::string &sId)
	{
		auto iIndex{this->sWindowMap.find(sId)};

		if (iIndex != this->sWindowMap.cend())
			return iIndex->second.get();

		return this->sWindowMap.emplace(sId, std::unique_ptr<Window>{new WindowType{this->pInstance, sId}}).first->second.get();
	}

	void DisplayManager::destroyWindow(const std::string &sId)
	{
		auto pWindow{this->getWindow(sId)};

		if (!pWindow)
			return;

		//this->pInstance->sRenderManager.destroyContext(pWindow);
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
}