
/*
	2019.05.12
	Created by AcrylicShrimp.
*/

#ifndef _CLASS_ONYX_RENDER_SHADER_H

#define _CLASS_ONYX_RENDER_SHADER_H

#include "../Vulkan.h"

#include "./ShaderLayout.h"

#include <cassert>
#include <cstddef>
#include <cstdint>
#include <stdexcept>
#include <string>
#include <string_view>
#include <tuple>
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
		ShaderLayout sShaderLayout;
		std::unordered_map<Stage, std::tuple<VkShaderModule, std::string>> sStageMap;

	public:
		Shader(Context *pContext, std::string_view sName);
		Shader(const Shader &sSrc) = delete;
		~Shader() noexcept;
		
	public:
		Shader &operator=(const Shader &sSrc) = delete;
		
	public:
		inline const ShaderLayout &layout() const;
		inline const std::unordered_map<Stage, std::tuple<VkShaderModule, std::string>> &stageMap() const;
		void attachStage(Stage eStage, std::size_t nCodeSize, const std::uint32_t *pCode, const std::string &sEntryPointName);
	};

	inline const ShaderLayout &Shader::layout() const
	{
		return this->sShaderLayout;
	}

	inline const std::unordered_map<Shader::Stage, std::tuple<VkShaderModule, std::string>> &Shader::stageMap() const
	{
		return this->sStageMap;
	}
}

#endif