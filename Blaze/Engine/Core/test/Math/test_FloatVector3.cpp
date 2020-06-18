#include <gtest/gtest.h>

#include "Blaze/Engine/Core/Math/FloatVector3.hpp"

using namespace blaze;


TEST(FloatVector3, constructor_default)
{
	const FloatVector3 vector{};

	ASSERT_FLOAT_EQ(vector.x, 0.0f);
	ASSERT_FLOAT_EQ(vector.y, 0.0f);
	ASSERT_FLOAT_EQ(vector.z, 0.0f);
}

TEST(FloatVector3, constructor_uniform)
{
	const FloatVector3 vector{5.0f};

	ASSERT_FLOAT_EQ(vector.x, 5.0f);
	ASSERT_FLOAT_EQ(vector.y, 5.0f);
	ASSERT_FLOAT_EQ(vector.z, 5.0f);
}

TEST(FloatVector3, constructor_values)
{
	const FloatVector3 vector{ 1.0f, 2.0f, 3.0f };

	ASSERT_FLOAT_EQ(vector.x, 1.0f);
	ASSERT_FLOAT_EQ(vector.y, 2.0f);
	ASSERT_FLOAT_EQ(vector.z, 3.0f);
}

TEST(FloatVector3, constructor_IntVector2)
{
	const IntVector2 other{ 1, 2 };
	const FloatVector3 vector(other);

	ASSERT_FLOAT_EQ(vector.x, 1.0f);
	ASSERT_FLOAT_EQ(vector.y, 2.0f);
	ASSERT_FLOAT_EQ(vector.z, 0.0f);
}

TEST(FloatVector3, constructor_IntVector3)
{
	const IntVector3 other{ 1, 2, 3 };
	const FloatVector3 vector(other);

	ASSERT_FLOAT_EQ(vector.x, 1.0f);
	ASSERT_FLOAT_EQ(vector.y, 2.0f);
	ASSERT_FLOAT_EQ(vector.z, 3.0f);
}

TEST(FloatVector3, operator_paranthesis)
{
	FloatVector3 vector{ 1.0f, 2.0f, 3.0f };

	ASSERT_FLOAT_EQ(vector(0), vector.x);
	ASSERT_FLOAT_EQ(vector(1), vector.y);
	ASSERT_FLOAT_EQ(vector(2), vector.z);

	vector(0) = 20.0f;
	vector(1) = 30.0f;
	vector(2) = 40.0f;

	ASSERT_FLOAT_EQ(vector(0), 20.0f);
	ASSERT_FLOAT_EQ(vector(1), 30.0f);
	ASSERT_FLOAT_EQ(vector(2), 40.0f);
}

TEST(FloatVector3, operator_bracket)
{
	FloatVector3 vector{ 1.0f, 2.0f, 3.0f };

	ASSERT_FLOAT_EQ(vector[0], vector.x);
	ASSERT_FLOAT_EQ(vector[1], vector.y);
	ASSERT_FLOAT_EQ(vector[2], vector.z);

	vector[0] = 20.0f;
	vector[1] = 30.0f;
	vector[2] = 40.0f;

	ASSERT_FLOAT_EQ(vector[0], 20.0f);
	ASSERT_FLOAT_EQ(vector[1], 30.0f);
	ASSERT_FLOAT_EQ(vector[2], 40.0f);
}


TEST(FloatVector3, operator_equality_inequality)
{
	const FloatVector3 vector{ 1.0f, 2.0f, 3.0f };
	FloatVector3 other{ 1.0f, 2.0f, 3.0f };

	ASSERT_TRUE(vector == other);
	ASSERT_FALSE(vector != other);

	other.z = 10.0f;
	ASSERT_FALSE(vector == other);
	ASSERT_TRUE(vector != other);
}

TEST(FloatVector3, operator_plusEqual)
{
	FloatVector3 vector{ 1.0f, 2.0f, 3.0f };
	vector += FloatVector3{ 10.0f, 10.0f, 10.0f };

	ASSERT_FLOAT_EQ(vector.x, 11.0f);
	ASSERT_FLOAT_EQ(vector.y, 12.0f);
	ASSERT_FLOAT_EQ(vector.z, 13.0f);
}

TEST(FloatVector3, operator_minusEqual)
{
	FloatVector3 vector{ 1.0f, 2.0f, 3.0f };
	vector -= FloatVector3{ 10.0f, 10.0f, 10.0f };

	ASSERT_FLOAT_EQ(vector.x, -9.0f);
	ASSERT_FLOAT_EQ(vector.y, -8.0f);
	ASSERT_FLOAT_EQ(vector.z, -7.0f);
}

TEST(FloatVector3, operator_multiplyEqual_vector)
{
	FloatVector3 vector{ 1.0f, 2.0f, 3.0f };
	vector *= FloatVector3{ 10.0f, 20.0f, 30.0f };

	ASSERT_FLOAT_EQ(vector.x, 10.0f);
	ASSERT_FLOAT_EQ(vector.y, 40.0f);
	ASSERT_FLOAT_EQ(vector.z, 90.0f);
}

TEST(FloatVector3, operator_multiplyEqual_scalar)
{
	FloatVector3 vector{ 1.0f, 2.0f, 3.0f };
	vector *= 10.0f;

	ASSERT_FLOAT_EQ(vector.x, 10.0f);
	ASSERT_FLOAT_EQ(vector.y, 20.0f);
	ASSERT_FLOAT_EQ(vector.z, 30.0f);
}

TEST(FloatVector3, operator_divideEqual_vector)
{
	FloatVector3 vector{ 1.0f, 2.0f, 3.0f };
	vector /= 2.0f;

	ASSERT_FLOAT_EQ(vector.x, 0.5f);
	ASSERT_FLOAT_EQ(vector.y, 1.0f);
	ASSERT_FLOAT_EQ(vector.z, 1.5f);
}

TEST(FloatVector3, operator_unaryPlus)
{
	const FloatVector3 vector{ 1.0f, 2.0f, 3.0f };
	const auto other = +vector;

	ASSERT_FLOAT_EQ(other.x, 1.0f);
	ASSERT_FLOAT_EQ(other.y, 2.0f);
	ASSERT_FLOAT_EQ(other.z, 3.0f);
}

TEST(FloatVector3, operator_unaryMinus)
{
	const FloatVector3 vector{ 1.0f, 2.0f, 3.0f };
	const auto other = -vector;

	ASSERT_FLOAT_EQ(other.x, -1.0f);
	ASSERT_FLOAT_EQ(other.y, -2.0f);
	ASSERT_FLOAT_EQ(other.z, -3.0f);
}

TEST(FloatVector3, dot)
{
	const FloatVector3 vector{ 1.0f, 2.0f, 3.0f };
	const FloatVector3 other{ 2.0f, 3.0f, 4.0f };
	const auto dot_product = vector.dot(other);
	
	ASSERT_FLOAT_EQ(dot_product, 1.0f * 2.0f + 2.0f * 3.0f + 3.0f * 4.0f);
}

TEST(FloatVector3, cross)
{
	const FloatVector3 vector{ 1.0f, 2.0f, 3.0f };
	const FloatVector3 other{ 2.0f, 3.0f, 4.0f };
	const auto result = vector.cross(other);

	ASSERT_FLOAT_EQ(result.x, 2.0f * 4.0f - 3.0f * 3.0f);
	ASSERT_FLOAT_EQ(result.y, 3.0f * 2.0f - 1.0f * 4.0f);
	ASSERT_FLOAT_EQ(result.z, 1.0f * 3.0f - 2.0f * 2.0f);
}

TEST(FloatVector3, getMax)
{
	const FloatVector3 vector{ 1.0f, 2.0f, 3.0f };

	ASSERT_FLOAT_EQ(vector.getMax(), 3.0f);
}

TEST(FloatVector3, getMin)
{
	const FloatVector3 vector{ 1.0f, 2.0f, 3.0f };

	ASSERT_FLOAT_EQ(vector.getMin(), 1.0f);
}

TEST(FloatVector3, getLength)
{
	const FloatVector3 vector{ 1.0f, 2.0f, 3.0f };

	ASSERT_FLOAT_EQ(vector.getLength(), sqrt(1.0f * 1.0f + 2.0f * 2.0f + 3.0f * 3.0f));
}

TEST(FloatVector3, getLengthSquared)
{
	const FloatVector3 vector{ 1.0f, 2.0f, 3.0f };

	ASSERT_FLOAT_EQ(vector.getLengthSquared(), 1.0f * 1.0f + 2.0f * 2.0f + 3.0f * 3.0f);
}

TEST(FloatVector3, normalize_isNormalize)
{
	FloatVector3 vector{ 1.0f, 2.0f, 3.0f };
	ASSERT_FALSE(vector.isNormalized());
	ASSERT_TRUE(vector.getLength() != 1.0f);

	vector.normalize();
	ASSERT_FLOAT_EQ(vector.getLength(), 1.0f);
	ASSERT_TRUE(vector.isNormalized());
}

TEST(FloatVector3, static_variables)
{
	ASSERT_TRUE(FloatVector3::k_zero == FloatVector3( 0.0f, 0.0f, 0.0f ));
	ASSERT_TRUE(FloatVector3::k_unit_x == FloatVector3(1.0f, 0.0f, 0.0f));
	ASSERT_TRUE(FloatVector3::k_unit_y == FloatVector3(0.0f, 1.0f, 0.0f));
	ASSERT_TRUE(FloatVector3::k_unit_z == FloatVector3(0.0f, 0.0f, 1.0f));
	ASSERT_TRUE(FloatVector3::k_up == FloatVector3(0.0f, 0.0f, 1.0f));
	ASSERT_TRUE(FloatVector3::k_down == FloatVector3(0.0f, 0.0f, -1.0f));
	ASSERT_TRUE(FloatVector3::k_right == FloatVector3(0.0f, 1.0f, 0.0f));
	ASSERT_TRUE(FloatVector3::k_left == FloatVector3(0.0f, -1.0f, 0.0f));
	ASSERT_TRUE(FloatVector3::k_forward == FloatVector3(1.0f, 0.0f, 0.0f));
	ASSERT_TRUE(FloatVector3::k_backward == FloatVector3(-1.0f, 0.0f, 0.0f));
}

TEST(FloatVector3, operator_plus)
{
	const FloatVector3 vector{ 1.0f, 2.0f, 3.0f };
	const FloatVector3 other{ 2.0f, 3.0f, 4.0f };
	const auto result = vector + other;

	ASSERT_FLOAT_EQ(result.x, 3.0f);
	ASSERT_FLOAT_EQ(result.y, 5.0f);
	ASSERT_FLOAT_EQ(result.z, 7.0f);
}

TEST(FloatVector3, operator_minus)
{
	const FloatVector3 vector{ 1.0f, 2.0f, 3.0f };
	const FloatVector3 other{ 2.0f, 3.0f, 4.0f };
	const auto result = vector - other;

	ASSERT_FLOAT_EQ(result.x, -1.0f);
	ASSERT_FLOAT_EQ(result.y, -1.0f);
	ASSERT_FLOAT_EQ(result.z, -1.0f);
}

TEST(FloatVector3, operator_multiply)
{
	const FloatVector3 vector{ 1.0f, 2.0f, 3.0f };
	const FloatVector3 other{ 2.0f, 3.0f, 4.0f };
	const auto result = vector * other;

	ASSERT_FLOAT_EQ(result.x, 2.0f);
	ASSERT_FLOAT_EQ(result.y, 6.0f);
	ASSERT_FLOAT_EQ(result.z, 12.0f);
}

TEST(FloatVector3, operator_divide)
{
	const FloatVector3 vector{ 1.0f, 2.0f, 3.0f };
	const FloatVector3 other{ 2.0f, 1.0f, 2.0f };
	const auto result = vector / other;

	ASSERT_FLOAT_EQ(result.x, 0.5f);
	ASSERT_FLOAT_EQ(result.y, 2.0f);
	ASSERT_FLOAT_EQ(result.z, 1.5f);
}

TEST(FloatVector3, operator_plus_scalar)
{
	const FloatVector3 vector{ 1.0f, 2.0f, 3.0f };
	const auto result = vector + 2.0f;

	ASSERT_FLOAT_EQ(result.x, 3.0f);
	ASSERT_FLOAT_EQ(result.y, 4.0f);
	ASSERT_FLOAT_EQ(result.z, 5.0f);
}

TEST(FloatVector3, operator_minus_scalar)
{
	const FloatVector3 vector{ 1.0f, 2.0f, 3.0f };
	const auto result = vector - 2.0f;

	ASSERT_FLOAT_EQ(result.x, -1.0f);
	ASSERT_FLOAT_EQ(result.y, 0.0f);
	ASSERT_FLOAT_EQ(result.z, 1.0f);
}

TEST(FloatVector3, operator_multiply_preScalar)
{
	const FloatVector3 vector{ 1.0f, 2.0f, 3.0f };
	const auto result = 2.0f * vector;

	ASSERT_FLOAT_EQ(result.x, 2.0f);
	ASSERT_FLOAT_EQ(result.y, 4.0f);
	ASSERT_FLOAT_EQ(result.z, 6.0f);
}

TEST(FloatVector3, operator_multiply_postScalar)
{
	const FloatVector3 vector{ 1.0f, 2.0f, 3.0f };
	const auto result = vector * 2.0f;

	ASSERT_FLOAT_EQ(result.x, 2.0f);
	ASSERT_FLOAT_EQ(result.y, 4.0f);
	ASSERT_FLOAT_EQ(result.z, 6.0f);
}

TEST(FloatVector3, operator_divide_scalar)
{
	const FloatVector3 vector{ 1.0f, 2.0f, 3.0f };
	const auto result = vector / 2.0f;

	ASSERT_FLOAT_EQ(result.x, 0.5f);
	ASSERT_FLOAT_EQ(result.y, 1.0f);
	ASSERT_FLOAT_EQ(result.z, 1.5f);
}

TEST(FloatVector3, operator_dot)
{
	const FloatVector3 vector{ 1.0f, 2.0f, 3.0f };
	const FloatVector3 other{ 2.0f, 3.0f, 4.0f };
	const auto dot_product = dot(vector, other);

	ASSERT_FLOAT_EQ(dot_product, 1.0f * 2.0f + 2.0f * 3.0f + 3.0f * 4.0f);
}

TEST(FloatVector3, operator_cross)
{
	const FloatVector3 vector{ 1.0f, 2.0f, 3.0f };
	const FloatVector3 other{ 2.0f, 3.0f, 4.0f };
	const auto result = cross(vector, other);

	ASSERT_FLOAT_EQ(result.x, 2.0f * 4.0f - 3.0f * 3.0f);
	ASSERT_FLOAT_EQ(result.y, 3.0f * 2.0f - 1.0f * 4.0f);
	ASSERT_FLOAT_EQ(result.z, 1.0f * 3.0f - 2.0f * 2.0f);
}