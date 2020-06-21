#pragma once

#include <Blaze/Engine/Core//Window/IWindow.hpp>
#include <Blaze/Engine/Core/Window/WindowSpecification.hpp>
#include <Windows.h>
#include <unordered_map>

namespace blaze
{
	class Win32Window final: public IWindow
	{
	public:
		Win32Window() = delete;
		Win32Window(const WindowSpecification& specification);
		~Win32Window();
		
		[[nodiscard]] void* getHandle() const noexcept override;

		void update() const noexcept override;
		void close() const noexcept override;

		void focus() const noexcept override;
		void show() const noexcept override;
		void hide() const noexcept override;

		void maximize() const noexcept override;
		void minimize() const noexcept override;
		void restore() const noexcept override;

		[[nodiscard]] Bool isMaximized() const noexcept override;
		[[nodiscard]] Bool isMinimized() const noexcept override;
		[[nodiscard]] Bool isVisible() const noexcept override;
		[[nodiscard]] Bool isFocused() const noexcept override;
		
		void setSize(Int32 x, Int32 y, Int32 width, Int32 height) const noexcept override;

		[[nodiscard]] Int32 getWidth() const noexcept override;
		[[nodiscard]] Int32 getHeight() const noexcept override;
	private:
		inline static Bool is_initialized { false };
		inline static HINSTANCE handle_instance{};
		inline static std::unordered_map<HWND, Win32Window*> window_registry{};

		HWND handle{};
		void createWindow(const WindowSpecification& specification) noexcept;

		static void initialize() noexcept;
		static void initializeInstanceHandle() noexcept;
		static void registerWindowClass() noexcept;
		static void createErrorMessage(const String& message) noexcept;

		static void registerWindow(HWND handle, Win32Window* window) noexcept;
		static Win32Window* getWindow(HWND handle) noexcept;
		
		static LRESULT CALLBACK windowProcCallback(HWND handle, UINT message, WPARAM w_param, LPARAM l_param);
	};
}
