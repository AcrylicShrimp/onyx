
#ifndef _ONYX_ONYX_H

#define _ONYX_ONYX_H

#include "onyx/includes/common/version.h"
#include "onyx/includes/core/contextManager.h"
#include "onyx/includes/display/displayManager.h"

#include <cstdint>
#include <iterator>
#include <memory>

namespace onyx {
	class Onyx final {
	public:
		const common::Version sVersion;
		const common::Version sApplicationVersion;

	private:
		std::unique_ptr<core::ContextManager>	 pContextMgr;
		std::unique_ptr<display::DisplayManager> pDisplayMgr;

	public:
		Onyx(common::Version &&sApplicationVersion);
		~Onyx() noexcept;

	public:
		core::ContextManager &contextMgr()
		{
			return *this->pContextMgr.get();
		}
		const core::ContextManager &contextMgr() const
		{
			return *this->pContextMgr.get();
		}
		display::DisplayManager &displayMgr()
		{
			return *this->pDisplayMgr.get();
		}
		const display::DisplayManager &displayMgr() const
		{
			return *this->pDisplayMgr.get();
		}
	};
}	 // namespace onyx

#endif