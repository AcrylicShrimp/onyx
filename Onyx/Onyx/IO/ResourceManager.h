
/*
	2019.10.13
	Created by AcrylicShrimp.
*/

#ifndef _CLASS_ONYX_IO_RESOURCEMANAGER_H

#define _CLASS_ONYX_IO_RESOURCEMANAGER_H

#include "../Render/SubContextManager.h"

#include <cstdint>
#include <istream>
#include <memory>
#include <vector>
#include <tuple>

namespace Onyx::IO
{
	class ResourceManager final : public Render::SubContextManager
	{
	public:
		ResourceManager(Render::Context *pContext);
		ResourceManager(const ResourceManager &sSrc) noexcept = default;
		~ResourceManager() noexcept = default;
		
	public:
		ResourceManager &operator=(const ResourceManager &sSrc) noexcept = default;
		
	public:
		std::tuple<std::uint32_t, std::uint32_t, std::uint32_t, std::vector<unsigned char>> loadImage(std::istream &sInput) const;
	};
}

#endif