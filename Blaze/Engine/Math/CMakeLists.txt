 add_library(
	blaze_engine_math
	"private/Types/IntVector2.cpp"
	"private/Types/IntVector3.cpp" 
	"private/Types/IntVector4.cpp"
	"private/Types/FloatVector2.cpp" 
	"private/Types/FloatVector3.cpp" 
	"private/Types/FloatVector4.cpp"
	"private/Types/Matrix4X4.cpp")

target_include_directories(blaze_engine_math 
	INTERFACE
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
		$<INSTALL_INTERFACE:include>
	PUBLIC
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>	
		$<INSTALL_INTERFACE:include>
)

target_link_libraries(
	blaze_engine_math
	PUBLIC Blaze::ProjectOption Blaze::ProjectWarnings DirectXMath
)

add_library(Blaze::Engine::Math ALIAS blaze_engine_math)

add_subdirectory(test)