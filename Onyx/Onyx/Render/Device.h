
/*
	2019.05.06
	Created by AcrylicShrimp.
*/

#ifndef _CLASS_ONYX_RENDER_DEVICE_H

#define _CLASS_ONYX_RENDER_DEVICE_H

#include "../Vulkan.h"

#include <algorithm>
#include <cassert>
#include <cstdint>
#include <cstring>
#include <functional>
#include <optional>
#include <stdexcept>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <utility>
#include <vector>

namespace Onyx::Render
{
	class ContextManager;

	class Device final
	{
	public:
		struct Attribute
		{
			VkPhysicalDevice vkDevice;
			VkPhysicalDeviceFeatures vkFeature;
			VkPhysicalDeviceProperties vkProperty;
			VkPhysicalDeviceMemoryProperties vkMemoryProperty;
			std::vector<VkQueueFamilyProperties> sQueueFamilyList;
			std::unordered_map<std::string, VkExtensionProperties> sExtensionMap;
		};

	public:
		ContextManager *const pContextManager;

	private:
		VkDevice vkDevice;
		VkPhysicalDevice vkPhysicalDevice;
		Attribute sPhysicalDeviceAttribute;
		
	public:
		Device(ContextManager *pContextManager);
		Device(const Device &sSrc) = delete;
		~Device() noexcept;
		
	public:
		Device &operator=(const Device &sSrc) = delete;

	public:
		inline VkDevice vulkanDevice() const;
		inline VkPhysicalDevice vulkanPhysicalDevice() const;
		inline const Attribute &physicalDeviceAttribute() const;
		bool selectPhysicalDevice(const std::vector<const char *> &sPhysicalDeviceExtensionList, const std::function<bool(const Attribute &)> &fPhysicalDeviceFilter);
		void createDeviceInstance(const std::vector<const char *> &sPhysicalDeviceExtensionList, const std::unordered_set<std::uint32_t> &sQueueFamilySet);
		std::optional<std::uint32_t> findMemoryType(std::uint32_t nMemoryTypeBit, VkMemoryPropertyFlags vkMemoryPropertyFlag) const;
	};

	inline VkDevice Device::vulkanDevice() const
	{
		return this->vkDevice;
	}

	inline VkPhysicalDevice Device::vulkanPhysicalDevice() const
	{
		return this->vkPhysicalDevice;
	}

	inline const Device::Attribute &Device::physicalDeviceAttribute() const
	{
		return this->sPhysicalDeviceAttribute;
	}
}

#endif