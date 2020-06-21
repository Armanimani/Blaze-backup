 add_library(
	blaze_engine_platform_windows
	"private/Win32Window.cpp"
	"private/Win32WindowFactoryAdapter.cpp")

target_include_directories(blaze_engine_platform_windows
	INTERFACE
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
		$<INSTALL_INTERFACE:include>
	PUBLIC
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>	
		$<INSTALL_INTERFACE:include>
)

target_link_libraries(
	blaze_engine_platform_windows
	PUBLIC 
		Blaze::ProjectOption 
		Blaze::ProjectWarnings 
		Blaze::Engine::Core
)

add_library(Blaze::Engine::Platform::Windows ALIAS blaze_engine_platform_windows)