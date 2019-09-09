
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
#include <stdexcept>
#include <vector>

namespace Onyx::Render
{
	class Context;

	class Material final
	{
	public:
		Context *const pContext;
		Shader *const pShader;

	private:
		VkPipeline vkPipeline;

	public:
		Material(Context *pContext, Shader *pShader);
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