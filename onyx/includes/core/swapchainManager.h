
#ifndef _ONYX_CORE_SWAPCHAINMANAGER_H

#define _ONYX_CORE_SWAPCHAINMANAGER_H

#include "onyx/includes/core/perContextManager.h"
#include "onyx/includes/core/vulkan.h"

#include <vector>

namespace onyx::core {
	class SwapchainManager : public PerContextManager {
	protected:
		VkExtent2D				 sExtent;
		VkSwapchainKHR			 sSwapchain;
		VkPresentModeKHR		 ePresentMode;
		VkImage					 sDepthImage;
		VkImageView				 sDepthImageView;
		VkDeviceMemory			 sDepthImageMemory;
		std::vector<VkImage>	 sImageVec;
		std::vector<VkImageView> sImageViewVec;

	public:
		SwapchainManager(Context *pContext);
		SwapchainManager(const SwapchainManager &sRhs) = delete;
		virtual ~SwapchainManager() noexcept;

	public:
		virtual bool isCompatible(const DeviceInfo &sDevice) override;
		virtual void init(const DeviceInfo &sDevice) override;
		virtual void fin() override;

	public:
		VkExtent2D vulkanExtent() const noexcept
		{
			return this->sExtent;
		}
		VkSwapchainKHR vulkanSwapchain() const noexcept
		{
			return this->sSwapchain;
		}
		VkImageView vulkanDepthImageView() const noexcept
		{
			return this->sDepthImageView;
		}
		const std::vector<VkImage> &vulkanImageVec() const noexcept
		{
			return this->sImageVec;
		}
		const std::vector<VkImageView> &vulkanImageViewVec() const noexcept
		{
			return this->sImageViewVec;
		}
	};
}	 // namespace onyx::core

#endif