#include "Blaze/Engine/Core/Application/Pipeline.hpp"

namespace blaze
{
	void Pipeline::addSystem(std::unique_ptr<ISystem>&& system) noexcept
	{
		systems.push_back(std::move(system));
	}

	void Pipeline::initialize(Context* context) noexcept
	{
		for (std::size_t i = 0; i != systems.size(); ++i)
		{
			systems[i]->initialize(context);
		}
	}
	void Pipeline::update(Context* context, const Float delta_time) noexcept
	{
		for (std::size_t i = 0; i != systems.size(); ++i)
		{
			systems[i]->update(context, delta_time);
		}
	}
	void Pipeline::finalize(Context* context) noexcept
	{
		for (std::size_t i = 0; i != systems.size(); ++i)
		{
			systems[i]->finalize(context);
		}
	}
}
