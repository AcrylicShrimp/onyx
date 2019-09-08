
/*
	2019.07.13
	Created by AcrylicShrimp.
*/

#ifndef _CLASS_ONYX_RENDER_MESHLAYOUT_H

#define _CLASS_ONYX_RENDER_MESHLAYOUT_H

#include "../Vulkan.h"

#include <cstdint>
#include <map>
#include <vector>
#include <utility>

namespace Onyx::Render
{
	class MeshLayout
	{
	public:
		const std::uint32_t nStride;
		const std::map<std::uint32_t, VkFormat> sOffsetMap;
		
	public:
		MeshLayout(std::uint32_t nStride, const std::vector<std::pair<std::uint32_t, VkFormat>> &sOffsetList);
		MeshLayout(const MeshLayout &sSrc) = default;
		MeshLayout(MeshLayout &&sSrc) noexcept = default;
		~MeshLayout() noexcept = default;
		
	public:
		MeshLayout &operator=(const MeshLayout &sSrc) = default;
		MeshLayout &operator=(MeshLayout &&sSrc) noexcept = default;

	public:
		static bool isSubLayout(const MeshLayout &sLayout, const MeshLayout &sSubLayout);
	};
}

#endif