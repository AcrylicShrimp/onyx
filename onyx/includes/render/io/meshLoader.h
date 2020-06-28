
#ifndef _ONYX_RENDER_IO_MESHLOADER_H

#define _ONYX_RENDER_IO_MESHLOADER_H

#include <memory>
#include <string>

namespace onyx {
	namespace core {
		class Context;
	}	 // namespace core
	namespace render::core {
		class Mesh;
	}	 // namespace render::core
}	 // namespace onyx

namespace onyx::render::io {
	class MeshLoader final {
	public:
		MeshLoader() = delete;

	public:
		static std::unique_ptr<::onyx::render::core::Mesh>
			loadMeshOBJ(const ::onyx::core::Context *pContext, const std::string &sContent);
	};
}	 // namespace onyx::render::io

#endif