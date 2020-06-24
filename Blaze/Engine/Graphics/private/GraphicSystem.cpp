#include "Blaze/Engine/Graphics/GraphicSystem.hpp"
#include "Blaze/Engine/Graphics/Context/GraphicContextFactory.hpp"
#include "Blaze/Engine/Graphics/GraphicComponent.hpp"
#include "Blaze/Engine/Core/Window/WindowComponent.hpp"

namespace blaze
{
	GraphicSystem::GraphicSystem(GraphicSpecification specification)
		: specification{ std::move(specification) } {}
	
	void GraphicSystem::initialize(Context* context) noexcept
	{
		context->entity_manager.reserve<GraphicComponent>(1);
		
		auto window_handle = context->entity_manager.get<WindowComponent>(context->master_entity).window_handle;
		
		graphic_context = GraphicContextFactory::create(specification, window_handle);
		// TODO: Transfer the properties in the specification to the context
	}

	
	void GraphicSystem::update([[maybe_unused]] Context* context, [[maybe_unused]] Float delta_time) noexcept
	{
		
	}
	
	void GraphicSystem::finalize([[maybe_unused]] Context* context) noexcept
	{
		
	}
}
