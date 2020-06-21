#include "Blaze/Engine/Core/Application/Application.hpp"
#include "Blaze/Engine/Core/Common/constants.hpp"
#include "Blaze/Engine/Core/Logging/ConsoleLogger.hpp"
#include "Blaze/Engine/Core/Window/WindowFactory.hpp"


namespace blaze
{
	void Application::start() noexcept
	{
		ConsoleLogger::logInformation(k_engine_channel, "Starting");

		// TODO: Move this to the configuration system
		WindowSpecification specification;
		specification.initial_position_x = 0;
		specification.initial_position_y = 0;
		specification.initial_width = 3840;
		specification.initial_height = 2160;

		// TODO: Creating window is only necessary if no handle was passed
		
		const auto window = WindowFactory::create(specification);
		window->show();

		while(true)
		{
			window->update();

			update_executors();
		}
	}


	void Application::initialize() noexcept
	{
		ConsoleLogger::logInformation(k_engine_channel, "Initializing");
	}
	
	void Application::update_executors() noexcept
	{
	}
}
