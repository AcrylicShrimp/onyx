
/*
	2019.05.06
	Created by AcrylicShrimp.
*/

#include "Surface.h"

#include "./ContextManager.h"

namespace Onyx::Render
{
	Surface::Surface(ContextManager *pContextManager, Display::Window *pWindow) :
		pContextManager{pContextManager},
		pWindow{pWindow}
	{
#if __ONYX_PLATFORM_WINDOWS
		VkWin32SurfaceCreateInfoKHR vkSurfaceCreateInfo
		{
			VkStructureType::VK_STRUCTURE_TYPE_WIN32_SURFACE_CREATE_INFO_KHR,
			nullptr,
			0,
			GetModuleHandle(nullptr),
			static_cast<Display::WindowType *>(this->pWindow)->windowHandle()
		};

		if (vkCreateWin32SurfaceKHR(this->pContextManager->vulkanInstance(), &vkSurfaceCreateInfo, nullptr, &this->vkSurface) != VkResult::VK_SUCCESS)
			throw std::runtime_error{"unable to create surface instance"};
#endif
	}
	
	Surface::~Surface() noexcept
	{
		vkDestroySurfaceKHR(this->pContextManager->vulkanInstance(), this->vkSurface, nullptr);
	}

	bool Surface::isCompatiblePhysicalDevice(VkPhysicalDevice vkPhysicalDevice)
	{
		std::uint32_t nSurfaceFormatCount;

		if (vkGetPhysicalDeviceSurfaceFormatsKHR(vkPhysicalDevice, this->vkSurface, &nSurfaceFormatCount, nullptr) != VkResult::VK_SUCCESS)
			throw std::runtime_error{"unable to query surface format of physical device"};

		return nSurfaceFormatCount != 0;
	}

	void Surface::findFormat(VkPhysicalDevice vkPhysicalDevice)
	{
		std::uint32_t nSurfaceFormatCount;

		if (vkGetPhysicalDeviceSurfaceFormatsKHR(vkPhysicalDevice, this->vkSurface, &nSurfaceFormatCount, nullptr) != VkResult::VK_SUCCESS)
			throw std::runtime_error{"unable to query surface format of physical device"};

		if (nSurfaceFormatCount == 0)
			throw std::runtime_error{"no supported surface format found"};

		std::vector<VkSurfaceFormatKHR> sSurfaceFormatList(nSurfaceFormatCount);

		if (vkGetPhysicalDeviceSurfaceFormatsKHR(vkPhysicalDevice, this->vkSurface, &nSurfaceFormatCount, sSurfaceFormatList.data()) != VkResult::VK_SUCCESS)
			throw std::runtime_error{"unable to query surface format of physical device"};

		for (auto vkSurfaceFormat : sSurfaceFormatList)
			if (vkSurfaceFormat.format == VkFormat::VK_FORMAT_UNDEFINED || vkSurfaceFormat.format == VkFormat::VK_FORMAT_B8G8R8A8_UNORM)
			{
				this->vkSurfaceFormat = vkSurfaceFormat;
				return;
			}

		this->vkSurfaceFormat = sSurfaceFormatList.front();
	}
}