
#include "onyx/includes/render/core/shader.h"

#include "onyx/includes/core/context.h"
#include "onyx/includes/core/deviceManager.h"
#include "spirv_reflect.h"

#include <cassert>
#include <stdexcept>

namespace onyx::render::core {
	Shader::Shader(const ::onyx::core::Context *pContext) : pContext{pContext} {}

	Shader::~Shader() noexcept {}

	void Shader::attachVertexStage(std::size_t nCodeSize, const std::uint32_t *pCode, std::string sEntryPoint)
	{
		assert(pCode);

		if (!nCodeSize) throw std::runtime_error{"code size must be greater then 0"};

		if (nCodeSize % 4) throw std::runtime_error{"code size must be a multiple of 4"};

		if (this->sVertexShader) throw std::runtime_error{"vertex stage already attached"};

		VkShaderModule			 sShaderModule;
		VkShaderModuleCreateInfo sShaderModuleCreateInfo{
			VkStructureType::VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO,
			nullptr,
			0,
			nCodeSize,
			pCode};

		if (vkCreateShaderModule(
				this->pContext->deviceMgr().vulkanDevice(),
				&sShaderModuleCreateInfo,
				nullptr,
				&sShaderModule)
			!= VkResult::VK_SUCCESS)
			throw std::runtime_error{"unable to create shader module"};

		this->sVertexShader = std::make_tuple(sShaderModule, sEntryPoint);

		SpvReflectShaderModule sReflectShaderModule;

		if (spvReflectCreateShaderModule(nCodeSize, pCode, &sReflectShaderModule)
			!= SpvReflectResult::SPV_REFLECT_RESULT_SUCCESS)
			throw std::runtime_error{"unable to create reflect shader module"};

		std::uint32_t nShaderInputCount;

		if (spvReflectEnumerateEntryPointInputVariables(
				&sReflectShaderModule,
				sEntryPoint.c_str(),
				&nShaderInputCount,
				nullptr)
			!= SpvReflectResult::SPV_REFLECT_RESULT_SUCCESS)
			throw std::runtime_error{"unable to fetch shader input variable count"};

		std::vector<SpvReflectInterfaceVariable *> sShaderInputList(nShaderInputCount);

		if (spvReflectEnumerateEntryPointInputVariables(
				&sReflectShaderModule,
				sEntryPoint.c_str(),
				&nShaderInputCount,
				sShaderInputList.data())
			!= SpvReflectResult::SPV_REFLECT_RESULT_SUCCESS)
			throw std::runtime_error{"unable to get shader input variable list"};

		for (const auto *pInput: sShaderInputList) {
			auto eFormat{static_cast<VkFormat>(pInput->format)};

			switch (eFormat) {
			case VkFormat::VK_FORMAT_R32_SFLOAT: {
				if (pInput->numeric.scalar.width == 16) eFormat = VkFormat::VK_FORMAT_R16_SFLOAT;
				else if (pInput->numeric.scalar.width == 64)
					eFormat = VkFormat::VK_FORMAT_R64_SFLOAT;
			} break;
			case VkFormat::VK_FORMAT_R32G32_SFLOAT: {
				if (pInput->numeric.scalar.width == 16) eFormat = VkFormat::VK_FORMAT_R16G16_SFLOAT;
				else if (pInput->numeric.scalar.width == 64)
					eFormat = VkFormat::VK_FORMAT_R64G64_SFLOAT;
			} break;
			case VkFormat::VK_FORMAT_R32G32B32_SFLOAT: {
				if (pInput->numeric.scalar.width == 16) eFormat = VkFormat::VK_FORMAT_R16G16B16_SFLOAT;
				else if (pInput->numeric.scalar.width == 64)
					eFormat = VkFormat::VK_FORMAT_R64G64B64_SFLOAT;
			} break;
			case VkFormat::VK_FORMAT_R32G32B32A32_SFLOAT: {
				if (pInput->numeric.scalar.width == 16) eFormat = VkFormat::VK_FORMAT_R16G16B16A16_SFLOAT;
				else if (pInput->numeric.scalar.width == 64)
					eFormat = VkFormat::VK_FORMAT_R64G64B64A64_SFLOAT;
			} break;
			default: break;
			}

			auto nLocation{pInput->location};
			auto fSpecifyLayoutNext{[this, pInput, eFormat, &nLocation]() {
				for (std::uint32_t nRow{0}, nMaxRow{std::max(1u, pInput->numeric.matrix.row_count)}; nRow < nMaxRow;
					 ++nRow, ++nLocation)
					this->sLocationFormatMap.emplace(nLocation, eFormat);
			}};

			if (!pInput->array.dims_count) {
				fSpecifyLayoutNext();
				continue;
			}

			std::uint32_t nLayoutCount{1};

			for (std::uint32_t nArrayDimIndex{0}, nMaxArrayDimIndex{std::max(1u, pInput->array.dims_count)};
				 nArrayDimIndex < nMaxArrayDimIndex;
				 ++nArrayDimIndex)
				nLayoutCount *= pInput->array.dims[nArrayDimIndex];

			for (std::uint32_t nLayout{0}; nLayout < nLayoutCount; ++nLayout) fSpecifyLayoutNext();
		}

		spvReflectDestroyShaderModule(&sReflectShaderModule);
	}

	void Shader::attachFragmentStage(std::size_t nCodeSize, const std::uint32_t *pCode, std::string sEntryPoint)
	{
		assert(pCode);

		if (!nCodeSize) throw std::runtime_error{"code size must be greater then 0"};

		if (nCodeSize % 4) throw std::runtime_error{"code size must be a multiple of 4"};

		if (this->sFragmentShader) throw std::runtime_error{"fragment stage already attached"};

		VkShaderModule			 sShaderModule;
		VkShaderModuleCreateInfo sShaderModuleCreateInfo{
			VkStructureType::VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO,
			nullptr,
			0,
			nCodeSize,
			pCode};

		if (vkCreateShaderModule(
				this->pContext->deviceMgr().vulkanDevice(),
				&sShaderModuleCreateInfo,
				nullptr,
				&sShaderModule)
			!= VkResult::VK_SUCCESS)
			throw std::runtime_error{"unable to create shader module"};

		this->sFragmentShader = std::make_tuple(sShaderModule, sEntryPoint);
	}
}	 // namespace onyx::render::core