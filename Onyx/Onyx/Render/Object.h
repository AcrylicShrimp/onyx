
/*
	2019.07.02
	Created by AcrylicShrimp.
*/

#ifndef _CLASS_ONYX_RENDER_OBJECT_H

#define _CLASS_ONYX_RENDER_OBJECT_H

#include "./Material.h"
#include "./Mesh.h"
#include "./Shader.h"
#include "../Transform/Mats.h"

#include "../Vulkan.h"

#include <cstdint>
#include <memory>
#include <stdexcept>

namespace Onyx::Render
{
	class Context;

	class Object
	{
	public:
		Context const *pContext;

	private:
		std::unique_ptr<Material> pMaterial;
		VkDeviceMemory vkDeviceMemory;
		VkBuffer vkBuffer;

	public:
		Object(Context *pContext, Mesh *pMesh, Shader *pShader, Transform::Mat44f sMatrix);
		Object(const Object &sSrc) = delete;
		~Object();
		
	public:
		Object &operator=(const Object &sSrc) = delete;
		
	public:
		inline Material *material() const;
		inline VkBuffer buffer() const;
	};

	inline Material *Object::material() const
	{
		return this->pMaterial.get();
	}

	inline VkBuffer Object::buffer() const
	{
		return this->vkBuffer;
	}
}

#endif