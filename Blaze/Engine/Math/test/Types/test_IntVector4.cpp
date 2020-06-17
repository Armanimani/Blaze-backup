#include <gtest/gtest.h>

#include "Blaze/Engine/Math/Types/IntVector4.hpp"

using namespace blaze;

TEST(IntVector4, constructor_default)
{
	const IntVector4 vector{};

	ASSERT_EQ(vector.x, 0);
	ASSERT_EQ(vector.y, 0);
	ASSERT_EQ(vector.z, 0);
	ASSERT_EQ(vector.w, 0);
}

TEST(IntVector4, constructor_uniform)
{
	const IntVector4 vector{ 10 };

	ASSERT_EQ(vector.x, 10);
	ASSERT_EQ(vector.y, 10);
	ASSERT_EQ(vector.z, 10);
	ASSERT_EQ(vector.w, 10);
}

TEST(IntVector4, constructor_values)
{
	const IntVector4 vector{ 1, 2, 3, 4 };

	ASSERT_EQ(vector.x, 1);
	ASSERT_EQ(vector.y, 2);
	ASSERT_EQ(vector.z, 3);
	ASSERT_EQ(vector.w, 4);
}

TEST(IntVector4, constructor_Int2Vector)
{
	const IntVector2 other{ 1, 2 };
	const IntVector4 vector(other);

	ASSERT_EQ(vector.x, 1);
	ASSERT_EQ(vector.y, 2);
	ASSERT_EQ(vector.z, 0);
	ASSERT_EQ(vector.w, 0);
}

TEST(IntVector4, constructor_Int3Vector)
{
	const IntVector3 other{ 1, 2, 3 };
	const IntVector4 vector(other);

	ASSERT_EQ(vector.x, 1);
	ASSERT_EQ(vector.y, 2);
	ASSERT_EQ(vector.z, 3);
	ASSERT_EQ(vector.w, 0);
}

TEST(IntVector4, operator_paranthesis)
{
	IntVector4 vector{ 1, 2, 3, 4 };

	ASSERT_EQ(vector(0), vector.x);
	ASSERT_EQ(vector(1), vector.y);
	ASSERT_EQ(vector(2), vector.z);
	ASSERT_EQ(vector(3), vector.w);

	vector(0) = 20;
	vector(1) = 30;
	vector(2) = 40;
	vector(3) = 50;

	ASSERT_EQ(vector(0), 20);
	ASSERT_EQ(vector(1), 30);
	ASSERT_EQ(vector(2), 40);
	ASSERT_EQ(vector(3), 50);
}

TEST(IntVector4, operator_bracket)
{
	IntVector4 vector{ 1, 2, 3, 4 };

	ASSERT_EQ(vector[0], vector.x);
	ASSERT_EQ(vector[1], vector.y);
	ASSERT_EQ(vector[2], vector.z);
	ASSERT_EQ(vector[3], vector.w);

	vector[0] = 20;
	vector[1] = 30;
	vector[2] = 40;
	vector[3] = 50;

	ASSERT_EQ(vector[0], 20);
	ASSERT_EQ(vector[1], 30);
	ASSERT_EQ(vector[2], 40);
	ASSERT_EQ(vector[3], 50);
}

TEST(IntVector4, operator_equality_inequality)
{
	const IntVector4 vector1{ 1, 2, 3, 4 };
	IntVector4 vector2{ 1, 2, 3, 4 };

	ASSERT_TRUE(vector1 == vector2);
	ASSERT_FALSE(vector1 != vector2);

	vector2.w = 10;
	ASSERT_FALSE(vector1 == vector2);
	ASSERT_TRUE(vector1 != vector2);
}

TEST(IntVector4, operator_plusEqual)
{
	IntVector4 vector{ 1, 2, 3, 4 };
	vector += IntVector4{ 10, 10, 10, 10 };

	ASSERT_EQ(vector[0], 11);
	ASSERT_EQ(vector[1], 12);
	ASSERT_EQ(vector[2], 13);
	ASSERT_EQ(vector[3], 14);
}

TEST(IntVector4, operator_minusEqual)
{
	IntVector4 vector{ 1, 2, 3, 4 };
	vector -= IntVector4{ 10, 10, 10, 10 };

	ASSERT_EQ(vector[0], -9);
	ASSERT_EQ(vector[1], -8);
	ASSERT_EQ(vector[2], -7);
	ASSERT_EQ(vector[3], -6);
}

TEST(IntVector4, operator_scalerEqual)
{
	IntVector4 vector{ 1, 2, 3, 4 };
	vector *= 10;

	ASSERT_EQ(vector[0], 10);
	ASSERT_EQ(vector[1], 20);
	ASSERT_EQ(vector[2], 30);
	ASSERT_EQ(vector[3], 40);
}

TEST(IntVector4, getMax)
{
	const IntVector4 vector{ 1, 2, 3, 4 };
	ASSERT_EQ(vector.getMax(), 4);
}

TEST(IntVector4, getMin)
{
	const IntVector4 vector{ 1, 2, 3, 4 };
	ASSERT_EQ(vector.getMin(), 1);
}

TEST(IntVector4, getLength)
{
	const IntVector4 vector{ 1, 2, 3, 4 };
	ASSERT_FLOAT_EQ(vector.getLength(), sqrtf(1 * 1 + 2 * 2 + 3 * 3 + 4 * 4));
}

TEST(IntVector4, getLengthSquared)
{
	const IntVector4 vector{ 1, 2, 3, 4 };
	ASSERT_EQ(vector.getLengthSquared(), 1 * 1 + 2 * 2 + 3 * 3 + 4 * 4);
}

TEST(IntVector4, static_variables)
{
	ASSERT_TRUE(IntVector4::k_zero == IntVector4(0, 0, 0, 0));
	ASSERT_TRUE(IntVector4::k_unit_x == IntVector4(1, 0, 0, 0));
	ASSERT_TRUE(IntVector4::k_unit_y == IntVector4(0, 1, 0, 0));
	ASSERT_TRUE(IntVector4::k_unit_z == IntVector4(0, 0, 1, 0));
	ASSERT_TRUE(IntVector4::k_unit_w == IntVector4(0, 0, 0, 1));
}

TEST(IntVector4, operator_plus)
{
	const IntVector4 vector{ 1, 2, 3, 4 };
	const IntVector4 other{ 10, 10, 10, 10 };
	const auto result = vector + other;

	ASSERT_EQ(result[0], 11);
	ASSERT_EQ(result[1], 12);
	ASSERT_EQ(result[2], 13);
	ASSERT_EQ(result[3], 14);
}

TEST(IntVector4, operator_minus)
{
	const IntVector4 vector{ 1, 2, 3, 4 };
	const IntVector4 other{ 10, 10, 10, 10 };
	const auto result = vector - other;

	ASSERT_EQ(result[0], -9);
	ASSERT_EQ(result[1], -8);
	ASSERT_EQ(result[2], -7);
	ASSERT_EQ(result[3], -6);
}

TEST(IntVector4, operator_preScalar)
{
	const IntVector4 vector{ 1, 2, 3, 4 };
	const auto result = vector * 2;

	ASSERT_EQ(result[0], 2);
	ASSERT_EQ(result[1], 4);
	ASSERT_EQ(result[2], 6);
	ASSERT_EQ(result[3], 8);
}

TEST(IntVector4, operator_postScalar)
{
	const IntVector4 vector{ 1, 2, 3, 4 };
	const auto result = 5 * vector;

	ASSERT_EQ(result[0], 5);
	ASSERT_EQ(result[1], 10);
	ASSERT_EQ(result[2], 15);
	ASSERT_EQ(result[3], 20);
}