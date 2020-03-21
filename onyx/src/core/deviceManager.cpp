
#include "onyx/includes/core/deviceManager.h"

#include "onyx/includes/core/context.h"
#include "onyx/includes/core/contextManager.h"
#include "onyx/includes/core/deviceInfo.h"

#include <cstdint>
#include <optional>
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

		VkPhysicalDeviceFeatures sDeviceFeatures{};
		sDeviceFeatures.fillModeNonSolid = VK_TRUE;

		std::vector<const char *> sDeviceExtensionVec;
		sDeviceExtensionVec.reserve(this->sExtensionVec.size());

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

		if (vkCreateDevice(sDevice.physicalDevice(), &sDeviceCreateInfo, nullptr, &this->sDevice)
			!= VkResult::VK_SUCCESS)
			throw std::runtime_error{"unable to create device instance"};

		vkGetDeviceQueue(this->sDevice, nGraphicsQueueIndex, 0, &this->sGraphicsQueue);
		vkGetDeviceQueue(this->sDevice, nPresentQueueIndex, 0, &this->sPresentQueue);
	}

	void DeviceManager::fin()
	{
		vkDestroyDevice(this->sDevice, nullptr);
	}

	VkDeviceMemory DeviceManager::allocateImageMemory(DeviceMemoryType eMemType, VkImage sImage) const
	{
		VkMemoryRequirements sMemoryReq;
		vkGetImageMemoryRequirements(this->sDevice, sImage, &sMemoryReq);

		std::optional<std::uint32_t> sMemoryTypeIndex;
		const auto &				 sMemoryProperties{this->pContext->deviceInfo()->memoryProperties()};

		VkMemoryPropertyFlags eMemoryPropertyFlags;

		switch (eMemType) {
		case DeviceMemoryType::Local:
			eMemoryPropertyFlags = VkMemoryPropertyFlagBits::VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT;
			break;
		case DeviceMemoryType::HostShared:
			eMemoryPropertyFlags
				= VkMemoryPropertyFlagBits::VK_MEMORY_PROPERTY_HOST_COHERENT_BIT | VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT;
			break;
		default: return VK_NULL_HANDLE;
		}

		for (std::uint32_t nIndex{0}; nIndex < sMemoryProperties.memoryTypeCount; ++nIndex)
			if (sMemoryReq.memoryTypeBits & (1 << nIndex)
				&& (sMemoryProperties.memoryTypes[nIndex].propertyFlags & eMemoryPropertyFlags)
					   == eMemoryPropertyFlags) {
				sMemoryTypeIndex = nIndex;
				break;
			}

		if (!sMemoryTypeIndex) throw std::runtime_error{"unable to find suitable memory type"};

		VkMemoryAllocateInfo vkMemoryAllocateInfo{VkStructureType::VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO,
												  nullptr,
												  sMemoryReq.size,
												  *sMemoryTypeIndex};

		VkDeviceMemory sMemory;

		if (vkAllocateMemory(this->sDevice, &vkMemoryAllocateInfo, nullptr, &sMemory) != VkResult::VK_SUCCESS)
			throw std::runtime_error{"unable to allocate memory"};

		return sMemory;
	}
}	 // namespace onyx::core