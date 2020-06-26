#include "Blaze/Engine/PlatformDirectX12/DX12FenceFactory.hpp"
#include <Blaze/Engine/Core/Logging/ConsoleLogger.hpp>

namespace blaze
{
	Microsoft::WRL::ComPtr<ID3D12Fence1> DX12FenceFactory::create(
		const Microsoft::WRL::ComPtr<ID3D12Device6>& device, const D3D12_FENCE_FLAGS flags) noexcept
	{
		Microsoft::WRL::ComPtr<ID3D12Fence1> fence{};

		if (FAILED(device->CreateFence(0, flags, IID_PPV_ARGS(&fence))))
			ConsoleLogger::logCritical(k_dx12_channel, "Unable to create fence!");

		return fence;
	}
}
