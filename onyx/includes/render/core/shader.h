
#ifndef _ONYX_RENDER_CORE_SHADER_H

#define _ONYX_RENDER_CORE_SHADER_H

#include "onyx/includes/core/vulkan.h"

#include <cstdint>
#include <optional>
#include <string>
#include <unordered_map>
#include <vector>

namespace onyx::core {
	class Context;
}

namespace onyx::render::core {
	class Shader final {
	public:
		const ::onyx::core::Context *const pContext;

	private:
		std::optional<std::tuple<VkShaderModule, std::string>> sVertexShader;
		std::optional<std::tuple<VkShaderModule, std::string>> sFragmentShader;
		std::unordered_map<std::uint32_t, VkFormat>			   sLocationFormatMap;

	public:
		Shader(const ::onyx::core::Context *pContext);
		Shader(const Shader &sRhs) = delete;
		~Shader() noexcept;

	public:
		Shader &operator=(const Shader &sRhs) = delete;

	public:
		void attachVertexStage(std::size_t nCodeSize, const std::uint32_t *pCode, std::string sEntryPoint);
		void attachFragmentStage(std::size_t nCodeSize, const std::uint32_t *pCode, std::string sEntryPoint);

	public:
		const std::optional<std::tuple<VkShaderModule, std::string>> &vertexShader() const noexcept
		{
			return this->sVertexShader;
		}
		const std::optional<std::tuple<VkShaderModule, std::string>> &fragmentShader() const noexcept
		{
			return this->sFragmentShader;
		}
		const std::unordered_map<std::uint32_t, VkFormat> &locationFormatMap() const noexcept
		{
			return this->sLocationFormatMap;
		}
	};
}	 // namespace onyx::render::core

#endif