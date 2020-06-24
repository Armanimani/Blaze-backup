#pragma once

#include "Blaze/Engine/Core/Types/base_types.hpp"
#include "Blaze/Engine/Core/Application/Pipeline.hpp"
#include "Blaze/Engine/Core/Application/Context.hpp"

namespace blaze
{
	class Application
	{
	public:
		Application();
		~Application() = default;

		void addPipeline(std::unique_ptr<Pipeline>&& pipeline);
		
		void start() noexcept;
	private:
		Bool is_running{ false };
		std::vector<std::unique_ptr<Pipeline>> pipelines{};
		std::unique_ptr<Context> context{ nullptr };
		
		void initialize() noexcept;
		void update() noexcept;
		void finalize() noexcept;

		void initializePipelines() noexcept;
		void updatePipelines(Float delta_time) noexcept;
		void finalizePipelines() noexcept;
	};
}
