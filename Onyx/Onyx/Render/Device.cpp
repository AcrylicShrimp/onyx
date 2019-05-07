
/*
	2019.05.06
	Created by AcrylicShrimp.
*/

#include "Device.h"

#include "./ContextManager.h"

namespace Onyx::Render
{
	Device::Device(ContextManager *pContextManager) :
		pContextManager{pContextManager},
		vkPhysicalDevice{VK_NULL_HANDLE},
		vkDevice{VK_NULL_HANDLE}
	{
		assert(this->pContextManager);
	}
	
	Device::~Device() noexcept
	{
		vkDestroyDevice(this->vkDevice, nullptr);
	}

	bool Device::selectPhysicalDevice(const std::vector<const char *> &sPhysicalDeviceExtensionList, const std::function<bool(const Attribute &)> &fPhysicalDeviceFilter)
	{
		auto sDeviceList{this->pContextManager->fetchPhysicalDevice()};

		for (auto vkDevice : sDeviceList)
		{
			Attribute sAttribute;
			sAttribute.vkDevice = vkDevice;

			vkGetPhysicalDeviceFeatures(vkDevice, &sAttribute.vkFeature);
			vkGetPhysicalDeviceProperties(vkDevice, &sAttribute.vkProperty);

			std::uint32_t nQueueFamilyCount;
			vkGetPhysicalDeviceQueueFamilyProperties(vkDevice, &nQueueFamilyCount, nullptr);

			sAttribute.sQueueFamilyList.resize(nQueueFamilyCount);
			vkGetPhysicalDeviceQueueFamilyProperties(vkDevice, &nQueueFamilyCount, sAttribute.sQueueFamilyList.data());

			std::uint32_t nExtensionCount;

			if (vkEnumerateDeviceExtensionProperties(vkDevice, nullptr, &nExtensionCount, nullptr) != VkResult::VK_SUCCESS)
				throw std::runtime_error{"unable to query device extension"};

			std::vector<VkExtensionProperties> sExtensionList{nExtensionCount};

			if (vkEnumerateDeviceExtensionProperties(vkDevice, nullptr, &nExtensionCount, sExtensionList.data()) != VkResult::VK_SUCCESS)
				throw std::runtime_error{"unable to query device extension"};

			for (const auto &vkExtension : sExtensionList)
				std::memcpy(
					&sAttribute.sExtensionMap.emplace(std::string{std::cbegin(vkExtension.extensionName), std::find(std::cbegin(vkExtension.extensionName), std::cend(vkExtension.extensionName), '\0')}, VkExtensionProperties{}).first->second,
					&vkExtension,
					sizeof(VkExtensionProperties)
				);

			for (const auto *pPhysicalDeviceExtension : sPhysicalDeviceExtensionList)
				if (!sAttribute.sExtensionMap.count(std::string{pPhysicalDeviceExtension}))
					continue;

			if (fPhysicalDeviceFilter(sAttribute))
			{
				this->vkPhysicalDevice = vkDevice;
				this->sPhysicalDeviceAttribute = std::move(sAttribute);
				break;
			}
		}

		return this->vkPhysicalDevice != VK_NULL_HANDLE;
	}

	void Device::createDeviceInstance(const std::vector<const char *> &sPhysicalDeviceExtensionList, const std::unordered_set<std::uint32_t> &sQueueFamilySet)
	{
		if (!this->vkPhysicalDevice)
			throw std::runtime_error{"no physical device selected"};

		auto nQueuePriority{1.f};

		std::vector<VkDeviceQueueCreateInfo> sQueueCreateInfoList;

		for (auto nQueueFamilyIndex : sQueueFamilySet)
			sQueueCreateInfoList.emplace_back(VkDeviceQueueCreateInfo
											  {
												  VkStructureType::VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO,
												  nullptr,
												  0,
												  nQueueFamilyIndex,
												  1,
												  &nQueuePriority
											  });

		VkPhysicalDeviceFeatures vkPhysicalDeviceFeatures{};
		VkDeviceCreateInfo vkDeviceCreateInfo
		{
			VkStructureType::VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO,
			nullptr,
			0,
			static_cast<std::uint32_t>(sQueueCreateInfoList.size()),
			sQueueCreateInfoList.data(),
			0,
			nullptr,
			static_cast<std::uint32_t>(sPhysicalDeviceExtensionList.size()),
			sPhysicalDeviceExtensionList.data(),
			&vkPhysicalDeviceFeatures
		};

		if (vkCreateDevice(this->vkPhysicalDevice, &vkDeviceCreateInfo, nullptr, &this->vkDevice) != VkResult::VK_SUCCESS)
			throw std::runtime_error{"unable to create device instance"};
	}
}