
/*
	2019.09.09
	Created by AcrylicShrimp.
*/

#include "ShaderLayout.h"

namespace Onyx::Render
{
	void ShaderLayout::specifyLayout(std::uint32_t nLocation, VkFormat vkFormat)
	{
		if (this->sLayoutMap.contains(nOffset))
			throw std::runtime_error{"already specified layout offset"};

		this->sLayoutMap.emplace(nOffset, vkFormat);
	}
}