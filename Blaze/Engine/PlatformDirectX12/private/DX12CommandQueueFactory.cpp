#include "Blaze/Engine/PlatformDirectX12/DX12CommandQueueFactory.hpp"
#include <Blaze/Engine/Core/Logging/ConsoleLogger.hpp>

namespace blaze
{
	Microsoft::WRL::ComPtr<ID3D12CommandQueue> DX12CommandQueueFactory::create(
		Microsoft::WRL::ComPtr<ID3D12Device>& device, 
		const D3D12_COMMAND_LIST_TYPE type,
		const D3D12_COMMAND_QUEUE_PRIORITY priority) noexcept
	{
		Microsoft::WRL::ComPtr<ID3D12CommandQueue> command_queue{};
		const auto descriptor = getDescriptor(type, priority);

		if (FAILED(device->CreateCommandQueue(&descriptor, IID_PPV_ARGS(&command_queue))))
			ConsoleLogger::logCritical(k_dx12_channel, "Unable to create the command queue!");

		return command_queue;
	}

	D3D12_COMMAND_QUEUE_DESC DX12CommandQueueFactory::getDescriptor(
		const D3D12_COMMAND_LIST_TYPE type,
		const D3D12_COMMAND_QUEUE_PRIORITY priority) noexcept
	{
		D3D12_COMMAND_QUEUE_DESC descriptor;
		descriptor.Type = type;
		descriptor.Priority = priority;
		descriptor.Flags = D3D12_COMMAND_QUEUE_FLAG_NONE;
		descriptor.NodeMask = 0;

		return descriptor;
	}
}
