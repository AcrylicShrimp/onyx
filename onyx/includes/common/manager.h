
#ifndef _ONYX_COMMON_MANAGER_H

#define _ONYX_COMMON_MANAGER_H

namespace onyx {
	class Onyx;
}	 // namespace onyx

namespace onyx::common {

	class Manager {
	public:
		Onyx *const pInstance;

	public:
		Manager(Onyx *pInstance);
		Manager(const Manager &sRhs) noexcept = default;
		~Manager() noexcept					  = default;

	public:
		Manager &operator=(const Manager &sRhs) = delete;
	};
}	 // namespace onyx::common

#endif