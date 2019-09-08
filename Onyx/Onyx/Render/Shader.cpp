
/*
	2019.05.12
	Created by AcrylicShrimp.
*/

#include "Shader.h"

#include "./Context.h"

namespace Onyx::Render
{
	Shader::Shader(Context *pContext, std::unordered_map<Stage, VkShaderModule> &&sStageModuleMap) :
		pContext{pContext},
		sStageModuleMap{std::move(sStageModuleMap)}
	{
		assert(this->pContext);
	}

	Shader::~Shader() noexcept
	{
		for (auto &sPair : this->sStageModuleMap)
			vkDestroyShaderModule(this->pContext->device().vulkanDevice(), sPair.second, nullptr);
	}
}