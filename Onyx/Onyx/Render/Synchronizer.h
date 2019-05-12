
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
		std::size_t nFrameIndex;
		std::size_t nMaxConcurrentFrameCount;
		VkCommandPool vkGraphicsCommandPool;
		VkCommandPool vkPresentCommandPool;
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
		void createSynchronizationObject(std::uint32_t nGraphicsFamily, std::uint32_t nPresentFamily);
		std::tuple<VkCommandBuffer, VkCommandBuffer, VkSemaphore, VkSemaphore, VkSemaphore, VkFence> sync();
	};
}

#endif