
#ifndef _ONYX_CORE_DEVICEMANAGER_H

#define _ONYX_CORE_DEVICEMANAGER_H

#include "onyx/includes/core/perContextManager.h"
#include "onyx/includes/core/vulkan.h"

#include <string>
#include <utility>
#include <vector>

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
	enum class DeviceMemoryType { Local, HostShared };

	class DeviceManager final : public PerContextManager {
	protected:
		VkDevice				 sDevice;
		VkQueue					 sGraphicsQueue;
		VkQueue					 sPresentQueue;
		std::vector<std::string> sExtensionVec;

	public:
		DeviceManager(Context *pContext);
		DeviceManager(const DeviceManager &sRhs) = delete;
		~DeviceManager() noexcept;

	public:
		virtual bool   isCompatible(const DeviceInfo &sDevice) override;
		virtual void   init(const DeviceInfo &sDevice) override;
		virtual void   fin() override;
		VkDeviceMemory allocateImageMemory(DeviceMemoryType eMemType, VkImage sImage) const;

	public:
		void addExtension(std::string sExtension)
		{
			this->sExtensionVec.emplace_back(std::move(sExtension));
		}
		VkDevice vulkanDevice() const
		{
			return this->sDevice;
		}
		VkQueue graphicsQueue() const
		{
			return this->sGraphicsQueue;
		}
		VkQueue presentQueue() const
		{
			return this->sPresentQueue;
		}
	};
}	 // namespace onyx::core

#endif