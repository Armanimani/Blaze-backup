#pragma once

#include "Blaze/Engine/Core/Types/base_types.hpp"
#include "Blaze/Engine/Core/Logging/IConsoleLoggerAdapter.hpp"
#include "spdlog/spdlog.h"


namespace blaze
{
	class ConsoleLoggerAdapter_SpdLog final: public IConsoleLoggerAdapter
	{
	public:
		ConsoleLoggerAdapter_SpdLog();
		
		void logCritical(StringView channel, StringView log_message) noexcept override;
		void logWarning(StringView channel, StringView log_message) noexcept override;
		void logInformation(StringView channel, StringView log_message) noexcept override;
		void logDebug(StringView channel, StringView log_message) noexcept override;
	private:	
		[[nodiscard]] static spdlog::logger* createLogger(StringView channel) noexcept;
		[[nodiscard]] spdlog::logger* getLogger(StringView channel) noexcept;
	};
}
