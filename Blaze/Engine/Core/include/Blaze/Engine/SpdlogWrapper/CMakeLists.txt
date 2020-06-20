 add_library(
	blaze_engine_spdlogWrapper
	"private/Math/IntVector2.cpp"
	"private/Math/IntVector3.cpp" 
	"private/Math/IntVector4.cpp"
	"private/Math/FloatVector2.cpp" 
	"private/Math/FloatVector3.cpp" 
	"private/Math/FloatVector4.cpp"
	"private/Math/Matrix4X4.cpp" "private/Logging/ConsoleLogger.cpp")

target_include_directories(blaze_engine_spdlogWrapper
	INTERFACE
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
		$<INSTALL_INTERFACE:include>
	PUBLIC
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>	
		$<INSTALL_INTERFACE:include>
)

target_link_libraries(
	blaze_engine_spdlogWrapper
	PUBLIC Blaze::ProjectOption Blaze::ProjectWarnings
)

add_library(Blaze::Engine::Core ALIAS blaze_engine_core)

add_subdirectory(test)