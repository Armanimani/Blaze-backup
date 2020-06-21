#pragma once

#include <Blaze/Engine/Core/Types/base_types.hpp>

namespace blaze
{
	struct WindowSpecification
	{
		Int32 initial_position_x{};
		Int32 initial_position_y{};
		Int32 initial_width{};
		Int32 initial_height{};

		String title{ "Blaze" };
	};
}
