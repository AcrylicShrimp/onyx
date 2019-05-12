
/*
	2019.05.11
	Created by AcrylicShrimp.
*/

#include "Synchronizer.h"

namespace Onyx::Render
{
	Synchronizer::Synchronizer(Device *pDevice, std::size_t nMaxConcurrentFrameCount) :
		pDevice{pDevice},
		nFrameIndex{0},
		nMaxConcurrentFrameCount{nMaxConcurrentFrameCount}
	{
		assert(this->pDevice);
		assert(this->nMaxConcurrentFrameCount);
	}
	
	Synchronizer::~Synchronizer()
	{
		vkDestroyCommandPool(this->pDevice->vulkanDevice(), this->vkGraphicsCommandPool, nullptr);
		vkDestroyCommandPool(this->pDevice->vulkanDevice(), this->vkPresentCommandPool, nullptr);

		for (std::size_t nIndex{0}; nIndex < this->nMaxConcurrentFrameCount; ++nIndex)
		{
			vkDestroySemaphore(this->pDevice->vulkanDevice(), this->sAfterRenderingSemaphoreList[nIndex], nullptr);
			vkDestroySemaphore(this->pDevice->vulkanDevice(), this->sAfterOwnershipTransferredSemaphoreList[nIndex], nullptr);
			vkDestroySemaphore(this->pDevice->vulkanDevice(), this->sAfterPresentationSemaphoreList[nIndex], nullptr);
			vkDestroyFence(this->pDevice->vulkanDevice(), this->sFenceList[nIndex], nullptr);
		}
	}

	void Synchronizer::createSynchronizationObject(std::uint32_t nGraphicsFamily, std::uint32_t nPresentFamily)
	{
		VkCommandPoolCreateInfo vkGraphicsCommandPoolCreateInfo
		{
			VkStructureType::VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO,
			nullptr,
			VkCommandPoolCreateFlagBits::VK_COMMAND_POOL_CREATE_TRANSIENT_BIT |
			VkCommandPoolCreateFlagBits::VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT,
			nGraphicsFamily
		};
		VkCommandPoolCreateInfo vkPresentCommandPoolCreateInfo
		{
			VkStructureType::VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO,
			nullptr,
			VkCommandPoolCreateFlagBits::VK_COMMAND_POOL_CREATE_TRANSIENT_BIT |
			VkCommandPoolCreateFlagBits::VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT,
			nPresentFamily
		};

		if (vkCreateCommandPool(this->pDevice->vulkanDevice(), &vkGraphicsCommandPoolCreateInfo, nullptr, &this->vkGraphicsCommandPool) != VkResult::VK_SUCCESS ||
			vkCreateCommandPool(this->pDevice->vulkanDevice(), &vkPresentCommandPoolCreateInfo, nullptr, &this->vkPresentCommandPool) != VkResult::VK_SUCCESS)
			throw std::runtime_error{"unable to create command pool"};

		this->sGraphicsCommandBufferList.resize(this->nMaxConcurrentFrameCount);
		this->sPresentCommandBufferList.resize(this->nMaxConcurrentFrameCount);
		this->sAfterRenderingSemaphoreList.resize(this->nMaxConcurrentFrameCount);
		this->sAfterOwnershipTransferredSemaphoreList.resize(this->nMaxConcurrentFrameCount);
		this->sAfterPresentationSemaphoreList.resize(this->nMaxConcurrentFrameCount);
		this->sFenceList.resize(this->nMaxConcurrentFrameCount);

		VkCommandBufferAllocateInfo vkGraphicsCommandBufferAllocateInfo
		{
			VkStructureType::VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO,
			nullptr,
			this->vkGraphicsCommandPool,
			VkCommandBufferLevel::VK_COMMAND_BUFFER_LEVEL_PRIMARY,
			static_cast<std::uint32_t>(this->nMaxConcurrentFrameCount)
		};
		VkCommandBufferAllocateInfo vkPresentCommandBufferAllocateInfo
		{
			VkStructureType::VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO,
			nullptr,
			this->vkPresentCommandPool,
			VkCommandBufferLevel::VK_COMMAND_BUFFER_LEVEL_PRIMARY,
			static_cast<std::uint32_t>(this->nMaxConcurrentFrameCount)
		};

		if (vkAllocateCommandBuffers(this->pDevice->vulkanDevice(), &vkGraphicsCommandBufferAllocateInfo, this->sGraphicsCommandBufferList.data()) != VkResult::VK_SUCCESS ||
			vkAllocateCommandBuffers(this->pDevice->vulkanDevice(), &vkPresentCommandBufferAllocateInfo, this->sPresentCommandBufferList.data()) != VkResult::VK_SUCCESS)
			throw std::runtime_error{"unable to allocate command buffer"};

		VkSemaphoreCreateInfo vkSemaphoreCreateInfo
		{
			VkStructureType::VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO,
			nullptr,
			0
		};
		VkFenceCreateInfo vkFenceCreateInfo
		{
			VkStructureType::VK_STRUCTURE_TYPE_FENCE_CREATE_INFO,
			nullptr,
			VkFenceCreateFlagBits::VK_FENCE_CREATE_SIGNALED_BIT
		};

		for (std::size_t nIndex{0}; nIndex < this->nMaxConcurrentFrameCount; ++nIndex)
			if (vkCreateSemaphore(this->pDevice->vulkanDevice(), &vkSemaphoreCreateInfo, nullptr, &this->sAfterRenderingSemaphoreList[nIndex]) != VkResult::VK_SUCCESS ||
				vkCreateSemaphore(this->pDevice->vulkanDevice(), &vkSemaphoreCreateInfo, nullptr, &this->sAfterOwnershipTransferredSemaphoreList[nIndex]) != VkResult::VK_SUCCESS ||
				vkCreateSemaphore(this->pDevice->vulkanDevice(), &vkSemaphoreCreateInfo, nullptr, &this->sAfterPresentationSemaphoreList[nIndex]) != VkResult::VK_SUCCESS ||
				vkCreateFence(this->pDevice->vulkanDevice(), &vkFenceCreateInfo, nullptr, &this->sFenceList[nIndex]) != VkResult::VK_SUCCESS)
				throw std::runtime_error{"unable to create synchronization object"};
	}

	std::tuple<VkCommandBuffer, VkCommandBuffer, VkSemaphore, VkSemaphore, VkSemaphore, VkFence> Synchronizer::sync()
	{
		auto sResult{std::make_tuple(
			this->sGraphicsCommandBufferList[this->nFrameIndex],
			this->sPresentCommandBufferList[this->nFrameIndex],
			this->sAfterRenderingSemaphoreList[this->nFrameIndex],
			this->sAfterOwnershipTransferredSemaphoreList[this->nFrameIndex],
			this->sAfterPresentationSemaphoreList[this->nFrameIndex],
			this->sFenceList[this->nFrameIndex]
		)};

		this->nFrameIndex = (this->nFrameIndex + 1) % this->nMaxConcurrentFrameCount;

		return sResult;
	}
}