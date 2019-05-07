
/*
	2019.05.05
	Created by AcrylicShrimp.
*/

#include "ContextManager.h"

#include "../Onyx.h"
#include "./Context.h"

#if _DEBUG
#include <iostream>
#endif

namespace Onyx::Render
{
	ContextManager::ContextManager(Onyx *pInstance) :
		Manager{pInstance},
		sLayerMap{ContextManager::fetchLayer()},
		sExtensionMap{ContextManager::fetchExtension()}
	{
		//Empty.
	}

	void ContextManager::initialize()
	{
		const char *const vLayerNameArray[]
		{
#if _DEBUG
			"VK_LAYER_KHRONOS_validation",
			"VK_LAYER_LUNARG_monitor"
#endif
		};
		const char *const vExtensionNameArray[]
		{
			/*
				TODO : Remove surface extension dependencies if there's no need to display image onto window.
			*/
			VK_KHR_SURFACE_EXTENSION_NAME,
#if __ONYX_PLATFORM_WINDOWS
			VK_KHR_WIN32_SURFACE_EXTENSION_NAME,
#endif
#if _DEBUG
			VK_EXT_DEBUG_UTILS_EXTENSION_NAME
#endif
		};

		auto nLayerNameCount{static_cast<std::uint32_t>(std::size(vLayerNameArray))};
		auto nExtensionNameCount{static_cast<std::uint32_t>(std::size(vExtensionNameArray))};

		for (std::uint32_t nIndex{0}; nIndex < nLayerNameCount; ++nIndex)
			if (!this->hasLayer(std::string{vLayerNameArray[nIndex]}))
				throw std::runtime_error{"unsupported layer found : " + std::string{vLayerNameArray[nIndex]}};

		for (std::uint32_t nIndex{0}; nIndex < nExtensionNameCount; ++nIndex)
			if (!this->hasExtension(std::string{vExtensionNameArray[nIndex]}))
				throw std::runtime_error{"unsupported extension found : " + std::string{vExtensionNameArray[nIndex]}};

		VkApplicationInfo vkApplicationInfo
		{
			VkStructureType::VK_STRUCTURE_TYPE_APPLICATION_INFO,
			nullptr,
			this->pInstance->sApplicationVersion.sName.data(),
			VK_MAKE_VERSION(this->pInstance->sApplicationVersion.nMajor, this->pInstance->sApplicationVersion.nMinor, this->pInstance->sApplicationVersion.nPatch),
			this->pInstance->sVersion.sName.data(),
			VK_MAKE_VERSION(this->pInstance->sVersion.nMajor, this->pInstance->sVersion.nMinor, this->pInstance->sVersion.nPatch),
			VK_API_VERSION_1_1
		};
		VkInstanceCreateInfo vkInstanceCreateInfo
		{
			VkStructureType::VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO,
			nullptr,
			0,
			&vkApplicationInfo,
			nLayerNameCount,
			vLayerNameArray,
			nExtensionNameCount,
			vExtensionNameArray
		};

		if (vkCreateInstance(&vkInstanceCreateInfo, nullptr, &this->vkInstance) != VkResult::VK_SUCCESS)
			throw std::runtime_error{"unable to create vulkan instance"};

#if _DEBUG
		VkDebugUtilsMessengerCreateInfoEXT vkDebugMessengerCreateInfo
		{
			VkStructureType::VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT,
			nullptr,
			0,
			VkDebugUtilsMessageSeverityFlagBitsEXT::VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT |
			VkDebugUtilsMessageSeverityFlagBitsEXT::VK_DEBUG_UTILS_MESSAGE_SEVERITY_INFO_BIT_EXT |
			VkDebugUtilsMessageSeverityFlagBitsEXT::VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT |
			VkDebugUtilsMessageSeverityFlagBitsEXT::VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT,
			VkDebugUtilsMessageTypeFlagBitsEXT::VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT |
			VkDebugUtilsMessageTypeFlagBitsEXT::VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT |
			VkDebugUtilsMessageTypeFlagBitsEXT::VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT,
			&ContextManager::__callbackDebug,
			nullptr
		};

		auto vkCreateDebugUtilsMessengerEXT{reinterpret_cast<PFN_vkCreateDebugUtilsMessengerEXT>(vkGetInstanceProcAddr(this->vkInstance, "vkCreateDebugUtilsMessengerEXT"))};

		if (!vkCreateDebugUtilsMessengerEXT)
			throw std::runtime_error{"unable to load vkCreateDebugUtilsMessengerEXT"};

		if (vkCreateDebugUtilsMessengerEXT(this->vkInstance, &vkDebugMessengerCreateInfo, nullptr, &this->vkDebugMessenger) != VkResult::VK_SUCCESS)
			throw std::runtime_error{"unable to create vulkan debug messenger instance"};
#endif
	}

	void ContextManager::finalize()
	{
#if _DEBUG
		auto vkDestroyDebugUtilsMessengerEXT{reinterpret_cast<PFN_vkDestroyDebugUtilsMessengerEXT>(vkGetInstanceProcAddr(this->vkInstance, "vkDestroyDebugUtilsMessengerEXT"))};

		if (vkDestroyDebugUtilsMessengerEXT)
			vkDestroyDebugUtilsMessengerEXT(this->vkInstance, this->vkDebugMessenger, nullptr);
#endif

		vkDestroyInstance(this->vkInstance, nullptr);
	}

	std::unique_ptr<Context> ContextManager::createContext(Display::Window *pWindow)
	{
		return std::make_unique<Context>(this, pWindow);
	}

	std::vector<VkPhysicalDevice> ContextManager::fetchPhysicalDevice() const
	{
		std::uint32_t nDeviceCount;

		if (vkEnumeratePhysicalDevices(this->vkInstance, &nDeviceCount, nullptr) != VkResult::VK_SUCCESS)
			throw std::runtime_error{"unable to query physical device of vulkan instance"};

		std::vector<VkPhysicalDevice> sPhysicalDeviceList(nDeviceCount);

		if (vkEnumeratePhysicalDevices(this->vkInstance, &nDeviceCount, sPhysicalDeviceList.data()) != VkResult::VK_SUCCESS)
			throw std::runtime_error{"unable to query physical device of vulkan instance"};

		return sPhysicalDeviceList;
	}

	std::unordered_map<std::string, VkLayerProperties> ContextManager::fetchLayer()
	{
		std::uint32_t nLayerCount;

		if (vkEnumerateInstanceLayerProperties(&nLayerCount, nullptr) != VkResult::VK_SUCCESS)
			throw std::runtime_error{"unable to query supported layer of vulkan"};

		std::vector<VkLayerProperties> sLayerList(nLayerCount);

		if (vkEnumerateInstanceLayerProperties(&nLayerCount, sLayerList.data()) != VkResult::VK_SUCCESS)
			throw std::runtime_error{"unable to query supported layer of vulkan"};

		std::unordered_map<std::string, VkLayerProperties> sLayerMap;

		for (const auto &vkLayer : sLayerList)
			std::memcpy(
				&sLayerMap.emplace(std::string{std::cbegin(vkLayer.layerName), std::find(std::cbegin(vkLayer.layerName), std::cend(vkLayer.layerName), '\0')}, VkLayerProperties{}).first->second,
				&vkLayer,
				sizeof(VkLayerProperties)
			);

		return sLayerMap;
	}

	std::unordered_map<std::string, VkExtensionProperties> ContextManager::fetchExtension()
	{
		std::uint32_t nExtensionCount;
		
		if (vkEnumerateInstanceExtensionProperties(nullptr, &nExtensionCount, nullptr) != VkResult::VK_SUCCESS)
			throw std::runtime_error{"unable to query supported extension of vulkan"};

		std::vector<VkExtensionProperties> sExtensionList(nExtensionCount);

		if (vkEnumerateInstanceExtensionProperties(nullptr, &nExtensionCount, sExtensionList.data()) != VkResult::VK_SUCCESS)
			throw std::runtime_error{"unable to query supported extension of vulkan"};

		std::unordered_map<std::string, VkExtensionProperties> sExtensionMap;

		for (const auto &vkExtension : sExtensionList)
			std::memcpy(
				&sExtensionMap.emplace(std::string{std::cbegin(vkExtension.extensionName), std::find(std::cbegin(vkExtension.extensionName), std::cend(vkExtension.extensionName), '\0')}, VkExtensionProperties{}).first->second,
				&vkExtension,
				sizeof(VkExtensionProperties)
			);

		return sExtensionMap;
	}

#if _DEBUG
	VKAPI_ATTR VkBool32 VKAPI_CALL ContextManager::__callbackDebug(
		VkDebugUtilsMessageSeverityFlagBitsEXT vkSeverityFlag,
		VkDebugUtilsMessageTypeFlagsEXT vkTypeFlag,
		const VkDebugUtilsMessengerCallbackDataEXT *pCallbackData,
		void *pUserData)
	{
		std::cout << pCallbackData->pMessageIdName << ": " << pCallbackData->pMessage << std::endl;

		return VK_FALSE;
	}
#endif
}