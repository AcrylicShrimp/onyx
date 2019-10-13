
/*
	2019.05.11
	Created by AcrylicShrimp.
*/

#ifndef _CLASS_ONYX_RENDER_SYNCHRONIZER_H

#define _CLASS_ONYX_RENDER_SYNCHRONIZER_H

#include "../Vulkan.h"
#include "./Device.h"

#include <cassert>
#include <cstddef>
#include <functional>
#include <stdexcept>
#include <tuple>
#include <vector>

namespace Onyx::Render
{
	class Synchronizer
	{
	public:
		Device *const pDevice;

	private:
		VkQueue vkGraphicsQueue;	//For Onetime command buffer;
		std::size_t nFrameIndex;
		std::size_t nMaxConcurrentFrameCount;
		VkCommandPool vkGraphicsCommandPool;
		VkCommandPool vkPresentCommandPool;
		VkCommandPool vkOnetimeCommandPool;
		std::vector<VkCommandBuffer> sGraphicsCommandBufferList;
		std::vector<VkCommandBuffer> sPresentCommandBufferList;
		std::vector<VkSemaphore> sAfterRenderingSemaphoreList;
		std::vector<VkSemaphore> sAfterOwnershipTransferredSemaphoreList;
		std::vector<VkSemaphore> sAfterPresentationSemaphoreList;
		std::vector<VkFence> sFenceList;
		
	public:
		Synchronizer(Device *pDevice, std::size_t nMaxConcurrentFrameCount);
		Synchronizer(const Synchronizer &sSrc) = delete;
		~Synchronizer();
		
	public:
		Synchronizer &operator=(const Synchronizer &sSrc) = delete;
		
	public:
		void executeOnetimeCommand(std::function<void(VkCommandBuffer)> fCommandFunction) const;
		void createSynchronizationObject(VkQueue vkGraphicsQueue, std::uint32_t nGraphicsFamily, std::uint32_t nPresentFamily);
		std::tuple<VkCommandBuffer, VkCommandBuffer, VkSemaphore, VkSemaphore, VkSemaphore, VkFence> sync();
	};
}

#endif