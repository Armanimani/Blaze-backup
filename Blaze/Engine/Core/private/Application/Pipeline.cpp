#include "Blaze/Engine/Core/Application/Pipeline.hpp"

namespace blaze
{
	void Pipeline::addSystem(std::unique_ptr<ISystem>&& system) noexcept
	{
		systems.push_back(std::move(system));
	}

	void Pipeline::initialize() noexcept
	{
		for (std::size_t i = 0; i != systems.size(); ++i)
		{
			systems[i]->initialize();
		}
	}
	void Pipeline::update(const Milliseconds delta_time) noexcept
	{
		for (std::size_t i = 0; i != systems.size(); ++i)
		{
			systems[i]->update(delta_time);
		}
	}
	void Pipeline::finalize() noexcept
	{
		for (std::size_t i = 0; i != systems.size(); ++i)
		{
			systems[i]->finalize();
		}
	}
}
