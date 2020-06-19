#include "Blaze/Engine/Core/Logging/ConsoleLogger.hpp"
#include <cassert>

namespace blaze
{
	ConsoleLogger::~ConsoleLogger()
	{
		clearRegistries();
	}

	void ConsoleLogger::registerLogger(std::unique_ptr<IConsoleLoggerAdapter>&& adapter)
	{
		assert(!s_adapter);

		s_adapter = std::move(adapter);
		s_adapter->setUp();
	}

	void ConsoleLogger::clearRegistries()
	{
		if (s_adapter)
		{
			s_adapter->tearDown();
			s_adapter.release();
		}
	}

	void ConsoleLogger::enableLoggingLevel(const LoggingLevel level)
	{
		s_logging_level |= static_cast<UInt8>(level);
	}
	void ConsoleLogger::disableLoggingLevel(const LoggingLevel level)
	{
		s_logging_level &= ~static_cast<UInt8>(level);
	}

	bool ConsoleLogger::isLoggingLevelEnabled(const LoggingLevel level)
	{
		return s_logging_level & static_cast<UInt8>(level);
	}

	void ConsoleLogger::logCritical(const std::string_view channel, const std::string_view log_message) noexcept
	{
		if (!isLoggingLevelEnabled(LoggingLevel::critical))
			return;

		assert(s_adapter);

		s_adapter->logCritical (channel, log_message);
	}
	
	void ConsoleLogger::logWarning(const std::string_view channel, const std::string_view log_message) noexcept
	{
		if (!isLoggingLevelEnabled(LoggingLevel::warning))
			return;

		assert(s_adapter);

		s_adapter->logWarning(channel, log_message);
	}
	
	void ConsoleLogger::logInformation(const std::string_view channel, const std::string_view log_message) noexcept
	{
		if (!isLoggingLevelEnabled(LoggingLevel::information))
			return;
		
		assert(s_adapter);

		s_adapter->logInformation(channel, log_message);
	}
	
	void ConsoleLogger::logDebug(const std::string_view channel, const std::string_view log_message) noexcept
	{
		if (!isLoggingLevelEnabled(LoggingLevel::debug))
			return;

		assert(s_adapter);

		s_adapter->logDebug(channel, log_message);
	}
}
