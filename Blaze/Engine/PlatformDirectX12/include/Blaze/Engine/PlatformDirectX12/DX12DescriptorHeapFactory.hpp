#pragma once

#include <Blaze/Engine/Core/Types/base_types.hpp>

#include "Blaze/Engine/PlatformDirectX12/common.hpp"

namespace blaze
{
	class DX12DescriptorHeapFactory
	{
	public:
		[[nodiscard]] static Microsoft::WRL::ComPtr<ID3D12DescriptorHeap> create(
			Microsoft::WRL::ComPtr<ID3D12Device>& device, UInt32 number, D3D12_DESCRIPTOR_HEAP_TYPE type) noexcept;
		
		[[nodiscard]] static UInt32 getRtvDescriptorSize(const Microsoft::WRL::ComPtr<ID3D12Device>& device) noexcept;
	private:
		[[nodiscard]] static D3D12_DESCRIPTOR_HEAP_DESC getDescriptor(UInt32 number, D3D12_DESCRIPTOR_HEAP_TYPE type) noexcept;
	};
}