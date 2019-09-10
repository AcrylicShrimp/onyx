
/*
	2019.08.27
	Created by AcrylicShrimp.
*/

#include "MeshLayout.h"

namespace Onyx::Render
{
	void MeshLayout::specifyLayout(std::uint32_t nOffset, VkFormat vkFormat)
	{
		if (this->sLayoutMap.contains(nOffset))
			throw std::runtime_error{"already specified layout offset"};

		this->sLayoutMap.emplace(nOffset, vkFormat);
	}

	std::uint32_t MeshLayout::calcOffset() const
	{
		if (!this->sLayoutMap.size())
			return 0;

		return std::min_element(this->sLayoutMap.cbegin(), this->sLayoutMap.cend(),
			[](const auto &sLeft, const auto &sRight)
			{
				return sLeft.first < sRight.first;
			})->first;
	}

	std::uint32_t MeshLayout::calcStride() const
	{
		if (!this->sLayoutMap.size())
			return 0;

		const auto sMax{std::max_element(this->sLayoutMap.cbegin(), this->sLayoutMap.cend(),
			[](const auto &sLeft, const auto &sRight)
			{
				return sLeft.first + MeshLayout::formatSize(sLeft.second) < sRight.first + MeshLayout::formatSize(sRight.second);
			})};

		return sMax->first + MeshLayout::formatSize(sMax->second) - this->calcOffset();
	}

	bool MeshLayout::isSubsetOf(const MeshLayout &sMeshLayout, const MeshLayout &sMeshLayoutSubset)
	{
		const auto iEnd{sMeshLayout.sLayoutMap.cend()};

		for (const auto &sPair : sMeshLayoutSubset.sLayoutMap)
		{
			const auto iIndex{sMeshLayout.sLayoutMap.find(sPair.first)};

			if (iIndex == iEnd)
				return false;

			if (iIndex->second != sPair.second)
				return false;
		}

		return true;
	}

	std::uint32_t MeshLayout::formatSize(VkFormat vkFormat) noexcept
	{
		switch (vkFormat)
		{
		case VkFormat::VK_FORMAT_R4G4_UNORM_PACK8:
			return 1;

		case VkFormat::VK_FORMAT_R4G4B4A4_UNORM_PACK16:
		case VkFormat::VK_FORMAT_B4G4R4A4_UNORM_PACK16:
		case VkFormat::VK_FORMAT_R5G6B5_UNORM_PACK16:
		case VkFormat::VK_FORMAT_B5G6R5_UNORM_PACK16:
		case VkFormat::VK_FORMAT_R5G5B5A1_UNORM_PACK16:
		case VkFormat::VK_FORMAT_B5G5R5A1_UNORM_PACK16:
		case VkFormat::VK_FORMAT_A1R5G5B5_UNORM_PACK16:
			return 2;

		case VkFormat::VK_FORMAT_R8_UNORM:
		case VkFormat::VK_FORMAT_R8_SNORM:
		case VkFormat::VK_FORMAT_R8_USCALED:
		case VkFormat::VK_FORMAT_R8_SSCALED:
		case VkFormat::VK_FORMAT_R8_UINT:
		case VkFormat::VK_FORMAT_R8_SINT:
		case VkFormat::VK_FORMAT_R8_SRGB:
			return 1;

		case VkFormat::VK_FORMAT_R8G8_UNORM:
		case VkFormat::VK_FORMAT_R8G8_SNORM:
		case VkFormat::VK_FORMAT_R8G8_USCALED:
		case VkFormat::VK_FORMAT_R8G8_SSCALED:
		case VkFormat::VK_FORMAT_R8G8_UINT:
		case VkFormat::VK_FORMAT_R8G8_SINT:
		case VkFormat::VK_FORMAT_R8G8_SRGB:
			return 2;

		case VkFormat::VK_FORMAT_R8G8B8_UNORM:
		case VkFormat::VK_FORMAT_R8G8B8_SNORM:
		case VkFormat::VK_FORMAT_R8G8B8_USCALED:
		case VkFormat::VK_FORMAT_R8G8B8_SSCALED:
		case VkFormat::VK_FORMAT_R8G8B8_UINT:
		case VkFormat::VK_FORMAT_R8G8B8_SINT:
		case VkFormat::VK_FORMAT_R8G8B8_SRGB:
		case VkFormat::VK_FORMAT_B8G8R8_UNORM:
		case VkFormat::VK_FORMAT_B8G8R8_SNORM:
		case VkFormat::VK_FORMAT_B8G8R8_USCALED:
		case VkFormat::VK_FORMAT_B8G8R8_SSCALED:
		case VkFormat::VK_FORMAT_B8G8R8_UINT:
		case VkFormat::VK_FORMAT_B8G8R8_SINT:
		case VkFormat::VK_FORMAT_B8G8R8_SRGB:
			return 3;

		case VkFormat::VK_FORMAT_R8G8B8A8_UNORM:
		case VkFormat::VK_FORMAT_R8G8B8A8_SNORM:
		case VkFormat::VK_FORMAT_R8G8B8A8_USCALED:
		case VkFormat::VK_FORMAT_R8G8B8A8_SSCALED:
		case VkFormat::VK_FORMAT_R8G8B8A8_UINT:
		case VkFormat::VK_FORMAT_R8G8B8A8_SINT:
		case VkFormat::VK_FORMAT_R8G8B8A8_SRGB:
		case VkFormat::VK_FORMAT_B8G8R8A8_UNORM:
		case VkFormat::VK_FORMAT_B8G8R8A8_SNORM:
		case VkFormat::VK_FORMAT_B8G8R8A8_USCALED:
		case VkFormat::VK_FORMAT_B8G8R8A8_SSCALED:
		case VkFormat::VK_FORMAT_B8G8R8A8_UINT:
		case VkFormat::VK_FORMAT_B8G8R8A8_SINT:
		case VkFormat::VK_FORMAT_B8G8R8A8_SRGB:
		case VkFormat::VK_FORMAT_A8B8G8R8_UNORM_PACK32:
		case VkFormat::VK_FORMAT_A8B8G8R8_SNORM_PACK32:
		case VkFormat::VK_FORMAT_A8B8G8R8_USCALED_PACK32:
		case VkFormat::VK_FORMAT_A8B8G8R8_SSCALED_PACK32:
		case VkFormat::VK_FORMAT_A8B8G8R8_UINT_PACK32:
		case VkFormat::VK_FORMAT_A8B8G8R8_SINT_PACK32:
		case VkFormat::VK_FORMAT_A8B8G8R8_SRGB_PACK32:
		case VkFormat::VK_FORMAT_A2R10G10B10_UNORM_PACK32:
		case VkFormat::VK_FORMAT_A2R10G10B10_SNORM_PACK32:
		case VkFormat::VK_FORMAT_A2R10G10B10_USCALED_PACK32:
		case VkFormat::VK_FORMAT_A2R10G10B10_SSCALED_PACK32:
		case VkFormat::VK_FORMAT_A2R10G10B10_UINT_PACK32:
		case VkFormat::VK_FORMAT_A2R10G10B10_SINT_PACK32:
		case VkFormat::VK_FORMAT_A2B10G10R10_UNORM_PACK32:
		case VkFormat::VK_FORMAT_A2B10G10R10_SNORM_PACK32:
		case VkFormat::VK_FORMAT_A2B10G10R10_USCALED_PACK32:
		case VkFormat::VK_FORMAT_A2B10G10R10_SSCALED_PACK32:
		case VkFormat::VK_FORMAT_A2B10G10R10_UINT_PACK32:
		case VkFormat::VK_FORMAT_A2B10G10R10_SINT_PACK32:
			return 4;

		case VkFormat::VK_FORMAT_R16_UNORM:
		case VkFormat::VK_FORMAT_R16_SNORM:
		case VkFormat::VK_FORMAT_R16_USCALED:
		case VkFormat::VK_FORMAT_R16_SSCALED:
		case VkFormat::VK_FORMAT_R16_UINT:
		case VkFormat::VK_FORMAT_R16_SINT:
		case VkFormat::VK_FORMAT_R16_SFLOAT:
			return 2;

		case VkFormat::VK_FORMAT_R16G16_UNORM:
		case VkFormat::VK_FORMAT_R16G16_SNORM:
		case VkFormat::VK_FORMAT_R16G16_USCALED:
		case VkFormat::VK_FORMAT_R16G16_SSCALED:
		case VkFormat::VK_FORMAT_R16G16_UINT:
		case VkFormat::VK_FORMAT_R16G16_SINT:
		case VkFormat::VK_FORMAT_R16G16_SFLOAT:
			return 4;

		case VkFormat::VK_FORMAT_R16G16B16_UNORM:
		case VkFormat::VK_FORMAT_R16G16B16_SNORM:
		case VkFormat::VK_FORMAT_R16G16B16_USCALED:
		case VkFormat::VK_FORMAT_R16G16B16_SSCALED:
		case VkFormat::VK_FORMAT_R16G16B16_UINT:
		case VkFormat::VK_FORMAT_R16G16B16_SINT:
		case VkFormat::VK_FORMAT_R16G16B16_SFLOAT:
			return 6;

		case VkFormat::VK_FORMAT_R16G16B16A16_UNORM:
		case VkFormat::VK_FORMAT_R16G16B16A16_SNORM:
		case VkFormat::VK_FORMAT_R16G16B16A16_USCALED:
		case VkFormat::VK_FORMAT_R16G16B16A16_SSCALED:
		case VkFormat::VK_FORMAT_R16G16B16A16_UINT:
		case VkFormat::VK_FORMAT_R16G16B16A16_SINT:
		case VkFormat::VK_FORMAT_R16G16B16A16_SFLOAT:
			return 8;

		case VkFormat::VK_FORMAT_R32_UINT:
		case VkFormat::VK_FORMAT_R32_SINT:
		case VkFormat::VK_FORMAT_R32_SFLOAT:
			return 4;

		case VkFormat::VK_FORMAT_R32G32_UINT:
		case VkFormat::VK_FORMAT_R32G32_SINT:
		case VkFormat::VK_FORMAT_R32G32_SFLOAT:
			return 8;

		case VkFormat::VK_FORMAT_R32G32B32_UINT:
		case VkFormat::VK_FORMAT_R32G32B32_SINT:
		case VkFormat::VK_FORMAT_R32G32B32_SFLOAT:
			return 12;

		case VkFormat::VK_FORMAT_R32G32B32A32_UINT:
		case VkFormat::VK_FORMAT_R32G32B32A32_SINT:
		case VkFormat::VK_FORMAT_R32G32B32A32_SFLOAT:
			return 16;

		case VkFormat::VK_FORMAT_R64_UINT:
		case VkFormat::VK_FORMAT_R64_SINT:
		case VkFormat::VK_FORMAT_R64_SFLOAT:
			return 8;

		case VkFormat::VK_FORMAT_R64G64_UINT:
		case VkFormat::VK_FORMAT_R64G64_SINT:
		case VkFormat::VK_FORMAT_R64G64_SFLOAT:
			return 16;

		case VkFormat::VK_FORMAT_R64G64B64_UINT:
		case VkFormat::VK_FORMAT_R64G64B64_SINT:
		case VkFormat::VK_FORMAT_R64G64B64_SFLOAT:
			return 24;

		case VkFormat::VK_FORMAT_R64G64B64A64_UINT:
		case VkFormat::VK_FORMAT_R64G64B64A64_SINT:
		case VkFormat::VK_FORMAT_R64G64B64A64_SFLOAT:
			return 32;

		case VkFormat::VK_FORMAT_B10G11R11_UFLOAT_PACK32:
		case VkFormat::VK_FORMAT_E5B9G9R9_UFLOAT_PACK32:
			return 4;

		case VkFormat::VK_FORMAT_D16_UNORM:
			return 2;

		case VkFormat::VK_FORMAT_X8_D24_UNORM_PACK32:
		case VkFormat::VK_FORMAT_D32_SFLOAT:
			return 4;

		case VkFormat::VK_FORMAT_S8_UINT:
			return 1;

		case VkFormat::VK_FORMAT_D16_UNORM_S8_UINT:
			return 3;

		case VkFormat::VK_FORMAT_D24_UNORM_S8_UINT:
			return 4;

		case VkFormat::VK_FORMAT_D32_SFLOAT_S8_UINT:
			return 5;

		case VkFormat::VK_FORMAT_BC1_RGB_UNORM_BLOCK:
		case VkFormat::VK_FORMAT_BC1_RGB_SRGB_BLOCK:
		case VkFormat::VK_FORMAT_BC1_RGBA_UNORM_BLOCK:
		case VkFormat::VK_FORMAT_BC1_RGBA_SRGB_BLOCK:
			return 8;

		case VkFormat::VK_FORMAT_BC2_UNORM_BLOCK:
		case VkFormat::VK_FORMAT_BC2_SRGB_BLOCK:
		case VkFormat::VK_FORMAT_BC3_UNORM_BLOCK:
		case VkFormat::VK_FORMAT_BC3_SRGB_BLOCK:
			return 16;

		case VkFormat::VK_FORMAT_BC4_UNORM_BLOCK:
		case VkFormat::VK_FORMAT_BC4_SNORM_BLOCK:
			return 8;

		case VkFormat::VK_FORMAT_BC5_UNORM_BLOCK:
		case VkFormat::VK_FORMAT_BC5_SNORM_BLOCK:
		case VkFormat::VK_FORMAT_BC6H_UFLOAT_BLOCK:
		case VkFormat::VK_FORMAT_BC6H_SFLOAT_BLOCK:
		case VkFormat::VK_FORMAT_BC7_UNORM_BLOCK:
		case VkFormat::VK_FORMAT_BC7_SRGB_BLOCK:
			return 16;

		case VkFormat::VK_FORMAT_ETC2_R8G8B8_UNORM_BLOCK:
		case VkFormat::VK_FORMAT_ETC2_R8G8B8_SRGB_BLOCK:
		case VkFormat::VK_FORMAT_ETC2_R8G8B8A1_UNORM_BLOCK:
		case VkFormat::VK_FORMAT_ETC2_R8G8B8A1_SRGB_BLOCK:
			return 8;

		case VkFormat::VK_FORMAT_ETC2_R8G8B8A8_UNORM_BLOCK:
		case VkFormat::VK_FORMAT_ETC2_R8G8B8A8_SRGB_BLOCK:
			return 16;

		case VkFormat::VK_FORMAT_EAC_R11_UNORM_BLOCK:
		case VkFormat::VK_FORMAT_EAC_R11_SNORM_BLOCK:
			return 8;

		case VkFormat::VK_FORMAT_EAC_R11G11_UNORM_BLOCK:
		case VkFormat::VK_FORMAT_EAC_R11G11_SNORM_BLOCK:
		case VkFormat::VK_FORMAT_ASTC_4x4_UNORM_BLOCK:
		case VkFormat::VK_FORMAT_ASTC_4x4_SRGB_BLOCK:
		case VkFormat::VK_FORMAT_ASTC_5x4_UNORM_BLOCK:
		case VkFormat::VK_FORMAT_ASTC_5x4_SRGB_BLOCK:
		case VkFormat::VK_FORMAT_ASTC_5x5_UNORM_BLOCK:
		case VkFormat::VK_FORMAT_ASTC_5x5_SRGB_BLOCK:
		case VkFormat::VK_FORMAT_ASTC_6x5_UNORM_BLOCK:
		case VkFormat::VK_FORMAT_ASTC_6x5_SRGB_BLOCK:
		case VkFormat::VK_FORMAT_ASTC_6x6_UNORM_BLOCK:
		case VkFormat::VK_FORMAT_ASTC_6x6_SRGB_BLOCK:
		case VkFormat::VK_FORMAT_ASTC_8x5_UNORM_BLOCK:
		case VkFormat::VK_FORMAT_ASTC_8x5_SRGB_BLOCK:
		case VkFormat::VK_FORMAT_ASTC_8x6_UNORM_BLOCK:
		case VkFormat::VK_FORMAT_ASTC_8x6_SRGB_BLOCK:
		case VkFormat::VK_FORMAT_ASTC_8x8_UNORM_BLOCK:
		case VkFormat::VK_FORMAT_ASTC_8x8_SRGB_BLOCK:
		case VkFormat::VK_FORMAT_ASTC_10x5_UNORM_BLOCK:
		case VkFormat::VK_FORMAT_ASTC_10x5_SRGB_BLOCK:
		case VkFormat::VK_FORMAT_ASTC_10x6_UNORM_BLOCK:
		case VkFormat::VK_FORMAT_ASTC_10x6_SRGB_BLOCK:
		case VkFormat::VK_FORMAT_ASTC_10x8_UNORM_BLOCK:
		case VkFormat::VK_FORMAT_ASTC_10x8_SRGB_BLOCK:
		case VkFormat::VK_FORMAT_ASTC_10x10_UNORM_BLOCK:
		case VkFormat::VK_FORMAT_ASTC_10x10_SRGB_BLOCK:
		case VkFormat::VK_FORMAT_ASTC_12x10_UNORM_BLOCK:
		case VkFormat::VK_FORMAT_ASTC_12x10_SRGB_BLOCK:
		case VkFormat::VK_FORMAT_ASTC_12x12_UNORM_BLOCK:
		case VkFormat::VK_FORMAT_ASTC_12x12_SRGB_BLOCK:
			return 16;

		case VkFormat::VK_FORMAT_G8B8G8R8_422_UNORM:
			return 4;

		default:
			return 0;
		}
	}
}