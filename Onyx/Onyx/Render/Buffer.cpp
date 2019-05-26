
/*
	2019.05.18
	Created by AcrylicShrimp.
*/

#include "Buffer.h"

#include "./Context.h"

namespace Onyx::Render
{
	Buffer::Buffer(Context *pContext, Usage eUsage, VkDeviceSize nSize) :
		pContext{pContext}
	{
		assert(this->pContext);

		VkBufferCreateInfo vkBufferCreateInfo
		{
			VkStructureType::VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO,
			nullptr,
			0,
			nSize,
			static_cast<VkBufferUsageFlags>(eUsage),
			VkSharingMode::VK_SHARING_MODE_EXCLUSIVE,
			0,
			nullptr
		};

		if (vkCreateBuffer(this->pContext->device().vulkanDevice(), &vkBufferCreateInfo, nullptr, &this->vkBuffer) != VkResult::VK_SUCCESS)
			throw std::runtime_error{"unable to create buffer"};

		VkMemoryRequirements vkBufferMemoryReq;
		vkGetBufferMemoryRequirements(this->pContext->device().vulkanDevice(), this->vkBuffer, &vkBufferMemoryReq);

		std::optional<std::uint32_t> sMemoryTypeIndex;
		const auto &vkMemoryProperty{this->pContext->device().physicalDeviceAttribute().vkMemoryProperty};

		VkMemoryPropertyFlags vkMemoryPropertyFlag{VkMemoryPropertyFlagBits::VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT};

		for (std::uint32_t nIndex{0}; nIndex < vkMemoryProperty.memoryTypeCount; ++nIndex)
			if (vkBufferMemoryReq.memoryTypeBits & (1 << nIndex) && (vkMemoryProperty.memoryTypes[nIndex].propertyFlags & vkMemoryPropertyFlag) == vkMemoryPropertyFlag)
				sMemoryTypeIndex = nIndex;

		if (!sMemoryTypeIndex)
			throw std::runtime_error{"unable to find suitable memory type"};

		VkMemoryAllocateInfo vkMemoryAllocateInfo
		{
			VkStructureType::VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO,
			nullptr,
			vkBufferMemoryReq.size,
			*sMemoryTypeIndex
		};

		if (vkAllocateMemory(this->pContext->device().vulkanDevice(), &vkMemoryAllocateInfo, nullptr, &this->vkDeviceMemory) != VkResult::VK_SUCCESS)
			throw std::runtime_error{"unable to allocate memory"};

		if (vkBindBufferMemory(this->pContext->device().vulkanDevice(), this->vkBuffer, this->vkDeviceMemory, 0) != VkResult::VK_SUCCESS)
			throw std::runtime_error{"unable to bind buffer memory"};

		this->nSize = vkBufferCreateInfo.size;
		this->nAllocationSize = vkMemoryAllocateInfo.allocationSize;
	}
	
	//Buffer::Buffer(const Buffer &sSrc)
	//{
	//	/*
	//		TODO : Place the implementation of the copy constructor here.
	//	*/
	//	
	//}
	//
	//Buffer::Buffer(Buffer &&sSrc)
	//{
	//	/*
	//		TODO : Place the implementation of the move constructor here.
	//	*/
	//	
	//}
	
	Buffer::~Buffer()
	{
		vkDestroyBuffer(this->pContext->device().vulkanDevice(), this->vkBuffer, nullptr);
		vkFreeMemory(this->pContext->device().vulkanDevice(), this->vkDeviceMemory, nullptr);
	}
	
	//Buffer &Buffer::operator=(const Buffer &sSrc)
	//{
	//	if (&sSrc == this)
	//		return *this;
	//	
	//	/*
	//		TODO : Place the implementation of the copy assignment operator here.
	//	*/
	//	
	//	
	//	return *this;
	//}
	//
	//Buffer &Buffer::operator=(Buffer &&sSrc)
	//{
	//	if (&sSrc == this)
	//		return *this;
	//	
	//	/*
	//		TODO : Place the implementation of the move assignment operator here.
	//	*/
	//	
	//	
	//	return *this;
	//}

	void Buffer::map(std::function<void(void *)> fMapFunction)
	{
		void *pData;
		
		if (vkMapMemory(this->pContext->device().vulkanDevice(), this->vkDeviceMemory, 0, static_cast<VkDeviceSize>(this->nSize), 0, &pData) != VkResult::VK_SUCCESS)
			throw std::runtime_error{"unable to map buffer"};

		fMapFunction(pData);

		vkUnmapMemory(this->pContext->device().vulkanDevice(), this->vkDeviceMemory);

		VkMappedMemoryRange vkMappedMemoryRange
		{
			VkStructureType::VK_STRUCTURE_TYPE_MAPPED_MEMORY_RANGE,
			nullptr,
			this->vkDeviceMemory,
			0,
			this->nAllocationSize
		};

		if (vkFlushMappedMemoryRanges(this->pContext->device().vulkanDevice(), 1, &vkMappedMemoryRange) != VkResult::VK_SUCCESS ||
			vkInvalidateMappedMemoryRanges(this->pContext->device().vulkanDevice(), 1, &vkMappedMemoryRange) != VkResult::VK_SUCCESS)
			throw std::runtime_error{"unable to flush memory"};
	}
}