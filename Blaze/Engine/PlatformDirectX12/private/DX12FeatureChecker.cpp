#include "Blaze/Engine/PlatformDirectX12/DX12FeatureChecker.hpp"
#include "Blaze/Engine/PlatformDirectX12/DX12DXGIFactoryFactory.hpp"

#include <Blaze/Engine/Core/Logging/ConsoleLogger.hpp>
#include <Blaze/Engine/PlatformDirectX12/common.hpp>

namespace blaze
{
	Bool DX12FeatureChecker::isTearingSupported() noexcept
	{
		auto result = FALSE;

		auto factory = DX12DXGIFactoryFactory::create();
		if (FAILED(factory->CheckFeatureSupport(DXGI_FEATURE_PRESENT_ALLOW_TEARING, &result, sizeof(result))))
		{
			ConsoleLogger::logCritical(k_dx12_channel, "Unable to get the tearing support");
			return false;
		}
		return true;
	}
}
