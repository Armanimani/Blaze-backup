#pragma once

#include "Blaze/Engine/PlatformDirectX12/common.hpp"

namespace blaze
{
	class DX12FenceEventFactory
	{
	public:
		[[nodiscard]] static HANDLE create() noexcept;
	};
}