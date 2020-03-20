
#include "onyx/includes/core/deviceInfo.h"

#include <algorithm>
#include <iterator>
#include <stdexcept>
#include <tuple>
#include <utility>

namespace onyx::core {
	DeviceInfo::DeviceInfo(VkPhysicalDevice sPhysicalDevice) : sPhysicalDevice{sPhysicalDevice}
	{
		vkGetPhysicalDeviceFeatures(this->sPhysicalDevice, &this->sFeatures);
		vkGetPhysicalDeviceProperties(this->sPhysicalDevice, &this->sProperties);
		vkGetPhysicalDeviceMemoryProperties(this->sPhysicalDevice, &this->sMemoryProperties);

		std::uint32_t nQueuePropertiesCount;
		vkGetPhysicalDeviceQueueFamilyProperties(this->sPhysicalDevice, &nQueuePropertiesCount, nullptr);

		this->sQueueProperties.resize(nQueuePropertiesCount);
		vkGetPhysicalDeviceQueueFamilyProperties(
			this->sPhysicalDevice,
			&nQueuePropertiesCount,
			this->sQueueProperties.data());

		std::uint32_t nExtensionPropertiesCount;
		if (vkEnumerateDeviceExtensionProperties(this->sPhysicalDevice, nullptr, &nExtensionPropertiesCount, nullptr)
			!= VkResult::VK_SUCCESS)
			throw std::runtime_error{"unable to query physical device extension properties"};

		std::vector<VkExtensionProperties> sExtensionPropertiesVec{nExtensionPropertiesCount};
		if (vkEnumerateDeviceExtensionProperties(
				this->sPhysicalDevice,
				nullptr,
				&nExtensionPropertiesCount,
				sExtensionPropertiesVec.data())
			!= VkResult::VK_SUCCESS)
			throw std::runtime_error{"unable to query physical device extension properties"};

		this->sExtensionProperties.reserve(nExtensionPropertiesCount);

		for (const auto &vkExtensionProperties: sExtensionPropertiesVec)
			this->sExtensionProperties.emplace(
				std::piecewise_construct,
				std::forward_as_tuple(
					std::cbegin(vkExtensionProperties.extensionName),
					std::find(
						std::cbegin(vkExtensionProperties.extensionName),
						std::cend(vkExtensionProperties.extensionName),
						'\0')),
				std::forward_as_tuple(vkExtensionProperties.specVersion));
	}
}	 // namespace onyx::core