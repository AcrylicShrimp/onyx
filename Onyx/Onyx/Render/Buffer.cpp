
/*
	2019.05.18
	Created by AcrylicShrimp.
*/

#include "Buffer.h"

#include "./Context.h"

namespace Onyx::Render
{
	Buffer::Buffer(Context *pContext, Usage eUsage, VkDeviceSize nSize) :
		pContext{pContext},
		eUsage{eUsage},
		nSize{nSize}
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

		this->vkDeviceMemory = this->pContext->memoryMgr().allocateBuffer(this->vkBuffer, VkMemoryPropertyFlagBits::VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VkMemoryPropertyFlagBits::VK_MEMORY_PROPERTY_HOST_COHERENT_BIT);

		if (vkBindBufferMemory(this->pContext->device().vulkanDevice(), this->vkBuffer, this->vkDeviceMemory, 0) != VkResult::VK_SUCCESS)
			throw std::runtime_error{"unable to bind buffer memory"};
	}

	//Buffer::Buffer(const Buffer &sSrc)
	//{
	//	/*
	//		TODO : Place the implementation of the copy constructor here.
	//	*/
	//	
	//}
	
	Buffer::Buffer(Buffer &&sSrc) :
		pContext{sSrc.pContext},
		eUsage{sSrc.eUsage},
		vkBuffer{sSrc.vkBuffer},
		vkDeviceMemory{sSrc.vkDeviceMemory},
		nSize{sSrc.nSize}
	{
		sSrc.vkBuffer = VK_NULL_HANDLE;
		sSrc.vkDeviceMemory = VK_NULL_HANDLE;
	}

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
	
	Buffer &Buffer::operator=(Buffer &&sSrc)
	{
		if (&sSrc == this)
			return *this;

		if (this->pContext != sSrc.pContext)
			throw std::runtime_error{"different context instance"};

		if (this->eUsage != sSrc.eUsage)
			throw std::runtime_error{"different usage"};
		
		vkDestroyBuffer(this->pContext->device().vulkanDevice(), this->vkBuffer, nullptr);
		vkFreeMemory(this->pContext->device().vulkanDevice(), this->vkDeviceMemory, nullptr);
		
		this->vkBuffer = sSrc.vkBuffer;
		this->vkDeviceMemory = sSrc.vkDeviceMemory;
		this->nSize = sSrc.nSize;

		sSrc.vkBuffer = VK_NULL_HANDLE;
		sSrc.vkDeviceMemory = VK_NULL_HANDLE;

		return *this;
	}

	void Buffer::map(std::function<void(void *)> fMapFunction)
	{
		void *pData;

		if (vkMapMemory(this->pContext->device().vulkanDevice(), this->vkDeviceMemory, 0, VK_WHOLE_SIZE, 0, &pData) != VkResult::VK_SUCCESS)
			throw std::runtime_error{"unable to map buffer"};

		fMapFunction(pData);

		vkUnmapMemory(this->pContext->device().vulkanDevice(), this->vkDeviceMemory);
	}

	void Buffer::resize(VkDeviceSize nSize)
	{
		vkDestroyBuffer(this->pContext->device().vulkanDevice(), this->vkBuffer, nullptr);
		vkFreeMemory(this->pContext->device().vulkanDevice(), this->vkDeviceMemory, nullptr);

		VkBufferCreateInfo vkBufferCreateInfo
		{
			VkStructureType::VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO,
			nullptr,
			0,
			nSize,
			static_cast<VkBufferUsageFlags>(this->eUsage),
			VkSharingMode::VK_SHARING_MODE_EXCLUSIVE,
			0,
			nullptr
		};

		if (vkCreateBuffer(this->pContext->device().vulkanDevice(), &vkBufferCreateInfo, nullptr, &this->vkBuffer) != VkResult::VK_SUCCESS)
			throw std::runtime_error{"unable to create buffer"};

		this->vkDeviceMemory = this->pContext->memoryMgr().allocateBuffer(this->vkBuffer, VkMemoryPropertyFlagBits::VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VkMemoryPropertyFlagBits::VK_MEMORY_PROPERTY_HOST_COHERENT_BIT);

		if (vkBindBufferMemory(this->pContext->device().vulkanDevice(), this->vkBuffer, this->vkDeviceMemory, 0) != VkResult::VK_SUCCESS)
			throw std::runtime_error{"unable to bind buffer memory"};

		this->nSize = nSize;
	}
}