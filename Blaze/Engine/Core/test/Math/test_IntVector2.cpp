#include <gtest/gtest.h>

#include "Blaze/Engine/Core/Math/IntVector2.hpp"

using namespace blaze;

TEST(IntVector2, constructor_default)
{
	const IntVector2 vector{};
	
	ASSERT_EQ(vector.x, 0);
	ASSERT_EQ(vector.y, 0);
}

TEST(IntVector2, constructor_uniform)
{
	const IntVector2 vector{ 10 };
	
	ASSERT_EQ(vector.x, 10);
	ASSERT_EQ(vector.y, 10);
}

TEST(IntVector2, constructor_values)
{
	const IntVector2 vector{ 1, 2 };
	
	ASSERT_EQ(vector.x, 1);
	ASSERT_EQ(vector.y, 2);
}

TEST(IntVector2, operator_paranthesis)
{
	IntVector2 vector{ 1, 2 };

	ASSERT_EQ(vector(0), vector.x);
	ASSERT_EQ(vector(1), vector.y);

	vector(0) = 20;
	vector(1) = 30;

	ASSERT_EQ(vector(0), 20);
	ASSERT_EQ(vector(1), 30);
}

TEST(IntVector2, operator_bracket)
{
	IntVector2 vector{ 1, 2 };

	ASSERT_EQ(vector[0], vector.x);
	ASSERT_EQ(vector[1], vector.y);

	vector[0] = 20;
	vector[1] = 30;

	ASSERT_EQ(vector[0], 20);
	ASSERT_EQ(vector[1], 30);
}

TEST(IntVector2, operator_equality_inequality)
{
	const IntVector2 vector1{ 1, 2 };
	IntVector2 vector2{ 1, 2 };

	ASSERT_TRUE(vector1 == vector2);
	ASSERT_FALSE(vector1 != vector2);

	vector2.x = 10;
	ASSERT_FALSE(vector1 == vector2);
	ASSERT_TRUE(vector1 != vector2);
}

TEST(IntVector2, operator_plusEqual)
{
	IntVector2 vector{ 1, 2 };
	vector += IntVector2{ 10, 10 };
	
	ASSERT_EQ(vector[0], 11);
	ASSERT_EQ(vector[1], 12);
}

TEST(IntVector2, operator_minusEqual)
{
	IntVector2 vector{ 1, 2 };
	vector -= IntVector2{ 10, 10 };

	ASSERT_EQ(vector[0], -9);
	ASSERT_EQ(vector[1], -8);
}

TEST(IntVector2, operator_scalerEqual)
{
	IntVector2 vector{ 1, 2 };
	vector *= 10;

	ASSERT_EQ(vector[0], 10);
	ASSERT_EQ(vector[1], 20);
}

TEST(IntVector2, getMax)
{
	const IntVector2 vector{ 1, 2 };
	ASSERT_EQ(vector.getMax(), 2);
}

TEST(IntVector2, getMin)
{
	const IntVector2 vector{ 1, 2 };
	ASSERT_EQ(vector.getMin(), 1);
}

TEST(IntVector2, getLength)
{
	const IntVector2 vector{ 1, 2 };
	ASSERT_FLOAT_EQ(vector.getLength(), sqrtf(1 * 1 + 2 * 2));
}

TEST(IntVector2, getLengthSquared)
{
	const IntVector2 vector{ 1, 2 };
	ASSERT_EQ(vector.getLengthSquared(), 1 * 1 + 2 * 2);
}

TEST(IntVector2, static_variables)
{
	ASSERT_TRUE(IntVector2::k_zero == IntVector2(0, 0));
	ASSERT_TRUE(IntVector2::k_unit_x == IntVector2(1, 0));
	ASSERT_TRUE(IntVector2::k_unit_y == IntVector2(0, 1));
}

TEST(IntVector2, operator_plus)
{
	const IntVector2 vector{ 1, 2 };
	const IntVector2 other{ 10, 10 };
	const auto result = vector + other;

	ASSERT_EQ(result[0], 11);
	ASSERT_EQ(result[1], 12);
}

TEST(IntVector2, operator_minus)
{
	const IntVector2 vector{ 1, 2 };
	const IntVector2 other{ 10, 10 };
	const auto result = vector - other;

	ASSERT_EQ(result[0], -9);
	ASSERT_EQ(result[1], -8);
}

TEST(IntVector2, operator_preScalar)
{
	const IntVector2 vector{ 1, 2 };
	const auto result = vector * 2;

	ASSERT_EQ(result[0], 2);
	ASSERT_EQ(result[1], 4);
}

TEST(IntVector2, operator_postScalar)
{
	const IntVector2 vector{ 1, 2 };
	const auto result = 5 * vector;

	ASSERT_EQ(result[0], 5);
	ASSERT_EQ(result[1], 10);
}