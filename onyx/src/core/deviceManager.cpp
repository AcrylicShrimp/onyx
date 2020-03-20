
#include "onyx/includes/core/deviceManager.h"

#include "onyx/includes/core/context.h"
#include "onyx/includes/core/contextManager.h"
#include "onyx/includes/core/deviceInfo.h"

#include <cstdint>
#include <iostream>
#include <unordered_set>

namespace onyx::core {
	DeviceManager::DeviceManager(Context *pContext) : PerContextManager{pContext}
	{
		// Empty.
	}

	DeviceManager::~DeviceManager() noexcept
	{
		vkDestroyDevice(this->sDevice, nullptr);
	}

	bool DeviceManager::isCompatible(const DeviceInfo &sDevice)
	{
		auto bHasGraphicsQueue{false};

		for (const auto &sQueueProp: sDevice.queueProperties()) {
			if (sQueueProp.queueCount && sQueueProp.queueFlags & VkQueueFlagBits::VK_QUEUE_GRAPHICS_BIT) {
				bHasGraphicsQueue = true;
				break;
			}
		}

		if (!bHasGraphicsQueue) return false;

		std::size_t nQueueIndex{0};
		auto		bHasPresentQueue{false};

		for (const auto &sQueueProp: sDevice.queueProperties()) {
			if (sQueueProp.queueCount) {
				VkBool32 vkSurfaceSupport;

				if (vkGetPhysicalDeviceSurfaceSupportKHR(
						sDevice.physicalDevice(),
						nQueueIndex,
						this->pContext->surfaceMgr().vulkanSurface(),
						&vkSurfaceSupport)
					!= VkResult::VK_SUCCESS)
					throw std::runtime_error{"unable to query surface support of physical device"};

				if (vkSurfaceSupport) {
					bHasPresentQueue = true;
					break;
				}

				++nQueueIndex;
			}
		}

		if (!bHasPresentQueue) return false;

		for (const auto &sExtension: this->sExtensionVec)
			if (!sDevice.extensionProperties().count(sExtension)) return false;

		if (!sDevice.features().fillModeNonSolid) return false;

		return true;
	}

	void DeviceManager::init(const DeviceInfo &sDevice)
	{
		std::cout << "@@@@@@@@@@ DeviceManager::init 1 @@@@@@@@@@" << std::endl;

		std::uint32_t nGraphicsQueueIndex{0};
		std::uint32_t nPresentQueueIndex{0};

		for (const auto &sQueueProp: sDevice.queueProperties()) {
			if (sQueueProp.queueCount && sQueueProp.queueFlags & VkQueueFlagBits::VK_QUEUE_GRAPHICS_BIT) break;
			++nGraphicsQueueIndex;
		}

		for (const auto &sQueueProp: sDevice.queueProperties()) {
			if (sQueueProp.queueCount) {
				VkBool32 vkSurfaceSupport;

				if (vkGetPhysicalDeviceSurfaceSupportKHR(
						sDevice.physicalDevice(),
						nPresentQueueIndex,
						this->pContext->surfaceMgr().vulkanSurface(),
						&vkSurfaceSupport)
					!= VkResult::VK_SUCCESS)
					throw std::runtime_error{"unable to query surface support of physical device"};

				if (vkSurfaceSupport) break;
			}

			++nPresentQueueIndex;
		}

		std::cout << "@@@@@@@@@@ DeviceManager::init 2 @@@@@@@@@@" << std::endl;

		auto							  nQueuePriority{1.f};
		std::unordered_set<std::uint32_t> sQueueIndexSet{nGraphicsQueueIndex, nPresentQueueIndex};

		std::vector<VkDeviceQueueCreateInfo> sQueueCreateInfoVec;
		sQueueCreateInfoVec.reserve(sQueueIndexSet.size());

		for (auto nQueueIndex: sQueueIndexSet)
			sQueueCreateInfoVec.emplace_back(
				VkDeviceQueueCreateInfo{VkStructureType::VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO,
										nullptr,
										0,
										nQueueIndex,
										1,
										&nQueuePriority});

		std::cout << "@@@@@@@@@@ DeviceManager::init 3 @@@@@@@@@@" << std::endl;

		VkPhysicalDeviceFeatures sDeviceFeatures{};
		sDeviceFeatures.fillModeNonSolid = VK_TRUE;

		std::vector<const char *> sDeviceExtensionVec;
		sDeviceExtensionVec.reserve(this->sExtensionVec.size());

		std::cout << "@@@@@@@@@@ DeviceManager::init 4 @@@@@@@@@@" << std::endl;

		for (const auto &sExtension: this->sExtensionVec) sDeviceExtensionVec.emplace_back(sExtension.c_str());

		VkDeviceCreateInfo sDeviceCreateInfo{VkStructureType::VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO,
											 nullptr,
											 0,
											 static_cast<std::uint32_t>(sQueueCreateInfoVec.size()),
											 sQueueCreateInfoVec.data(),
											 0,
											 nullptr,
											 static_cast<std::uint32_t>(sDeviceExtensionVec.size()),
											 sDeviceExtensionVec.data(),
											 &sDeviceFeatures};

		std::cout << "@@@@@@@@@@ DeviceManager::init 5 @@@@@@@@@@" << std::endl;

		VkResult eResult;

		if ((eResult = vkCreateDevice(sDevice.physicalDevice(), &sDeviceCreateInfo, nullptr, &this->sDevice))
			!= VkResult::VK_SUCCESS) {
			std::cout << eResult << std::endl;
			throw std::runtime_error{"unable to create device instance"};
		}

		std::cout << "@@@@@@@@@@ DeviceManager::init 6 @@@@@@@@@@" << std::endl;

		vkGetDeviceQueue(this->sDevice, nGraphicsQueueIndex, 0, &this->sGraphicsQueue);
		vkGetDeviceQueue(this->sDevice, nPresentQueueIndex, 0, &this->sPresentQueue);

		std::cout << "@@@@@@@@@@ DeviceManager::init @@@@@@@@@@" << std::endl;
	}

	void DeviceManager::fin()
	{
		// Empty.
	}
}	 // namespace onyx::core