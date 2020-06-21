#include "Blaze/Engine/PlatfowmWindows/Win32WindowFactoryAdapter.hpp"
#include "Blaze/Engine/PlatfowmWindows/Win32Window.hpp"

namespace blaze
{
	std::unique_ptr<IWindow> Win32WindowFactoryAdapter::createWindow(const WindowSpecification& specification) noexcept
	{
		return std::make_unique<Win32Window>(specification);
	}
}
