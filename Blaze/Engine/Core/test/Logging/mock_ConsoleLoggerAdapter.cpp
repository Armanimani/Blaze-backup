#include "mock_ConsoleLoggerAdapter.hpp"

void MockConsoleLoggerAdapter::setUp()
{
	*set_up_called = true;
	
}

void MockConsoleLoggerAdapter::tearDown()
{
	*tear_down_called = true;
}

void MockConsoleLoggerAdapter::logCritical(const std::string_view channel, const std::string_view log_message) noexcept
{
	*last_channel_logged = channel;
	*last_message_logged = log_message;
}

void MockConsoleLoggerAdapter::logWarning(const std::string_view channel, const std::string_view log_message) noexcept
{
	*last_channel_logged = channel;
	*last_message_logged = log_message;
}

void MockConsoleLoggerAdapter::logInformation(const std::string_view channel, const std::string_view log_message) noexcept
{
	*last_channel_logged = channel;
	*last_message_logged = log_message;
}

void MockConsoleLoggerAdapter::logDebug(const std::string_view channel, const std::string_view log_message) noexcept
{
	*last_channel_logged = channel;
	*last_message_logged = log_message;
}
