
#include "onyx/includes/core/vulkan.h"

#include <cstdint>
#include <string>
#include <unordered_map>
#include <vector>

namespace onyx::core {
	class DeviceInfo final {
	private:
		VkPhysicalDevice							   sPhysicalDevice;
		VkPhysicalDeviceFeatures					   sFeatures;
		VkPhysicalDeviceProperties					   sProperties;
		VkPhysicalDeviceMemoryProperties			   sMemoryProperties;
		std::vector<VkQueueFamilyProperties>		   sQueueProperties;
		std::unordered_map<std::string, std::uint32_t> sExtensionProperties;

	public:
		DeviceInfo(VkPhysicalDevice sPhysicalDevice);
		DeviceInfo(const DeviceInfo &sRhs) = default;
		DeviceInfo(DeviceInfo &&sRhs)	   = default;
		~DeviceInfo() noexcept			   = default;

	public:
		DeviceInfo &operator=(const DeviceInfo &sRhs) = default;
		DeviceInfo &operator=(DeviceInfo &&sRhs) = default;

	public:
		VkPhysicalDevice physicalDevice() const noexcept
		{
			return this->sPhysicalDevice;
		}
		const VkPhysicalDeviceFeatures &features() const noexcept
		{
			return this->sFeatures;
		}
		const VkPhysicalDeviceProperties &properties() const noexcept
		{
			return this->sProperties;
		}
		const VkPhysicalDeviceMemoryProperties &memoryProperties() const noexcept
		{
			return this->sMemoryProperties;
		}
		const std::vector<VkQueueFamilyProperties> &queueProperties() const noexcept
		{
			return this->sQueueProperties;
		}
		const std::unordered_map<std::string, std::uint32_t> &extensionProperties() const noexcept
		{
			return this->sExtensionProperties;
		}
	};
}	 // namespace onyx::core
