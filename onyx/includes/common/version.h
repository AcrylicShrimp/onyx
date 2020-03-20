
#ifndef _ONYX_COMMON_VERSION_H

#define _ONYX_COMMON_VERSION_H

#include <cstdint>
#include <stdexcept>
#include <string>

namespace onyx::common {
	class Version final {
	public:
		const std::string	sName;
		const std::uint16_t nMajor;
		const std::uint16_t nMinor;
		const std::uint16_t nPatch;

	public:
		Version(std::string &&sName, std::uint16_t nMajor, std::uint16_t nMinor, std::uint16_t nPatch);
		Version(const Version &sVersion) = default;
		Version(Version &&sVersion)		 = default;
		~Version() noexcept				 = default;
	};
}	 // namespace onyx::common

#endif