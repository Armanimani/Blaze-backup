#pragma once

#include <cstdint>
#include <cstdlib>
#include <string>
#include <string_view>
#include <chrono>

namespace blaze
{
	using Int8 = int_fast8_t;
	using Int16 = int_fast16_t;
	using Int32 = int_fast32_t;
	using Int64 = int_fast64_t;

	using UInt8 = uint_fast8_t;
	using UInt16 = uint_fast16_t;
	using UInt32 = uint_fast32_t;
	using UInt64 = uint_fast64_t;

	using Float = float;
	using Double = double;

	using Bool = bool;

	using Char = char;
	using String = std::string;
	using StringView = std::string_view;

	using Milliseconds = std::chrono::milliseconds;

	/* Aliases */
	using Size_t = UInt64;

	/* Constants */
	constexpr Float k_floating_point_precision = 1.0E-7f;
}
