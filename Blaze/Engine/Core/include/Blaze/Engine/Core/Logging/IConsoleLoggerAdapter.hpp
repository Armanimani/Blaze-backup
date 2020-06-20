#pragma once

#include <string_view>

namespace blaze
{	
	class IConsoleLoggerAdapter
	{
	public:
		virtual ~IConsoleLoggerAdapter() = default;
		
		virtual void logCritical(std::string_view channel, std::string_view log_message) noexcept = 0;
		virtual void logWarning(std::string_view channel, std::string_view log_message) noexcept = 0;
		virtual void logInformation(std::string_view channel, std::string_view log_message) noexcept = 0;
		virtual void logDebug(std::string_view channel, std::string_view log_message) noexcept = 0;
	};
}
