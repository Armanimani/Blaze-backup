#include "Blaze/Engine/PlatformDirectX12/DX12GraphicContext.hpp"

namespace blaze
{
	DX12GraphicContext::DX12GraphicContext([[maybe_unused]] const GraphicSpecification& specification, void* window_handle)
		: handle{ static_cast<HWND>(window_handle) } {}
}
