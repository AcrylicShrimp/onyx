
#ifndef _ONYX_CORE_CONTEXT_H

#define _ONYX_CORE_CONTEXT_H

#include "onyx/includes/core/deviceManager.h"
#include "onyx/includes/core/renderingManager.h"
#include "onyx/includes/core/surfaceManager.h"
#include "onyx/includes/core/swapchainManager.h"
#include "onyx/includes/core/synchronizationManager.h"

#include <memory>
#include <vector>

namespace onyx {
	namespace core {
		class ContextManager;
		class PerContextManager;
	}	 // namespace core

	namespace display {
		class Window;
	}	 // namespace display
}	 // namespace onyx

namespace onyx::core {
	class Context final {
	public:
		ContextManager *const pContextMgr;

	private:
		std::vector<PerContextManager *> sPerContextMgrVec;
		std::unique_ptr<DeviceInfo>		 pDeviceInfo;
		SurfaceManager					 sSurfaceMgr;
		DeviceManager					 sDeviceMgr;
		SwapchainManager				 sSwapchainMgr;
		SynchronizationManager			 sSyncMgr;
		RenderingManager				 sRenderingMgr;

	public:
		Context(ContextManager *pContextMgr, display::Window *pWindow);
		Context(const Context &sRhs) = delete;
		~Context() noexcept;

	public:
		Context &operator=(const Context &sRhs) = delete;

	private:
		bool			  isCompatible(const DeviceInfo &sDevice) const;
		const DeviceInfo *selectCompatible(const std::vector<DeviceInfo> &sDeviceVec) const;

	public:
		void registerPerContextMgr(PerContextManager *pPerContextMgr)
		{
			this->sPerContextMgrVec.emplace_back(pPerContextMgr);
		}
		const DeviceInfo *deviceInfo() const
		{
			return this->pDeviceInfo.get();
		}
		SurfaceManager &surfaceMgr() noexcept
		{
			return this->sSurfaceMgr;
		}
		const SurfaceManager &surfaceMgr() const noexcept
		{
			return this->sSurfaceMgr;
		}
		DeviceManager &deviceMgr() noexcept
		{
			return this->sDeviceMgr;
		}
		const DeviceManager &deviceMgr() const noexcept
		{
			return this->sDeviceMgr;
		}
		SwapchainManager &swapchainMgr() noexcept
		{
			return this->sSwapchainMgr;
		}
		const SwapchainManager &swapchainMgr() const noexcept
		{
			return this->sSwapchainMgr;
		}
		SynchronizationManager &syncMgr() noexcept
		{
			return this->sSyncMgr;
		}
		const SynchronizationManager &syncMgr() const noexcept
		{
			return this->sSyncMgr;
		}
		RenderingManager &renderingMgr() noexcept
		{
			return this->sRenderingMgr;
		}
		const RenderingManager &renderingMgr() const noexcept
		{
			return this->sRenderingMgr;
		}
	};
}	 // namespace onyx::core

#endif