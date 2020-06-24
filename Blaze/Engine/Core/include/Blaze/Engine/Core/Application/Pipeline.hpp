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
		
		void initialize(Context* context) noexcept;
		void update(Context* context, Float delta_time) noexcept;
		void finalize(Context* context) noexcept;
	private:
		std::vector<std::unique_ptr<ISystem>> systems{};
	};
}