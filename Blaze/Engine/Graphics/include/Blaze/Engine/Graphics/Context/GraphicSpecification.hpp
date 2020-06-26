#pragma once

#include "Blaze/Engine/Core/Types/base_types.hpp"

namespace blaze
{
	struct GraphicSpecification
	{
		Bool is_v_sync_enabled{ false };
		Bool is_triple_buffering_enabled{ false };
	};
}
