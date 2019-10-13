
/*
	2019.05.26
	Created by AcrylicShrimp.
*/

#ifndef _CLASS_ONYX_RENDER_UNIFORMMANAGER_H

#define _CLASS_ONYX_RENDER_UNIFORMMANAGER_H

#include "../Vulkan.h"

#include "./Buffer.h"
#include "./SubContextManager.h"
#include "./Texture.h"
#include "../Transform/Mats.h"

#include <algorithm>
#include <chrono>
#include <cstddef>
#include <cstdint>
#include <cstring>
#include <fstream>
#include <memory>
#include <optional>
#include <vector>

namespace Onyx::Render
{
	class UniformManager final : public SubContextManager
	{
	public:
		struct alignas(32) Time
		{
			float nTotal;
			float nTotalInv;
			float nDelta;
			float nDeltaInv;
		};

	private:
		VkDescriptorSetLayout vkDescriptorSetLayout;
		VkPipelineLayout vkPipelineLayout;
		VkDescriptorPool vkDescriptorPool;
		std::vector<Buffer> sTimeBufferList;
		std::vector<Buffer> sGlobalTransformBufferList;
		std::vector<VkDescriptorSet> sDescriptorSetList;
		std::optional<std::chrono::system_clock::time_point> sFirstTimepoint;
		std::optional<std::chrono::system_clock::time_point> sLastTimepoint;
		std::unique_ptr<Texture> pTexture;
		
	public:
		UniformManager(Context *pContext);
		UniformManager(const UniformManager &sSrc) = delete;
		~UniformManager() noexcept;
		
	public:
		UniformManager &operator=(const UniformManager &sSrc) = delete;
		
	public:
		inline VkPipelineLayout vulkanPipelineLayout() const;
		inline const std::vector<VkDescriptorSet> &vulkanDescriptorSetList() const;
		void updateUniform(
			std::uint32_t nImageIndex,
			const Transform::Mat44f &sViewTransform,
			const Transform::Mat44f &sProjectionTransform);
	};

	inline VkPipelineLayout UniformManager::vulkanPipelineLayout() const
	{
		return this->vkPipelineLayout;
	}

	inline const std::vector<VkDescriptorSet> &UniformManager::vulkanDescriptorSetList() const
	{
		return this->sDescriptorSetList;
	}
}

#endif