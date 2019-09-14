
/*
	2019.05.19
	Created by AcrylicShrimp.
*/

#include "Mesh.h"

#include "./Context.h"

namespace Onyx::Render
{
	Mesh::Mesh(Context *pContext, const MeshLayout &sMeshLayout, VkDeviceSize nSize, const void *pData) :
		pContext{pContext},
		sMeshLayout{sMeshLayout},
		sBuffer{pContext, Buffer::Usage::VertexBuffer, nSize}
	{
		assert(this->pContext);

		this->sBuffer.map([pData, nSize](void *pDestination)
			{
				std::memcpy(pDestination, pData, nSize);
			});
	}
}