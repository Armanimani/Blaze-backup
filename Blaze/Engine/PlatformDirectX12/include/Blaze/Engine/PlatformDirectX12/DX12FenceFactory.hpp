#pragma once

#include "Blaze/Engine/PlatformDirectX12/common.hpp"

namespace blaze
{
	class DX12FenceFactory
	{
	public:
		[[nodiscard]] static Microsoft::WRL::ComPtr<ID3D12Fence1> create(
			const Microsoft::WRL::ComPtr<ID3D12Device6>& device, D3D12_FENCE_FLAGS flags) noexcept;
	};
}
