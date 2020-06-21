#include "Blaze/Engine/Core/Window/WindowFactory.hpp"
#include "Blaze/Engine/Core/DesignPatterns/ServiceLocator.hpp"

namespace blaze
{
	std::unique_ptr<IWindow> WindowFactory::create(const WindowSpecification& specification) noexcept
	{
		return getAdapter()->createWindow(specification);
	}

	IWindowFactoryAdapter* WindowFactory::getAdapter()
	{
		return Locator<IWindowFactoryAdapter>::get();
	}
}
