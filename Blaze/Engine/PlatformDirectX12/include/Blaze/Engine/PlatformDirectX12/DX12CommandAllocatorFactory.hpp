#pragma once

#include "Blaze/Engine/PlatformDirectX12/common.hpp"

namespace blaze
{
	class DX12CommandAllocatorFactory
	{
	public:
		[[nodiscard]] static Microsoft::WRL::ComPtr<ID3D12CommandAllocator> create(
			const Microsoft::WRL::ComPtr<ID3D12Device6>& device, D3D12_COMMAND_LIST_TYPE type) noexcept;
	};
}