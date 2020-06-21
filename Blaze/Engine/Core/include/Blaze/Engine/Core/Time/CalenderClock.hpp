#pragma once

#include <chrono>

#include "Blaze/Engine/Core/Types/base_types.hpp"

namespace blaze
{
	struct CalenderInformation
	{
		Int32 year{};
		Int32 moth{};
		Int32 day{};
		Int32 hour{};
		Int32 minute{};
		Int32 second{};
	};

	class CalenderClock
	{
	public:
		using clock_type = std::chrono::system_clock;
		
		static CalenderInformation getCalenderInformation() noexcept;
	};
}