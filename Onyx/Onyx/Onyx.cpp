
/*
	2019.05.04
	Created by AcrylicShrimp.
*/

#include "Onyx.h"

namespace Onyx
{
	Onyx::Onyx(Version sApplicationVersion) :
		sVersion{"Onyx alpha", 0, 0, 1},
		sApplicationVersion{sApplicationVersion}
	{
		this->pDisplayMgr = std::make_unique<Display::DisplayManager>(this);
		this->pContextMgr = std::make_unique<Render::ContextManager>(this);
	}

	Onyx::~Onyx()
	{
		this->pContextMgr = nullptr;
		this->pDisplayMgr = nullptr;
	}
}