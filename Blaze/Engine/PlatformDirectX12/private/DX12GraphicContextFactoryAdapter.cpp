#include "Blaze/Engine/PlatformDirectX12/DX12GraphicContextFactoryAdapter.hpp"
#include "Blaze/Engine/PlatformDirectX12/DX12GraphicContext.hpp"

namespace blaze
{
	std::unique_ptr<IGraphicContext> DX12GraphicContextFactoryAdapter::createContext(
		const GraphicSpecification& specification, void* window_handle) noexcept
	{
		return std::make_unique<DX12GraphicContext>(specification, window_handle);
	}
}
