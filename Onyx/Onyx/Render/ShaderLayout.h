
/*
	2019.09.09
	Created by AcrylicShrimp.
*/

#ifndef _CLASS_ONYX_RENDER_SHADERLAYOUT_H

#define _CLASS_ONYX_RENDER_SHADERLAYOUT_H

#include "../Vulkan.h"

#include <cstdint>
#include <stdexcept>
#include <unordered_map>

namespace Onyx::Render
{
	class ShaderLayout final
	{
	private:
		std::unordered_map<std::uint32_t, VkFormat> sLayoutMap;
		
	public:
		ShaderLayout() = default;
		ShaderLayout(const ShaderLayout &sSrc) = default;
		ShaderLayout(ShaderLayout &&sSrc) noexcept = default;
		~ShaderLayout() noexcept = default;
		
	public:
		ShaderLayout &operator=(const ShaderLayout &sSrc) = default;
		ShaderLayout &operator=(ShaderLayout &&sSrc) noexcept = default;
		
	public:
		inline const std::unordered_map<std::uint32_t, VkFormat> &layoutMap() const noexcept;
		void specifyLayout(std::uint32_t nLocation, VkFormat vkFormat);
	};

	inline const std::unordered_map<std::uint32_t, VkFormat> &ShaderLayout::layoutMap() const noexcept
	{
		return this->sLayoutMap;
	}
}

#endif