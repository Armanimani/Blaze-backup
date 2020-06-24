#pragma once

#include "Blaze/Engine/Core/Types/base_types.hpp"

namespace blaze
{
	struct WindowComponent
	{
		Bool own_window{ false };
		void* window_handle{ nullptr };
	};
}