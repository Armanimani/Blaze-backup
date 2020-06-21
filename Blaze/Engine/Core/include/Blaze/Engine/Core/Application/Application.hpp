#pragma once

#include "Blaze/Engine/Core/Types/base_types.hpp"

namespace blaze
{
	class Application
	{
	public:
		Application() = default;
		~Application() = default;

		void start() noexcept;
	private:
		Bool is_running{ false };
		void initialize() noexcept;
	};
}
