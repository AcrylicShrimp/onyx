
#include "onyx/includes/render/core/meshElement.h"

namespace onyx::render::core {
	MeshElement::MeshElement(VkFormat eFormat, VkDeviceSize nSize, const void *pData) :
		eFormat{eFormat},
		nSize{nSize},
		pData{pData}
	{
		// Empty.
	}
}	 // namespace onyx::render::core