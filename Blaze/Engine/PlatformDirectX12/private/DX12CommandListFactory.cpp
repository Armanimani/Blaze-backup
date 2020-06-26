#include "Blaze/Engine/PlatformDirectX12/DX12CommandListFactory.hpp"
#include "Blaze/Engine/Core/Logging/ConsoleLogger.hpp"


namespace blaze
{
	Microsoft::WRL::ComPtr<ID3D12GraphicsCommandList> DX12CommandListFactory::create(
		const Microsoft::WRL::ComPtr<ID3D12Device>& device,
		const Microsoft::WRL::ComPtr<ID3D12CommandAllocator>& allocator, 
		const D3D12_COMMAND_LIST_TYPE type) noexcept
	{
		Microsoft::WRL::ComPtr<ID3D12GraphicsCommandList> command_list{};

		if (FAILED(device->CreateCommandList(0, type, allocator.Get(), nullptr, IID_PPV_ARGS(&command_list))))
			ConsoleLogger::logCritical(k_dx12_channel, "Unable to create the command list!");

		command_list->Close();
		return command_list;
	}
}
