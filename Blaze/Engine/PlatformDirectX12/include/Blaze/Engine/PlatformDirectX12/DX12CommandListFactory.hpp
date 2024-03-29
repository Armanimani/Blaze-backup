#pragma once

#include "Blaze/Engine/PlatformDirectX12/common.hpp"

namespace blaze
{
	class DX12CommandListFactory
	{
	public:
		[[nodiscard]] static Microsoft::WRL::ComPtr<ID3D12GraphicsCommandList> create(
			const Microsoft::WRL::ComPtr<ID3D12Device>& device,
			const Microsoft::WRL::ComPtr<ID3D12CommandAllocator>& allocator,
			D3D12_COMMAND_LIST_TYPE type) noexcept;
	};
}