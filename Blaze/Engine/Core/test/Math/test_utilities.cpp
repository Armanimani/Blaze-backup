#include <gtest/gtest.h>

#include "Blaze/Engine/Core/Math/utilities.hpp"

using namespace blaze;

TEST(utilities, min)
{
	constexpr auto a{ 10.1f };
	constexpr auto b{ 20.2f };

	ASSERT_FLOAT_EQ(min(a, b), a);
}

TEST(utilities, max)
{
	constexpr auto a{ 10.1f };
	constexpr auto b{ 20.2f };

	ASSERT_FLOAT_EQ(max(a, b), b);
}