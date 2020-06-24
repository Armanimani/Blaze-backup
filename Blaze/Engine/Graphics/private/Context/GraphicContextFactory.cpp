#include "Blaze/Engine/Graphics/Context/GraphicContextFactory.hpp"
#include <Blaze/Engine/Core/DesignPatterns/ServiceLocator.hpp>

namespace blaze
{
	std::unique_ptr<IGraphicContext> GraphicContextFactory::create(const GraphicSpecification& specification, void* window_handle) noexcept
	{
		return getAdapter()->createContext(specification, window_handle);
	}

	IGraphicContextFactoryAdapter* GraphicContextFactory::getAdapter()
	{
		return Locator<IGraphicContextFactoryAdapter>::get();
	}
}
