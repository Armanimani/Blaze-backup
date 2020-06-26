#include "Blaze/Engine/PlatformDirectX12/DX12DebugController.hpp"
#include <Blaze/Engine/Core/Logging/ConsoleLogger.hpp>
#include <Blaze/Engine/PlatformDirectX12/common.hpp>

namespace blaze
{
	void DX12DebugController::enableDebugInterface() noexcept
	{
		Microsoft::WRL::ComPtr<ID3D12Debug3> debug{};

		if (FAILED(D3D12GetDebugInterface(IID_PPV_ARGS(&debug))))
			ConsoleLogger::logWarning(k_dx12_channel, "Unable to enable debug interface!");
		
		debug->EnableDebugLayer();
	}
	
	void DX12DebugController::enableDebugInfoQueue(const Microsoft::WRL::ComPtr<ID3D12Device>& device) noexcept
	{
		Microsoft::WRL::ComPtr<ID3D12InfoQueue> info_queue{};

		if (FAILED(device.As(&info_queue)))
			ConsoleLogger::logWarning(k_dx12_channel, "Unable to query the info queue");

		info_queue->SetBreakOnSeverity(D3D12_MESSAGE_SEVERITY_CORRUPTION, true);
		info_queue->SetBreakOnSeverity(D3D12_MESSAGE_SEVERITY_ERROR, true);
		info_queue->SetBreakOnSeverity(D3D12_MESSAGE_SEVERITY_WARNING, true);
	}
}
