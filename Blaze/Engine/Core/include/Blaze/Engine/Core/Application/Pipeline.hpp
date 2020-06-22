#pragma once

#include "Blaze/Engine/Core/Application/ISystem.hpp"

#include <memory>
#include <vector>

namespace blaze
{
	class Pipeline
	{
	public:
		void addSystem(std::unique_ptr<ISystem>&& system) noexcept;
		
		void initialize() noexcept;
		void update(Float delta_time) noexcept;
		void finalize() noexcept;
	private:
		std::vector<std::unique_ptr<ISystem>> systems{};
	};
}