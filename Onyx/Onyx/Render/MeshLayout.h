
/*
	2019.08.27
	Created by AcrylicShrimp.
*/

#ifndef _CLASS_ONYX_RENDER_MESHLAYOUT_H

#define _CLASS_ONYX_RENDER_MESHLAYOUT_H

#include "../Vulkan.h"

#include <algorithm>
#include <cstdint>
#include <stdexcept>
#include <unordered_map>

namespace Onyx::Render
{
	class MeshLayout final
	{
	private:
		std::unordered_map<std::uint32_t, VkFormat> sLayoutMap;
		
	public:
		MeshLayout() = default;
		MeshLayout(const MeshLayout &sSrc) = default;
		MeshLayout(MeshLayout &&sSrc) noexcept = default;
		~MeshLayout() noexcept = default;
		
	public:
		MeshLayout &operator=(const MeshLayout &sSrc) = default;
		MeshLayout &operator=(MeshLayout &&sSrc) noexcept = default;
		
	public:
		inline const std::unordered_map<std::uint32_t, VkFormat> &layoutMap() const noexcept;
		void specifyLayout(std::uint32_t nOffset, VkFormat vkFormat);
		std::uint32_t calcOffset() const;
		std::uint32_t calcStride() const;

	public:
		static bool isSubsetOf(const MeshLayout &sMeshLayout, const MeshLayout &sMeshLayoutSubset);
		static std::uint32_t formatSize(VkFormat vkFormat) noexcept;
	};

	inline const std::unordered_map<std::uint32_t, VkFormat> &MeshLayout::layoutMap() const noexcept
	{
		return this->sLayoutMap;
	}
}

#endif