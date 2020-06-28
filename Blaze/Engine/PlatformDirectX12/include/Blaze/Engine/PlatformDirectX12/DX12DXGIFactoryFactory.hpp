#pragma once

#include "Blaze/Engine/PlatformDirectX12/common.hpp"
#include "Blaze/Engine/Core/Types/base_types.hpp"

namespace blaze
{
	class DX12DXGIFactoryFactory
	{
	public:
		[[nodiscard]] static Microsoft::WRL::ComPtr<IDXGIFactory7> create(Bool is_debug_enabled = false) noexcept;
	};
}
