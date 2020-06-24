add_subdirectory(Core)
add_subdirectory(Graphics)
add_subdirectory(PlatformWindows)
add_subdirectory(PlatformDirectX12)
add_subdirectory(SpdLog)

 add_library(
	blaze_engine
	INTERFACE
)

target_link_libraries(
	blaze_engine
	INTERFACE 
		Blaze::ProjectOption 
		Blaze::ProjectWarnings 
		Blaze::Engine::Core
		Blaze::Engine::Graphics
		Blaze::Engine::Platform::DirectX12
		Blaze::Engine::Platform::Windows
		Blaze::Engine::SpdLog
)

add_library(Blaze::Engine ALIAS blaze_engine)
