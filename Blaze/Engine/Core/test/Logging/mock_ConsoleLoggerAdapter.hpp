#pragma once

#include <Blaze/Engine/Core/Logging/ConsoleLogger.hpp>

class MockConsoleLoggerAdapter final : public blaze::IConsoleLoggerAdapter
{
public:
	void logCritical(std::string_view channel, std::string_view log_message) noexcept override;
	void logWarning(std::string_view channel, std::string_view log_message) noexcept override;
	void logInformation(std::string_view channel, std::string_view log_message) noexcept override;
	void logDebug(std::string_view channel, std::string_view log_message) noexcept override;

	std::string* last_message_logged{ nullptr };
	std::string* last_channel_logged{ nullptr };
};