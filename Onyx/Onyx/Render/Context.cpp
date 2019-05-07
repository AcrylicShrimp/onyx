
/*
	2019.05.04
	Created by AcrylicShrimp.
*/

#include "Context.h"

namespace Onyx::Render
{
	Context::Context(ContextManager *pContextManager, Display::Window *pWindow) :
		pContextManager{pContextManager},
		pWindow{pWindow},
		sDevice{pContextManager},
		sSurface{pContextManager, pWindow}
	{
		assert(this->pContextManager);

		std::vector<const char *> sPhysicalDeviceExtensionList
		{
			VK_KHR_SWAPCHAIN_EXTENSION_NAME
		};

		if (!this->sDevice.selectPhysicalDevice(sPhysicalDeviceExtensionList, [this](const Device::Attribute &sDeviceAttribute)
		{
			bool bGraphicsQueue{false};

			for (const auto &vkQueueFamily : sDeviceAttribute.sQueueFamilyList)
				if (vkQueueFamily.queueCount != 0 && vkQueueFamily.queueFlags & VkQueueFlagBits::VK_QUEUE_GRAPHICS_BIT)
				{
					bGraphicsQueue = true;
					break;
				}

			if (!bGraphicsQueue)
				return false;

			bool bPresentQueue{false};

			for (std::uint32_t nIndex{0}, nMaxIndex{static_cast<std::uint32_t>(sDeviceAttribute.sQueueFamilyList.size())}; nIndex < nMaxIndex; ++nIndex)
				if (sDeviceAttribute.sQueueFamilyList[nIndex].queueCount != 0)
				{
					VkBool32 vkSurfaceSupport;

					if (vkGetPhysicalDeviceSurfaceSupportKHR(sDeviceAttribute.vkDevice, nIndex, this->sSurface.vulkanSurface(), &vkSurfaceSupport) != VkResult::VK_SUCCESS)
						throw std::runtime_error{"unable to query surface support of physical device"};

					if (vkSurfaceSupport)
					{
						bPresentQueue = true;
						break;
					}
				}

			if (!bPresentQueue)
				return false;

			if (!this->sSurface.isCompatiblePhysicalDevice(sDeviceAttribute.vkDevice))
				return false;

			return true;
		}))
			throw std::runtime_error{"no suitable physical device detected"};

		const auto &sPhysicalDeviceAttribute{this->sDevice.physicalDeviceAttribute()};
		const auto &sQueueFamilyList{sPhysicalDeviceAttribute.sQueueFamilyList};

		for (std::uint32_t nIndex{0}, nMaxIndex{static_cast<std::uint32_t>(sQueueFamilyList.size())}; nIndex < nMaxIndex; ++nIndex)
			if (sQueueFamilyList[nIndex].queueCount != 0 && sQueueFamilyList[nIndex].queueFlags & VkQueueFlagBits::VK_QUEUE_GRAPHICS_BIT)
			{
				this->nGraphicsFamily = nIndex;
				break;
			}

		for (std::uint32_t nIndex{0}, nMaxIndex{static_cast<std::uint32_t>(sQueueFamilyList.size())}; nIndex < nMaxIndex; ++nIndex)
			if (sQueueFamilyList[nIndex].queueCount != 0)
			{
				VkBool32 vkSurfaceSupport;

				if (vkGetPhysicalDeviceSurfaceSupportKHR(sPhysicalDeviceAttribute.vkDevice, nIndex, this->sSurface.vulkanSurface(), &vkSurfaceSupport) != VkResult::VK_SUCCESS)
					throw std::runtime_error{"unable to query surface support of physical device"};

				if (vkSurfaceSupport)
				{
					this->nPresentFamily = nIndex;
					break;
				}
			}

		this->sDevice.createDeviceInstance(sPhysicalDeviceExtensionList, std::unordered_set<std::uint32_t>
		{
			this->nGraphicsFamily,
			this->nPresentFamily
		});

		vkGetDeviceQueue(this->sDevice.vulkanDevice(), this->nGraphicsFamily, 0, &this->vkGraphicsQueue);
		vkGetDeviceQueue(this->sDevice.vulkanDevice(), this->nPresentFamily, 0, &this->vkPresentQueue);
	}

	Context::~Context() noexcept
	{
		//Empty.
	}
}