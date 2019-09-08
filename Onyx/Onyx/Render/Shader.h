
/*
	2019.05.12
	Created by AcrylicShrimp.
*/

#ifndef _CLASS_ONYX_RENDER_SHADER_H

#define _CLASS_ONYX_RENDER_SHADER_H

#include "../Vulkan.h"

#include <cassert>
#include <cstddef>
#include <cstdint>
#include <stdexcept>
#include <unordered_map>
#include <utility>
#include <vector>

namespace Onyx::Render
{
	class Context;

	class Shader final
	{
	public:
		enum class Stage
		{
			Vertex = VkShaderStageFlagBits::VK_SHADER_STAGE_VERTEX_BIT,
			Fragment = VkShaderStageFlagBits::VK_SHADER_STAGE_FRAGMENT_BIT
		};

	public:
		Context *const pContext;
		const std::unordered_map<Stage, VkShaderModule> sStageModuleMap;

	public:
		Shader(Context *pContext, std::unordered_map<Stage, VkShaderModule> &&sStageModuleMap);
		Shader(const Shader &sSrc) = delete;
		Shader(Shader &&sSrc) = default;
		~Shader() noexcept;
		
	public:
		Shader &operator=(const Shader &sSrc) = delete;
		Shader &operator=(Shader &&sSrc) = default;
	};
}

#endif