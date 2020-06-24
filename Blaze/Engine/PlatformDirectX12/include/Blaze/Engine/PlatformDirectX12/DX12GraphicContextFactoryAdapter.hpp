#pragma once

#include <Blaze/Engine/Graphics/Context/IGraphicContextFactoryAdapter.hpp>

namespace blaze
{
	class DX12GraphicContextFactoryAdapter final : public IGraphicContextFactoryAdapter
	{
	public:
		[[nodiscard]] std::unique_ptr<IGraphicContext> createContext(
			const GraphicSpecification& specification, void* window_handle) noexcept override;
	};
}
