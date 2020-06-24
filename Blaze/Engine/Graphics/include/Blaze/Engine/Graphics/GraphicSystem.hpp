#pragma once

#include "Blaze/Engine/Graphics/Context/IGraphicContext.hpp"
#include "Blaze/Engine/Graphics/Context/GraphicSpecification.hpp"
#include <Blaze/Engine/Core/Application/ISystem.hpp>
#include <memory>


namespace blaze
{
	class GraphicSystem final: public ISystem
	{
	public:
		explicit GraphicSystem(GraphicSpecification specification = {});
		void initialize(Context* context) noexcept override;
		void update(Context* context, Float delta_time) noexcept override;
		void finalize(Context* context) noexcept override;
	private:
		std::unique_ptr<IGraphicContext> graphic_context{ nullptr };
		GraphicSpecification specification{};
	};
}
