 add_library(
	blaze_engine_platform_directX12
	"private/DX12GraphicContextFactoryAdapter.cpp" "include/Blaze/Engine/PlatformDirectX12/DX12GraphicContext.hpp" "private/DX12GraphicContext.cpp" "private/DX12DebugController.cpp" "include/Blaze/Engine/PlatformDirectX12/common.hpp")

target_include_directories(blaze_engine_platform_directX12
	INTERFACE
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
		$<INSTALL_INTERFACE:include>
	PUBLIC
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>	
		$<INSTALL_INTERFACE:include>
)

target_link_libraries(
	blaze_engine_platform_directX12
	PUBLIC 
		Blaze::ProjectOption 
		Blaze::ProjectWarnings
		Blaze::Engine::Core
		Blaze::Engine::Graphics
)

add_library(Blaze::Engine::Platform::DirectX12 ALIAS blaze_engine_platform_directX12)