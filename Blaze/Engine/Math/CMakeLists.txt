 add_library(
	blaze_engine_math
	"private/Types/IntVector2.cpp"
)

target_include_directories(blaze_engine_math 
	INTERFACE
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
		$<INSTALL_INTERFACE:include>
	PUBLIC
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>	
)

target_link_libraries(
	blaze_engine_math
	PUBLIC Blaze::ProjectOption Blaze::ProjectWarnings DirectXMath
)

add_library(Blaze::Engine::Math ALIAS blaze_engine_math)

add_subdirectory(test)