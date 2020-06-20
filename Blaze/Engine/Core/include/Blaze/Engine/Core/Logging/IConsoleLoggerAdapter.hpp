#pragma once

namespace blaze
{	
	class IConsoleLoggerAdapter
	{
	public:
		virtual ~IConsoleLoggerAdapter() = default;
		
		virtual void logCritical(StringView channel, StringView log_message) noexcept = 0;
		virtual void logWarning(StringView channel, StringView log_message) noexcept = 0;
		virtual void logInformation(StringView channel, StringView log_message) noexcept = 0;
		virtual void logDebug(StringView channel, StringView log_message) noexcept = 0;
	};
}
