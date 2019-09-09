
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
	class MeshLayout
	{
	private:
		std::unordered_map<std::uint32_t, VkFormat> sFormatMap;
		
	public:
		MeshLayout() = default;
		MeshLayout(const MeshLayout &sSrc) = default;
		MeshLayout(MeshLayout &&sSrc) noexcept = default;
		~MeshLayout() noexcept = default;
		
	public:
		MeshLayout &operator=(const MeshLayout &sSrc) = default;
		MeshLayout &operator=(MeshLayout &&sSrc) noexcept = default;
		
	public:
		void specifyFormat(std::uint32_t nOffset, VkFormat vkFormat, std::size_t nCount = 1);
		std::uint32_t calcOffset() const;
		std::uint32_t calcStride() const;

	public:
		static bool isSubsetOf(const MeshLayout &sMeshLayout, const MeshLayout &sMeshLayoutSubset);
		static std::uint32_t formatSize(VkFormat vkFormat) noexcept;
	};
}

#endif