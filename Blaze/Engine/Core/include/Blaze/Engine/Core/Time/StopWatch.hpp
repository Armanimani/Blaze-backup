#pragma once

#include <chrono>

#include "Blaze/Engine/Core/Types/base_types.hpp"

namespace blaze
{
	class StopWatch
	{
	public:
		using duration_type = std::chrono::milliseconds;
		using clock_type = std::chrono::steady_clock;

		void start() noexcept;
		void stop() noexcept;
		void reset() noexcept;

		[[nodiscard]] duration_type getElapsedTime() const noexcept;
	private:
		Bool is_running{ false };
		std::chrono::time_point<clock_type> start_time{};
		duration_type elapsed_duration{};
	};
}
