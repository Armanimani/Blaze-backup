#pragma once

#include <Blaze/Engine/Core/Types/base_types.hpp>

namespace blaze
{
	class DX12FeatureChecker
	{
	public:
		[[nodiscard]] static Bool isTearingSupported() noexcept;
	};
}