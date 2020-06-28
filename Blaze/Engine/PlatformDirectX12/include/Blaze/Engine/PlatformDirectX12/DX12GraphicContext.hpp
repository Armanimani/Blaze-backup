#pragma once

#include <Blaze/Engine/Graphics/Context/IGraphicContext.hpp>
#include <Blaze/Engine/Graphics/Context/GraphicSpecification.hpp>
#include <Windows.h>
#include <vector>
#include <memory>

#include "Blaze/Engine/PlatformDirectX12/common.hpp"
#include "Blaze/Engine/PlatformDirectX12/DX12Device.hpp"
#include "Blaze/Engine/PlatformDirectX12/DX12Fence.hpp"

namespace blaze
{
	class DX12GraphicContext final: public IGraphicContext
	{
	public:
		DX12GraphicContext(const GraphicSpecification& specification, void* window_handle);

		void initialize() noexcept override;
		void present() noexcept override;
		void finalize() noexcept override;

		void handleResize() noexcept;
	private:
		HWND handle{};
		UInt32 buffer_count{};
		UInt32 frame_index{};
		
		std::unique_ptr<DX12Device> device{ nullptr };
		Microsoft::WRL::ComPtr<IDXGISwapChain4> swap_chain{};
		Microsoft::WRL::ComPtr<ID3D12GraphicsCommandList> graphic_command_list{};
		Microsoft::WRL::ComPtr<ID3D12CommandQueue> graphic_command_queue{};
		Microsoft::WRL::ComPtr<ID3D12DescriptorHeap> rtv_descriptor_heap{};
		Microsoft::WRL::ComPtr<ID3D12DescriptorHeap> dsv_descriptor_heap{};

		std::vector<Microsoft::WRL::ComPtr<ID3D12Resource1>> back_buffer_list{};
		std::vector<Microsoft::WRL::ComPtr<ID3D12CommandAllocator>> command_allocator_list{};
		std::vector<DX12Fence> fence_list{};

		UInt32 rtv_descriptor_size{};
		UInt32 dsv_descriptor_size{};
		UInt32 cbv_srv_uav_descriptor_size{};

		void createFences() noexcept;
		void createCommandObjects() noexcept;
		void createSwapChain() noexcept;
		void createRtvAndDsvDescriptorHeaps() noexcept;

		[[nodiscard]] D3D12_CPU_DESCRIPTOR_HANDLE getCurrentBackBufferViewHandle() const noexcept;
		[[nodiscard]] D3D12_CPU_DESCRIPTOR_HANDLE getCurrentDepthStencilViewHandle() const noexcept;
		[[nodiscard]] ID3D12Resource* getCurrentBackBuffer() const noexcept;
		
		void waitForPreviousFrame() noexcept;
		void updatePipeline() noexcept;
	};
}