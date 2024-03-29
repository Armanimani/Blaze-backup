#include <Blaze/Engine/Core/Logging/ConsoleLogger.hpp>
#include "Blaze/Engine/PlatfowmWindows/Win32Window.hpp"
#include "Blaze/Engine/PlatfowmWindows/constants.hpp"

namespace blaze
{
	constexpr const char* k_window_class_name = "BlazeWindow";

	Win32Window::Win32Window(const WindowSpecification& specification)
	{
		if (!is_initialized)
		{
			initialize();
		}
		createWindow(specification);
	}

	Win32Window::~Win32Window()
	{
		close();
	}

	void Win32Window::initialize() noexcept
	{
		initializeInstanceHandle();
		registerWindowClass();
		is_initialized = true;
	}

	void Win32Window::registerWindowClass() noexcept
	{
		WNDCLASSEXA wc{};
		wc.cbSize = sizeof(wc);
		wc.style = CS_DBLCLKS | CS_HREDRAW | CS_VREDRAW;
		wc.lpfnWndProc = windowProcCallback;
		wc.cbClsExtra = 0;
		wc.cbWndExtra = 0;
		wc.hInstance = handle_instance;
		wc.hIcon = LoadIcon(nullptr, IDI_APPLICATION);
		wc.hIconSm = LoadIcon(nullptr, IDI_APPLICATION);
		wc.hCursor = LoadCursor(nullptr, IDC_ARROW);
		wc.hbrBackground = nullptr;
		wc.lpszMenuName = nullptr;
		wc.lpszClassName = k_window_class_name;

		if (!RegisterClassExA(&wc))
		{
			createErrorMessage("Windows class registration failed!");
		}
	}
	
	void Win32Window::createWindow(const WindowSpecification& specification) noexcept
	{
		RECT rect{};
		rect.left = specification.initial_position_x;
		rect.top = specification.initial_position_y;
		rect.right = specification.initial_width;
		rect.bottom = specification.initial_height;

		const DWORD dwStyle = WS_CLIPCHILDREN | WS_CLIPSIBLINGS | WS_OVERLAPPEDWINDOW;
		const DWORD dwExStyle = WS_EX_APPWINDOW | WS_EX_WINDOWEDGE;

		AdjustWindowRectEx(&rect, dwStyle, false, dwExStyle);

		const auto window_x = specification.initial_position_x;
		const auto window_y = specification.initial_position_y;
		const auto window_width = rect.right - rect.left;
		const auto window_height = rect.bottom - rect.top;

		handle = CreateWindowExA(
			dwExStyle, k_window_class_name, specification.title.c_str(), dwStyle,
			window_x, window_y, window_width, window_height,
			nullptr, nullptr, handle_instance, nullptr
		);

		if (!handle)
		{
			createErrorMessage("Unable to create window");
			return;
		}

		registerWindow(handle, this);
	}

	void* Win32Window::getHandle() const noexcept
	{
		return static_cast<void*>(handle);
	}

	void Win32Window::close() const noexcept
	{
		CloseWindow(handle);
	}

	void Win32Window::focus() const noexcept
	{
		SetFocus(handle);
	}

	void Win32Window::setSize(const Int32 x, const Int32 y, const Int32 width, const Int32 height) const noexcept
	{
		SetWindowPos(handle, nullptr, x, y, width, height, SWP_NOZORDER);
	}
	
	Int32 Win32Window::getWidth() const noexcept
	{
		RECT rect{};
		GetWindowRect(handle, &rect);
		return rect.right - rect.left;
	}
	
	Int32 Win32Window::getHeight() const noexcept
	{
		RECT rect{};
		GetWindowRect(handle, &rect);
		return rect.top - rect.bottom;
	}
	
	void Win32Window::maximize() const noexcept
	{
		ShowWindow(handle, SW_MAXIMIZE);
	}
	
	void Win32Window::minimize() const noexcept
	{
		ShowWindow(handle, SW_MINIMIZE);
	}
	
	void Win32Window::restore() const noexcept
	{
		ShowWindow(handle, SW_RESTORE);
	}
	
	void Win32Window::show() const noexcept
	{
		ShowWindow(handle, SW_SHOW);
	}
	
	void Win32Window::hide() const noexcept
	{
		ShowWindow(handle, SW_HIDE);
	}
	
	Bool Win32Window::isMaximized() const noexcept
	{
		return IsZoomed(handle);
	}
	
	Bool Win32Window::isMinimized() const noexcept
	{
		return IsIconic(handle);
	}
	
	Bool Win32Window::isVisible() const noexcept
	{
		return IsWindowVisible(handle);
	}

	Bool Win32Window::isFocused() const noexcept
	{
		return (GetFocus() == handle);
	}

	void Win32Window::registerWindow(HWND handle, Win32Window* window) noexcept
	{
		window_registry[handle] = window;
	}
	
	Win32Window* Win32Window::getWindow(HWND handle) noexcept
	{
		return window_registry[handle];
	}

	void Win32Window::initializeInstanceHandle() noexcept
	{
		handle_instance = GetModuleHandle(nullptr);
		if (!handle_instance)
		{
			createErrorMessage("Unable to get the module handle");
		}
	}

	void Win32Window::createErrorMessage(const String& message)  noexcept
	{
		const UInt32 error = GetLastError();
		ConsoleLogger::logCritical(k_windows_channel, message + " ErrorCode: " + std::to_string(error));
		MessageBox(nullptr, TEXT(message.c_str()), TEXT("Error"), MB_ICONEXCLAMATION | MB_OK);
	}

	void Win32Window::update() const noexcept
	{
		MSG message{};
		while (PeekMessage(&message, nullptr, 0, 0, PM_REMOVE) > 0)
		{
			TranslateMessage(&message);
			DispatchMessage(&message);
		}
	}

	LRESULT CALLBACK Win32Window::windowProcCallback(HWND handle, const UINT message, const WPARAM w_param, const LPARAM l_param)
	{
		return DefWindowProc(handle, message, w_param, l_param);
	}
}
