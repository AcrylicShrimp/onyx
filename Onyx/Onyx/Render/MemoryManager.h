
/*
	2019.10.13
	Created by AcrylicShrimp.
*/

#ifndef _CLASS_ONYX_RENDER_MEMORYMANAGER_H

#define _CLASS_ONYX_RENDER_MEMORYMANAGER_H

#include "../Vulkan.h"

#include "./SubContextManager.h"

#include <cstdint>
#include <optional>

namespace Onyx::Render
{
	class MemoryManager final : public SubContextManager
	{
	public:
		MemoryManager(Context *pContext);
		MemoryManager(const MemoryManager &sSrc) noexcept = default;
		~MemoryManager() noexcept = default;
		
	public:
		MemoryManager &operator=(const MemoryManager &sSrc) noexcept = default;
		
	public:
		VkDeviceMemory allocateBuffer(
			VkBuffer vkBuffer,
			VkMemoryPropertyFlags vkMemPropFlags) const;
		VkDeviceMemory allocateImage(
			VkImage vkImage,
			VkMemoryPropertyFlags vkMemPropFlags) const;

	private:
		VkDeviceMemory __allocateDeviceMemory(
			VkMemoryRequirements vkMemReq,
			VkMemoryPropertyFlags vkMemPropFlags
		) const;
	};
}

#endif