#pragma once

#include "Blaze/Engine/Core/Types/base_types.hpp"

namespace blaze
{
	template<typename IdType = UInt32>
	struct Entity
	{
		IdType internal_identifier{};
		IdType unique_identifier{};
	};
}
