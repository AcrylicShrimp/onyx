
#include "onyx/includes/onyx.h"

#include <utility>

namespace onyx {
	Onyx::Onyx(common::Version &&sApplicationVersion) :
		sVersion{"onyx alpha", 0, 0, 1},
		sApplicationVersion{std::move(sApplicationVersion)}
	{
		this->pContextMgr = std::make_unique<core::ContextManager>(this);
		this->pDisplayMgr = std::make_unique<display::DisplayManager>(this);
	}

	Onyx::~Onyx() noexcept
	{
		this->pContextMgr = nullptr;
		this->pDisplayMgr = nullptr;
	}
}	 // namespace onyx