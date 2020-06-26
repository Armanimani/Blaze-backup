#include "Blaze/Engine/PlatformDirectX12/DX12GraphicContext.hpp"
#include "Blaze/Engine/PlatformDirectX12/DX12DebugController.hpp"
#include "Blaze/Engine/PlatformDirectX12/DX12DeviceFactory.hpp"

namespace blaze
{
	DX12GraphicContext::DX12GraphicContext([[maybe_unused]] const GraphicSpecification& specification, void* window_handle)
		: handle{ static_cast<HWND>(window_handle) } {}

	void DX12GraphicContext::initialize() noexcept
	{
		DX12DebugController::enableDebugInterface();
		device = DX12DeviceFactory::create();
		DX12DebugController::enableDebugInfoQueue(device);

		
	}


	void DX12GraphicContext::present() noexcept
	{
		
	}
	
	void DX12GraphicContext::finalize() noexcept
	{
		
	}
}
