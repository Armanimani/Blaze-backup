#include <gtest/gtest.h>
#include <Blaze/Engine/Core/Logging/ConsoleLogger.hpp>
#include <Blaze/Engine/Core/DesignPatterns/ServiceLocator.hpp>
#include "mock_ConsoleLoggerAdapter.hpp"

using namespace blaze;

TEST(ConsoleLogger, Enable_Disable_LoggingLevel)
{
	std::string channel{};
	std::string message{};
	
	auto console_logger = std::make_unique<MockConsoleLoggerAdapter>();
	console_logger->last_message_logged = &message;
	console_logger->last_channel_logged = &channel;
	Locator<IConsoleLoggerAdapter>::provide(std::move(console_logger));
	
	const std::string dummy_channel = "channel";
	const std::string dummy_critical_message = "critical";
	
	/* Logging when level is not enabled */
	ConsoleLogger::logCritical(dummy_channel, dummy_critical_message);
	ASSERT_TRUE(channel.empty());
	ASSERT_TRUE(message.empty());
	channel.clear();
	message.clear();

	/* Logging when level is enabled */
	ConsoleLogger::enableLoggingLevel(ConsoleLogger::LoggingLevel::critical);
	ConsoleLogger::logCritical(dummy_channel, dummy_critical_message);
	ASSERT_EQ(channel, dummy_channel);
	ASSERT_EQ(message, dummy_critical_message);

	channel.clear();
	message.clear();

	/* Logging when level is disabled */
	ConsoleLogger::disableLoggingLevel(ConsoleLogger::LoggingLevel::critical);
	ConsoleLogger::logCritical(dummy_channel, dummy_critical_message);
	ASSERT_TRUE(channel.empty());
	ASSERT_TRUE(message.empty());
}

TEST(ConsoleLogger, LoggingLevelManipulation)
{
	std::string channel{};
	std::string message{};

	auto console_logger = std::make_unique<MockConsoleLoggerAdapter>();
	console_logger->last_message_logged = &message;
	console_logger->last_channel_logged = &channel;
	Locator<IConsoleLoggerAdapter>::provide(std::move(console_logger));

	ASSERT_FALSE(ConsoleLogger::isLoggingLevelEnabled(ConsoleLogger::LoggingLevel::critical));
	ASSERT_FALSE(ConsoleLogger::isLoggingLevelEnabled(ConsoleLogger::LoggingLevel::warning));
	ASSERT_FALSE(ConsoleLogger::isLoggingLevelEnabled(ConsoleLogger::LoggingLevel::information));
	ASSERT_FALSE(ConsoleLogger::isLoggingLevelEnabled(ConsoleLogger::LoggingLevel::debug));
	
	ConsoleLogger::enableLoggingLevel(ConsoleLogger::LoggingLevel::critical);
	ASSERT_TRUE(ConsoleLogger::isLoggingLevelEnabled(ConsoleLogger::LoggingLevel::critical));
	ASSERT_FALSE(ConsoleLogger::isLoggingLevelEnabled(ConsoleLogger::LoggingLevel::warning));
	ASSERT_FALSE(ConsoleLogger::isLoggingLevelEnabled(ConsoleLogger::LoggingLevel::information));
	ASSERT_FALSE(ConsoleLogger::isLoggingLevelEnabled(ConsoleLogger::LoggingLevel::debug));

	ConsoleLogger::enableLoggingLevel(ConsoleLogger::LoggingLevel::warning);
	ASSERT_TRUE(ConsoleLogger::isLoggingLevelEnabled(ConsoleLogger::LoggingLevel::critical));
	ASSERT_TRUE(ConsoleLogger::isLoggingLevelEnabled(ConsoleLogger::LoggingLevel::warning));
	ASSERT_FALSE(ConsoleLogger::isLoggingLevelEnabled(ConsoleLogger::LoggingLevel::information));
	ASSERT_FALSE(ConsoleLogger::isLoggingLevelEnabled(ConsoleLogger::LoggingLevel::debug));

	ConsoleLogger::enableLoggingLevel(ConsoleLogger::LoggingLevel::debug);
	ASSERT_TRUE(ConsoleLogger::isLoggingLevelEnabled(ConsoleLogger::LoggingLevel::critical));
	ASSERT_TRUE(ConsoleLogger::isLoggingLevelEnabled(ConsoleLogger::LoggingLevel::warning));
	ASSERT_FALSE(ConsoleLogger::isLoggingLevelEnabled(ConsoleLogger::LoggingLevel::information));
	ASSERT_TRUE(ConsoleLogger::isLoggingLevelEnabled(ConsoleLogger::LoggingLevel::debug));

	ConsoleLogger::disableLoggingLevel(ConsoleLogger::LoggingLevel::information);
	ASSERT_TRUE(ConsoleLogger::isLoggingLevelEnabled(ConsoleLogger::LoggingLevel::critical));
	ASSERT_TRUE(ConsoleLogger::isLoggingLevelEnabled(ConsoleLogger::LoggingLevel::warning));
	ASSERT_FALSE(ConsoleLogger::isLoggingLevelEnabled(ConsoleLogger::LoggingLevel::information));
	ASSERT_TRUE(ConsoleLogger::isLoggingLevelEnabled(ConsoleLogger::LoggingLevel::debug));

	ConsoleLogger::disableLoggingLevel(ConsoleLogger::LoggingLevel::critical);
	ASSERT_FALSE(ConsoleLogger::isLoggingLevelEnabled(ConsoleLogger::LoggingLevel::critical));
	ASSERT_TRUE(ConsoleLogger::isLoggingLevelEnabled(ConsoleLogger::LoggingLevel::warning));
	ASSERT_FALSE(ConsoleLogger::isLoggingLevelEnabled(ConsoleLogger::LoggingLevel::information));
	ASSERT_TRUE(ConsoleLogger::isLoggingLevelEnabled(ConsoleLogger::LoggingLevel::debug));
}

TEST(ConsoleLogger, LoggingToLoggingLevels)
{
	std::string channel{};
	std::string message{};
	
	auto console_logger = std::make_unique<MockConsoleLoggerAdapter>();
	console_logger->last_message_logged = &message;
	console_logger->last_channel_logged = &channel;
	Locator<IConsoleLoggerAdapter>::provide(std::move(console_logger));
	
	const std::string dummy_channel = "channel";

	/* test logging critical */
	ConsoleLogger::enableLoggingLevel(ConsoleLogger::LoggingLevel::critical);
	const std::string dummy_critical_message = "critical";
	ConsoleLogger::logCritical(dummy_channel, dummy_critical_message);
	ASSERT_EQ(channel, dummy_channel);
	ASSERT_EQ(message, dummy_critical_message);

	channel.clear();
	message.clear();
	ConsoleLogger::disableLoggingLevel(ConsoleLogger::LoggingLevel::critical);

	/* test logging warning */
	ConsoleLogger::enableLoggingLevel(ConsoleLogger::LoggingLevel::warning);
	const std::string dummy_warning_message = "warning";
	ConsoleLogger::logWarning(dummy_channel, dummy_warning_message);
	ASSERT_EQ(channel, dummy_channel);
	ASSERT_EQ(message, dummy_warning_message);

	channel.clear();
	message.clear();
	ConsoleLogger::disableLoggingLevel(ConsoleLogger::LoggingLevel::warning);

	/* test logging information */
	ConsoleLogger::enableLoggingLevel(ConsoleLogger::LoggingLevel::information);
	const std::string dummy_warning_information = "information";
	ConsoleLogger::logInformation(dummy_channel, dummy_warning_information);
	ASSERT_EQ(channel, dummy_channel);
	ASSERT_EQ(message, dummy_warning_information);

	channel.clear();
	message.clear();
	ConsoleLogger::disableLoggingLevel(ConsoleLogger::LoggingLevel::information);

	/* test logging debug */
	ConsoleLogger::enableLoggingLevel(ConsoleLogger::LoggingLevel::debug);
	const std::string dummy_warning_debug = "debug";
	ConsoleLogger::logDebug(dummy_channel, dummy_warning_debug);
	ASSERT_EQ(channel, dummy_channel);
	ASSERT_EQ(message, dummy_warning_debug);

	channel.clear();
	message.clear();
	ConsoleLogger::disableLoggingLevel(ConsoleLogger::LoggingLevel::debug);
}