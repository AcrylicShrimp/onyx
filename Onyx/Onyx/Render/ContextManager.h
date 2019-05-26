
/*
	2019.05.05
	Created by AcrylicShrimp.
*/

#ifndef _CLASS_ONYX_RENDER_CONTEXTMANAGER_H

#define _CLASS_ONYX_RENDER_CONTEXTMANAGER_H

#include "../Manager.h"
#include "../Platform.h"
#include "../Version.h"
#include "../Vulkan.h"
#include "../Display/Window.h"
#include "./Context.h"

#include <algorithm>
#include <cstdint>
#include <cstring>
#include <iterator>
#include <memory>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

namespace Onyx::Render
{
	class ContextManager final : public Manager
	{
	private:
		VkInstance vkInstance;
#if _DEBUG
		VkDebugUtilsMessengerEXT vkDebugMessenger;
#endif
		std::unordered_map<std::string, VkLayerProperties> sLayerMap;
		std::unordered_map<std::string, VkExtensionProperties> sExtensionMap;
		
	public:
		ContextManager(Onyx *pInstance);
		ContextManager(const ContextManager &sSrc) = delete;
		~ContextManager() noexcept;
		
	public:
		ContextManager &operator=(const ContextManager &sSrc) = delete;
		
	public:
		inline VkInstance vulkanInstance() const;
		inline bool hasLayer(const std::string &sLayerName) const;
		inline bool hasExtension(const std::string &sExtensionName) const;
		std::unique_ptr<Context> createContext(Display::Window *pWindow);
		std::vector<VkPhysicalDevice> fetchPhysicalDevice() const;
		static std::unordered_map<std::string, VkLayerProperties> fetchLayer();
		static std::unordered_map<std::string, VkExtensionProperties> fetchExtension();

	private:
#if _DEBUG
		static VKAPI_ATTR VkBool32 VKAPI_CALL __callbackDebug(
			VkDebugUtilsMessageSeverityFlagBitsEXT vkSeverityFlag,
			VkDebugUtilsMessageTypeFlagsEXT vkTypeFlag,
			const VkDebugUtilsMessengerCallbackDataEXT *pCallbackData,
			void *pUserData);
#endif
	};

	inline VkInstance ContextManager::vulkanInstance() const
	{
		return this->vkInstance;
	}

	inline bool ContextManager::hasLayer(const std::string &sLayerName) const
	{
		return this->sLayerMap.count(sLayerName) != 0;
	}

	inline bool ContextManager::hasExtension(const std::string &sExtensionName) const
	{
		return this->sExtensionMap.count(sExtensionName) != 0;
	}
}

#endif