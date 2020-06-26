#pragma once

#include <Blaze/Engine/Graphics/Context/IGraphicContext.hpp>
#include <Blaze/Engine/Graphics/Context/GraphicSpecification.hpp>
#include <Windows.h>
#include <vector>

#include "Blaze/Engine/PlatformDirectX12/common.hpp"

namespace blaze
{
	class DX12GraphicContext final: public IGraphicContext
	{
	public:
		DX12GraphicContext(const GraphicSpecification& specification, void* window_handle);

		void initialize() noexcept override;
		void present() noexcept override;
		void finalize() noexcept override;
	private:
		HWND handle{};
		UInt32 buffer_count{};
		
		Microsoft::WRL::ComPtr<ID3D12Device> device{};
		Microsoft::WRL::ComPtr<IDXGISwapChain4> swap_chain{};
		Microsoft::WRL::ComPtr<ID3D12GraphicsCommandList5> graphic_command_list{};
		Microsoft::WRL::ComPtr<ID3D12CommandQueue> graphic_command_queue{};
		Microsoft::WRL::ComPtr<ID3D12DescriptorHeap> rtv_descriptor_heap{};

		std::vector<Microsoft::WRL::ComPtr<ID3D12Resource1>> back_buffer_list{};
		std::vector<Microsoft::WRL::ComPtr<ID3D12CommandAllocator>> command_allocator_list{};
		std::vector<Microsoft::WRL::ComPtr<ID3D12Fence1>> fence_list{};
		std::vector<UINT64> fence_value_list{};

		UInt32 frame_index{};
		HANDLE fence_event{};

		void createRenderTargetViews() noexcept;
		void createCommandList() noexcept;
		void createFences() noexcept;

		void waitForPreviousFrame() noexcept;
		void updatePipeline() noexcept;
	};
}