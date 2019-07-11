
/*
	2019.05.12
	Created by AcrylicShrimp.
*/

#ifndef _CLASS_ONYX_RENDER_RENDERINGMANAGER_H

#define _CLASS_ONYX_RENDER_RENDERINGMANAGER_H

#include "./SubContextManager.h"

#include "../Vulkan.h"

#include <fstream>
#include <vector>

namespace Onyx::Render
{
	class Object;

	class RenderingManager final : public SubContextManager
	{
	private:
		VkRenderPass vkRenderPass;
		//VkPipeline vkGBufferPipeline;
		//VkPipelineLayout vkGBufferPipelineLayout;
		//std::vector<VkFramebuffer> sPositionGBuffer;
		//std::vector<VkFramebuffer> sNormalGBuffer;
		//std::vector<VkFramebuffer> sColorGBuffer;
		//std::vector<VkFramebuffer> sDepthFramebufferList;
		std::vector<VkFramebuffer> sFinalFramebufferList;

	public:
		RenderingManager(Context *pContext);
		RenderingManager(const RenderingManager &sSrc) = delete;
		~RenderingManager();

	public:
		RenderingManager &operator=(const RenderingManager &sSrc) = delete;

	public:
		inline VkRenderPass vulkanRenderPass() const;
		void render(std::uint32_t nImageIndex, VkCommandBuffer vkCommandBuffer, const Object &sObject);
	};

	inline VkRenderPass RenderingManager::vulkanRenderPass() const
	{
		return this->vkRenderPass;
	}
}

#endif