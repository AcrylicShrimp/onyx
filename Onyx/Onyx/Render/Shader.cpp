
/*
	2019.05.12
	Created by AcrylicShrimp.
*/

#include "Shader.h"

#include "Context.h"

namespace Onyx::Render
{
	Shader::Shader(Context *pContext, std::string_view sName) :
		pContext{pContext},
		sName{sName}
	{
		assert(this->pContext);
	}

	Shader::~Shader() noexcept
	{
		for (auto &sPair : this->sStageMap)
			vkDestroyShaderModule(this->pContext->device().vulkanDevice(), std::get<0>(sPair.second), nullptr);
	}

	void Shader::attachStage(Stage eStage, std::size_t nCodeSize, const std::uint32_t *pCode, const std::string &sStageName)
	{
		assert(pCode);

		if (!nCodeSize)
			throw std::runtime_error{"code size must be greater then 0"};

		if (nCodeSize % 4)
			throw std::runtime_error{"code size must be a multiple of 4"};

		if (this->sStageMap.contains(eStage))
			throw std::runtime_error{"already attached stage"};

		VkShaderModule vkShaderModule;
		VkShaderModuleCreateInfo vkShaderModuleCreateInfo
		{
			VkStructureType::VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO,
			nullptr,
			0,
			nCodeSize,
			pCode
		};

		if (vkCreateShaderModule(this->pContext->device().vulkanDevice(), &vkShaderModuleCreateInfo, nullptr, &vkShaderModule) != VkResult::VK_SUCCESS)
			throw std::runtime_error{"unable to create shader module"};

		this->sStageMap.emplace(eStage, std::make_tuple(vkShaderModule, sStageName));
	}
}