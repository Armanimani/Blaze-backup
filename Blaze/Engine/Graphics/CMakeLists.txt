 add_library(
	blaze_engine_graphics
	"private/Context/GraphicContextFactory.cpp" "include/Blaze/Engine/Graphics/Context/IGraphicContextFactoryAdapter.hpp" "include/Blaze/Engine/Graphics/GraphicSystem.hpp" "private/GraphicSystem.cpp" "include/Blaze/Engine/Graphics/GraphicComponent.hpp" )

target_include_directories(blaze_engine_graphics
	INTERFACE
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
		$<INSTALL_INTERFACE:include>
	PUBLIC
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>	
		$<INSTALL_INTERFACE:include>
)

target_link_libraries(
	blaze_engine_graphics
	PUBLIC 
		Blaze::ProjectOption 
		Blaze::ProjectWarnings
		Blaze::Engine::Core
)

add_library(Blaze::Engine::Graphics ALIAS blaze_engine_graphics)