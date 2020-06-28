
#include "onyx/includes/render/core/mesh.h"

#include "onyx/includes/core/context.h"
#include "onyx/includes/core/deviceInfo.h"
#include "onyx/includes/core/deviceManager.h"

#include <cstddef>
#include <cstring>
#include <stdexcept>

namespace onyx::render::core {
	Mesh::Mesh(const ::onyx::core::Context *pContext, std::vector<MeshElement> sElementVec) :
		pContext{pContext},
		nCount{0},
		nStride{0}
	{
		this->sFormatOffsetVec.reserve(sElementVec.size());

		VkDeviceSize nSize{0};

		if (!sElementVec.empty()) this->nCount = sElementVec.front().count();

		for (const auto &sElement: sElementVec) {
			if (this->nCount != sElement.count()) throw std::runtime_error{"the count of mesh elements are not match"};

			this->sFormatOffsetVec.emplace_back(sElement.eFormat, this->nStride);
			this->nStride += sElement.stride();
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

		this->sDeviceMemory = this->pContext->deviceMgr().allocateBufferMemory(
			::onyx::core::DeviceMemoryType::HostShared,
			this->sBuffer);

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

		for (std::size_t nIndex{0}, nMaxIndex{sElementVec.size()}; nIndex < nMaxIndex; ++nIndex) {
			auto  nElementStride{sElementVec[nIndex].stride()};
			auto *pSrc{pBuffer + std::get<1>(this->sFormatOffsetVec[nIndex])};

			for (std::uint32_t nCount{0}, nMaxCount{sElementVec[nIndex].count()}; nCount < nMaxCount; ++nCount) {
				std::memcpy(
					pSrc,
					reinterpret_cast<const unsigned char *>(sElementVec[nIndex].pData) + nElementStride * nCount,
					nElementStride);
				pSrc += this->nStride;
			}
		}

		vkUnmapMemory(this->pContext->deviceMgr().vulkanDevice(), this->sDeviceMemory);
	}

	Mesh::~Mesh() noexcept
	{
		vkDestroyBuffer(this->pContext->deviceMgr().vulkanDevice(), this->sBuffer, nullptr);
		vkFreeMemory(this->pContext->deviceMgr().vulkanDevice(), this->sDeviceMemory, nullptr);
	}
}	 // namespace onyx::render::core