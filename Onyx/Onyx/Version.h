
/*
	2019.05.04
	Created by AcrylicShrimp.
*/

#ifndef _CLASS_ONYX_VERSION_H

#define _CLASS_ONYX_VERSION_H

#include <cstdint>
#include <stdexcept>
#include <string_view>

namespace Onyx
{
	class Version final
	{
	public:
		const std::string_view sName;
		const std::uint16_t nMajor;
		const std::uint16_t nMinor;
		const std::uint16_t nPatch;

	public:
		Version(std::string_view sName, std::uint16_t nMajor, std::uint16_t nMinor, std::uint16_t nPatch);
		Version(const Version &sSrc) noexcept = default;
		~Version() noexcept = default;
		
	public:
		Version &operator=(const Version &sSrc) noexcept = default;
	};
}

#endif