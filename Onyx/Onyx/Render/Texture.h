
/*
	2019.10.13
	Created by AcrylicShrimp.
*/

#ifndef _CLASS_ONYX_RENDER_TEXTURE_H

#define _CLASS_ONYX_RENDER_TEXTURE_H

#include "../Vulkan.h"
#include "./Buffer.h"

#include <cstdint>
#include <cstring>
#include <istream>
#include <stdexcept>

namespace Onyx::Render
{
	class Context;

	class Texture
	{
	public:
		Context *const pContext;

	private:
		VkImage vkImage;
		VkImageView vkImageView;
		VkDeviceMemory vkImageMemory;
		VkSampler vkSampler;
		std::uint32_t nWidth;
		std::uint32_t nHeight;
		std::uint32_t nChannel;
		
	public:
		Texture(Context *pContext, std::istream &sInput);
		Texture(const Texture &sSrc) = delete;
		Texture(Texture &&sSrc) = delete;
		~Texture();
		
	public:
		Texture &operator=(const Texture &sSrc) = delete;
		Texture &operator=(Texture &&sSrc) = delete;
		
	public:
		inline VkSampler vulkanSampler() const;
		inline VkImageView vulkanImageView() const;
	};

	inline VkSampler Texture::vulkanSampler() const
	{
		return this->vkSampler;
	}

	inline VkImageView Texture::vulkanImageView() const
	{
		return this->vkImageView;
	}
}

#endif