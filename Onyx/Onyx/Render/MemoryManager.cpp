
/*
	2019.10.13
	Created by AcrylicShrimp.
*/

#include "MemoryManager.h"

#include "./Context.h"

namespace Onyx::Render
{
	MemoryManager::MemoryManager(Context *pContext) :
		SubContextManager{pContext}
	{
		//Empty.
	}

	VkDeviceMemory MemoryManager::allocateBuffer(
		VkBuffer vkBuffer,
		VkMemoryPropertyFlags vkMemPropFlags) const
	{
		VkMemoryRequirements vkMemReq;
		vkGetBufferMemoryRequirements(this->pContext->device().vulkanDevice(), vkBuffer, &vkMemReq);
		
		return this->__allocateDeviceMemory(vkMemReq, vkMemPropFlags);
	}

	VkDeviceMemory MemoryManager::allocateImage(
		VkImage vkImage,
		VkMemoryPropertyFlags vkMemPropFlags) const
	{
		VkMemoryRequirements vkMemReq;
		vkGetImageMemoryRequirements(this->pContext->device().vulkanDevice(), vkImage, &vkMemReq);

		return this->__allocateDeviceMemory(vkMemReq, vkMemPropFlags);
	}

	VkDeviceMemory MemoryManager::__allocateDeviceMemory(
		VkMemoryRequirements vkMemReq,
		VkMemoryPropertyFlags vkMemPropFlags) const
	{
		std::optional<std::uint32_t> sMemTypeIndex;
		const auto &vkMemProp{this->pContext->device().physicalDeviceAttribute().vkMemoryProperty};

		for (std::uint32_t nIndex{0}; nIndex < vkMemProp.memoryTypeCount; ++nIndex)
			if (vkMemReq.memoryTypeBits & (1 << nIndex) && (vkMemProp.memoryTypes[nIndex].propertyFlags & vkMemPropFlags) == vkMemPropFlags)
				sMemTypeIndex = nIndex;

		if (!sMemTypeIndex)
			throw std::runtime_error{"unable to find suitable memory type"};

		VkMemoryAllocateInfo vkMemoryAllocateInfo
		{
			VkStructureType::VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO,
			nullptr,
			vkMemReq.size,
			*sMemTypeIndex
		};

		VkDeviceMemory vkDeviceMem;

		if (vkAllocateMemory(this->pContext->device().vulkanDevice(), &vkMemoryAllocateInfo, nullptr, &vkDeviceMem) != VkResult::VK_SUCCESS)
			throw std::runtime_error{"unable to allocate memory"};

		return vkDeviceMem;
	}
}