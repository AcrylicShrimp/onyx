
#ifndef _ONYX_RENDER_CORE_MESH_H

#define _ONYX_RENDER_CORE_MESH_H

#include "onyx/includes/core/vulkan.h"
#include "onyx/includes/render/core/meshElement.h"

#include <cstdint>
#include <tuple>
#include <vector>

namespace onyx::core {
	class Context;
}

namespace onyx::render::core {
	class Mesh final {
	public:
		const ::onyx::core::Context *const pContext;

	private:
		VkBuffer										 sBuffer;
		VkDeviceMemory									 sDeviceMemory;
		std::uint32_t									 nCount;
		std::uint32_t									 nStride;
		std::vector<std::tuple<VkFormat, std::uint32_t>> sFormatOffsetVec;

	public:
		Mesh(const ::onyx::core::Context *pContext, std::vector<MeshElement> sElementVec);
		Mesh(const Mesh &sRhs) = delete;
		~Mesh() noexcept;

	public:
		Mesh &operator=(const Mesh &sRhs) = delete;

	public:
		VkBuffer buffer() const noexcept
		{
			return this->sBuffer;
		}
		std::uint32_t count() const noexcept
		{
			return this->nCount;
		}
		std::uint32_t stride() const noexcept
		{
			return this->nStride;
		}
		const std::vector<std::tuple<VkFormat, std::uint32_t>> &formatOffsetVec() const noexcept
		{
			return this->sFormatOffsetVec;
		}
	};
}	 // namespace onyx::render::core

#endif