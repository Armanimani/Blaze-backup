#pragma once

#include "Blaze/Engine/Core/Application/ISystem.hpp"
#include "Blaze/Engine/Core/Window/IWindow.hpp"
#include "Blaze/Engine/Core/Window/WindowSpecification.hpp"

namespace blaze
{
	class WindowSystem final: public ISystem
	{
	public:
		explicit WindowSystem(WindowSpecification specification = {});
		~WindowSystem() = default;
		void initialize(Context* context) noexcept override;
		void update(Context* context, Float delta_time) noexcept override;
		void finalize(Context* context) noexcept override;
	private:
		std::unique_ptr<IWindow> window{ nullptr };
		WindowSpecification specification{};
	};
}