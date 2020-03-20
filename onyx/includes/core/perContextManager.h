
#ifndef _ONYX_CORE_PERCONTEXTMANAGER_H

#define _ONYX_CORE_PERCONTEXTMANAGER_H

namespace onyx::core {
	class Context;
	class DeviceInfo;
}	 // namespace onyx::core

namespace onyx::core {
	class PerContextManager {
	public:
		Context *const pContext;

	public:
		PerContextManager(Context *pContext);
		PerContextManager(const PerContextManager &sRhs) = delete;
		virtual ~PerContextManager() noexcept			 = default;

	public:
		virtual bool isCompatible(const DeviceInfo &sDevice);
		virtual void init(const DeviceInfo &sDevice) = 0;
		virtual void fin()							 = 0;
	};
}	 // namespace onyx::core

#endif