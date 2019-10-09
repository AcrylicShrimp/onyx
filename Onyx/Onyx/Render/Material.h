
/*
	2019.05.24
	Created by AcrylicShrimp.
*/

#ifndef _CLASS_ONYX_RENDER_MATERIAL_H

#define _CLASS_ONYX_RENDER_MATERIAL_H

#include "./Mesh.h"
#include "./MeshLayout.h"
#include "./Shader.h"

#include <cassert>
#include <cstdint>
#include <stdexcept>
#include <unordered_map>
#include <vector>

namespace Onyx::Render
{
	class Context;

	class Material final
	{
	public:
		Context *const pContext;
		const Shader *const pShader;
		const MeshLayout *const pMeshLayout;

	private:
		VkPipeline vkPipeline;

	public:
		Material(Context *pContext, const Shader *pShader, const MeshLayout *pMeshLayout, const std::unordered_map<std::uint32_t, std::uint32_t> &sLocationOffsetMapping);
		Material(const Material &sSrc) = delete;
		~Material();
		
	public:
		Material &operator=(const Material &sSrc) = delete;
		
	public:
		inline VkPipeline vulkanPipeline() const;
	};

	inline VkPipeline Material::vulkanPipeline() const
	{
		return this->vkPipeline;
	}
}

#endif