
/*
	2019.05.19
	Created by AcrylicShrimp.
*/

#include "Mesh.h"

#include "./Context.h"
#include "./MeshManager.h"

namespace Onyx::Render
{
	Mesh::Mesh(MeshManager *pMeshManager, MeshLayout &&sMeshLayout, std::uint32_t nLength, VkDeviceSize nSize, void *pData) :
		pMeshManager{pMeshManager},
		sMeshLayout{std::move(sMeshLayout)},
		nLength{nLength}
	{
		assert(this->pMeshManager);

		VkBufferCreateInfo vkBufferCreateInfo
		{
			VkStructureType::VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO,
			nullptr,
			0,
			nSize,
			VkBufferUsageFlagBits::VK_BUFFER_USAGE_VERTEX_BUFFER_BIT,
			VkSharingMode::VK_SHARING_MODE_EXCLUSIVE,
			0,
			nullptr
		};

		if (vkCreateBuffer(this->pMeshManager->pContext->device().vulkanDevice(), &vkBufferCreateInfo, nullptr, &this->vkBuffer) != VkResult::VK_SUCCESS)
			throw std::runtime_error{"unable to create buffer"};

		VkMemoryRequirements vkBufferMemoryReq;
		vkGetBufferMemoryRequirements(this->pMeshManager->pContext->device().vulkanDevice(), this->vkBuffer, &vkBufferMemoryReq);

		std::optional<std::uint32_t> sMemoryTypeIndex;
		const auto &vkMemoryProperty{this->pMeshManager->pContext->device().physicalDeviceAttribute().vkMemoryProperty};

		VkMemoryPropertyFlags vkMemoryPropertyFlag{VkMemoryPropertyFlagBits::VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VkMemoryPropertyFlagBits::VK_MEMORY_PROPERTY_HOST_COHERENT_BIT};

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

		if (vkAllocateMemory(this->pMeshManager->pContext->device().vulkanDevice(), &vkMemoryAllocateInfo, nullptr, &this->vkDeviceMemory) != VkResult::VK_SUCCESS)
			throw std::runtime_error{"unable to allocate memory"};

		if (vkBindBufferMemory(this->pMeshManager->pContext->device().vulkanDevice(), this->vkBuffer, this->vkDeviceMemory, 0) != VkResult::VK_SUCCESS)
			throw std::runtime_error{"unable to bind buffer memory"};

		void *pBufferData;

		if (vkMapMemory(this->pMeshManager->pContext->device().vulkanDevice(), this->vkDeviceMemory, 0, vkBufferMemoryReq.size, 0, &pBufferData) != VkResult::VK_SUCCESS)
			throw std::runtime_error{"unable to map buffer"};

		std::memcpy(pBufferData, pData, static_cast<std::size_t>(nSize));

		vkUnmapMemory(this->pMeshManager->pContext->device().vulkanDevice(), this->vkDeviceMemory);
	}
	
	Mesh::~Mesh()
	{
		vkDestroyBuffer(this->pMeshManager->pContext->device().vulkanDevice(), this->vkBuffer, nullptr);
		vkFreeMemory(this->pMeshManager->pContext->device().vulkanDevice(), this->vkDeviceMemory, nullptr);
	}
}