
/*
	2019.05.12
	Created by AcrylicShrimp.
*/

#ifndef _CLASS_ONYX_RENDER_RENDERINGMANAGER_H

#define _CLASS_ONYX_RENDER_RENDERINGMANAGER_H

#include "../Vulkan.h"

#include "./Buffer.h"
#include "./Material.h"
#include "./Mesh.h"
#include "./SubContextManager.h"
#include "../Transform/Mats.h"

#include <cstdint>
#include <cstring>
#include <fstream>
#include <tuple>
#include <vector>

namespace Onyx::Render
{
	class Material;

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
		std::vector<Buffer> sTransformBufferList;

	public:
		RenderingManager(Context *pContext);
		RenderingManager(const RenderingManager &sSrc) = delete;
		~RenderingManager();

	public:
		RenderingManager &operator=(const RenderingManager &sSrc) = delete;

	public:
		inline VkRenderPass vulkanRenderPass() const;
		void render(
			std::uint32_t nImageIndex,
			VkCommandBuffer vkCommandBuffer,
			const std::vector<Transform::Mat44<float>> &sTransformList,
			const std::vector<std::tuple<Material *, Mesh *>> &sRenderableList);
	};

	inline VkRenderPass RenderingManager::vulkanRenderPass() const
	{
		return this->vkRenderPass;
	}
}

#endif