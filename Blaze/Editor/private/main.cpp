#include "Blaze/Engine/Core/Logging/ConsoleLogger.hpp"
#include "Blaze/Engine/Core/DesignPatterns/ServiceLocator.hpp"
#include "Blaze/Engine/Core/Window/WindowFactory.hpp"
#include "Blaze/Engine/PlatfowmWindows/Win32WindowFactoryAdapter.hpp"
#include "Blaze/Engine/SpdLog/ConsoleLoggerAdapter_SpdLog.hpp"

int main()
{
	auto logger = std::make_unique<blaze::ConsoleLoggerAdapter_SpdLog>();
	blaze::Locator<blaze::IConsoleLoggerAdapter>::provide(std::move(logger));	

	blaze::ConsoleLogger::enableLoggingLevel(blaze::ConsoleLogger::LoggingLevel::critical);
	blaze::ConsoleLogger::enableLoggingLevel(blaze::ConsoleLogger::LoggingLevel::warning);
	blaze::ConsoleLogger::enableLoggingLevel(blaze::ConsoleLogger::LoggingLevel::information);
	blaze::ConsoleLogger::enableLoggingLevel(blaze::ConsoleLogger::LoggingLevel::debug);

	blaze::ConsoleLogger::logCritical("Editor", "Critical message");
	blaze::ConsoleLogger::logCritical("Core", "Critical message");
	blaze::ConsoleLogger::logWarning("Editor", "Warning message");
	blaze::ConsoleLogger::logInformation("Editor", "Information message");
	blaze::ConsoleLogger::logDebug("Editor", "Debug message");

	auto windowFactory = std::make_unique<blaze::Win32WindowFactoryAdapter>();
	blaze::Locator<blaze::IWindowFactoryAdapter>::provide(std::move(windowFactory));

	blaze::WindowSpecification specification;
	specification.initial_position_x = 0;
	specification.initial_position_y = 0;
	specification.initial_width = 3840;
	specification.initial_height = 2160;
	
	const auto window = blaze::WindowFactory::create(specification);
	window->show();

	while(true)
	{
		window->update();
	}
}