 add_library(
	blaze_engine_spdlog
	"private/ConsoleLoggerAdapter_SpdLog.cpp")

target_include_directories(blaze_engine_spdlog
	INTERFACE
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
		$<INSTALL_INTERFACE:include>
	PUBLIC
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>	
		$<INSTALL_INTERFACE:include>
)

target_link_libraries(
	blaze_engine_spdlog
	PUBLIC 
		Blaze::ProjectOption 
		Blaze::ProjectWarnings 
		Blaze::Engine::Core
		spdlog
		
)

add_library(Blaze::Engine::SpdLog ALIAS blaze_engine_spdlog)