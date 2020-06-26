#pragma once

#include "Blaze/Engine/PlatformDirectX12/common.hpp"

namespace blaze
{
	class DX12DXGIFactoryFactory
	{
	public:
		[[nodiscard]] static Microsoft::WRL::ComPtr<IDXGIFactory7> create() noexcept;
	};
}
