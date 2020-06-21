#pragma once

namespace blaze
{
	class Application
	{
	public:
		Application() = default;
		~Application() = default;

		void start() noexcept;
	private:
		void initialize() noexcept;
		void update_executors() noexcept;
	};
}
