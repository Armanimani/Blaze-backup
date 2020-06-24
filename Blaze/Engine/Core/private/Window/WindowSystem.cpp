#include "Blaze/Engine/Core/Window/WindowSystem.hpp"
#include "Blaze/Engine/Core/Window/WindowComponent.hpp"
#include "Blaze/Engine/Core/Window/WindowSpecification.hpp"
#include "Blaze/Engine/Core/Window/WindowFactory.hpp"

namespace blaze
{
	WindowSystem::WindowSystem(WindowSpecification specification)
		: specification{ std::move(specification) } {}

	void WindowSystem::initialize(Context* context) noexcept
	{
		context->entity_manager.reserve<WindowComponent>(1);
		// TODO: Creating window is only necessary if no handle was passed during configuration
		// TODO: The logic for updating the window can be decoupled form the main thread
		// TODO: Move this to the configuration system
		window = WindowFactory::create(specification);
		context->entity_manager.emplace<WindowComponent>(context->master_entity, true, window->getHandle());
		window->show();
	}
	
	void WindowSystem::update([[maybe_unused]] Context* context, [[maybe_unused]] Float delta_time) noexcept
	{
		window->update();
	}

	void WindowSystem::finalize([[maybe_unused]] Context* context) noexcept
	{
		if (window->isVisible())
			window->close();
	}
}
