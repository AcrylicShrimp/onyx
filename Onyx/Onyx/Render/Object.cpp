
/*
	2019.07.02
	Created by AcrylicShrimp.
*/

#include "Object.h"

#include "Context.h"

namespace Onyx::Render
{
	Object::Object(Context *pContext, Mesh *pMesh, Shader *pShader, Transform::Mat44f sMatrix) :
		pContext{pContext},
		pMaterial{std::make_unique<Material>(pContext, pMesh, pShader)}
	{
		VkBufferCreateInfo vkBufferCreateInfo
		{
			VkStructureType::VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO,
			nullptr,
			0,
			sizeof(float) * 16,
			VkBufferUsageFlagBits::VK_BUFFER_USAGE_VERTEX_BUFFER_BIT,
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

		if (vkAllocateMemory(this->pContext->device().vulkanDevice(), &vkMemoryAllocateInfo, nullptr, &this->vkDeviceMemory) != VkResult::VK_SUCCESS)
			throw std::runtime_error{"unable to allocate memory"};

		if (vkBindBufferMemory(this->pContext->device().vulkanDevice(), this->vkBuffer, this->vkDeviceMemory, 0) != VkResult::VK_SUCCESS)
			throw std::runtime_error{"unable to bind buffer memory"};

		void *pBufferData;

		if (vkMapMemory(this->pContext->device().vulkanDevice(), this->vkDeviceMemory, 0, vkBufferMemoryReq.size, 0, &pBufferData) != VkResult::VK_SUCCESS)
			throw std::runtime_error{"unable to map buffer"};

		std::memcpy(pBufferData, reinterpret_cast<const float *>(&sMatrix), static_cast<std::size_t>(sizeof(float) * 16));

		vkUnmapMemory(this->pContext->device().vulkanDevice(), this->vkDeviceMemory);
	}

	Object::~Object()
	{
		vkDestroyBuffer(this->pContext->device().vulkanDevice(), this->vkBuffer, nullptr);
		vkFreeMemory(this->pContext->device().vulkanDevice(), this->vkDeviceMemory, nullptr);
	}
}