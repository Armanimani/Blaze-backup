#pragma once

#include "Blaze/Engine/Core/Window/IWindowFactoryAdapter.hpp"

namespace blaze
{
	class Win32WindowFactoryAdapter final: public IWindowFactoryAdapter
	{
	public:
		[[nodiscard]] std::unique_ptr<IWindow> createWindow(const WindowSpecification& specification) noexcept override;
	};
}
