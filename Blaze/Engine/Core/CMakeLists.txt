 add_library(
	blaze_engine_core
	"private/Math/IntVector2.cpp"
	"private/Math/IntVector3.cpp" 
	"private/Math/IntVector4.cpp"
	"private/Math/FloatVector2.cpp" 
	"private/Math/FloatVector3.cpp" 
	"private/Math/FloatVector4.cpp"
	"private/Math/Matrix4X4.cpp" 
	"private/Logging/ConsoleLogger.cpp"
	"private/Window/WindowFactory.cpp" 
	"private/Application/Application.cpp"
	"private/Application/Pipeline.cpp"
	"private/Time/Timer.cpp" 
	"private/Time/CalenderClock.cpp" 
	"private/Time/StopWatch.cpp" 
	"private/Time/Clock.cpp"
	"private/Window/WindowSystem.cpp")

target_include_directories(blaze_engine_core
	INTERFACE
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
		$<INSTALL_INTERFACE:include>
	PUBLIC
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>	
		$<INSTALL_INTERFACE:include>
)

target_link_libraries(
	blaze_engine_core
	PUBLIC 
		Blaze::ProjectOption 
		Blaze::ProjectWarnings 
		DirectXMath
		entt
)

add_library(Blaze::Engine::Core ALIAS blaze_engine_core)

add_subdirectory(test)