#pragma once

#include "Blaze/Engine/Core/Entity/entity.hpp"

namespace blaze
{
	struct Context
	{
		Context()
		{
			master_entity = entity_manager.create();
		}
		
		EntityManager entity_manager{};
		Entity master_entity{};
	};
}
