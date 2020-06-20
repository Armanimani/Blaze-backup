#include "mock_ConsoleLoggerAdapter.hpp"

void MockConsoleLoggerAdapter::logCritical(const blaze::StringView channel, const blaze::StringView log_message) noexcept
{
	*last_channel_logged = channel;
	*last_message_logged = log_message;
}

void MockConsoleLoggerAdapter::logWarning(const blaze::StringView channel, blaze::StringView log_message) noexcept
{
	*last_channel_logged = channel;
	*last_message_logged = log_message;
}

void MockConsoleLoggerAdapter::logInformation(const blaze::StringView channel, const blaze::StringView log_message) noexcept
{
	*last_channel_logged = channel;
	*last_message_logged = log_message;
}

void MockConsoleLoggerAdapter::logDebug(const blaze::StringView channel, const blaze::StringView log_message) noexcept
{
	*last_channel_logged = channel;
	*last_message_logged = log_message;
}
