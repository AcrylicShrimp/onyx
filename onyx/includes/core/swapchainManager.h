
#ifndef _ONYX_CORE_SWAPCHAINMANAGER_H

#define _ONYX_CORE_SWAPCHAINMANAGER_H

#include "onyx/includes/core/perContextManager.h"
#include "onyx/includes/core/vulkan.h"

#include <string>
#include <utility>
#include <vector>

namespace onyx::core {
	class SwapchainManager : public PerContextManager {
	protected:
		VkExtent2D				 sExtent;
		VkSwapchainKHR			 sSwapchain;
		VkPresentModeKHR		 ePresentMode;
		VkImage					 sDepthImage;
		VkImageView				 sDepthImageView;
		std::vector<VkImage>	 sImageList;
		std::vector<VkImageView> sImageViewList;

	public:
		SwapchainManager(Context *pContext);
		SwapchainManager(const SwapchainManager &sRhs) = delete;
		virtual ~SwapchainManager() noexcept;

	public:
		virtual bool isCompatible(const DeviceInfo &sDevice) override;
		virtual void init(const DeviceInfo &sDevice) override;
		virtual void fin() override;
	};
}	 // namespace onyx::core

#endif