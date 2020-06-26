 add_library(
	blaze_engine_platform_directX12
	"private/DX12GraphicContextFactoryAdapter.cpp" 
	"private/DX12GraphicContext.cpp" 
	"private/DX12DebugController.cpp" 
	"private/DX12DeviceFactory.cpp" 
	"private/DX12CommandQueueFactory.cpp" 
	"private/DX12CommandListFactory.cpp"
	"private/DX12SwapChainFactory.cpp"
	"private/DX12FeatureChecker.cpp"
	"private/DX12DXGIFactoryFactory.cpp" 
	"private/DX12CommandAllocatorFactory.cpp" 
	"private/DX12DescriptorHeapFactory.cpp" 
	"private/DX12FenceFactory.cpp" 
	"private/DX12FenceEventFactory.cpp")

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
		D3D12.lib
)

add_library(Blaze::Engine::Platform::DirectX12 ALIAS blaze_engine_platform_directX12)