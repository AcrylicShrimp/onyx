
/*
	2019.10.13
	Created by AcrylicShrimp.
*/

#include "ResourceManager.h"

#define STB_IMAGE_IMPLEMENTATION
#include <stb/stb_image.h>

namespace Onyx::IO
{
	ResourceManager::ResourceManager(Render::Context *pContext) :
		SubContextManager{pContext}
	{
		//Empty.
	}

	std::tuple<std::uint32_t, std::uint32_t, std::uint32_t, std::vector<unsigned char>> ResourceManager::loadImage(std::istream &sInput) const
	{
		std::istreambuf_iterator<char> sStreamIterator{sInput};
		std::vector<char> sBuffer{sStreamIterator, {}};

		int nWidth, nHeight, nChannel;
		stbi_set_flip_vertically_on_load(0);

		auto pImage{stbi_load_from_memory(reinterpret_cast<const stbi_uc *>(sBuffer.data()), static_cast<int>(sBuffer.size()), &nWidth, &nHeight, &nChannel, 0)};
		auto sResult{std::make_tuple(static_cast<std::uint32_t>(nWidth), static_cast<std::uint32_t>(nHeight), static_cast<std::uint32_t>(nChannel), std::vector<unsigned char>{pImage, pImage + nWidth * nHeight * nChannel})};

		stbi_image_free(pImage);

		return sResult;
	}
}