#pragma once

#include <chrono>

#include "Blaze/Engine/Core/Types/base_types.hpp"

namespace blaze
{
	class Clock
	{
	public:
		using duration_type = std::chrono::milliseconds;
		using clock_type = std::chrono::steady_clock;

		void start() noexcept;
		void stop() noexcept;
		void tick() noexcept;

		[[nodiscard]] duration_type getElapsedTime() const noexcept;
		[[nodiscard]] duration_type getLastTickTime() const noexcept;
		[[nodiscard]] Int64 getNumberOfTicks() const noexcept;
	private:
		Bool is_running{ false };
		Int64 number_of_ticks{};
		
		std::chrono::time_point<clock_type> start_time{};
		std::chrono::time_point<clock_type> last_tick_time{};
		
		duration_type last_tick_duration{};
		duration_type elapsed_duration{};

		void update() noexcept;
	};
}