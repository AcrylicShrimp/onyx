
#ifndef _ONYX_CORE_RENDERINGMANAGER_H

#define _ONYX_CORE_RENDERINGMANAGER_H

#include "onyx/includes/core/perContextManager.h"
#include "onyx/includes/core/vulkan.h"

#include <tuple>
#include <vector>

namespace onyx {
	namespace core {
		class Context;
		class DeviceInfo;
	}	 // namespace core
	namespace display {
		class Window;
	}	 // namespace display
	namespace render::core {
		class Material;
		class Mesh;
	}	 // namespace render::core
}	 // namespace onyx

namespace onyx::core {
	class RenderingManager : public PerContextManager {
	private:
		VkRenderPass			   sRenderPass;
		std::vector<VkFramebuffer> sFinalFramebufferVec;

	public:
		RenderingManager(Context *pContext);
		RenderingManager(const RenderingManager &sRhs) = delete;
		virtual ~RenderingManager() noexcept;

	public:
		virtual void init(const DeviceInfo &sDevice) override;
		virtual void fin() override;
		void		 render(
					const std::vector<std::tuple<const ::onyx::render::core::Material *, const ::onyx::render::core::Mesh *>>
						&sMaterialMeshVec);

	public:
		VkRenderPass renderPass() const noexcept
		{
			return this->sRenderPass;
		}
	};
}	 // namespace onyx::core

#endif