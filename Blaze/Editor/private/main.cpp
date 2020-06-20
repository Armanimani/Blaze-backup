#include "Blaze/Engine/Core/Logging/ConsoleLogger.hpp"
#include "Blaze/Engine/SpdLog/ConsoleLoggerAdapter_SpdLog.hpp"
#include "Blaze/Engine/Core/DesignPatterns/ServiceLocator.hpp"

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
}