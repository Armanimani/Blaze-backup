#include "Blaze/Engine/SpdLog/ConsoleLoggerAdapter_SpdLog.hpp"

#include <spdlog/sinks/stdout_color_sinks.h>

namespace blaze
{
	ConsoleLoggerAdapter_SpdLog::ConsoleLoggerAdapter_SpdLog()
	{
		spdlog::set_pattern("%^[%T] %n: %v%$");
		spdlog::set_level(spdlog::level::trace);
	}

	void ConsoleLoggerAdapter_SpdLog::logCritical(const StringView channel, const StringView log_message) noexcept
	{
		const auto logger = getLogger(channel);
		logger->critical(log_message);
	}

	void ConsoleLoggerAdapter_SpdLog::logWarning(const StringView channel, const StringView log_message) noexcept
	{
		const auto logger = getLogger(channel);
		logger->warn(log_message);
	}
	
	void ConsoleLoggerAdapter_SpdLog::logInformation(const StringView channel, const StringView log_message) noexcept
	{
		const auto logger = getLogger(channel);
		logger->info(log_message);
	}
	
	void ConsoleLoggerAdapter_SpdLog::logDebug(const StringView channel, const StringView log_message) noexcept
	{
		const auto logger = getLogger(channel);
		logger->debug(log_message);
	}

	spdlog::logger* ConsoleLoggerAdapter_SpdLog::createLogger(const StringView channel) noexcept
	{
		const auto channel_name = String(channel);
		const auto logger = spdlog::stdout_color_mt(channel_name);
		return spdlog::get(channel_name).get();
	}

	spdlog::logger* ConsoleLoggerAdapter_SpdLog::getLogger(const StringView channel) noexcept
	{
		const auto channel_name = String(channel);
		const auto logger = spdlog::get(channel_name);
		if (logger)
		{
			return logger.get();
		}

		return createLogger(channel_name);
	}
}
