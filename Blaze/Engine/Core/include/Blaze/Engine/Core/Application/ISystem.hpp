#pragma once

#include "Blaze/Engine/Core/Types/base_types.hpp"

namespace blaze
{
	class ISystem
	{
	public:
		virtual ~ISystem() = default;
		
		virtual void initialize() noexcept = 0;
		virtual void update(Milliseconds delta_time) noexcept = 0;
		virtual void finalize() noexcept = 0;
	};
}