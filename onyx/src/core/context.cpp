
#include "onyx/includes/core/context.h"

#include "onyx/includes/core/contextManager.h"
#include "onyx/includes/core/deviceInfo.h"
#include "onyx/includes/core/perContextManager.h"
#include "onyx/includes/core/vulkan.h"

#include <algorithm>
#include <cassert>
#include <cstdint>
#include <stdexcept>
#include <tuple>

namespace onyx::core {
	Context::Context(ContextManager *pContextMgr, display::Window *pWindow) :
		pContextMgr{pContextMgr},
		sSurfaceMgr{this, pWindow},
		sDeviceMgr{this},
		sSwapchainMgr{this},
		sSyncMgr{this, 3},
		sRenderingMgr{this}
	{
		assert(this->pContextMgr);

		auto sPhysicalDeviceVec{this->pContextMgr->fetchPhysicalDevice()};

		std::vector<DeviceInfo> sDeviceVec;
		sDeviceVec.reserve(sPhysicalDeviceVec.size());

		for (auto sPhysicalDevice: sPhysicalDeviceVec) sDeviceVec.emplace_back(sPhysicalDevice);

		const DeviceInfo *pDeviceInfo{this->selectCompatible(sDeviceVec)};

		if (!pDeviceInfo) throw std::runtime_error{"no suitable physical device detected"};

		this->pDeviceInfo = std::make_unique<DeviceInfo>(*pDeviceInfo);

		for (auto *pPerContextMgr: this->sPerContextMgrVec) pPerContextMgr->init(*this->pDeviceInfo.get());
	}

	Context::~Context() noexcept
	{
		for (auto iIndex{this->sPerContextMgrVec.rbegin()}, iEnd{this->sPerContextMgrVec.rend()}; iIndex != iEnd;
			 ++iIndex)
			(*iIndex)->fin();
	}

	bool Context::isCompatible(const DeviceInfo &sDevice) const
	{
		auto bHasGraphicsQueue{false};

		for (const auto &sQueueProp: sDevice.queueProperties()) {
			if (sQueueProp.queueCount && sQueueProp.queueFlags & VkQueueFlagBits::VK_QUEUE_GRAPHICS_BIT) {
				bHasGraphicsQueue = true;
				break;
			}
		}

		if (!bHasGraphicsQueue) return false;

		std::size_t nQueueIndex{0};
		auto		bHasPresentQueue{false};

		for (const auto &sQueueProp: sDevice.queueProperties()) {
			if (sQueueProp.queueCount) {
				VkBool32 vkSurfaceSupport;

				if (vkGetPhysicalDeviceSurfaceSupportKHR(
						sDevice.physicalDevice(),
						nQueueIndex,
						this->sSurfaceMgr.vulkanSurface(),
						&vkSurfaceSupport)
					!= VkResult::VK_SUCCESS)
					throw std::runtime_error{"unable to query surface support of physical device"};

				if (vkSurfaceSupport) {
					bHasPresentQueue = true;
					break;
				}

				++nQueueIndex;
			}
		}

		if (!bHasPresentQueue) return false;

		auto bIsCompatible{true};

		for (auto *pPerContextMgr: this->sPerContextMgrVec)
			if (!pPerContextMgr->isCompatible(sDevice)) {
				bIsCompatible = false;
				break;
			}

		return bIsCompatible;
	}

	const DeviceInfo *Context::selectCompatible(const std::vector<DeviceInfo> &sDeviceVec) const
	{
		if (sDeviceVec.empty()) return nullptr;

		if (sDeviceVec.size() == 1) return this->isCompatible(sDeviceVec.front()) ? &sDeviceVec.front() : nullptr;

		if (sDeviceVec.size() == 2) {
			auto bFrontDiscreteGPU{sDeviceVec.front().properties().deviceType
								   == VkPhysicalDeviceType::VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU};
			auto bFrontIntegratedGPU{sDeviceVec.front().properties().deviceType
									 == VkPhysicalDeviceType::VK_PHYSICAL_DEVICE_TYPE_INTEGRATED_GPU};
			auto bBackDiscreteGPU{sDeviceVec.back().properties().deviceType
								  == VkPhysicalDeviceType::VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU};
			auto bBackIntegratedGPU{sDeviceVec.back().properties().deviceType
									== VkPhysicalDeviceType::VK_PHYSICAL_DEVICE_TYPE_INTEGRATED_GPU};

			const DeviceInfo *pDiscreteGPU{nullptr};
			const DeviceInfo *pIntegratedGPU{nullptr};

			if (bFrontDiscreteGPU && bBackIntegratedGPU) {
				pDiscreteGPU   = &sDeviceVec.front();
				pIntegratedGPU = &sDeviceVec.back();
			}
			else if (bFrontIntegratedGPU && bBackDiscreteGPU) {
				pIntegratedGPU = &sDeviceVec.front();
				pDiscreteGPU   = &sDeviceVec.back();
			}

			if (pDiscreteGPU && pIntegratedGPU) {
				if (this->isCompatible(*pDiscreteGPU)) return pDiscreteGPU;

				if (this->isCompatible(*pIntegratedGPU)) return pIntegratedGPU;

				return nullptr;
			}
		}

		std::vector<std::tuple<const DeviceInfo *, std::size_t>> sDeviceScoreTupleVec;
		sDeviceScoreTupleVec.reserve(sDeviceVec.size());

		for (std::size_t nIndex{0}, nMaxIndex{sDeviceVec.size()}; nIndex < nMaxIndex; ++nIndex) {
			std::size_t nScore{0};

			switch (sDeviceVec[nIndex].properties().deviceType) {
			case VkPhysicalDeviceType::VK_PHYSICAL_DEVICE_TYPE_VIRTUAL_GPU: nScore += 1; break;
			case VkPhysicalDeviceType::VK_PHYSICAL_DEVICE_TYPE_INTEGRATED_GPU: nScore += 2; break;
			case VkPhysicalDeviceType::VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU: nScore += 5; break;
			default: break;
			}

			// TODO: Add more scoring logics here.

			sDeviceScoreTupleVec.emplace_back(&sDeviceVec[nIndex], nScore);
		}

		std::sort(sDeviceScoreTupleVec.begin(), sDeviceScoreTupleVec.end(), [](const auto &sLhs, const auto &sRhs) {
			return std::get<1>(sLhs) > std::get<1>(sRhs);
		});

		for (const auto &sDeviceScoreTuple: sDeviceScoreTupleVec)
			if (this->isCompatible(*std::get<0>(sDeviceScoreTuple))) return std::get<0>(sDeviceScoreTuple);

		return nullptr;
	}
}	 // namespace onyx::core