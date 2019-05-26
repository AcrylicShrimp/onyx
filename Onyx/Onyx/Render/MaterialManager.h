
/*
	2019.05.25
	Created by AcrylicShrimp.
*/

#ifndef _CLASS_ONYX_RENDER_MATERIALMANAGER_H

#define _CLASS_ONYX_RENDER_MATERIALMANAGER_H

#include "./Material.h"
#include "./Mesh.h"
#include "./Shader.h"
#include "./SubContextManager.h"

#include "../Vulkan.h"

#include <memory>

namespace Onyx::Render
{
	class MaterialManager final : public SubContextManager
	{
	private:
		
		
	public:
		MaterialManager(Context *pContext);
		MaterialManager(const MaterialManager &sSrc) = delete;
		~MaterialManager() noexcept;
		
	public:
		MaterialManager &operator=(const MaterialManager &sSrc) = delete;
		
	public:
		//std::unique_ptr<Material> createMaterial(Mesh *pMesh, Shader *pShader);
	};
}

#endif