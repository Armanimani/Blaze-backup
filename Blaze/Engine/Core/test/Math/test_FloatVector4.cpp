#include <gtest/gtest.h>

#include "Blaze/Engine/Core/Math/FloatVector4.hpp"

using namespace blaze;


TEST(FloatVector4, constructor_default)
{
	const FloatVector4 vector{};

	ASSERT_FLOAT_EQ(vector.x, 0.0f);
	ASSERT_FLOAT_EQ(vector.y, 0.0f);
	ASSERT_FLOAT_EQ(vector.z, 0.0f);
	ASSERT_FLOAT_EQ(vector.w, 0.0f);
}

TEST(FloatVector4, constructor_uniform)
{
	const FloatVector4 vector{ 5.0f };

	ASSERT_FLOAT_EQ(vector.x, 5.0f);
	ASSERT_FLOAT_EQ(vector.y, 5.0f);
	ASSERT_FLOAT_EQ(vector.z, 5.0f);
	ASSERT_FLOAT_EQ(vector.w, 5.0f);
}

TEST(FloatVector4, constructor_values)
{
	const FloatVector4 vector{ 1.0f, 2.0f, 3.0f, 4.0f };

	ASSERT_FLOAT_EQ(vector.x, 1.0f);
	ASSERT_FLOAT_EQ(vector.y, 2.0f);
	ASSERT_FLOAT_EQ(vector.z, 3.0f);
	ASSERT_FLOAT_EQ(vector.w, 4.0f);
}

TEST(FloatVector4, constructor_IntVector2)
{
	const IntVector2 other{ 1, 2 };
	const FloatVector4 vector(other);

	ASSERT_FLOAT_EQ(vector.x, 1.0f);
	ASSERT_FLOAT_EQ(vector.y, 2.0f);
	ASSERT_FLOAT_EQ(vector.z, 0.0f);
	ASSERT_FLOAT_EQ(vector.w, 0.0f);
}

TEST(FloatVector4, constructor_IntVector3)
{
	const IntVector3 other{ 1, 2, 3 };
	const FloatVector4 vector(other);

	ASSERT_FLOAT_EQ(vector.x, 1.0f);
	ASSERT_FLOAT_EQ(vector.y, 2.0f);
	ASSERT_FLOAT_EQ(vector.z, 3.0f);
	ASSERT_FLOAT_EQ(vector.w, 0.0f);
}

TEST(FloatVector4, constructor_IntVector4)
{
	const IntVector4 other{ 1, 2, 3, 4 };
	const FloatVector4 vector(other);

	ASSERT_FLOAT_EQ(vector.x, 1.0f);
	ASSERT_FLOAT_EQ(vector.y, 2.0f);
	ASSERT_FLOAT_EQ(vector.z, 3.0f);
	ASSERT_FLOAT_EQ(vector.w, 4.0f);
}

TEST(FloatVector4, constructor_FloatVector2)
{
	const FloatVector2 other{ 1.0f, 2.0f };
	const FloatVector4 vector(other);

	ASSERT_FLOAT_EQ(vector.x, 1.0f);
	ASSERT_FLOAT_EQ(vector.y, 2.0f);
	ASSERT_FLOAT_EQ(vector.z, 0.0f);
	ASSERT_FLOAT_EQ(vector.w, 0.0f);
}

TEST(FloatVector4, constructor_FloatVector3)
{
	const FloatVector3 other{ 1.0f, 2.0f, 3.0f };
	const FloatVector4 vector(other);

	ASSERT_FLOAT_EQ(vector.x, 1.0f);
	ASSERT_FLOAT_EQ(vector.y, 2.0f);
	ASSERT_FLOAT_EQ(vector.z, 3.0f);
	ASSERT_FLOAT_EQ(vector.w, 0.0f);
}

TEST(FloatVector4, operator_paranthesis)
{
	FloatVector4 vector{ 1.0f, 2.0f, 3.0f, 4.0f };

	ASSERT_FLOAT_EQ(vector(0), vector.x);
	ASSERT_FLOAT_EQ(vector(1), vector.y);
	ASSERT_FLOAT_EQ(vector(2), vector.z);
	ASSERT_FLOAT_EQ(vector(3), vector.w);

	vector(0) = 20.0f;
	vector(1) = 30.0f;
	vector(2) = 40.0f;
	vector(3) = 50.0f;

	ASSERT_FLOAT_EQ(vector(0), 20.0f);
	ASSERT_FLOAT_EQ(vector(1), 30.0f);
	ASSERT_FLOAT_EQ(vector(2), 40.0f);
	ASSERT_FLOAT_EQ(vector(3), 50.0f);
}

TEST(FloatVector4, operator_bracket)
{
	FloatVector4 vector{ 1.0f, 2.0f, 3.0f, 4.0f };

	ASSERT_FLOAT_EQ(vector[0], vector.x);
	ASSERT_FLOAT_EQ(vector[1], vector.y);
	ASSERT_FLOAT_EQ(vector[2], vector.z);
	ASSERT_FLOAT_EQ(vector[3], vector.w);

	vector[0] = 20.0f;
	vector[1] = 30.0f;
	vector[2] = 40.0f;
	vector[3] = 50.0f;

	ASSERT_FLOAT_EQ(vector[0], 20.0f);
	ASSERT_FLOAT_EQ(vector[1], 30.0f);
	ASSERT_FLOAT_EQ(vector[2], 40.0f);
	ASSERT_FLOAT_EQ(vector[3], 50.0f);
}


TEST(FloatVector4, operator_equality_inequality)
{
	const FloatVector4 vector{ 1.0f, 2.0f, 3.0f, 4.0f };
	FloatVector4 other{ 1.0f, 2.0f, 3.0f, 4.0f };

	ASSERT_TRUE(vector == other);
	ASSERT_FALSE(vector != other);

	other.z = 10.0f;
	ASSERT_FALSE(vector == other);
	ASSERT_TRUE(vector != other);
}

TEST(FloatVector4, operator_plusEqual)
{
	FloatVector4 vector{ 1.0f, 2.0f, 3.0f, 4.0f };
	vector += FloatVector4{ 10.0f, 10.0f, 10.0f, 10.0f };

	ASSERT_FLOAT_EQ(vector.x, 11.0f);
	ASSERT_FLOAT_EQ(vector.y, 12.0f);
	ASSERT_FLOAT_EQ(vector.z, 13.0f);
	ASSERT_FLOAT_EQ(vector.w, 14.0f);
}

TEST(FloatVector4, operator_minusEqual)
{
	FloatVector4 vector{ 1.0f, 2.0f, 3.0f, 4.0f };
	vector -= FloatVector4{ 10.0f, 10.0f, 10.0f, 10.0f };

	ASSERT_FLOAT_EQ(vector.x, -9.0f);
	ASSERT_FLOAT_EQ(vector.y, -8.0f);
	ASSERT_FLOAT_EQ(vector.z, -7.0f);
	ASSERT_FLOAT_EQ(vector.w, -6.0f);
}

TEST(FloatVector4, operator_multiplyEqual_vector)
{
	FloatVector4 vector{ 1.0f, 2.0f, 3.0f, 4.0f };
	vector *= FloatVector4{ 10.0f, 20.0f, 30.0f, 40.0f };

	ASSERT_FLOAT_EQ(vector.x, 10.0f);
	ASSERT_FLOAT_EQ(vector.y, 40.0f);
	ASSERT_FLOAT_EQ(vector.z, 90.0f);
	ASSERT_FLOAT_EQ(vector.w, 160.0f);
}

TEST(FloatVector4, operator_multiplyEqual_scalar)
{
	FloatVector4 vector{ 1.0f, 2.0f, 3.0f, 4.0f };
	vector *= 10.0f;

	ASSERT_FLOAT_EQ(vector.x, 10.0f);
	ASSERT_FLOAT_EQ(vector.y, 20.0f);
	ASSERT_FLOAT_EQ(vector.z, 30.0f);
	ASSERT_FLOAT_EQ(vector.w, 40.0f);
}

TEST(FloatVector4, operator_divideEqual_vector)
{
	FloatVector4 vector{ 1.0f, 2.0f, 3.0f, 4.0f };
	vector /= 2.0f;

	ASSERT_FLOAT_EQ(vector.x, 0.5f);
	ASSERT_FLOAT_EQ(vector.y, 1.0f);
	ASSERT_FLOAT_EQ(vector.z, 1.5f);
	ASSERT_FLOAT_EQ(vector.w, 2.0f);
}

TEST(FloatVector4, operator_unaryPlus)
{
	const FloatVector4 vector{ 1.0f, 2.0f, 3.0f, 4.0f };
	const auto other = +vector;

	ASSERT_FLOAT_EQ(other.x, 1.0f);
	ASSERT_FLOAT_EQ(other.y, 2.0f);
	ASSERT_FLOAT_EQ(other.z, 3.0f);
	ASSERT_FLOAT_EQ(other.w, 4.0f);
}

TEST(FloatVector4, operator_unaryMinus)
{
	const FloatVector4 vector{ 1.0f, 2.0f, 3.0f, 4.0f };
	const auto other = -vector;

	ASSERT_FLOAT_EQ(other.x, -1.0f);
	ASSERT_FLOAT_EQ(other.y, -2.0f);
	ASSERT_FLOAT_EQ(other.z, -3.0f);
	ASSERT_FLOAT_EQ(other.w, -4.0f);
}

TEST(FloatVector4, dot)
{
	const FloatVector4 vector{ 1.0f, 2.0f, 3.0f, 4.0f };
	const FloatVector4 other{ 2.0f, 3.0f, 4.0f, 5.0f };
	const auto dot_product = vector.dot(other);

	ASSERT_FLOAT_EQ(dot_product, 1.0f * 2.0f + 2.0f * 3.0f + 3.0f * 4.0f + 4.0f * 5.0f);
}


TEST(FloatVector4, getMax)
{
	const FloatVector4 vector{ 1.0f, 2.0f, 3.0f, 4.0f };

	ASSERT_FLOAT_EQ(vector.getMax(), 4.0f);
}

TEST(FloatVector4, getMin)
{
	const FloatVector4 vector{ 1.0f, 2.0f, 3.0f, 4.0f };

	ASSERT_FLOAT_EQ(vector.getMin(), 1.0f);
}

TEST(FloatVector4, getLength)
{
	const FloatVector4 vector{ 1.0f, 2.0f, 3.0f, 4.0f };

	ASSERT_FLOAT_EQ(vector.getLength(), sqrt(1.0f * 1.0f + 2.0f * 2.0f + 3.0f * 3.0f + 4.0f * 4.0f));
}

TEST(FloatVector4, getLengthSquared)
{
	const FloatVector4 vector{ 1.0f, 2.0f, 3.0f, 4.0f };

	ASSERT_FLOAT_EQ(vector.getLengthSquared(), 1.0f * 1.0f + 2.0f * 2.0f + 3.0f * 3.0f + 4.0f * 4.0f);
}

TEST(FloatVector4, normalize_isNormalize)
{
	FloatVector4 vector{ 1.0f, 2.0f, 3.0f, 4.0f };
	ASSERT_FALSE(vector.isNormalized());
	ASSERT_TRUE(vector.getLength() != 1.0f);

	vector.normalize();
	ASSERT_FLOAT_EQ(vector.getLength(), 1.0f);
	ASSERT_TRUE(vector.isNormalized());
}

TEST(FloatVector4, static_variables)
{
	ASSERT_TRUE(FloatVector4::k_zero == FloatVector4(0.0f, 0.0f, 0.0f, 0.0f));
	ASSERT_TRUE(FloatVector4::k_unit_x == FloatVector4(1.0f, 0.0f, 0.0f, 0.0f));
	ASSERT_TRUE(FloatVector4::k_unit_y == FloatVector4(0.0f, 1.0f, 0.0f, 0.0f));
	ASSERT_TRUE(FloatVector4::k_unit_z == FloatVector4(0.0f, 0.0f, 1.0f, 0.0f));
	ASSERT_TRUE(FloatVector4::k_unit_w == FloatVector4(0.0f, 0.0f, 0.0f, 1.0f));
}

TEST(FloatVector4, operator_plus)
{
	const FloatVector4 vector{ 1.0f, 2.0f, 3.0f, 4.0f };
	const FloatVector4 other{ 2.0f, 3.0f, 4.0f, 5.0f };
	const auto result = vector + other;

	ASSERT_FLOAT_EQ(result.x, 3.0f);
	ASSERT_FLOAT_EQ(result.y, 5.0f);
	ASSERT_FLOAT_EQ(result.z, 7.0f);
	ASSERT_FLOAT_EQ(result.w, 9.0f);
}

TEST(FloatVector4, operator_minus)
{
	const FloatVector4 vector{ 1.0f, 2.0f, 3.0f, 4.0f };
	const FloatVector4 other{ 2.0f, 3.0f, 4.0f, 5.0f };
	const auto result = vector - other;

	ASSERT_FLOAT_EQ(result.x, -1.0f);
	ASSERT_FLOAT_EQ(result.y, -1.0f);
	ASSERT_FLOAT_EQ(result.z, -1.0f);
	ASSERT_FLOAT_EQ(result.w, -1.0f);
}

TEST(FloatVector4, operator_multiply)
{
	const FloatVector4 vector{ 1.0f, 2.0f, 3.0f, 4.0f };
	const FloatVector4 other{ 2.0f, 3.0f, 4.0f, 5.0f };
	const auto result = vector * other;

	ASSERT_FLOAT_EQ(result.x, 2.0f);
	ASSERT_FLOAT_EQ(result.y, 6.0f);
	ASSERT_FLOAT_EQ(result.z, 12.0f);
	ASSERT_FLOAT_EQ(result.w, 20.0f);
}

TEST(FloatVector4, operator_divide)
{
	const FloatVector4 vector{ 1.0f, 2.0f, 3.0f, 4.0f };
	const FloatVector4 other{ 2.0f, 1.0f, 2.0f, 5.0f };
	const auto result = vector / other;

	ASSERT_FLOAT_EQ(result.x, 0.5f);
	ASSERT_FLOAT_EQ(result.y, 2.0f);
	ASSERT_FLOAT_EQ(result.z, 1.5f);
	ASSERT_FLOAT_EQ(result.w, 0.8f);
}

TEST(FloatVector4, operator_plus_scalar)
{
	const FloatVector4 vector{ 1.0f, 2.0f, 3.0f, 4.0f };
	const auto result = vector + 2.0f;

	ASSERT_FLOAT_EQ(result.x, 3.0f);
	ASSERT_FLOAT_EQ(result.y, 4.0f);
	ASSERT_FLOAT_EQ(result.z, 5.0f);
	ASSERT_FLOAT_EQ(result.w, 6.0f);
}

TEST(FloatVector4, operator_minus_scalar)
{
	const FloatVector4 vector{ 1.0f, 2.0f, 3.0f, 4.0f };
	const auto result = vector - 2.0f;

	ASSERT_FLOAT_EQ(result.x, -1.0f);
	ASSERT_FLOAT_EQ(result.y, 0.0f);
	ASSERT_FLOAT_EQ(result.z, 1.0f);
	ASSERT_FLOAT_EQ(result.w, 2.0f);
}

TEST(FloatVector4, operator_multiply_preScalar)
{
	const FloatVector4 vector{ 1.0f, 2.0f, 3.0f, 4.0f };
	const auto result = 2.0f * vector;

	ASSERT_FLOAT_EQ(result.x, 2.0f);
	ASSERT_FLOAT_EQ(result.y, 4.0f);
	ASSERT_FLOAT_EQ(result.z, 6.0f);
	ASSERT_FLOAT_EQ(result.w, 8.0f);
}

TEST(FloatVector4, operator_multiply_postScalar)
{
	const FloatVector4 vector{ 1.0f, 2.0f, 3.0f, 4.0f };
	const auto result = vector * 2.0f;

	ASSERT_FLOAT_EQ(result.x, 2.0f);
	ASSERT_FLOAT_EQ(result.y, 4.0f);
	ASSERT_FLOAT_EQ(result.z, 6.0f);
	ASSERT_FLOAT_EQ(result.w, 8.0f);
}

TEST(FloatVector4, operator_divide_scalar)
{
	const FloatVector4 vector{ 1.0f, 2.0f, 3.0f, 4.0f };
	const auto result = vector / 2.0f;

	ASSERT_FLOAT_EQ(result.x, 0.5f);
	ASSERT_FLOAT_EQ(result.y, 1.0f);
	ASSERT_FLOAT_EQ(result.z, 1.5f);
	ASSERT_FLOAT_EQ(result.w, 2.0f);
}

TEST(FloatVector4, operator_dot)
{
	const FloatVector4 vector{ 1.0f, 2.0f, 3.0f, 4.0f };
	const FloatVector4 other{ 2.0f, 3.0f, 4.0f, 5.0f };
	const auto dot_product = dot(vector, other);

	ASSERT_FLOAT_EQ(dot_product, 1.0f * 2.0f + 2.0f * 3.0f + 3.0f * 4.0f + 4.0f * 5.0f);
}