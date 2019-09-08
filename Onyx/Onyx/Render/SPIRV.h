
/*
	2019.08.05
	Created by AcrylicShrimp.
*/

#ifndef _CLASS_ONYX_RENDER_SPIRV_H

#define _CLASS_ONYX_RENDER_SPIRV_H

#include <cstddef>
#include <cstdint>
#include <vector>

namespace Onyx::Render
{
	class SPIRV final
	{
	private:
		std::vector<std::uint32_t> sCodeList;

	public:
		SPIRV();
		SPIRV(const SPIRV &sSrc) = default;
		SPIRV(SPIRV &&sSrc) noexcept = default;
		~SPIRV() noexcept = default;

	public:
		SPIRV &operator=(const SPIRV &sSrc) = default;
		SPIRV &operator=(SPIRV &&sSrc) noexcept = default;

	public:

	};
}

#endif