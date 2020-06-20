#pragma once

#include <Blaze/Engine/Core/Logging/ConsoleLogger.hpp>

class MockConsoleLoggerAdapter final : public blaze::IConsoleLoggerAdapter
{
public:
	void logCritical(blaze::StringView channel, blaze::StringView  log_message) noexcept override;
	void logWarning(blaze::StringView  channel, blaze::StringView  log_message) noexcept override;
	void logInformation(blaze::StringView channel, blaze::StringView log_message) noexcept override;
	void logDebug(blaze::StringView channel, blaze::StringView log_message) noexcept override;

	blaze::String* last_message_logged{ nullptr };
	blaze::String* last_channel_logged{ nullptr };
};