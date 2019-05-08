
/*
	2019.05.04
	Created by AcrylicShrimp.
*/

#include "Version.h"

namespace Onyx
{
	Version::Version(std::string_view sName, std::uint16_t nMajor, std::uint16_t nMinor, std::uint16_t nPatch) :
		sName{sName},
		nMajor{nMajor},
		nMinor{nMinor},
		nPatch{nPatch}
	{
		if (this->nMajor > 0x7FF)
			throw std::runtime_error{"major version must be 10 bit"};

		if (this->nMinor > 0x7FF)
			throw std::runtime_error{"minor version must be 10 bit"};

		if (this->nPatch > 0x1FFF)
			throw std::runtime_error{"patch version must be 12 bit"};
	}
}