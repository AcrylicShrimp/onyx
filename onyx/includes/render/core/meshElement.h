
#ifndef _ONYX_RENDER_CORE_MESHELEMENT_H

#define _ONYX_RENDER_CORE_MESHELEMENT_H

#include "onyx/includes/core/vulkan.h"
#include "onyx/includes/render/helper.h"

#include <cstddef>
#include <cstdint>

namespace onyx::render::core {
	class MeshElement final {
	public:
		const VkFormat	   eFormat;
		const VkDeviceSize nSize;
		const void *const  pData;

	public:
		MeshElement(VkFormat eFormat, VkDeviceSize nSize, const void *pData);
		MeshElement(const MeshElement &sRhs) noexcept = default;
		~MeshElement() noexcept						  = default;

	public:
		MeshElement &operator=(const MeshElement &sRhs) noexcept = delete;

	public:
		std::uint32_t stride() const noexcept
		{
			return sizeFormat(this->eFormat);
		}
		std::uint32_t count() const noexcept
		{
			return static_cast<std::uint32_t>(this->nSize / this->stride());
		}
	};
}	 // namespace onyx::render::core

#endif