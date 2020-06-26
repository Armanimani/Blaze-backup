#pragma once

#include <wrl.h>
#include <d3d12.h>

namespace blaze
{
	class DX12DebugController
	{
	public:
		static void enableDebugInterface() noexcept;
		static void enableDebugInfoQueue(const Microsoft::WRL::ComPtr<ID3D12Device>& device) noexcept;
	};
}
