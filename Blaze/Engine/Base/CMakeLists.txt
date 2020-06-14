 add_library(
	blaze_engine_base
	src/app.cpp
)

target_include_directories(blaze_engine_base 
	INTERFACE
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
		$<INSTALL_INTERFACE:include>
	PUBLIC
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>	
)

target_link_libraries(
	blaze_engine_base
	INTERFACE Blaze::ProjectOption Blaze::ProjectWarnings
)

add_library(Blaze::Engine::Base ALIAS blaze_engine_base)

add_subdirectory(test)