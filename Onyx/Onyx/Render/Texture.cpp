
/*
	2019.10.13
	Created by AcrylicShrimp.
*/

#include "Texture.h"

#include "./Context.h"

namespace Onyx::Render
{
	Texture::Texture(Context *pContext, std::istream &sInput) :
		pContext{pContext}
	{
		const auto sImage{this->pContext->resourceMgr().loadImage(sInput)};

		this->nWidth = std::get<0>(sImage);
		this->nHeight = std::get<1>(sImage);
		this->nChannel = std::get<2>(sImage);

		Buffer sStagingBuffer{this->pContext, Buffer::Usage::TransformSrc, std::get<3>(sImage).size()};
		sStagingBuffer.map([&sImage](void *pDestination)
			{
				std::memcpy(pDestination, std::get<3>(sImage).data(), std::get<3>(sImage).size());
			});

		VkImageCreateInfo vkImageCreateInfo
		{
			VkStructureType::VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO,
			nullptr,
			0,
			VkImageType::VK_IMAGE_TYPE_2D,
			this->nChannel == 1 ? VkFormat::VK_FORMAT_R8_UNORM : this->nChannel == 3 ? VkFormat::VK_FORMAT_R8G8B8_UNORM : VkFormat::VK_FORMAT_R8G8B8A8_UNORM,
			VkExtent3D
			{
				this->nWidth,
				this->nHeight,
				1
			},
			1,
			1,
			VkSampleCountFlagBits::VK_SAMPLE_COUNT_1_BIT,
			VkImageTiling::VK_IMAGE_TILING_OPTIMAL,
			VkImageUsageFlagBits::VK_IMAGE_USAGE_TRANSFER_DST_BIT | VkImageUsageFlagBits::VK_IMAGE_USAGE_SAMPLED_BIT,
			VkSharingMode::VK_SHARING_MODE_EXCLUSIVE,
			0,
			nullptr,
			VkImageLayout::VK_IMAGE_LAYOUT_UNDEFINED
		};

		if (vkCreateImage(this->pContext->device().vulkanDevice(), &vkImageCreateInfo, nullptr, &this->vkImage) != VkResult::VK_SUCCESS)
			throw std::runtime_error{"unable to create image"};

		this->vkImageMemory = this->pContext->memoryMgr().allocateImage(this->vkImage, VkMemoryPropertyFlagBits::VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT);

		if (vkBindImageMemory(this->pContext->device().vulkanDevice(), this->vkImage, this->vkImageMemory, 0) != VkResult::VK_SUCCESS)
			throw std::runtime_error{"unable to bind image memory"};

		VkImageViewCreateInfo vkImageViewCreateInfo
		{
			VkStructureType::VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO,
			nullptr,
			0,
			this->vkImage,
			VkImageViewType::VK_IMAGE_VIEW_TYPE_2D,
			this->nChannel == 1 ? VkFormat::VK_FORMAT_R8_UNORM : this->nChannel == 3 ? VkFormat::VK_FORMAT_R8G8B8_UNORM : VkFormat::VK_FORMAT_R8G8B8A8_UNORM,
			VkComponentMapping
			{
				VkComponentSwizzle::VK_COMPONENT_SWIZZLE_IDENTITY,
				VkComponentSwizzle::VK_COMPONENT_SWIZZLE_IDENTITY,
				VkComponentSwizzle::VK_COMPONENT_SWIZZLE_IDENTITY,
				VkComponentSwizzle::VK_COMPONENT_SWIZZLE_IDENTITY
			},
			VkImageSubresourceRange
			{
				VkImageAspectFlagBits::VK_IMAGE_ASPECT_COLOR_BIT,
				0,
				1,
				0,
				1
			}
		};

		if (vkCreateImageView(this->pContext->device().vulkanDevice(), &vkImageViewCreateInfo, nullptr, &this->vkImageView) != VkResult::VK_SUCCESS)
			throw std::runtime_error{"unable to create image view"};

		VkSamplerCreateInfo vkSamplerCreateInfo
		{
			VkStructureType::VK_STRUCTURE_TYPE_SAMPLER_CREATE_INFO,
			nullptr,
			0,
			VkFilter::VK_FILTER_LINEAR,
			VkFilter::VK_FILTER_LINEAR,
			VkSamplerMipmapMode::VK_SAMPLER_MIPMAP_MODE_LINEAR,
			VkSamplerAddressMode::VK_SAMPLER_ADDRESS_MODE_CLAMP_TO_EDGE,
			VkSamplerAddressMode::VK_SAMPLER_ADDRESS_MODE_CLAMP_TO_EDGE,
			VkSamplerAddressMode::VK_SAMPLER_ADDRESS_MODE_CLAMP_TO_EDGE,
			.0f,
			VK_FALSE,
			.0f,
			VK_FALSE,
			VkCompareOp::VK_COMPARE_OP_NEVER,
			.0f,
			.0f,
			VkBorderColor::VK_BORDER_COLOR_FLOAT_OPAQUE_BLACK,
			VK_FALSE
		};

		if (vkCreateSampler(this->pContext->device().vulkanDevice(), &vkSamplerCreateInfo, nullptr, &this->vkSampler) != VkResult::VK_SUCCESS)
			throw std::runtime_error{"unable to create sampler"};

		this->pContext->synchronizer().executeOnetimeCommand([this, &sStagingBuffer](VkCommandBuffer vkCommandBuffer)
			{
				VkImageMemoryBarrier vkFirstBarrier
				{
					VkStructureType::VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER,
					nullptr,
					0,
					VkAccessFlagBits::VK_ACCESS_TRANSFER_WRITE_BIT,
					VkImageLayout::VK_IMAGE_LAYOUT_UNDEFINED,
					VkImageLayout::VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL,
					VK_QUEUE_FAMILY_IGNORED,
					VK_QUEUE_FAMILY_IGNORED,
					this->vkImage,
					VkImageSubresourceRange
					{
						VkImageAspectFlagBits::VK_IMAGE_ASPECT_COLOR_BIT,
						0,
						1,
						0,
						1
					}
				};
				vkCmdPipelineBarrier(vkCommandBuffer, VkPipelineStageFlagBits::VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT, VkPipelineStageFlagBits::VK_PIPELINE_STAGE_TRANSFER_BIT, 0, 0, nullptr, 0, nullptr, 1, &vkFirstBarrier);

				VkBufferImageCopy vkBufferImageCopy
				{
					0,
					0,
					0,
					VkImageSubresourceLayers
					{
						VkImageAspectFlagBits::VK_IMAGE_ASPECT_COLOR_BIT,
						0,
						0,
						1
					},
					VkOffset3D
					{
						0,
						0,
						0
					},
					VkExtent3D
					{
						this->nWidth,
						this->nHeight,
						1
					}
				};
				vkCmdCopyBufferToImage(vkCommandBuffer, sStagingBuffer.vulkanBuffer(), this->vkImage, VkImageLayout::VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL, 1, &vkBufferImageCopy);

				VkImageMemoryBarrier vkSecondBarrier
				{
					VkStructureType::VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER,
					nullptr,
					VkAccessFlagBits::VK_ACCESS_TRANSFER_WRITE_BIT,
					VkAccessFlagBits::VK_ACCESS_SHADER_READ_BIT,
					VkImageLayout::VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL,
					VkImageLayout::VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL,
					VK_QUEUE_FAMILY_IGNORED,
					VK_QUEUE_FAMILY_IGNORED,
					this->vkImage,
					VkImageSubresourceRange
					{
						VkImageAspectFlagBits::VK_IMAGE_ASPECT_COLOR_BIT,
							0,
							1,
							0,
							1
					}
				};
				vkCmdPipelineBarrier(vkCommandBuffer, VkPipelineStageFlagBits::VK_PIPELINE_STAGE_TRANSFER_BIT, VkPipelineStageFlagBits::VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT, 0, 0, nullptr, 0, nullptr, 1, &vkSecondBarrier);
			});
	}
	
	Texture::~Texture()
	{
		vkDestroySampler(this->pContext->device().vulkanDevice(), this->vkSampler, nullptr);
		vkDestroyImageView(this->pContext->device().vulkanDevice(), this->vkImageView, nullptr);
		vkDestroyImage(this->pContext->device().vulkanDevice(), this->vkImage, nullptr);
		vkFreeMemory(this->pContext->device().vulkanDevice(), this->vkImageMemory, nullptr);
	}
}