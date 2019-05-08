
/*
	2019.05.08
	Created by AcrylicShrimp.
*/

#ifndef _CLASS_ONYX_RENDER_TEST__TRIANGLERENDERPASS_H

#define _CLASS_ONYX_RENDER_TEST__TRIANGLERENDERPASS_H

#include "../Vulkan.h"
#include "./Context.h"

#include <cassert>
#include <cstddef>
#include <fstream>
#include <stdexcept>
#include <string_view>
#include <vector>

namespace Onyx::Render
{
	class TEST__TriangleRenderPass
	{
	public:
		Context *const pContext;

	private:
		VkRenderPass vkRenderPass;
		VkPipeline vkPipeline;
		VkPipelineLayout vkPipelineLayout;
		std::vector<VkFramebuffer> sFramebufferList;
		
	public:
		TEST__TriangleRenderPass(Context *pContext);
		TEST__TriangleRenderPass(const TEST__TriangleRenderPass &sSrc) = delete;
		~TEST__TriangleRenderPass() noexcept;
		
	public:
		TEST__TriangleRenderPass &operator=(const TEST__TriangleRenderPass &sSrc) = delete;
		
	public:
		inline VkPipeline vulkanPipeline() const;
		inline VkRenderPass vulkanRenderPass() const;
		inline const std::vector<VkFramebuffer> &vulkanFramebufferList() const;
	};

	inline VkPipeline TEST__TriangleRenderPass::vulkanPipeline() const
	{
		return this->vkPipeline;
	}

	inline VkRenderPass TEST__TriangleRenderPass::vulkanRenderPass() const
	{
		return this->vkRenderPass;
	}

	inline const std::vector<VkFramebuffer> &TEST__TriangleRenderPass::vulkanFramebufferList() const
	{
		return this->sFramebufferList;
	}
}

#endif