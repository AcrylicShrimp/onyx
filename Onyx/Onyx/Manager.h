
/*
	2019.05.05
	Created by AcrylicShrimp.
*/

#ifndef _CLASS_ONYX_MANAGER_H

#define _CLASS_ONYX_MANAGER_H

#include <cassert>

namespace Onyx
{
	class Onyx;

	class Manager
	{
	public:
		Onyx *const pInstance;
		
	public:
		Manager(Onyx *pInstance);
		Manager(const Manager &sSrc) noexcept = default;
		~Manager() noexcept = default;
		
	public:
		Manager &operator=(const Manager &sSrc) noexcept = default;
		
	public:
		virtual void initialize() = 0;
		virtual void finalize() = 0;
	};
}

#endif