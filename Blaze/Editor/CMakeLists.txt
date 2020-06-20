add_executable(
	blaze_editor
	"private/main.cpp"
)

target_link_libraries(
	blaze_editor
	PUBLIC Blaze::ProjectOption Blaze::ProjectWarnings Blaze::Engine
)

target_include_directories(
	blaze_editor
	PRIVATE 
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>	
		$<INSTALL_INTERFACE:include>
)

add_subdirectory(test)