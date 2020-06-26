#include "Blaze/Engine/PlatformDirectX12/DX12DXGIFactoryFactory.hpp"
#include <Blaze/Engine/Core/Logging/ConsoleLogger.hpp>

namespace blaze
{
	Microsoft::WRL::ComPtr<IDXGIFactory7> DX12DXGIFactoryFactory::create() noexcept
	{
		// TODO: Add support for non-debug build
		Microsoft::WRL::ComPtr<IDXGIFactory7> factory{};
		if (FAILED(CreateDXGIFactory2(DXGI_CREATE_FACTORY_DEBUG, IID_PPV_ARGS(&factory))))
		{
			ConsoleLogger::logCritical(k_dx12_channel, "Unable to create DXGI factory in debug mode!");
		}
		return factory;
	}
}
