
#include "onyx/includes/render/core/mesh.h"

#include "onyx/includes/core/context.h"
#include "onyx/includes/core/deviceInfo.h"
#include "onyx/includes/core/deviceManager.h"

#include <cstring>

namespace onyx::render::core {
	Mesh::Mesh(const ::onyx::core::Context *pContext, std::vector<MeshElement> sElementVec) : pContext{pContext}
	{
		this->sOffsetFormatVec.reserve(sElementVec.size());

		VkDeviceSize nSize{0};

		for (const auto &sElement: sElementVec) {
			this->sOffsetFormatVec.emplace_back(nSize, sElement.eFormat);
			nSize += sElement.nSize;
		}

		VkBufferCreateInfo sBufferCreateInfo{
			VkStructureType::VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO,
			nullptr,
			0,
			nSize,
			VkBufferUsageFlagBits::VK_BUFFER_USAGE_VERTEX_BUFFER_BIT,
			VkSharingMode::VK_SHARING_MODE_EXCLUSIVE,
			0,
			nullptr};

		if (vkCreateBuffer(this->pContext->deviceMgr().vulkanDevice(), &sBufferCreateInfo, nullptr, &this->sBuffer)
			!= VkResult::VK_SUCCESS)
			throw std::runtime_error{"unable to create buffer"};

		this->sDeviceMemory
			= this->pContext->deviceMgr().allocateBufferMemory(::onyx::core::DeviceMemoryType::Local, this->sBuffer);

		if (vkBindBufferMemory(this->pContext->deviceMgr().vulkanDevice(), this->sBuffer, this->sDeviceMemory, 0)
			!= VkResult::VK_SUCCESS)
			throw std::runtime_error{"unable to bind buffer memory"};

		unsigned char *pBuffer;

		if (vkMapMemory(
				this->pContext->deviceMgr().vulkanDevice(),
				this->sDeviceMemory,
				0,
				VK_WHOLE_SIZE,
				0,
				reinterpret_cast<void **>(&pBuffer))
			!= VkResult::VK_SUCCESS)
			throw std::runtime_error{"unable to map buffer"};

		for (const auto &sElement: sElementVec) {
			std::memcpy(pBuffer, sElement.pData, sElement.nSize);
			pBuffer += sElement.nSize;
		}

		vkUnmapMemory(this->pContext->deviceMgr().vulkanDevice(), this->sDeviceMemory);
	}

	Mesh::~Mesh() noexcept
	{
		vkDestroyBuffer(this->pContext->deviceMgr().vulkanDevice(), this->sBuffer, nullptr);
		vkFreeMemory(this->pContext->deviceMgr().vulkanDevice(), this->sDeviceMemory, nullptr);
	}
}	 // namespace onyx::render::core