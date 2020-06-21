#pragma once

#include <memory>

#include "Blaze/Engine/Core/Window/IWindow.hpp"
#include "Blaze/Engine/Core/Window/WindowSpecification.hpp"
#include "Blaze/Engine/Core/Window/IWindowFactoryAdapter.hpp"

namespace blaze
{
	class WindowFactory
	{
	public:
		static std::unique_ptr<IWindow> create(const WindowSpecification& specification) noexcept;

	private:
		static IWindowFactoryAdapter* getAdapter();
	};
}
