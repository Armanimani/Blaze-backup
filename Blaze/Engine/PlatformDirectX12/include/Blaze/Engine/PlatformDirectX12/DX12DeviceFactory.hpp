#pragma once

#include "Blaze/Engine/PlatformDirectX12/common.hpp"

namespace blaze
{
	class DX12DeviceFactory
	{
	public:
		[[nodiscard]] static Microsoft::WRL::ComPtr<ID3D12Device6> create() noexcept;
	};
}