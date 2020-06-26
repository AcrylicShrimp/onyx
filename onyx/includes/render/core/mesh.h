
#ifndef _ONYX_RENDER_CORE_MESH_H

#define _ONYX_RENDER_CORE_MESH_H

#include "onyx/includes/core/vulkan.h"
#include "onyx/includes/render/core/meshElement.h"

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
		VkBuffer										sBuffer;
		VkDeviceMemory									sDeviceMemory;
		std::vector<std::tuple<VkDeviceSize, VkFormat>> sOffsetFormatVec;

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
		const std::vector<std::tuple<VkDeviceSize, VkFormat>> &offsetFormatVec() const noexcept
		{
			return this->sOffsetFormatVec;
		}
	};
}	 // namespace onyx::render::core

#endif