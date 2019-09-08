
/*
	2019.08.04
	Created by AcrylicShrimp.
*/

#ifndef _CLASS_ONYX_RENDER_SHADERBUILDER_H

#define _CLASS_ONYX_RENDER_SHADERBUILDER_H

#include "../Vulkan.h"

#include "./MeshLayout.h"
#include "./Shader.h"

#include <cassert>
#include <cstddef>
#include <cstdint>
#include <istream>
#include <stdexcept>
#include <tuple>
#include <unordered_map>
#include <vector>

namespace Onyx::Render
{
	class Context;

	class ShaderBuilder final
	{
	public:
		Context *const pContext;

	private:
		std::unordered_map<Shader::Stage, std::vector<std::uint32_t>> sStageCodeMap;
		
	public:
		ShaderBuilder(Context *pContext);
		ShaderBuilder(const ShaderBuilder &sSrc) = default;
		ShaderBuilder(ShaderBuilder &&sSrc) noexcept = default;
		~ShaderBuilder() noexcept = default;
		
	public:
		ShaderBuilder &operator=(const ShaderBuilder &sSrc) = default;
		ShaderBuilder &operator=(ShaderBuilder &&sSrc) noexcept = default;
		
	public:
		ShaderBuilder &stage(Shader::Stage eStage, std::istream &sStream);
		Shader build();
	};
}

#endif