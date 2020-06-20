#pragma once

#include "Blaze/Engine/Core/Types/base_types.hpp"
#include "Blaze/Engine/Core/Logging/IConsoleLoggerAdapter.hpp"

namespace blaze
{	
	class ConsoleLogger
	{
	public:
		enum class LoggingLevel
		{
			critical = 1 << 1,
			warning = 1 << 2,
			information = 1 << 3,
			debug = 1 << 4
		};

		ConsoleLogger() = delete;

		ConsoleLogger(const ConsoleLogger& other) = delete;
		ConsoleLogger(ConsoleLogger&& other) noexcept = delete;
		ConsoleLogger& operator=(const ConsoleLogger& other) = delete;
		ConsoleLogger& operator=(ConsoleLogger&& other) noexcept = delete;
		~ConsoleLogger() = delete;
		
		static void enableLoggingLevel(LoggingLevel level);
		static void disableLoggingLevel(LoggingLevel level);
		
		[[nodiscard]]static bool isLoggingLevelEnabled(LoggingLevel level);

		static void logCritical(StringView channel, StringView log_message) noexcept;
		static void logWarning(StringView channel, StringView log_message) noexcept;
		static void logInformation(StringView channel, StringView log_message) noexcept;
		static void logDebug(StringView channel, StringView log_message) noexcept;
	private:
		inline static UInt8 s_logging_level{};

		static IConsoleLoggerAdapter* getAdapter();
	};
}
