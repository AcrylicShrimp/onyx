
/*
	2019.05.04
	Created by AcrylicShrimp.
*/

#include "Onyx.h"

namespace Onyx
{
	Onyx::Onyx(Version sApplicationVersion) :
		sVersion{"Onyx alpha", 0, 0, 1},
		sApplicationVersion{sApplicationVersion},
		sDisplayMgr{this},
		sContextMgr{this}
	{
		this->sDisplayMgr.initialize();
		this->sContextMgr.initialize();
	}

	Onyx::~Onyx()
	{
		this->sContextMgr.finalize();
		this->sDisplayMgr.finalize();
	}
}