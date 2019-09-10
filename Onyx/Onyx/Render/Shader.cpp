
/*
	2019.05.12
	Created by AcrylicShrimp.
*/

#include "Shader.h"

#include "./Context.h"

#include <SPIRV-Reflect/spirv_reflect.h>

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

	void Shader::attachStage(Stage eStage, std::size_t nCodeSize, const std::uint32_t *pCode, const std::string &sEntryPointName)
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

		this->sStageMap.emplace(eStage, std::make_tuple(vkShaderModule, sEntryPointName));

		if (eStage == Stage::Vertex)
		{
			SpvReflectShaderModule sReflectShaderModule;

			if (spvReflectCreateShaderModule(nCodeSize, pCode, &sReflectShaderModule) != SpvReflectResult::SPV_REFLECT_RESULT_SUCCESS)
				throw std::runtime_error{"unable to create reflect shader module"};

			std::uint32_t nShaderInputCount;

			if (spvReflectEnumerateEntryPointInputVariables(&sReflectShaderModule, sEntryPointName.c_str(), &nShaderInputCount, nullptr) != SpvReflectResult::SPV_REFLECT_RESULT_SUCCESS)
				throw std::runtime_error{"unable to fetch shader input variable count"};

			std::vector<SpvReflectInterfaceVariable *> sShaderInputList(nShaderInputCount);

			if (spvReflectEnumerateEntryPointInputVariables(&sReflectShaderModule, sEntryPointName.c_str(), &nShaderInputCount, sShaderInputList.data()) != SpvReflectResult::SPV_REFLECT_RESULT_SUCCESS)
				throw std::runtime_error{"unable to get shader input variable list"};

			for (const auto *pInput : sShaderInputList)
			{
				this->sShaderLayout.specifyLayout(pInput->location, VK_FORMAT_R32_UINT);
			}

			spvReflectDestroyShaderModule(&sReflectShaderModule);
		}
	}
}