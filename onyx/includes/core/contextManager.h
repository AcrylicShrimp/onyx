
#ifndef _ONYX_CORE_CONTEXTMANAGER_H

#define _ONYX_CORE_CONTEXTMANAGER_H

#include "onyx/includes/common/manager.h"
#include "onyx/includes/core/context.h"
#include "onyx/includes/core/vulkan.h"

#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

namespace onyx::display {
	class Window;
}	 // namespace onyx::display

namespace onyx::core {

	class ContextManager final : public common::Manager {
#if _DEBUG
		VkDebugUtilsMessengerEXT vkDebugMessenger;
#endif
		VkInstance											   vkInstance;
		std::unordered_map<std::string, VkLayerProperties>	   sLayerMap;
		std::unordered_map<std::string, VkExtensionProperties> sExtensionMap;

	public:
		ContextManager(Onyx *pInstance);
		ContextManager(const ContextManager &sRhs) = delete;
		~ContextManager() noexcept;

	public:
		ContextManager &operator=(const ContextManager &sRhs) = delete;

	public:
		std::unique_ptr<Context>									  createContext(display::Window *pWindow);
		std::vector<VkPhysicalDevice>								  fetchPhysicalDevice() const;
		static std::unordered_map<std::string, VkLayerProperties>	  fetchLayer();
		static std::unordered_map<std::string, VkExtensionProperties> fetchExtension();

	public:
		VkInstance vulkanInstance() const noexcept
		{
			return this->vkInstance;
		}
		bool hasLayer(const std::string &sLayerName) const
		{
			return this->sLayerMap.count(sLayerName) != 0;
		}
		bool hasExtension(const std::string &sExtensionName) const
		{
			return this->sExtensionMap.count(sExtensionName) != 0;
		}
	};
}	 // namespace onyx::core

#endif