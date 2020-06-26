#include "Blaze/Engine/PlatformDirectX12/DX12FenceEventFactory.hpp"

#include <Blaze/Engine/Core/Logging/ConsoleLogger.hpp>

namespace blaze
{
	HANDLE DX12FenceEventFactory::create() noexcept
	{
		const auto fence_event = CreateEvent(nullptr, false, false, nullptr);

		if (!fence_event)
			ConsoleLogger::logCritical(k_dx12_channel, "Unable to create fence event!");

		return fence_event;
	}
}
