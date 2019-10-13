
/*
	2019.05.04
	Created by AcrylicShrimp.
*/

#ifndef _CLASS_ONYX_RENDER_CONTEXT_H

#define _CLASS_ONYX_RENDER_CONTEXT_H

#include "../Vulkan.h"
#include "../Display/Window.h"
#include "../IO/ResourceManager.h"
#include "./Device.h"
#include "./Material.h"
#include "./MemoryManager.h"
#include "./Mesh.h"
#include "./MeshManager.h"
#include "./Surface.h"
#include "./Synchronizer.h"
#include "./Swapchain.h"
#include "./ShaderManager.h"
#include "./RenderingManager.h"
#include "./UniformManager.h"
#include "../Transform/Mats.h"

#include <algorithm>
#include <cassert>
#include <cstdint>
#include <cstring>
#include <iterator>
#include <limits>
#include <memory>
#include <stdexcept>
#include <string>
#include <string_view>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

namespace Onyx::Render
{
	class ContextManager;

	class Context final
	{
	public:
		ContextManager *const pContextManager;
		Display::Window *const pWindow;

	private:
		Device sDevice;
		Surface sSurface;
		Swapchain sSwapchain;
		Synchronizer sSynchronizer;
		VkQueue vkGraphicsQueue;
		VkQueue vkPresentQueue;
		std::uint32_t nGraphicsFamily;
		std::uint32_t nPresentFamily;
		std::unique_ptr<MemoryManager> pMemoryMgr;
		std::unique_ptr<UniformManager> pUniformMgr;
		std::unique_ptr<ShaderManager> pShaderMgr;
		std::unique_ptr<RenderingManager> pRenderingMgr;
		std::unique_ptr<IO::ResourceManager> pResourceMgr;
		std::unique_ptr<MeshManager> pMeshMgr;

	public:
		Context(ContextManager *pContextManager, Display::Window *pWindow);
		Context(const Context &sSrc) = delete;
		~Context() noexcept;

	public:
		Context &operator=(const Context &sSrc) = delete;

	public:
		inline const Device &device() const;
		inline const Surface &surface() const;
		inline const Swapchain &swapchain() const;
		inline const Synchronizer &synchronizer() const;
		inline MemoryManager &memoryMgr() const;
		inline UniformManager &uniformMgr() const;
		inline ShaderManager &shaderMgr() const;
		inline RenderingManager &renderingMgr() const;
		inline IO::ResourceManager &resourceMgr() const;
		inline MeshManager &meshMgr() const;
		void render(
			const Transform::Mat44f &sViewTransform,
			const Transform::Mat44f &sProjectionTransform,
			const std::vector<Transform::Mat44f> &sTransformList,
			const std::vector<std::tuple<Material *, Mesh *>> &sRenderableList);
	};

	inline const Device &Context::device() const
	{
		return this->sDevice;
	}

	inline const Surface &Context::surface() const
	{
		return this->sSurface;
	}

	inline const Swapchain &Context::swapchain() const
	{
		return this->sSwapchain;
	}

	inline const Synchronizer &Context::synchronizer() const
	{
		return this->sSynchronizer;
	}

	inline MemoryManager &Context::memoryMgr() const
	{
		return *this->pMemoryMgr;
	}

	inline UniformManager &Context::uniformMgr() const
	{
		return *this->pUniformMgr;
	}

	inline ShaderManager &Context::shaderMgr() const
	{
		return *this->pShaderMgr;
	}

	inline RenderingManager &Context::renderingMgr() const
	{
		return *this->pRenderingMgr;
	}

	inline IO::ResourceManager &Context::resourceMgr() const
	{
		return *this->pResourceMgr;
	}

	inline MeshManager &Context::meshMgr() const
	{
		return *this->pMeshMgr;
	}
}

#endif