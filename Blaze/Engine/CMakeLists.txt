add_subdirectory(Core)

 add_library(
	blaze_engine
	INTERFACE
)

target_link_libraries(
	blaze_engine
	INTERFACE Blaze::ProjectOption Blaze::ProjectWarnings Blaze::Engine::Core
)

add_library(Blaze::Engine ALIAS blaze_engine)
