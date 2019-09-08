
/*
	2019.08.04
	Created by AcrylicShrimp.
*/

#include "ShaderBuilder.h"

#include "./Context.h"

namespace Onyx::Render
{
	ShaderBuilder::ShaderBuilder(Context *pContext) :
		pContext{pContext}
	{
		assert(this->pContext);
	}

	ShaderBuilder &ShaderBuilder::stage(Shader::Stage eStage, std::istream &sStream)
	{
		if (this->sStageCodeMap.contains(eStage))
			throw std::runtime_error{"duplicated stage"};

		const auto nCursorPosition{sStream.tellg()};
		sStream.seekg(0, std::ios::end);

		const auto nCodeSize{sStream.tellg() - nCursorPosition};
		sStream.seekg(nCursorPosition);

		if (!nCodeSize)
			throw std::runtime_error{"code size must be greater than 0"};

		if (nCodeSize % 4)
			throw std::runtime_error{"code size must be multiple of 4"};

		std::vector<std::uint32_t> sCodeBuffer(static_cast<std::size_t>(nCodeSize));
		sStream.read(reinterpret_cast<char *>(sCodeBuffer.data()), nCodeSize);

		if (eStage == Shader::Stage::Vertex)
		{
			/*
				TODO : Analyse above code and generate mesh layout here.
			*/
		}

		this->sStageCodeMap[eStage] = std::move(sCodeBuffer);

		return *this;
	}

	Shader ShaderBuilder::build()
	{
		std::unordered_map<Shader::Stage, VkShaderModule> sStageModuleMap;

		for (const auto &sPair : this->sStageCodeMap)
		{
			VkShaderModuleCreateInfo vkShaderModuleCreateInfo
			{
				VkStructureType::VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO,
				nullptr,
				0,
				sPair.second.size(),
				sPair.second.data()
			};

			if (vkCreateShaderModule(this->pContext->device().vulkanDevice(), &vkShaderModuleCreateInfo, nullptr, &sStageModuleMap[sPair.first]) != VkResult::VK_SUCCESS)
				throw std::runtime_error{"unable to create shader module"};
		}

		return Shader{this->pContext, std::move(sStageModuleMap)};
	}
}