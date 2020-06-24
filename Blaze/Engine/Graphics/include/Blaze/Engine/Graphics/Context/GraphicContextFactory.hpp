#pragma once

#include <memory>

#include "Blaze/Engine/Graphics/Context/GraphicSpecification.hpp"
#include "Blaze/Engine/Graphics/Context/IGraphicContext.hpp"
#include "Blaze/Engine/Graphics/Context/IGraphicContextFactoryAdapter.hpp"

namespace blaze
{
	class GraphicContextFactory
	{
	public:
		static std::unique_ptr<IGraphicContext> create(const GraphicSpecification& specification, void* window_handle) noexcept;
	private:
		static IGraphicContextFactoryAdapter* getAdapter();
	};
}
