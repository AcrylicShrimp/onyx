
/*
	2019.05.26
	Created by AcrylicShrimp.
*/

#include "UniformManager.h"

#include "./Context.h"

namespace Onyx::Render
{
	UniformManager::UniformManager(Context *pContext) :
		SubContextManager{pContext}
	{
		std::ifstream sTextureInput{"AcrylicShrimp_dot.png", std::ios_base::binary};
		this->pTexture = std::make_unique<Texture>(pContext, sTextureInput);

		VkDescriptorSetLayoutBinding vkTimeDescriptorSetLayoutBinding
		{
			0,
			VkDescriptorType::VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER,
			1,
			VkShaderStageFlagBits::VK_SHADER_STAGE_ALL,
			nullptr
		};
		VkDescriptorSetLayoutBinding vkGlobalTransformDescriptorSetLayoutBinding
		{
			1,
			VkDescriptorType::VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER,
			1,
			VkShaderStageFlagBits::VK_SHADER_STAGE_ALL,
			nullptr
		};
		VkDescriptorSetLayoutBinding vkTextureDescriptorSetLayoutBinding
		{
			2,
			VkDescriptorType::VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER,
			1,
			VkShaderStageFlagBits::VK_SHADER_STAGE_FRAGMENT_BIT,
			nullptr
		};

		VkDescriptorSetLayoutBinding vDescriptorSetLayoutBindingArray[]
		{
			vkTimeDescriptorSetLayoutBinding,
			vkGlobalTransformDescriptorSetLayoutBinding,
			vkTextureDescriptorSetLayoutBinding
		};

		VkDescriptorSetLayoutCreateInfo vkDescriptorSetLayoutCreateInfo
		{
			VkStructureType::VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_CREATE_INFO,
			nullptr,
			0,
			3,
			vDescriptorSetLayoutBindingArray
		};

		if (vkCreateDescriptorSetLayout(this->pContext->device().vulkanDevice(), &vkDescriptorSetLayoutCreateInfo, nullptr, &this->vkDescriptorSetLayout) != VkResult::VK_SUCCESS)
			throw std::runtime_error{"unable to create descriptor set layout"};

		VkPipelineLayoutCreateInfo vkPipelineLayoutCreateInfo
		{
			VkStructureType::VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO,
			nullptr,
			0,
			1,
			&this->vkDescriptorSetLayout,
			0,
			nullptr
		};

		if (vkCreatePipelineLayout(this->pContext->device().vulkanDevice(), &vkPipelineLayoutCreateInfo, nullptr, &this->vkPipelineLayout) != VkResult::VK_SUCCESS)
			throw std::runtime_error{"unable to create pipeline layout"};

		auto nMaxIndex{this->pContext->swapchain().vulkanImageList().size()};

		VkDescriptorPoolSize vkDescriptorPoolSize
		{
			VkDescriptorType::VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER,
			static_cast<std::uint32_t>(nMaxIndex)
		};
		VkDescriptorPoolCreateInfo vkDescriptorPoolCreateInfo
		{
			VkStructureType::VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_CREATE_INFO,
			nullptr,
			0,
			static_cast<std::uint32_t>(nMaxIndex),
			1,
			&vkDescriptorPoolSize
		};

		if (vkCreateDescriptorPool(this->pContext->device().vulkanDevice(), &vkDescriptorPoolCreateInfo, nullptr, &this->vkDescriptorPool) != VkResult::VK_SUCCESS)
			throw std::runtime_error{"unable to create descriptor pool"};

		for (std::size_t nIndex{0}; nIndex < nMaxIndex; ++nIndex)
		{
			this->sTimeBufferList.emplace_back(this->pContext, Buffer::Usage::UniformBuffer, sizeof(Time));
			this->sGlobalTransformBufferList.emplace_back(this->pContext, Buffer::Usage::UniformBuffer, sizeof(Transform::Mat44f) + sizeof(Transform::Mat44f));
		}

		std::vector<VkDescriptorSetLayout> sDescriptorSetLayout(nMaxIndex, this->vkDescriptorSetLayout);

		VkDescriptorSetAllocateInfo vkDescriptorSetAllocateInfo
		{
			VkStructureType::VK_STRUCTURE_TYPE_DESCRIPTOR_SET_ALLOCATE_INFO,
			nullptr,
			this->vkDescriptorPool,
			static_cast<std::uint32_t>(nMaxIndex),
			sDescriptorSetLayout.data()
		};

		this->sDescriptorSetList.resize(nMaxIndex);

		if (vkAllocateDescriptorSets(this->pContext->device().vulkanDevice(), &vkDescriptorSetAllocateInfo, this->sDescriptorSetList.data()) != VkResult::VK_SUCCESS)
			throw std::runtime_error{"unable to allocate descriptor set"};

		for (std::size_t nIndex{0}; nIndex < nMaxIndex; ++nIndex)
		{
			VkDescriptorBufferInfo vkTimeDescriptorBufferInfo
			{
				this->sTimeBufferList[nIndex].vulkanBuffer(),
				0,
				VK_WHOLE_SIZE
			};
			VkDescriptorBufferInfo vkGlobalTransformDescriptorBufferInfo
			{
				this->sGlobalTransformBufferList[nIndex].vulkanBuffer(),
				0,
				VK_WHOLE_SIZE
			};
			VkDescriptorImageInfo vkTextureDescriptorImageInfo
			{
				this->pTexture->vulkanSampler(),
				this->pTexture->vulkanImageView(),
				VkImageLayout::VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL
			};
			VkWriteDescriptorSet vkTimeWriteDescriptorSet
			{
				VkStructureType::VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET,
				nullptr,
				this->sDescriptorSetList[nIndex],
				0,
				0,
				1,
				VkDescriptorType::VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER,
				nullptr,
				&vkTimeDescriptorBufferInfo,
				nullptr
			};
			VkWriteDescriptorSet vkGlobalTransformWriteDescriptorSet
			{
				VkStructureType::VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET,
				nullptr,
				this->sDescriptorSetList[nIndex],
				1,
				0,
				1,
				VkDescriptorType::VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER,
				nullptr,
				&vkGlobalTransformDescriptorBufferInfo,
				nullptr
			};
			VkWriteDescriptorSet vkTextureWriteDescriptorSet
			{
				VkStructureType::VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET,
				nullptr,
				this->sDescriptorSetList[nIndex],
				2,
				0,
				1,
				VkDescriptorType::VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER,
				&vkTextureDescriptorImageInfo,
				nullptr,
				nullptr
			};
			VkWriteDescriptorSet vWriteDescriptorSetArray[]
			{
				vkTimeWriteDescriptorSet,
				vkGlobalTransformWriteDescriptorSet,
				vkTextureWriteDescriptorSet
			};

			vkUpdateDescriptorSets(this->pContext->device().vulkanDevice(), 3, vWriteDescriptorSetArray, 0, nullptr);
		}
	}
	
	UniformManager::~UniformManager() noexcept
	{
		vkDestroyDescriptorPool(this->pContext->device().vulkanDevice(), this->vkDescriptorPool, nullptr);
		vkDestroyPipelineLayout(this->pContext->device().vulkanDevice(), this->vkPipelineLayout, nullptr);
		vkDestroyDescriptorSetLayout(this->pContext->device().vulkanDevice(), this->vkDescriptorSetLayout, nullptr);
	}

	void UniformManager::updateUniform(
		std::uint32_t nImageIndex,
		const Transform::Mat44f &sViewTransform,
		const Transform::Mat44f &sProjectionTransform)
	{
		this->sTimeBufferList[nImageIndex].map([this](void *pTimeBuffer)
			{
				std::chrono::system_clock::time_point sNow{std::chrono::system_clock::now()};

				if (!this->sFirstTimepoint)
				{
					this->sFirstTimepoint = sNow;
					this->sLastTimepoint = sNow;
				}

				using fseconds = std::chrono::duration<float>;

				auto nTotal = std::chrono::duration_cast<fseconds>(sNow - *this->sFirstTimepoint).count();
				auto nDelta = std::chrono::duration_cast<fseconds>(sNow - *this->sLastTimepoint).count();

				float vData[]
				{
					nTotal,
					1.f / std::max(1e-6f, nTotal),
					nDelta,
					1.f / std::max(1e-6f, nDelta),
				};

				std::memcpy(pTimeBuffer, vData, sizeof(vData));

				this->sLastTimepoint = sNow;
			});

		this->sGlobalTransformBufferList[nImageIndex].map([this, &sViewTransform, &sProjectionTransform](void *pGlobalTransformBuffer)
			{
				std::memcpy(pGlobalTransformBuffer, &sViewTransform, sizeof(Transform::Mat44f));
				std::memcpy(reinterpret_cast<std::uint8_t *>(pGlobalTransformBuffer) + sizeof(Transform::Mat44f), &sProjectionTransform, sizeof(Transform::Mat44f));
			});
	}
}