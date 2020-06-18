#pragma once

namespace blaze
{
	template <typename T>
	constexpr T max(const T lhs , const T rhs) noexcept
	{
		return (lhs > rhs) ? lhs : rhs;
	}

	template <typename T>
	constexpr T min(const T lhs, const T rhs) noexcept
	{
		return (lhs <= rhs) ? lhs : rhs;
	}
}
