
/*
	2019.05.19
	Created by AcrylicShrimp.
*/

#ifndef _CLASS_ONYX_RENDER_MESH_H

#define _CLASS_ONYX_RENDER_MESH_H

#include "../Vulkan.h"

#include "./Buffer.h"
#include "./MeshLayout.h"

#include <cstring>

namespace Onyx::Render
{
	class Context;

	class Mesh
	{
	public:
		Context *const pContext;
		const MeshLayout sMeshLayout;

	private:
		Buffer sBuffer;
		
	public:
		Mesh(Context *pContext, const MeshLayout &sMeshLayout, VkDeviceSize nSize, const void *pData);
		Mesh(const Mesh &sSrc) = delete;
		~Mesh() noexcept = default;
		
	public:
		Mesh &operator=(const Mesh &sSrc) = delete;
		
	public:
		inline const Buffer &buffer() const;
	};

	inline const Buffer &Mesh::buffer() const
	{

	}
}

#endif