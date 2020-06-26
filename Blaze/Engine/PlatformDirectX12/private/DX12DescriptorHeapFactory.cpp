#include "Blaze/Engine/PlatformDirectX12/DX12DescriptorHeapFactory.hpp"

#include <Blaze/Engine/Core/Logging/ConsoleLogger.hpp>

namespace blaze
{
	Microsoft::WRL::ComPtr<ID3D12DescriptorHeap> DX12DescriptorHeapFactory::create(
		Microsoft::WRL::ComPtr<ID3D12Device6>& device, const UInt32 number, const D3D12_DESCRIPTOR_HEAP_TYPE type) noexcept
	{
		const auto descriptor = getDescriptor(number, type);
		Microsoft::WRL::ComPtr<ID3D12DescriptorHeap> descriptor_heap{};
		
		if (FAILED(device->CreateDescriptorHeap(&descriptor, IID_PPV_ARGS(&descriptor_heap))))
			ConsoleLogger::logCritical(k_dx12_channel, "Unable to create descriptor heap!");

		return descriptor_heap;
	}

	UInt32 DX12DescriptorHeapFactory::getRtvDescriptorSize(const Microsoft::WRL::ComPtr<ID3D12Device6>& device) noexcept
	{
		return device->GetDescriptorHandleIncrementSize(D3D12_DESCRIPTOR_HEAP_TYPE_RTV);
	}

	D3D12_DESCRIPTOR_HEAP_DESC DX12DescriptorHeapFactory::getDescriptor(const UInt32 number, const D3D12_DESCRIPTOR_HEAP_TYPE type) noexcept
	{
		D3D12_DESCRIPTOR_HEAP_DESC descriptor{};
		descriptor.Type = type;
		descriptor.NumDescriptors = number;

		return descriptor;
	}
}
