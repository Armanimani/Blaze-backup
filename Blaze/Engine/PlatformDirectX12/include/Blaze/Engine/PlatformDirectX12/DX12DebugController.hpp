#pragma once

#include "Blaze/Engine/PlatformDirectX12/common.hpp"

namespace blaze
{
	class DX12DebugController
	{
	public:
		static void enableDebugInterface() noexcept;
		static void enableDebugInfoQueue(const Microsoft::WRL::ComPtr<ID3D12Device>& device) noexcept;
	};
}
