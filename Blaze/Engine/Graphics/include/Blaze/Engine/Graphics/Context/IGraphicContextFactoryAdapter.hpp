#pragma once

#include <memory>

#include "Blaze/Engine/Graphics/Context/GraphicSpecification.hpp"
#include "Blaze/Engine/Graphics/Context/IGraphicContext.hpp"

namespace blaze
{
	class IGraphicContextFactoryAdapter
	{
	public:
		virtual ~IGraphicContextFactoryAdapter() = default;
		
		[[nodiscard]] virtual std::unique_ptr<IGraphicContext> createContext(
			const GraphicSpecification& initial_specification, void* window_handle) noexcept = 0;
	};
}