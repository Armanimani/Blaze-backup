#include "Blaze/Engine/PlatformDirectX12/DX12CommandAllocatorFactory.hpp"
#include <Blaze/Engine/Core/Logging/ConsoleLogger.hpp>

namespace blaze
{
	Microsoft::WRL::ComPtr<ID3D12CommandAllocator> DX12CommandAllocatorFactory::create(
		const Microsoft::WRL::ComPtr<ID3D12Device6>& device, const D3D12_COMMAND_LIST_TYPE type) noexcept
	{
		Microsoft::WRL::ComPtr<ID3D12CommandAllocator> command_allocator{};
		
		if (FAILED(device->CreateCommandAllocator(type, IID_PPV_ARGS(&command_allocator))))
			ConsoleLogger::logCritical(k_dx12_channel, "Unable to create command allocator!");
		
		return command_allocator;
	}
}
