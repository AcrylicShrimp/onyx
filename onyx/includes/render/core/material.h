
#ifndef _ONYX_RENDER_CORE_MATERIAL_H

#define _ONYX_RENDER_CORE_MATERIAL_H

#include "onyx/includes/core/vulkan.h"

#include <cstdint>
#include <tuple>
#include <vector>

namespace onyx::core {
	class Context;
}

namespace onyx::render::core {
	class Shader;
}

namespace onyx::render::core {
	class Material final {
	public:
		const ::onyx::core::Context *const pContext;
		const Shader *const				   pShader;

	private:
		VkPipeline		 sPipeline;
		VkPipelineLayout sPipelineLayout;

	public:
		Material(
			const ::onyx::core::Context *						  pContext,
			const Shader *										  pShader,
			std::uint32_t										  nStride,
			std::vector<std::tuple<std::uint32_t, std::uint32_t>> sLocationOffsetVec);
		Material(const Material &sRhs) = delete;
		~Material() noexcept;

	public:
		Material &operator=(const Material &sRhs) = delete;

	public:
		VkPipeline pipeline() const noexcept
		{
			return this->sPipeline;
		}
		VkPipelineLayout pipelineLayout() const noexcept
		{
			return this->sPipelineLayout;
		}
	};
}	 // namespace onyx::render::core

#endif