
/*
	2019.05.18
	Created by AcrylicShrimp.
*/

#ifndef _CLASS_ONYX_RENDER_BUFFER_H

#define _CLASS_ONYX_RENDER_BUFFER_H

#include "../Vulkan.h"

#include <cassert>
#include <cstddef>
#include <cstdint>
#include <functional>
#include <optional>

namespace Onyx::Render
{
	class Context;

	class Buffer final
	{
	public:
		enum Usage
		{
			VertexBuffer = VkBufferUsageFlagBits::VK_BUFFER_USAGE_VERTEX_BUFFER_BIT,
			UniformBuffer = VkBufferUsageFlagBits::VK_BUFFER_USAGE_UNIFORM_BUFFER_BIT,
			TransformSrc = VkBufferUsageFlagBits::VK_BUFFER_USAGE_TRANSFER_SRC_BIT
		};

	public:
		Context *const pContext;
		const Usage eUsage;

	private:
		VkBuffer vkBuffer;
		VkDeviceMemory vkDeviceMemory;
		VkDeviceSize nSize;
		
	public:
		Buffer(Context *pContext, Usage eUsage, VkDeviceSize nSize);
		Buffer(const Buffer &sSrc) = delete;
		Buffer(Buffer &&sSrc);
		~Buffer() noexcept;
		
	public:
		Buffer &operator=(const Buffer &sSrc) = delete;
		Buffer &operator=(Buffer &&sSrc);
		
	public:
		inline VkBuffer vulkanBuffer() const;
		inline VkDeviceSize size() const;
		void map(std::function<void(void *)> fMapFunction);
		void resize(VkDeviceSize nSize);
	};

	inline VkBuffer Buffer::vulkanBuffer() const
	{
		return this->vkBuffer;
	}

	inline VkDeviceSize Buffer::size() const
	{
		return this->nSize;
	}
}

#endif