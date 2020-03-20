
#include "onyx/includes/common/version.h"

#include <utility>

namespace onyx::common {
	Version::Version(std::string &&sName, std::uint16_t nMajor, std::uint16_t nMinor, std::uint16_t nPatch) :
		sName{std::move(sName)},
		nMajor{nMajor},
		nMinor{nMinor},
		nPatch{nPatch}
	{
		if (this->nMajor > 0x7FF) throw std::runtime_error{"major version must be 10 bit"};

		if (this->nMinor > 0x7FF) throw std::runtime_error{"minor version must be 10 bit"};

		if (this->nPatch > 0x1FFF) throw std::runtime_error{"patch version must be 12 bit"};
	}
}	 // namespace onyx