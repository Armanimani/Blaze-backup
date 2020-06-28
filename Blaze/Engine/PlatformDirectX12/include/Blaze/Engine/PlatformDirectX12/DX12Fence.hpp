#pragma once

#include "Blaze/Engine/PlatformDirectX12/common.hpp"
#include "Blaze/Engine/Core/Types/base_types.hpp"

namespace blaze
{
	class DX12Fence
	{
	public:
		DX12Fence(const Microsoft::WRL::ComPtr<ID3D12Device>& device, D3D12_FENCE_FLAGS flags);

		void wait() noexcept;
		
		[[nodiscard]] UInt64 getNextValue() const noexcept;
		[[nodiscard]] UInt64 getValue() const noexcept;
		
		[[nodiscard]] ID3D12Fence1* getNativeFence() const noexcept;
	private:
		Microsoft::WRL::ComPtr<ID3D12Fence1> fence{};
		
		HANDLE handle{};
		UInt64 value{};

		Bool isSignaled() const noexcept;
	};
}