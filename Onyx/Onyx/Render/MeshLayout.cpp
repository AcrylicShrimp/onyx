
/*
	2019.07.13
	Created by AcrylicShrimp.
*/

#include "MeshLayout.h"

namespace Onyx::Render
{
	MeshLayout::MeshLayout(std::uint32_t nStride, const std::vector<std::pair<std::uint32_t, VkFormat>> &sOffsetList) :
		nStride{nStride},
		sOffsetMap{sOffsetList.cbegin(), sOffsetList.cend()}
	{
		//Empty.
	}

	bool MeshLayout::isSubLayout(const MeshLayout &sLayout, const MeshLayout &sSubLayout)
	{
		if (sLayout.nStride != sSubLayout.nStride)
			return false;

		const auto iEnd{sLayout.sOffsetMap.cend()};

		for (const auto &sPair : sSubLayout.sOffsetMap)
		{
			const auto iIndex{sLayout.sOffsetMap.find(sPair.first)};

			if (iIndex == iEnd)
				return false;

			if (iIndex->second != sPair.second)
				return false;
		}

		return true;
	}
}