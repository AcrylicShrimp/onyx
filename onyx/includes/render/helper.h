
#ifndef _ONYX_RENDER_HELPER_H

#define _ONYX_RENDER_HELPER_H

#include "onyx/includes/core/vulkan.h"

#include <cstdint>

namespace onyx::render {
	std::uint32_t sizeFormat(VkFormat eFormat) noexcept;
}

#endif