
/*
	2019.05.25
	Created by AcrylicShrimp.
*/

#ifndef _CLASS_ONYX_RENDER_MESHMANAGER_H

#define _CLASS_ONYX_RENDER_MESHMANAGER_H

#include "./Mesh.h"
#include "./SubContextManager.h"

#include "../Vulkan.h"

#include <algorithm>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <iterator>
#include <memory>
#include <optional>
#include <sstream>
#include <stdexcept>
#include <string>
#include <tuple>
#include <unordered_map>
#include <vector>

namespace Onyx::Render
{
	class MeshManager final : public SubContextManager
	{
	private:
		std::unordered_map<std::string, std::tuple<VkDeviceMemory>> sMeshMap;
		
	public:
		MeshManager(Context *pContext);
		MeshManager(const MeshManager &sSrc) = delete;
		~MeshManager() noexcept;
		
	public:
		MeshManager &operator=(const MeshManager &sSrc) = delete;
		
	public:
		std::unique_ptr<Mesh> createMesh();
		std::unique_ptr<Mesh> loadMeshOBJ(const std::string &sContent);
	};
}

#endif