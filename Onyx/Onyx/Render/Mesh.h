
/*
	2019.05.19
	Created by AcrylicShrimp.
*/

#ifndef _CLASS_ONYX_RENDER_MESH_H

#define _CLASS_ONYX_RENDER_MESH_H

#include "../Vulkan.h"

#include <cassert>
#include <cstddef>
#include <cstdint>
#include <cstring>
#include <optional>
#include <string>
#include <tuple>
#include <unordered_map>
#include <utility>
#include <vector>

namespace Onyx::Render
{
	class MeshManager;

	class Mesh
	{
	public:
		struct Data
		{
			VkFormat vkFormat;
			std::uint32_t vkOffset;
		};

	public:
		MeshManager *const pMeshManager;

	private:
		VkDeviceMemory vkDeviceMemory;
		VkBuffer vkBuffer;
		std::uint32_t nStride;
		std::uint32_t nLength;
		std::unordered_map<std::string, Data> sDataMap;
		
	public:
		Mesh(MeshManager *pMeshManager, std::uint32_t nStride, std::uint32_t nLength, const std::vector<std::tuple<std::string, Data>> &sDataList, VkDeviceSize nSize, void *pData);
		Mesh(const Mesh &sSrc) = delete;
		~Mesh();
		
	public:
		Mesh &operator=(const Mesh &sSrc) = delete;
		Data *operator[](const std::string &sDataName);
		const Data *operator[](const std::string &sDataName) const;
		
	public:
		inline VkBuffer vulkanBuffer() const noexcept;
		inline std::uint32_t stride() const;
		inline std::uint32_t length() const;
	};

	inline VkBuffer Mesh::vulkanBuffer() const noexcept
	{
		return this->vkBuffer;
	}

	inline std::uint32_t Mesh::stride() const
	{
		return this->nStride;
	}

	inline std::uint32_t Mesh::length() const
	{
		return this->nLength;
	}
}

#endif