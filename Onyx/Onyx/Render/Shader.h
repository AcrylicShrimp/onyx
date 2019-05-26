
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
#include <string>
#include <string_view>
#include <unordered_map>
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
		const std::string sName;

	private:
		std::unordered_map<Stage, VkPipelineShaderStageCreateInfo> sStageMap;

	public:
		Shader(Context *pContext, std::string_view sName);
		Shader(const Shader &sSrc) = delete;
		~Shader() noexcept;
		
	public:
		Shader &operator=(const Shader &sSrc) = delete;
		
	public:
		void attachStage(Stage eStage, std::size_t nCodeSize, const std::uint32_t *pCode);
		std::vector<VkPipelineShaderStageCreateInfo> generateShaderStageCreateInfoList() const;
	};
}

#endif