
#ifndef _ONYX_CORE_SURFACEMANAGER_H

#define _ONYX_CORE_SURFACEMANAGER_H

#include "onyx/includes/core/perContextManager.h"
#include "onyx/includes/core/vulkan.h"

namespace onyx {
	namespace core {
		class Context;
		class DeviceInfo;
	}	 // namespace core
	namespace display {
		class Window;
	}	 // namespace display
}	 // namespace onyx

namespace onyx::core {
	class SurfaceManager : public PerContextManager {
	public:
		display::Window *const pWindow;

	protected:
		VkSurfaceKHR	   sSurface;
		VkSurfaceFormatKHR sSurfaceFormat;

	public:
		SurfaceManager(Context *pContext, display::Window *pWindow);
		SurfaceManager(const SurfaceManager &sRhs) = delete;
		virtual ~SurfaceManager() noexcept;

	public:
		virtual bool isCompatible(const DeviceInfo &sDevice) override;
		virtual void init(const DeviceInfo &sDevice) override;
		virtual void fin() override;

	public:
		VkSurfaceKHR vulkanSurface() const noexcept
		{
			return this->sSurface;
		}
		VkSurfaceFormatKHR vulkanSurfaceFormat() const noexcept
		{
			return this->sSurfaceFormat;
		}
	};
}	 // namespace onyx::core

#endif