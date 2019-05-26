
/*
	2019.05.12
	Created by AcrylicShrimp.
*/

#ifndef _CLASS_ONYX_RENDER_SHADERMANAGER_H

#define _CLASS_ONYX_RENDER_SHADERMANAGER_H

#include "./SubContextManager.h"
#include "./Shader.h"

#include <stdexcept>
#include <string>
#include <string_view>
#include <tuple>
#include <unordered_map>

namespace Onyx::Render
{
	class ShaderManager final : public SubContextManager
	{
	private:
		std::unordered_map<std::string, Shader> sShaderMap;
		
	public:
		ShaderManager(Context *pContext);
		ShaderManager(const ShaderManager &sSrc) = delete;
		~ShaderManager() noexcept = default;
		
	public:
		ShaderManager &operator=(const ShaderManager &sSrc) = delete;
		
	public:
		Shader *createShader(const std::string &sShaderName);
		void deleteShader(const std::string &sShaderName);
		Shader *findShader(const std::string &sShaderName);
		const Shader *findShader(const std::string &sShaderName) const;
	};
}

#endif