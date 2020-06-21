add_subdirectory(Core)
add_subdirectory(SpdLog)
add_subdirectory(PlatformWindows)

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
		Blaze::Engine::Platform::Windows
		Blaze::Engine::SpdLog
)

add_library(Blaze::Engine ALIAS blaze_engine)
