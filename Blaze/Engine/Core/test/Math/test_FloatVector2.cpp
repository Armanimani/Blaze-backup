#include <gtest/gtest.h>

#include "Blaze/Engine/Core/Math/FloatVector2.hpp"

using namespace blaze;


TEST(FloatVector2, constructor_default)
{
	const FloatVector2 vector{};

	ASSERT_FLOAT_EQ(vector.x, 0.0f);
	ASSERT_FLOAT_EQ(vector.y, 0.0f);
}

TEST(FloatVector2, constructor_uniform)
{
	const FloatVector2 vector{ 5.0f };

	ASSERT_FLOAT_EQ(vector.x, 5.0f);
	ASSERT_FLOAT_EQ(vector.y, 5.0f);
}

TEST(FloatVector2, constructor_values)
{
	const FloatVector2 vector{ 1.0f, 2.0f };

	ASSERT_FLOAT_EQ(vector.x, 1.0f);
	ASSERT_FLOAT_EQ(vector.y, 2.0f);
}

TEST(FloatVector2, constructor_IntVector2)
{
	const IntVector2 other{ 1, 2 };
	const FloatVector2 vector(other);

	ASSERT_FLOAT_EQ(vector.x, 1.0f);
	ASSERT_FLOAT_EQ(vector.y, 2.0f);
}


TEST(FloatVector2, operator_paranthesis)
{
	FloatVector2 vector{ 1.0f, 2.0f };

	ASSERT_FLOAT_EQ(vector(0), vector.x);
	ASSERT_FLOAT_EQ(vector(1), vector.y);

	vector(0) = 20.0f;
	vector(1) = 30.0f;

	ASSERT_FLOAT_EQ(vector(0), 20.0f);
	ASSERT_FLOAT_EQ(vector(1), 30.0f);
}

TEST(FloatVector2, operator_bracket)
{
	FloatVector2 vector{ 1.0f, 2.0f };

	ASSERT_FLOAT_EQ(vector[0], vector.x);
	ASSERT_FLOAT_EQ(vector[1], vector.y);

	vector[0] = 20.0f;
	vector[1] = 30.0f;

	ASSERT_FLOAT_EQ(vector[0], 20.0f);
	ASSERT_FLOAT_EQ(vector[1], 30.0f);
}


TEST(FloatVector2, operator_equality_inequality)
{
	const FloatVector2 vector{ 1.0f, 2.0f };
	FloatVector2 other{ 1.0f, 2.0f };

	ASSERT_TRUE(vector == other);
	ASSERT_FALSE(vector != other);

	other.y = 10.0f;
	ASSERT_FALSE(vector == other);
	ASSERT_TRUE(vector != other);
}

TEST(FloatVector2, operator_plusEqual)
{
	FloatVector2 vector{ 1.0f, 2.0f };
	vector += FloatVector2{ 10.0f, 10.0f };

	ASSERT_FLOAT_EQ(vector.x, 11.0f);
	ASSERT_FLOAT_EQ(vector.y, 12.0f);
}

TEST(FloatVector2, operator_minusEqual)
{
	FloatVector2 vector{ 1.0f, 2.0f };
	vector -= FloatVector2{ 10.0f, 10.0f };

	ASSERT_FLOAT_EQ(vector.x, -9.0f);
	ASSERT_FLOAT_EQ(vector.y, -8.0f);
}

TEST(FloatVector2, operator_multiplyEqual_vector)
{
	FloatVector2 vector{ 1.0f, 2.0f };
	vector *= FloatVector2{ 10.0f, 20.0f };

	ASSERT_FLOAT_EQ(vector.x, 10.0f);
	ASSERT_FLOAT_EQ(vector.y, 40.0f);
}

TEST(FloatVector2, operator_multiplyEqual_scalar)
{
	FloatVector2 vector{ 1.0f, 2.0f };
	vector *= 10.0f;

	ASSERT_FLOAT_EQ(vector.x, 10.0f);
	ASSERT_FLOAT_EQ(vector.y, 20.0f);
}

TEST(FloatVector2, operator_divideEqual_vector)
{
	FloatVector2 vector{ 1.0f, 2.0f };
	vector /= 2.0f;

	ASSERT_FLOAT_EQ(vector.x, 0.5f);
	ASSERT_FLOAT_EQ(vector.y, 1.0f);
}

TEST(FloatVector2, operator_unaryPlus)
{
	const FloatVector2 vector{ 1.0f, 2.0f };
	const auto other = +vector;

	ASSERT_FLOAT_EQ(other.x, 1.0f);
	ASSERT_FLOAT_EQ(other.y, 2.0f);
}

TEST(FloatVector2, operator_unaryMinus)
{
	const FloatVector2 vector{ 1.0f, 2.0f };
	const auto other = -vector;

	ASSERT_FLOAT_EQ(other.x, -1.0f);
	ASSERT_FLOAT_EQ(other.y, -2.0f);
}

TEST(FloatVector2, dot)
{
	const FloatVector2 vector{ 1.0f, 2.0f };
	const FloatVector2 other{ 2.0f, 3.0f };
	const auto dot_product = vector.dot(other);

	ASSERT_FLOAT_EQ(dot_product, 1.0f * 2.0f + 2.0f * 3.0f);
}

TEST(FloatVector2, cross)
{
	const FloatVector2 vector{ 1.0f, 2.0f };
	const FloatVector2 other{ 2.0f, 3.0f };
	const auto result = vector.cross(other);

	ASSERT_FLOAT_EQ(result, 1.0f * 3.0f - 2.0f * 2.0f);
}

TEST(FloatVector2, getMax)
{
	const FloatVector2 vector{ 1.0f, 2.0f };

	ASSERT_FLOAT_EQ(vector.getMax(), 2.0f);
}

TEST(FloatVector2, getMin)
{
	const FloatVector2 vector{ 1.0f, 2.0f };

	ASSERT_FLOAT_EQ(vector.getMin(), 1.0f);
}

TEST(FloatVector2, getLength)
{
	const FloatVector2 vector{ 1.0f, 2.0f };

	ASSERT_FLOAT_EQ(vector.getLength(), sqrt(1.0f * 1.0f + 2.0f * 2.0f));
}

TEST(FloatVector2, getLengthSquared)
{
	const FloatVector2 vector{ 1.0f, 2.0f };

	ASSERT_FLOAT_EQ(vector.getLengthSquared(), 1.0f * 1.0f + 2.0f * 2.0f);
}

TEST(FloatVector2, normalize_isNormalize)
{
	FloatVector2 vector{ 1.0f, 2.0f };
	ASSERT_FALSE(vector.isNormalized());
	ASSERT_TRUE(vector.getLength() != 1.0f);

	vector.normalize();
	ASSERT_FLOAT_EQ(vector.getLength(), 1.0f);
	ASSERT_TRUE(vector.isNormalized());
}

TEST(FloatVector2, static_variables)
{
	ASSERT_TRUE(FloatVector2::k_zero == FloatVector2(0.0f, 0.0f));
	ASSERT_TRUE(FloatVector2::k_unit_x == FloatVector2(1.0f, 0.0f));
	ASSERT_TRUE(FloatVector2::k_unit_y == FloatVector2(0.0f, 1.0f));
}

TEST(FloatVector2, operator_plus)
{
	const FloatVector2 vector{ 1.0f, 2.0f };
	const FloatVector2 other{ 2.0f, 3.0f };
	const auto result = vector + other;

	ASSERT_FLOAT_EQ(result.x, 3.0f);
	ASSERT_FLOAT_EQ(result.y, 5.0f);
}

TEST(FloatVector2, operator_minus)
{
	const FloatVector2 vector{ 1.0f, 2.0f };
	const FloatVector2 other{ 2.0f, 3.0f };
	const auto result = vector - other;

	ASSERT_FLOAT_EQ(result.x, -1.0f);
	ASSERT_FLOAT_EQ(result.y, -1.0f);
}

TEST(FloatVector2, operator_multiply)
{
	const FloatVector2 vector{ 1.0f, 2.0f };
	const FloatVector2 other{ 2.0f, 3.0f };
	const auto result = vector * other;

	ASSERT_FLOAT_EQ(result.x, 2.0f);
	ASSERT_FLOAT_EQ(result.y, 6.0f);
}

TEST(FloatVector2, operator_divide)
{
	const FloatVector2 vector{ 1.0f, 2.0f };
	const FloatVector2 other{ 2.0f, 1.0f };
	const auto result = vector / other;

	ASSERT_FLOAT_EQ(result.x, 0.5f);
	ASSERT_FLOAT_EQ(result.y, 2.0f);
}

TEST(FloatVector2, operator_plus_scalar)
{
	const FloatVector2 vector{ 1.0f, 2.0f };
	const auto result = vector + 2.0f;

	ASSERT_FLOAT_EQ(result.x, 3.0f);
	ASSERT_FLOAT_EQ(result.y, 4.0f);
}

TEST(FloatVector2, operator_minus_scalar)
{
	const FloatVector2 vector{ 1.0f, 2.0f};
	const auto result = vector - 2.0f;

	ASSERT_FLOAT_EQ(result.x, -1.0f);
	ASSERT_FLOAT_EQ(result.y, 0.0f);
}

TEST(FloatVector2, operator_multiply_preScalar)
{
	const FloatVector2 vector{ 1.0f, 2.0f };
	const auto result = 2.0f * vector;

	ASSERT_FLOAT_EQ(result.x, 2.0f);
	ASSERT_FLOAT_EQ(result.y, 4.0f);
}

TEST(FloatVector2, operator_multiply_postScalar)
{
	const FloatVector2 vector{ 1.0f, 2.0f };
	const auto result = vector * 2.0f;

	ASSERT_FLOAT_EQ(result.x, 2.0f);
	ASSERT_FLOAT_EQ(result.y, 4.0f);
}

TEST(FloatVector2, operator_divide_scalar)
{
	const FloatVector2 vector{ 1.0f, 2.0f };
	const auto result = vector / 2.0f;

	ASSERT_FLOAT_EQ(result.x, 0.5f);
	ASSERT_FLOAT_EQ(result.y, 1.0f);
}

TEST(FloatVector2, operator_dot)
{
	const FloatVector2 vector{ 1.0f, 2.0f };
	const FloatVector2 other{ 2.0f, 3.0f };
	const auto dot_product = dot(vector, other);

	ASSERT_FLOAT_EQ(dot_product, 1.0f * 2.0f + 2.0f * 3.0f);
}

TEST(FloatVector2, operator_cross)
{
	const FloatVector2 vector{ 1.0f, 2.0f };
	const FloatVector2 other{ 2.0f, 3.0f };
	const auto result = cross(vector, other);

	ASSERT_FLOAT_EQ(result, 1.0f * 3.0f - 2.0f * 2.0f);
}