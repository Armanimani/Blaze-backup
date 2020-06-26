#include "Blaze/Engine/PlatformDirectX12/DX12DeviceFactory.hpp"
#include "Blaze/Engine/PlatformDirectX12/common.hpp"
#include <Blaze/Engine/Core/Logging/ConsoleLogger.hpp>

namespace blaze
{
	Microsoft::WRL::ComPtr<ID3D12Device> DX12DeviceFactory::create() noexcept
	{
		Microsoft::WRL::ComPtr<ID3D12Device> device;

		if (FAILED(D3D12CreateDevice(nullptr, D3D_FEATURE_LEVEL_12_1, IID_PPV_ARGS(&device))))
			ConsoleLogger::logCritical(k_dx12_channel, "Unable to create DirectX12 device!");

		return device;
	}
}
