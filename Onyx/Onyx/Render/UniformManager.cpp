
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
		VkDescriptorSetLayoutBinding vkTimeDescriptorSetLayoutBinding
		{
			0,
			VkDescriptorType::VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER,
			1,
			VkShaderStageFlagBits::VK_SHADER_STAGE_ALL,
			nullptr
		};
		VkDescriptorSetLayoutBinding vkTransformDescriptorSetLayoutBinding
		{
			1,
			VkDescriptorType::VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER,
			1,
			VkShaderStageFlagBits::VK_SHADER_STAGE_ALL,
			nullptr
		};

		VkDescriptorSetLayoutBinding vDescriptorSetLayoutBindingArray[]
		{
			vkTimeDescriptorSetLayoutBinding,
			vkTransformDescriptorSetLayoutBinding
		};

		VkDescriptorSetLayoutCreateInfo vkDescriptorSetLayoutCreateInfo
		{
			VkStructureType::VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_CREATE_INFO,
			nullptr,
			0,
			1,
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

		this->sBufferList.resize(nMaxIndex);
		this->sDeviceMemoryList.resize(nMaxIndex);

		for (std::size_t nIndex{0}; nIndex < nMaxIndex; ++nIndex)
		{
			VkBufferCreateInfo vkBufferCreateInfo
			{
				VkStructureType::VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO,
				nullptr,
				0,
				sizeof(Time),
				VkBufferUsageFlagBits::VK_BUFFER_USAGE_UNIFORM_BUFFER_BIT,
				VkSharingMode::VK_SHARING_MODE_EXCLUSIVE,
				0,
				nullptr
			};

			if (vkCreateBuffer(this->pContext->device().vulkanDevice(), &vkBufferCreateInfo, nullptr, &this->sBufferList[nIndex]) != VkResult::VK_SUCCESS)
				throw std::runtime_error{"unable to create buffer"};

			VkMemoryRequirements vkBufferMemoryReq;
			vkGetBufferMemoryRequirements(this->pContext->device().vulkanDevice(), this->sBufferList[nIndex], &vkBufferMemoryReq);
			
			auto sMemoryTypeIndex{this->pContext->device().findMemoryType(vkBufferMemoryReq.memoryTypeBits, VkMemoryPropertyFlagBits::VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VkMemoryPropertyFlagBits::VK_MEMORY_PROPERTY_HOST_COHERENT_BIT)};
			
			if (!sMemoryTypeIndex)
				throw std::runtime_error{"unable to find suitable memory type"};

			VkMemoryAllocateInfo vkMemoryAllocateInfo
			{
				VkStructureType::VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO,
				nullptr,
				vkBufferMemoryReq.size,
				*sMemoryTypeIndex
			};

			if (vkAllocateMemory(this->pContext->device().vulkanDevice(), &vkMemoryAllocateInfo, nullptr, &this->sDeviceMemoryList[nIndex]) != VkResult::VK_SUCCESS)
				throw std::runtime_error{"unable to allocate memory"};

			if (vkBindBufferMemory(this->pContext->device().vulkanDevice(), this->sBufferList[nIndex], this->sDeviceMemoryList[nIndex], 0) != VkResult::VK_SUCCESS)
				throw std::runtime_error{"unable to bind buffer memory"};

			this->sDeviceMemorySizeList.emplace_back(vkBufferMemoryReq.size);
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
				this->sBufferList[nIndex],
				0,
				static_cast<VkDeviceSize>(sizeof(float) * 4)
			};
			VkDescriptorBufferInfo vkTransformDescriptorBufferInfo
			{
				this->sBufferList[nIndex],
				static_cast<VkDeviceSize>(sizeof(float) * 4),
				static_cast<VkDeviceSize>(sizeof(float) * 4)
			};
			VkDescriptorBufferInfo vDescriptorBufferInfoArray[]
			{
				vkTimeDescriptorBufferInfo,
				vkTransformDescriptorBufferInfo
			};
			VkWriteDescriptorSet vkWriteDescriptorSet
			{
				VkStructureType::VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET,
				nullptr,
				this->sDescriptorSetList[nIndex],
				0,
				0,
				1,
				VkDescriptorType::VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER,
				nullptr,
				vDescriptorBufferInfoArray,
				nullptr
			};

			vkUpdateDescriptorSets(this->pContext->device().vulkanDevice(), 1, &vkWriteDescriptorSet, 0, nullptr);
		}
	}
	
	UniformManager::~UniformManager() noexcept
	{
		for (auto vkBuffer : this->sBufferList)
			vkDestroyBuffer(this->pContext->device().vulkanDevice(), vkBuffer, nullptr);

		for (auto vkDeviceMemory : this->sDeviceMemoryList)
			vkFreeMemory(this->pContext->device().vulkanDevice(), vkDeviceMemory, nullptr);

		vkDestroyDescriptorPool(this->pContext->device().vulkanDevice(), this->vkDescriptorPool, nullptr);
		vkDestroyPipelineLayout(this->pContext->device().vulkanDevice(), this->vkPipelineLayout, nullptr);
		vkDestroyDescriptorSetLayout(this->pContext->device().vulkanDevice(), this->vkDescriptorSetLayout, nullptr);
	}

	void UniformManager::updateUniform(std::uint32_t nImageIndex)
	{
		std::chrono::system_clock::time_point sNow{std::chrono::system_clock::now()};

		if (!this->sFirstTimepoint)
		{
			this->sFirstTimepoint = sNow;
			this->sLastTimepoint = sNow;
		}

		void *pBufferData;

		if (vkMapMemory(this->pContext->device().vulkanDevice(), this->sDeviceMemoryList[nImageIndex], 0, this->sDeviceMemorySizeList[nImageIndex], 0, &pBufferData) != VkResult::VK_SUCCESS)
			throw std::runtime_error{"unable to map buffer"};
		
		using fseconds = std::chrono::duration<float>;

		auto nTotal = std::chrono::duration_cast<fseconds>(sNow - *this->sFirstTimepoint).count();
		auto nDelta = std::chrono::duration_cast<fseconds>(sNow - *this->sLastTimepoint).count();

		float vData[]
		{
			nTotal,
			1.f / std::max(1e-6f, nTotal),
			nDelta,
			1.f / std::max(1e-6f, nDelta)
		};
		std::memcpy(pBufferData, vData, sizeof(vData));

		vkUnmapMemory(this->pContext->device().vulkanDevice(), this->sDeviceMemoryList[nImageIndex]);

		this->sLastTimepoint = sNow;
	}
}