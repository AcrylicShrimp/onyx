
/*
	2019.05.19
	Created by AcrylicShrimp.
*/

#ifndef _CLASS_ONYX_RENDER_MESH_H

#define _CLASS_ONYX_RENDER_MESH_H

#include "../Vulkan.h"
#include "./MeshLayout.h"

#include <cassert>
#include <cstddef>
#include <cstdint>
#include <cstring>
#include <optional>
#include <utility>

namespace Onyx::Render
{
	class MeshManager;

	class Mesh
	{
	public:
		MeshManager *const pMeshManager;
		const MeshLayout sMeshLayout;

	private:
		std::uint32_t nLength;
		VkBuffer vkBuffer;
		VkDeviceMemory vkDeviceMemory;
		
	public:
		Mesh(MeshManager *pMeshManager, MeshLayout &&sMeshLayout, std::uint32_t nLength, VkDeviceSize nSize, void *pData);
		Mesh(const Mesh &sSrc) = delete;
		~Mesh();
		
	public:
		Mesh &operator=(const Mesh &sSrc) = delete;
		
	public:
		inline VkBuffer vulkanBuffer() const noexcept;
		inline std::uint32_t length() const;
	};

	inline VkBuffer Mesh::vulkanBuffer() const noexcept
	{
		return this->vkBuffer;
	}

	inline std::uint32_t Mesh::length() const
	{
		return this->nLength;
	}
}

#endif