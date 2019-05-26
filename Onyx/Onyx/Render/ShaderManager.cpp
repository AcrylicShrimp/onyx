
/*
	2019.05.12
	Created by AcrylicShrimp.
*/

#include "ShaderManager.h"

namespace Onyx::Render
{
	ShaderManager::ShaderManager(Context *pContext) :
		SubContextManager{pContext}
	{
		//Empty.
	}

	Shader *ShaderManager::createShader(const std::string &sShaderName)
	{
		auto iIndex{this->sShaderMap.find(sShaderName)};

		if (iIndex != this->sShaderMap.cend())
			throw std::runtime_error{"this name is already taken"};

		auto iResult{this->sShaderMap.emplace(std::piecewise_construct, std::forward_as_tuple(sShaderName), std::forward_as_tuple(this->pContext, sShaderName))};

		if (!iResult.second)
			throw std::runtime_error{"unable to create shader"};

		return &iResult.first->second;
	}

	void ShaderManager::deleteShader(const std::string &sShaderName)
	{
		this->sShaderMap.erase(sShaderName);
	}

	Shader *ShaderManager::findShader(const std::string &sShaderName)
	{
		auto iIndex{this->sShaderMap.find(sShaderName)};

		if (iIndex == this->sShaderMap.cend())
			return nullptr;

		return &iIndex->second;
	}

	const Shader *ShaderManager::findShader(const std::string &sShaderName) const
	{
		auto iIndex{this->sShaderMap.find(sShaderName)};

		if (iIndex == this->sShaderMap.cend())
			return nullptr;

		return &iIndex->second;
	}
}