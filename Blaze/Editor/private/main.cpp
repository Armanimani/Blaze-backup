#include "Blaze/Engine/Core/Logging/ConsoleLogger.hpp"
#include "Blaze/Engine/Core/DesignPatterns/ServiceLocator.hpp"
#include "Blaze/Engine/PlatfowmWindows/Win32WindowFactoryAdapter.hpp"
#include "Blaze/Engine/SpdLog/ConsoleLoggerAdapter_SpdLog.hpp"
#include "Blaze/Engine/Core/Application/Application.hpp"
#include "Blaze/Engine/Core/Application/ISystem.hpp"
#include "Blaze/Engine/Core/Window/WindowSystem.hpp"
#include "Blaze/Engine/Graphics/Context/IGraphicContextFactoryAdapter.hpp"
#include "Blaze/Engine/PlatformDirectX12/DX12GraphicContextFactoryAdapter.hpp"
#include "Blaze/Engine/Graphics/GraphicSystem.hpp"

constexpr const char* k_editor_channel = "Editor";

class FPSSystem: public blaze::ISystem
{
public:
	void initialize([[maybe_unused]] blaze::Context* context) noexcept override
	{
		blaze::ConsoleLogger::logInformation(k_editor_channel, "FPSSystem initialized!");
	}
	
	void update([[maybe_unused]] blaze::Context* context, const blaze::Float delta_time) noexcept override
	{
		frame_count++;
		total_duration += delta_time;

		if (total_duration > 1.0f)
		{
			blaze::ConsoleLogger::logInformation(k_editor_channel, "FPS: " + std::to_string(frame_count));
			total_duration -= 1.0f;
			frame_count = 0;
		}
	}
	
	void finalize([[maybe_unused]] blaze::Context* context) noexcept override
	{
		blaze::ConsoleLogger::logInformation(k_editor_channel, "FPSSystem finalized!");
	}
private:
	blaze::Float total_duration{};
	blaze::UInt32 frame_count{};
};



int main()
{
	auto logger = std::make_unique<blaze::ConsoleLoggerAdapter_SpdLog>();
	blaze::Locator<blaze::IConsoleLoggerAdapter>::provide(std::move(logger));	

	blaze::ConsoleLogger::enableLoggingLevel(blaze::ConsoleLogger::LoggingLevel::critical);
	blaze::ConsoleLogger::enableLoggingLevel(blaze::ConsoleLogger::LoggingLevel::warning);
	blaze::ConsoleLogger::enableLoggingLevel(blaze::ConsoleLogger::LoggingLevel::information);
	blaze::ConsoleLogger::enableLoggingLevel(blaze::ConsoleLogger::LoggingLevel::debug);

	auto window_factory = std::make_unique<blaze::Win32WindowFactoryAdapter>();
	blaze::Locator<blaze::IWindowFactoryAdapter>::provide(std::move(window_factory));

	auto graphic_factory = std::make_unique<blaze::DX12GraphicContextFactoryAdapter>();
	blaze::Locator<blaze::IGraphicContextFactoryAdapter>::provide(std::move(graphic_factory));
	
	auto main_pipeline = std::make_unique<blaze::Pipeline>();
	auto fps_system = std::make_unique<FPSSystem>();
	main_pipeline->addSystem(std::move(fps_system));
	main_pipeline->addSystem(std::make_unique<blaze::WindowSystem>());
	main_pipeline->addSystem(std::make_unique<blaze::GraphicSystem>());

	blaze::Application application{};
	application.addPipeline(std::move(main_pipeline));
	
	application.start();
}