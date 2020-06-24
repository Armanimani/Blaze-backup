#include "Blaze/Engine/Core/Application/Application.hpp"
#include "Blaze/Engine/Core/Common/constants.hpp"
#include "Blaze/Engine/Core/Logging/ConsoleLogger.hpp"
#include "Blaze/Engine/Core/Time/StopWatch.hpp"
#include "Blaze/Engine/Core/Time/Clock.hpp"
#include "Blaze/Engine/Core/Entity/entity.hpp"

namespace blaze
{
	Application::Application()
	{
		context = std::make_unique<Context>();
	}

	void Application::addPipeline(std::unique_ptr<Pipeline>&& pipeline)
	{
		pipelines.push_back(std::move(pipeline));
	}

	void Application::start() noexcept
	{
		ConsoleLogger::logInformation(k_engine_channel, "Starting");
		initialize();
		update();
		finalize();
	}

	void Application::initialize() noexcept
	{
		auto stop_watch = StopWatch();
		stop_watch.start();
		
		ConsoleLogger::logInformation(k_engine_channel, "Initializing");
		initializePipelines();

		stop_watch.stop();
		const auto elapsed_time = stop_watch.getElapsedTime().count();
		ConsoleLogger::logInformation(k_engine_channel, "Initializing Done! took " + std::to_string(elapsed_time) + " ms");
	}

	void Application::update() noexcept
	{
		ConsoleLogger::logInformation(k_engine_channel, "Updating");
		auto frame_clock = Clock();

		is_running = true;
		frame_clock.start();
		while (is_running)
		{
			frame_clock.tick();
			updatePipelines(frame_clock.getLastTickTime().count());
		}

		ConsoleLogger::logInformation(k_engine_channel, "Updating done! took " + std::to_string(frame_clock.getElapsedTime().count()) + " ms");
	}
	
	void Application::finalize() noexcept
	{
		ConsoleLogger::logInformation(k_engine_channel, "Finalizing");
		finalizePipelines();
	}
	
	void Application::initializePipelines() noexcept
	{
		for (Size_t i = 0; i != pipelines.size(); ++i)
		{
			pipelines[i]->initialize(context.get());
		}
	}
	
	void Application::updatePipelines(const Float delta_time) noexcept
	{
		for (Size_t i = 0; i != pipelines.size(); ++i)
		{
			pipelines[i]->update(context.get(), delta_time);
		}
	}
	
	void Application::finalizePipelines() noexcept
	{
		for (Size_t i = 0; i != pipelines.size(); ++i)
		{
			pipelines[i]->finalize(context.get());
		}
	}
}
