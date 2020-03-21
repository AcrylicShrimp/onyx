
#ifndef _ONYX_CORE_SYNCHRONIZATIONMANAGER_H

#define _ONYX_CORE_SYNCHRONIZATIONMANAGER_H

#include "onyx/includes/core/perContextManager.h"
#include "onyx/includes/core/vulkan.h"

#include <cstddef>
#include <tuple>
#include <vector>

namespace onyx::core {
	class SynchronizationManager : public PerContextManager {
	public:
		const std::size_t nMaxConcurrentFrameCount;

	protected:
		std::size_t					 nFrameIndex;
		VkCommandPool				 sGraphicsCommandPool;
		VkCommandPool				 sPresentCommandPool;
		VkCommandPool				 sOnetimeCommandPool;
		std::vector<VkCommandBuffer> sGraphicsCommandBufferList;
		std::vector<VkCommandBuffer> sPresentCommandBufferList;
		std::vector<VkSemaphore>	 sAfterRenderingSemaphoreList;
		std::vector<VkSemaphore>	 sAfterOwnershipTransferredSemaphoreList;
		std::vector<VkSemaphore>	 sAfterPresentationSemaphoreList;
		std::vector<VkFence>		 sFenceList;

	public:
		SynchronizationManager(Context *pContext, std::size_t nMaxConcurrentFrameCount);
		SynchronizationManager(const SynchronizationManager &sRhs) = delete;
		virtual ~SynchronizationManager() noexcept;

	public:
		virtual void init(const DeviceInfo &sDevice) override;
		virtual void fin() override;
		std::tuple<VkCommandBuffer, VkCommandBuffer, VkSemaphore, VkSemaphore, VkSemaphore, VkFence>
			nextSynchronizationObject();
	};
}	 // namespace onyx::core

#endif