
#include "onyx/includes/core/surfaceManager.h"

#include "onyx/includes/common/platform.h"
#include "onyx/includes/core/context.h"
#include "onyx/includes/core/contextManager.h"
#include "onyx/includes/core/deviceInfo.h"
#include "onyx/includes/display/window.h"

#include <cstdint>
#include <stdexcept>

namespace onyx::core {
	SurfaceManager::SurfaceManager(Context *pContext, display::Window *pWindow) :
		PerContextManager{pContext},
		pWindow{pWindow}
	{
#if __ONYX_PLATFORM_WINDOWS
		VkWin32SurfaceCreateInfoKHR sSurfaceCreateInfo{
			VkStructureType::VK_STRUCTURE_TYPE_WIN32_SURFACE_CREATE_INFO_KHR,
			nullptr,
			0,
			GetModuleHandle(nullptr),
			static_cast<display::WindowType *>(this->pWindow)->windowHandle()};

		if (vkCreateWin32SurfaceKHR(
				this->pContextManager->vulkanInstance(),
				&sSurfaceCreateInfo,
				nullptr,
				&this->vkSurface)
			!= VkResult::VK_SUCCESS)
			throw std::runtime_error{"unable to create surface instance"};
#elif __ONYX_PLATFORM_APPLE_OSX
		VkMacOSSurfaceCreateInfoMVK sSurfaceCreateInfo{
			VkStructureType::VK_STRUCTURE_TYPE_MACOS_SURFACE_CREATE_INFO_MVK,
			nullptr,
			0,
			static_cast<display::WindowType *>(this->pWindow)->getMetalView()};

		if (vkCreateMacOSSurfaceMVK(
				this->pContext->pContextMgr->vulkanInstance(),
				&sSurfaceCreateInfo,
				nullptr,
				&this->sSurface)
			!= VkResult::VK_SUCCESS)
			throw std::runtime_error{"unable to create surface instance"};
#else
		throw std::runtime_error{"surface is not supported on this platform"};
#endif
	}

	SurfaceManager::~SurfaceManager() noexcept
	{
		vkDestroySurfaceKHR(this->pContext->pContextMgr->vulkanInstance(), this->sSurface, nullptr);
	}

	bool SurfaceManager::isCompatible(const DeviceInfo &sDevice)
	{
		std::uint32_t nSurfaceFormatCount;

		if (vkGetPhysicalDeviceSurfaceFormatsKHR(
				sDevice.physicalDevice(),
				this->sSurface,
				&nSurfaceFormatCount,
				nullptr)
			!= VkResult::VK_SUCCESS)
			throw std::runtime_error{"unable to query surface format of physical device"};

		return nSurfaceFormatCount != 0;
	}

	void SurfaceManager::init(const DeviceInfo &sDevice)
	{
		std::uint32_t nSurfaceFormatCount;

		if (vkGetPhysicalDeviceSurfaceFormatsKHR(
				sDevice.physicalDevice(),
				this->sSurface,
				&nSurfaceFormatCount,
				nullptr)
			!= VkResult::VK_SUCCESS)
			throw std::runtime_error{"unable to query surface format of physical device"};

		if (nSurfaceFormatCount == 0) throw std::runtime_error{"no supported surface format found"};

		std::vector<VkSurfaceFormatKHR> sSurfaceFormatList(nSurfaceFormatCount);

		if (vkGetPhysicalDeviceSurfaceFormatsKHR(
				sDevice.physicalDevice(),
				this->sSurface,
				&nSurfaceFormatCount,
				sSurfaceFormatList.data())
			!= VkResult::VK_SUCCESS)
			throw std::runtime_error{"unable to query surface format of physical device"};

		for (auto vkSurfaceFormat: sSurfaceFormatList)
			if (vkSurfaceFormat.format == VkFormat::VK_FORMAT_UNDEFINED
				|| vkSurfaceFormat.format == VkFormat::VK_FORMAT_B8G8R8A8_UNORM) {
				this->sSurfaceFormat = vkSurfaceFormat;
				return;
			}

		this->sSurfaceFormat = sSurfaceFormatList.front();
	}

	void SurfaceManager::fin()
	{
		// Empty.
	}
}	 // namespace onyx::core