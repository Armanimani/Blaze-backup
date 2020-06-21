#include "Blaze/Engine/Core/Application/Application.hpp"
#include "Blaze/Engine/Core/Common/constants.hpp"
#include "Blaze/Engine/Core/Logging/ConsoleLogger.hpp"
#include "Blaze/Engine/Core/Window/WindowFactory.hpp"
#include "Blaze/Engine/Core/Time/StopWatch.hpp"
#include "Blaze/Engine/Core/Time/Clock.hpp"


namespace blaze
{
	void Application::start() noexcept
	{
		initialize();
		
		ConsoleLogger::logInformation(k_engine_channel, "Starting");

		// TODO: Move this to the configuration system
		WindowSpecification specification;
		specification.initial_position_x = 0;
		specification.initial_position_y = 0;
		specification.initial_width = 3840;
		specification.initial_height = 2160;

		// TODO: Creating window is only necessary if no handle was passed
		// TODO: The logic for updating the window can be decoupled form the main thread
		const auto window = WindowFactory::create(specification);
		window->show();

		auto frame_clock = Clock();
		
		is_running = true;
		frame_clock.start();
		while(is_running)
		{
			frame_clock.tick();
			window->update();
		}
	}

	void Application::initialize() noexcept
	{
		auto stop_watch = StopWatch();
		stop_watch.start();
		
		ConsoleLogger::logInformation(k_engine_channel, "Initializing");

		stop_watch.stop();
		const auto elapsed_time = stop_watch.getElapsedTime().count();
		ConsoleLogger::logInformation(k_engine_channel, "Initializing Done! took " + std::to_string(elapsed_time) + " ms");
	}
	
}
