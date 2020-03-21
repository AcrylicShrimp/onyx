
#include "onyx/includes/core/synchronizationManager.h"

#include "onyx/includes/core/context.h"

namespace onyx::core {
	SynchronizationManager::SynchronizationManager(Context *pContext, std::size_t nMaxConcurrentFrameCount) :
		PerContextManager{pContext},
		nMaxConcurrentFrameCount{nMaxConcurrentFrameCount},
		nFrameIndex{0}
	{
		// Empty.
	}

	SynchronizationManager::~SynchronizationManager() noexcept
	{
		// Empty.
	}

	void SynchronizationManager::init(const DeviceInfo &sDevice)
	{
		VkCommandPoolCreateInfo sGraphicsCommandPoolCreateInfo{
			VkStructureType::VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO,
			nullptr,
			VkCommandPoolCreateFlagBits::VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT,
			this->pContext->deviceMgr().graphicsQueueFamilyIndex()};
		VkCommandPoolCreateInfo sPresentCommandPoolCreateInfo{
			VkStructureType::VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO,
			nullptr,
			VkCommandPoolCreateFlagBits::VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT,
			this->pContext->deviceMgr().presentQueueFamilyIndex()};
		VkCommandPoolCreateInfo sOnetimeCommandPoolCreateInfo{
			VkStructureType::VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO,
			nullptr,
			VkCommandPoolCreateFlagBits::VK_COMMAND_POOL_CREATE_TRANSIENT_BIT
				| VkCommandPoolCreateFlagBits::VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT,
			this->pContext->deviceMgr().graphicsQueueFamilyIndex()};

		if (vkCreateCommandPool(
				this->pContext->deviceMgr().vulkanDevice(),
				&sGraphicsCommandPoolCreateInfo,
				nullptr,
				&this->sGraphicsCommandPool)
				!= VkResult::VK_SUCCESS
			|| vkCreateCommandPool(
				   this->pContext->deviceMgr().vulkanDevice(),
				   &sPresentCommandPoolCreateInfo,
				   nullptr,
				   &this->sPresentCommandPool)
				   != VkResult::VK_SUCCESS
			|| vkCreateCommandPool(
				   this->pContext->deviceMgr().vulkanDevice(),
				   &sOnetimeCommandPoolCreateInfo,
				   nullptr,
				   &this->sOnetimeCommandPool)
				   != VkResult::VK_SUCCESS)
			throw std::runtime_error{"unable to create command pool"};

		this->sGraphicsCommandBufferList.resize(this->nMaxConcurrentFrameCount);
		this->sPresentCommandBufferList.resize(this->nMaxConcurrentFrameCount);
		this->sAfterRenderingSemaphoreList.resize(this->nMaxConcurrentFrameCount);
		this->sAfterOwnershipTransferredSemaphoreList.resize(this->nMaxConcurrentFrameCount);
		this->sAfterPresentationSemaphoreList.resize(this->nMaxConcurrentFrameCount);
		this->sFenceList.resize(this->nMaxConcurrentFrameCount);

		VkCommandBufferAllocateInfo vkGraphicsCommandBufferAllocateInfo{
			VkStructureType::VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO,
			nullptr,
			this->sGraphicsCommandPool,
			VkCommandBufferLevel::VK_COMMAND_BUFFER_LEVEL_PRIMARY,
			static_cast<std::uint32_t>(this->nMaxConcurrentFrameCount)};
		VkCommandBufferAllocateInfo vkPresentCommandBufferAllocateInfo{
			VkStructureType::VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO,
			nullptr,
			this->sPresentCommandPool,
			VkCommandBufferLevel::VK_COMMAND_BUFFER_LEVEL_PRIMARY,
			static_cast<std::uint32_t>(this->nMaxConcurrentFrameCount)};

		if (vkAllocateCommandBuffers(
				this->pContext->deviceMgr().vulkanDevice(),
				&vkGraphicsCommandBufferAllocateInfo,
				this->sGraphicsCommandBufferList.data())
				!= VkResult::VK_SUCCESS
			|| vkAllocateCommandBuffers(
				   this->pContext->deviceMgr().vulkanDevice(),
				   &vkPresentCommandBufferAllocateInfo,
				   this->sPresentCommandBufferList.data())
				   != VkResult::VK_SUCCESS)
			throw std::runtime_error{"unable to allocate command buffer"};

		VkSemaphoreCreateInfo vkSemaphoreCreateInfo{VkStructureType::VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO,
													nullptr,
													0};
		VkFenceCreateInfo	  vkFenceCreateInfo{VkStructureType::VK_STRUCTURE_TYPE_FENCE_CREATE_INFO,
											nullptr,
											VkFenceCreateFlagBits::VK_FENCE_CREATE_SIGNALED_BIT};

		for (std::size_t nIndex{0}; nIndex < this->nMaxConcurrentFrameCount; ++nIndex)
			if (vkCreateSemaphore(
					this->pContext->deviceMgr().vulkanDevice(),
					&vkSemaphoreCreateInfo,
					nullptr,
					&this->sAfterRenderingSemaphoreList[nIndex])
					!= VkResult::VK_SUCCESS
				|| vkCreateSemaphore(
					   this->pContext->deviceMgr().vulkanDevice(),
					   &vkSemaphoreCreateInfo,
					   nullptr,
					   &this->sAfterOwnershipTransferredSemaphoreList[nIndex])
					   != VkResult::VK_SUCCESS
				|| vkCreateSemaphore(
					   this->pContext->deviceMgr().vulkanDevice(),
					   &vkSemaphoreCreateInfo,
					   nullptr,
					   &this->sAfterPresentationSemaphoreList[nIndex])
					   != VkResult::VK_SUCCESS
				|| vkCreateFence(
					   this->pContext->deviceMgr().vulkanDevice(),
					   &vkFenceCreateInfo,
					   nullptr,
					   &this->sFenceList[nIndex])
					   != VkResult::VK_SUCCESS)
				throw std::runtime_error{"unable to create synchronization object"};
	}

	void SynchronizationManager::fin()
	{
		// Empty.
	}

	std::tuple<VkCommandBuffer, VkCommandBuffer, VkSemaphore, VkSemaphore, VkSemaphore, VkFence>
		SynchronizationManager::nextSynchronizationObject()
	{
		auto sResult{std::make_tuple(
			this->sGraphicsCommandBufferList[this->nFrameIndex],
			this->sPresentCommandBufferList[this->nFrameIndex],
			this->sAfterRenderingSemaphoreList[this->nFrameIndex],
			this->sAfterOwnershipTransferredSemaphoreList[this->nFrameIndex],
			this->sAfterPresentationSemaphoreList[this->nFrameIndex],
			this->sFenceList[this->nFrameIndex])};

		this->nFrameIndex = (this->nFrameIndex + 1) % this->nMaxConcurrentFrameCount;

		return sResult;
	}
}	 // namespace onyx::core