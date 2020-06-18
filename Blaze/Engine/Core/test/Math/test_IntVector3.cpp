#include <gtest/gtest.h>

#include "Blaze/Engine/Core/Math/IntVector3.hpp"

using namespace blaze;

TEST(IntVector3, constructor_default)
{
	const IntVector3 vector{};

	ASSERT_EQ(vector.x, 0);
	ASSERT_EQ(vector.y, 0);
	ASSERT_EQ(vector.z, 0);
}

TEST(IntVector3, constructor_uniform)
{
	const IntVector3 vector{ 10 };

	ASSERT_EQ(vector.x, 10);
	ASSERT_EQ(vector.y, 10);
	ASSERT_EQ(vector.z, 10);
}

TEST(IntVector3, constructor_values)
{
	const IntVector3 vector{ 1, 2, 3 };

	ASSERT_EQ(vector.x, 1);
	ASSERT_EQ(vector.y, 2);
	ASSERT_EQ(vector.z, 3);
}

TEST(IntVector3, constructor_IntVector2)
{
	const IntVector2 other{ 1, 2 };
	const IntVector3 vector(other);

	ASSERT_EQ(vector.x, 1);
	ASSERT_EQ(vector.y, 2);
	ASSERT_EQ(vector.z, 0);
}

TEST(IntVector3, operator_paranthesis)
{
	IntVector3 vector{ 1, 2, 3 };

	ASSERT_EQ(vector(0), vector.x);
	ASSERT_EQ(vector(1), vector.y);
	ASSERT_EQ(vector(2), vector.z);

	vector(0) = 20;
	vector(1) = 30;
	vector(2) = 40;

	ASSERT_EQ(vector(0), 20);
	ASSERT_EQ(vector(1), 30);
	ASSERT_EQ(vector(2), 40);
}

TEST(IntVector3, operator_bracket)
{
	IntVector3 vector{ 1, 2, 3 };

	ASSERT_EQ(vector[0], vector.x);
	ASSERT_EQ(vector[1], vector.y);
	ASSERT_EQ(vector[2], vector.z);

	vector[0] = 20;
	vector[1] = 30;
	vector[2] = 40;

	ASSERT_EQ(vector[0], 20);
	ASSERT_EQ(vector[1], 30);
	ASSERT_EQ(vector[2], 40);
}

TEST(IntVector3, operator_equality_inequality)
{
	const IntVector3 vector1{ 1, 2, 3 };
	IntVector3 vector2{ 1, 2, 3 };

	ASSERT_TRUE(vector1 == vector2);
	ASSERT_FALSE(vector1 != vector2);

	vector2.z = 10;
	ASSERT_FALSE(vector1 == vector2);
	ASSERT_TRUE(vector1 != vector2);
}

TEST(IntVector3, operator_plusEqual)
{
	IntVector3 vector{ 1, 2, 3 };
	vector += IntVector3{ 10, 10, 10 };

	ASSERT_EQ(vector[0], 11);
	ASSERT_EQ(vector[1], 12);
	ASSERT_EQ(vector[2], 13);
}

TEST(IntVector3, operator_minusEqual)
{
	IntVector3 vector{ 1, 2, 3 };
	vector -= IntVector3{ 10, 10, 10 };

	ASSERT_EQ(vector[0], -9);
	ASSERT_EQ(vector[1], -8);
	ASSERT_EQ(vector[2], -7);
}

TEST(IntVector3, operator_scalerEqual)
{
	IntVector3 vector{ 1, 2, 3 };
	vector *= 10;

	ASSERT_EQ(vector[0], 10);
	ASSERT_EQ(vector[1], 20);
	ASSERT_EQ(vector[2], 30);
}

TEST(IntVector3, getMax)
{
	const IntVector3 vector{ 1, 2, 3 };
	ASSERT_EQ(vector.getMax(), 3);
}

TEST(IntVector3, getMin)
{
	const IntVector3 vector{ 1, 2, 3 };
	ASSERT_EQ(vector.getMin(), 1);
}

TEST(IntVector3, getLength)
{
	const IntVector3 vector{ 1, 2, 3 };
	ASSERT_FLOAT_EQ(vector.getLength(), sqrtf(1 * 1 + 2 * 2 + 3 * 3));
}

TEST(IntVector3, getLengthSquared)
{
	const IntVector3 vector{ 1, 2, 3 };
	ASSERT_EQ(vector.getLengthSquared(), 1 * 1 + 2 * 2 + 3 * 3);
}

TEST(IntVector3, static_variables)
{
	ASSERT_TRUE(IntVector3::k_zero == IntVector3(0, 0, 0));
	ASSERT_TRUE(IntVector3::k_unit_x == IntVector3(1, 0, 0));
	ASSERT_TRUE(IntVector3::k_unit_y == IntVector3(0, 1, 0));
	ASSERT_TRUE(IntVector3::k_unit_z == IntVector3(0, 0, 1));
	ASSERT_TRUE(IntVector3::k_up == IntVector3(0, 0, 1));
	ASSERT_TRUE(IntVector3::k_down == IntVector3(0, 0, -1));
	ASSERT_TRUE(IntVector3::k_right == IntVector3(0, 1, 0));
	ASSERT_TRUE(IntVector3::k_left == IntVector3(0, -1, 0));
	ASSERT_TRUE(IntVector3::k_forward == IntVector3(1, 0, 0));
	ASSERT_TRUE(IntVector3::k_backward == IntVector3(-1, 0, 0));
}

TEST(IntVector3, operator_plus)
{
	const IntVector3 vector{ 1, 2, 3 };
	const IntVector3 other{ 10, 10, 10 };
	const auto result = vector + other;

	ASSERT_EQ(result[0], 11);
	ASSERT_EQ(result[1], 12);
	ASSERT_EQ(result[2], 13);
}

TEST(IntVector3, operator_minus)
{
	const IntVector3 vector{ 1, 2, 3 };
	const IntVector3 other{ 10, 10, 10 };
	const auto result = vector - other;

	ASSERT_EQ(result[0], -9);
	ASSERT_EQ(result[1], -8);
	ASSERT_EQ(result[2], -7);
}

TEST(IntVector3, operator_preScalar)
{
	const IntVector3 vector{ 1, 2, 3 };
	const auto result = vector * 2;

	ASSERT_EQ(result[0], 2);
	ASSERT_EQ(result[1], 4);
	ASSERT_EQ(result[2], 6);
}

TEST(IntVector3, operator_postScalar)
{
	const IntVector3 vector{ 1, 2, 3 };
	const auto result = 5 * vector;

	ASSERT_EQ(result[0], 5);
	ASSERT_EQ(result[1], 10);
	ASSERT_EQ(result[2], 15);
}