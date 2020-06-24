#include "Blaze/Engine/PlatformDirectX12/DX12GraphicContext.hpp"

namespace blaze
{
	DX12GraphicContext::DX12GraphicContext([[maybe_unused]] const GraphicSpecification& specification, void* window_handle)
		: handle{ static_cast<HWND>(window_handle) } {}

	void DX12GraphicContext::initialize() noexcept
	{
		
	}


	void DX12GraphicContext::update() noexcept
	{
		
	}
	
	void DX12GraphicContext::finalize() noexcept
	{
		
	}
}
