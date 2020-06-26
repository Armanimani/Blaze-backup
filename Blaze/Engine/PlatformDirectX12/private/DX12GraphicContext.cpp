#include "Blaze/Engine/PlatformDirectX12/DX12GraphicContext.hpp"
#include "Blaze/Engine/PlatformDirectX12/common.hpp"
#include "Blaze/Engine/PlatformDirectX12/DX12DebugController.hpp"
#include "Blaze/Engine/PlatformDirectX12/DX12DeviceFactory.hpp"
#include "Blaze/Engine/PlatformDirectX12/DX12CommandQueueFactory.hpp"
#include "Blaze/Engine/PlatformDirectX12/DX12CommandListFactory.hpp"
#include "Blaze/Engine/PlatformDirectX12/DX12DescriptorHeapFactory.hpp"
#include "Blaze/Engine/PlatformDirectX12/DX12SwapChainFactory.hpp"
#include "Blaze/Engine/PlatformDirectX12/DX12CommandAllocatorFactory.hpp"
#include "Blaze/Engine/PlatformDirectX12/DX12FenceFactory.hpp"

#include <Blaze/Engine/Core/Logging/ConsoleLogger.hpp>

namespace blaze
{
	DX12GraphicContext::DX12GraphicContext([[maybe_unused]] const GraphicSpecification& specification, void* window_handle)
		: handle{ static_cast<HWND>(window_handle) }
	{
		if (specification.is_triple_buffering_enabled)
			buffer_count = 3;
		else
			buffer_count = 2;
	}

	void DX12GraphicContext::initialize() noexcept
	{
		// TODO: add a custom compiling rule for debug mode
		DX12DebugController::enableDebugInterface();
		device = DX12DeviceFactory::create();
		DX12DebugController::enableDebugInfoQueue(device);

		graphic_command_queue = DX12CommandQueueFactory::create(device, D3D12_COMMAND_LIST_TYPE_DIRECT, D3D12_COMMAND_QUEUE_PRIORITY_NORMAL);
		swap_chain = DX12SwapChainFactory::create(graphic_command_queue, handle, 0, 0, buffer_count);	

		createRenderTargetViews();
		createCommandList();
		createFences();
	}


	void DX12GraphicContext::present() noexcept
	{
		updatePipeline();

		ID3D12CommandList* const command_list[] =
		{
			graphic_command_list.Get()
		};

		graphic_command_queue->ExecuteCommandLists(1, command_list);

		if (FAILED(graphic_command_queue->Signal(fence_list[frame_index].Get(), fence_value_list[frame_index])))
			ConsoleLogger::logCritical(k_dx12_channel, "Unable to signal the fence value!");

		if (FAILED(swap_chain->Present(0, 0)))
			ConsoleLogger::logCritical(k_dx12_channel, "Unable to present!");
	}
	
	void DX12GraphicContext::finalize() noexcept
	{
		for (UInt32 i = 0; i != buffer_count; ++i)
		{
			frame_index = i;
			waitForPreviousFrame();
		}
	}

	void DX12GraphicContext::createRenderTargetViews() noexcept
	{
		rtv_descriptor_heap = DX12DescriptorHeapFactory::create(device, buffer_count, D3D12_DESCRIPTOR_HEAP_TYPE_RTV);
		
		const auto rtv_descriptor_size = DX12DescriptorHeapFactory::getRtvDescriptorSize(device);
		CD3DX12_CPU_DESCRIPTOR_HANDLE descriptor_handle(rtv_descriptor_heap->GetCPUDescriptorHandleForHeapStart());
		
		for (UInt32 i = 0; i != buffer_count; ++i)
		{
			back_buffer_list.emplace_back(nullptr);
			const auto result = swap_chain->GetBuffer(i, IID_PPV_ARGS(&back_buffer_list[i]));

			if (FAILED(result))
				ConsoleLogger::logCritical(k_dx12_channel, "Unable to get the back buffer from swap chain!");

			device->CreateRenderTargetView(back_buffer_list[i].Get(), nullptr, descriptor_handle);
			descriptor_handle.Offset(rtv_descriptor_size);
		}
	}
	
	void DX12GraphicContext::createCommandList() noexcept
	{
		for (UInt32 i = 0; i != buffer_count; ++i)
			command_allocator_list.push_back(DX12CommandAllocatorFactory::create(device, D3D12_COMMAND_LIST_TYPE_DIRECT));

		graphic_command_list = DX12CommandListFactory::create(device, command_allocator_list[0], D3D12_COMMAND_LIST_TYPE_DIRECT);
	}
	
	void DX12GraphicContext::createFences() noexcept
	{
		for (UInt32 i = 0; i != buffer_count; ++i)
		{
			const auto fence = DX12FenceFactory::create(device, D3D12_FENCE_FLAG_NONE);
			fence_list.push_back(fence);
			fence_value_list.push_back(0);
		}
	}
	
	void DX12GraphicContext::waitForPreviousFrame() noexcept
	{
		frame_index = swap_chain->GetCurrentBackBufferIndex();

		if (fence_list[frame_index]->GetCompletedValue() < fence_value_list[frame_index])
		{
			if (FAILED(fence_list[frame_index]->SetEventOnCompletion(fence_value_list[frame_index], fence_event)))
				ConsoleLogger::logCritical(k_dx12_channel, "Unable to set the event for fence");
			
			WaitForSingleObject(fence_event, INFINITE);
		}

		fence_value_list[frame_index]++;
	}
	
	void DX12GraphicContext::updatePipeline() noexcept
	{
		waitForPreviousFrame();

		if (FAILED(command_allocator_list[frame_index]->Reset()))
			ConsoleLogger::logCritical(k_dx12_channel, "Unable to reset the command allocator");

		if (FAILED(graphic_command_list->Reset(command_allocator_list[frame_index].Get(), NULL)))
			ConsoleLogger::logCritical(k_dx12_channel, "Unable to reset the command allocator");

		const auto rtv_barrier = CD3DX12_RESOURCE_BARRIER::Transition(back_buffer_list[frame_index].Get(), D3D12_RESOURCE_STATE_PRESENT, D3D12_RESOURCE_STATE_RENDER_TARGET);
		graphic_command_list->ResourceBarrier(1, &rtv_barrier);

		const auto rtv_descriptor_size = DX12DescriptorHeapFactory::getRtvDescriptorSize(device);
		CD3DX12_CPU_DESCRIPTOR_HANDLE descriptor_handle(rtv_descriptor_heap->GetCPUDescriptorHandleForHeapStart(), frame_index, rtv_descriptor_size);
		graphic_command_list->OMSetRenderTargets(1, &descriptor_handle, FALSE, nullptr);

		const float color[] = { 0.0f, 0.2f, 0.4f, 1.0f };
		graphic_command_list->ClearRenderTargetView(descriptor_handle, color, 0, nullptr);

		const auto state_present_barrier = CD3DX12_RESOURCE_BARRIER::Transition(back_buffer_list[frame_index].Get(), D3D12_RESOURCE_STATE_RENDER_TARGET, D3D12_RESOURCE_STATE_PRESENT);
		graphic_command_list->ResourceBarrier(1, &state_present_barrier);

		if (FAILED(graphic_command_list->Close()))
			ConsoleLogger::logCritical(k_dx12_channel, "Unable to close the graphic command list");
	}
}
