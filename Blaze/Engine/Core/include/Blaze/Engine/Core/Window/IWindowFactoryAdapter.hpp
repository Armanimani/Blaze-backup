#pragma once

#include <memory>

#include "Blaze/Engine/Core/Window/IWindow.hpp"
#include "Blaze/Engine/Core/Window/WindowSpecification.hpp"

namespace blaze
{
	class IWindowFactoryAdapter
	{
	public:
		virtual ~IWindowFactoryAdapter() = default;
		[[nodiscard]] virtual std::unique_ptr<IWindow> createWindow(const WindowSpecification& initial_specification) noexcept = 0;
	};
}