#pragma once

#include "Blaze/Engine/PlatformDirectX12/common.hpp"

namespace blaze
{
	class DX12CommandQueueFactory
	{
	public:
		[[nodiscard]] static Microsoft::WRL::ComPtr<ID3D12CommandQueue> create(
			Microsoft::WRL::ComPtr<ID3D12Device>& device, D3D12_COMMAND_LIST_TYPE type, 
			D3D12_COMMAND_QUEUE_PRIORITY priority) noexcept;
	private:
		[[nodiscard]] static D3D12_COMMAND_QUEUE_DESC getDescriptor(D3D12_COMMAND_LIST_TYPE type, D3D12_COMMAND_QUEUE_PRIORITY priority) noexcept;
	};
}