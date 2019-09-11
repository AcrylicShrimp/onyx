
/*
	2019.05.12
	Created by AcrylicShrimp.
*/

#define NOMINMAX 1

#include "Shader.h"

#include "./Context.h"

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
				Shader::specifyLayout(this->sShaderLayout, pInput);

			spvReflectDestroyShaderModule(&sReflectShaderModule);
		}
	}

	void Shader::specifyLayout(ShaderLayout &sShaderLayout, const SpvReflectInterfaceVariable *pReflectShaderInputVariable)
	{
		auto vkFormat{static_cast<VkFormat>(pReflectShaderInputVariable->format)};

		switch (vkFormat)
		{
		case VkFormat::VK_FORMAT_R32_SFLOAT:
		{
			if (pReflectShaderInputVariable->numeric.scalar.width == 16)
				vkFormat = VkFormat::VK_FORMAT_R16_SFLOAT;
			else if (pReflectShaderInputVariable->numeric.scalar.width == 64)
				vkFormat = VkFormat::VK_FORMAT_R64_SFLOAT;
		}
		break;
		case VkFormat::VK_FORMAT_R32G32_SFLOAT:
		{
			if (pReflectShaderInputVariable->numeric.scalar.width == 16)
				vkFormat = VkFormat::VK_FORMAT_R16G16_SFLOAT;
			else if (pReflectShaderInputVariable->numeric.scalar.width == 64)
				vkFormat = VkFormat::VK_FORMAT_R64G64_SFLOAT;
		}
		break;
		case VkFormat::VK_FORMAT_R32G32B32_SFLOAT:
		{
			if (pReflectShaderInputVariable->numeric.scalar.width == 16)
				vkFormat = VkFormat::VK_FORMAT_R16G16B16_SFLOAT;
			else if (pReflectShaderInputVariable->numeric.scalar.width == 64)
				vkFormat = VkFormat::VK_FORMAT_R64G64B64_SFLOAT;
		}
		break;
		case VkFormat::VK_FORMAT_R32G32B32A32_SFLOAT:
		{
			if (pReflectShaderInputVariable->numeric.scalar.width == 16)
				vkFormat = VkFormat::VK_FORMAT_R16G16B16A16_SFLOAT;
			else if (pReflectShaderInputVariable->numeric.scalar.width == 64)
				vkFormat = VkFormat::VK_FORMAT_R64G64B64A64_SFLOAT;
		}
		break;
		}

		auto nLocation{pReflectShaderInputVariable->location};

		for (std::uint32_t nRow{0}, nMaxRow{std::min(1, pReflectShaderInputVariable->numeric.matrix.row_count)}; nRow < nMaxRow; ++nRow, ++nLocation)
			sShaderLayout.specifyLayout(nLocation, vkFormat);

		//FIXME
		for (std::uint32_t nArrayDimIndex{0}, nMaxArrayDimIndex{std::min(1, pReflectShaderInputVariable->array.dims_count)}; nRow < nMaxRow; ++nRow, ++nLocation)
			sShaderLayout.specifyLayout(nLocation, vkFormat);
	}
}