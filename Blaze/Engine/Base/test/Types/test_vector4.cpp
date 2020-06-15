#include <gtest/gtest.h>
#include "Blaze/Engine/Base/Vector4.hpp"

using namespace blaze::base;

TEST(vector4, constructor_default)
{
	const auto vec = Vector4{};
	ASSERT_FLOAT_EQ(vec.getX(), 0.0f);
	ASSERT_FLOAT_EQ(vec.getY(), 0.0f);
	ASSERT_FLOAT_EQ(vec.getZ(), 0.0f);
	ASSERT_FLOAT_EQ(vec.getW(), 0.0f);
}

TEST(vector4, constructor_uniform)
{
	const auto vec = Vector4{ 0.5f };
	ASSERT_FLOAT_EQ(vec.getX(), 0.5f);
	ASSERT_FLOAT_EQ(vec.getY(), 0.5f);
	ASSERT_FLOAT_EQ(vec.getZ(), 0.5f);
	ASSERT_FLOAT_EQ(vec.getW(), 0.5f);
}

TEST(vector4, constructor_values)
{
	const auto vec = Vector4{ 0.5f, 0.8f, 1.1f, 2.2f };
	ASSERT_FLOAT_EQ(vec.getX(), 0.5f);
	ASSERT_FLOAT_EQ(vec.getY(), 0.8f);
	ASSERT_FLOAT_EQ(vec.getZ(), 1.1f);
	ASSERT_FLOAT_EQ(vec.getW(), 2.2f);
}

TEST(vector4, copy_constructor)
{
	const auto vec = Vector4{ 0.1f, 0.2f, 0.4f, 0.6f };
	const auto other{ vec };
	ASSERT_EQ(other, vec);
}

TEST(vector4, copy_assignment)
{
	const auto vec = Vector4{ 0.1f, 0.2f, 0.4f, 0.6f };
	const auto other = vec;
	ASSERT_EQ(other, vec);
}

TEST(vector4, move_constructor)
{
	auto vec = Vector4{ 0.1f, 0.2f, 0.4f, 0.8f };
	const auto other{ std::move(vec) };
	ASSERT_FLOAT_EQ(other.getX(), 0.1f);
	ASSERT_FLOAT_EQ(other.getY(), 0.2f);
	ASSERT_FLOAT_EQ(other.getZ(), 0.4f);
	ASSERT_FLOAT_EQ(other.getW(), 0.8f);
}

TEST(vector4, move_assignment)
{
	auto vec = Vector4{ 0.1f, 0.2f, 0.4f, 0.8f };
	const auto other = std::move(vec);
	ASSERT_FLOAT_EQ(other.getX(), 0.1f);
	ASSERT_FLOAT_EQ(other.getY(), 0.2f);
	ASSERT_FLOAT_EQ(other.getZ(), 0.4f);
	ASSERT_FLOAT_EQ(other.getW(), 0.8f);
}

TEST(vector4, operator_equal)
{
	const auto vec = Vector4{ 0.1f, 0.2f, 0.3f, 0.4f };
	const auto other = Vector4{ 0.1f, 0.2f, 0.3f, 0.4f };
	ASSERT_TRUE(other == vec);
}

TEST(vector4, operator_notEqual)
{
	const auto vec = Vector4{ 0.1f, 0.2f, 0.8f, 1.0f };
	const auto other = Vector4{ 5.5f, 5.9f, 0.8f, 1.0f };
	ASSERT_TRUE(other != vec);
}

TEST(vector4, operator_plusEqual)
{
	auto vec = Vector4{ 1.0f, 2.0f, 3.0f, 4.0f };
	const auto other = Vector4{ 0.5f, 0.5f, 0.5f, 0.5f };
	vec += other;
	ASSERT_FLOAT_EQ(vec.getX(), 1.5f);
	ASSERT_FLOAT_EQ(vec.getY(), 2.5f);
	ASSERT_FLOAT_EQ(vec.getZ(), 3.5f);
	ASSERT_FLOAT_EQ(vec.getW(), 4.5f);
}

TEST(vector4, operator_minusEqual)
{
	auto vec = Vector4{ 1.0f, 2.0f, 3.0f, 4.0f };
	const auto other = Vector4{ 0.5f, 0.5f, 0.5f, 0.5f };
	vec -= other;
	ASSERT_FLOAT_EQ(vec.getX(), 0.5f);
	ASSERT_FLOAT_EQ(vec.getY(), 1.5f);
	ASSERT_FLOAT_EQ(vec.getZ(), 2.5f);
	ASSERT_FLOAT_EQ(vec.getW(), 3.5f);
}

TEST(vector4, operator_multiplyEqual_vector)
{
	auto vec = Vector4{ 1.0f, 2.0f, 3.0f, 4.0f };
	const auto other = Vector4{ 0.5f, 0.5f, 0.5f, 0.5f };
	vec *= other;
	ASSERT_FLOAT_EQ(vec.getX(), 1.0f * 0.5f);
	ASSERT_FLOAT_EQ(vec.getY(), 2.0f * 0.5f);
	ASSERT_FLOAT_EQ(vec.getZ(), 3.0f * 0.5f);
	ASSERT_FLOAT_EQ(vec.getW(), 4.0f * 0.5f);
}

TEST(vector4, operator_multiplyEqual_scaler)
{
	auto vec = Vector4{ 1.0f, 2.0f, 3.0f, 4.0f };
	const auto other = 0.5f;
	vec *= other;
	ASSERT_FLOAT_EQ(vec.getX(), 1.0f * 0.5f);
	ASSERT_FLOAT_EQ(vec.getY(), 2.0f * 0.5f);
	ASSERT_FLOAT_EQ(vec.getZ(), 3.0f * 0.5f);
	ASSERT_FLOAT_EQ(vec.getW(), 4.0f * 0.5f);
}

TEST(vector4, operator_divideEqual_scaler)
{
	auto vec = Vector4{ 1.0f, 2.0f, 3.0f, 4.0f };
	const auto other = 0.5f;
	vec /= other;
	ASSERT_FLOAT_EQ(vec.getX(), 1.0f / 0.5f);
	ASSERT_FLOAT_EQ(vec.getY(), 2.0f / 0.5f);
	ASSERT_FLOAT_EQ(vec.getZ(), 3.0f / 0.5f);
	ASSERT_FLOAT_EQ(vec.getW(), 4.0f / 0.5f);
}

TEST(vector4, operator_unaryPlus)
{
	const auto vec = Vector4{ 1.0f, 2.0f, 3.0f, 4.0f };
	const auto other = +vec;
	ASSERT_FLOAT_EQ(vec.getX(), other.getX());
	ASSERT_FLOAT_EQ(vec.getY(), other.getY());
	ASSERT_FLOAT_EQ(vec.getZ(), other.getZ());
	ASSERT_FLOAT_EQ(vec.getW(), other.getW());
}

TEST(vector4, operator_unaryMinus)
{
	const auto vec = Vector4{ 1.0f, 2.0f, 3.0f, 4.0f };
	const auto other = -vec;
	ASSERT_FLOAT_EQ(vec.getX(), -1.0f * other.getX());
	ASSERT_FLOAT_EQ(vec.getY(), -1.0f * other.getY());
	ASSERT_FLOAT_EQ(vec.getZ(), -1.0f * other.getZ());
	ASSERT_FLOAT_EQ(vec.getW(), -1.0f * other.getW());
}

TEST(vector4, get_x)
{
	const auto vec = Vector4{ 1.0f, 2.0f, 3.0f, 4.0f };
	ASSERT_FLOAT_EQ(vec.getX(), 1.0f);
}

TEST(vector4, get_y)
{
	const auto vec = Vector4{ 1.0f, 2.0f, 3.0f, 4.0f };
	ASSERT_FLOAT_EQ(vec.getY(), 2.0f);
}

TEST(vector4, get_z)
{
	const auto vec = Vector4{ 1.0f, 2.0f, 3.0f, 4.0f };
	ASSERT_FLOAT_EQ(vec.getZ(), 3.0f);
}

TEST(vector4, get_w)
{
	const auto vec = Vector4{ 1.0f, 2.0f, 3.0f, 4.0f };
	ASSERT_FLOAT_EQ(vec.getW(), 4.0f);
}

TEST(vector4, set_x)
{
	auto vec = Vector4{};
	vec.setX(1.0f);
	ASSERT_FLOAT_EQ(vec.getX(), 1.0f);
}

TEST(vector4, set_y)
{
	auto vec = Vector4{};
	vec.setY(1.0f);
	ASSERT_FLOAT_EQ(vec.getY(), 1.0f);
}

TEST(vector4, set_z)
{
	auto vec = Vector4{};
	vec.setZ(1.0f);
	ASSERT_FLOAT_EQ(vec.getZ(), 1.0f);
}

TEST(vector4, set_w)
{
	auto vec = Vector4{};
	vec.setW(1.0f);
	ASSERT_FLOAT_EQ(vec.getW(), 1.0f);
}

TEST(vector4, set_values)
{
	auto vec = Vector4{};
	vec.setValues(1.0f, 2.0f, 3.0f, 4.0f);
	ASSERT_FLOAT_EQ(vec.getX(), 1.0f);
	ASSERT_FLOAT_EQ(vec.getY(), 2.0f);
	ASSERT_FLOAT_EQ(vec.getZ(), 3.0f);
	ASSERT_FLOAT_EQ(vec.getW(), 4.0f);
}

TEST(vector4, length)
{
	const auto vec = Vector4{ 1.0f, 2.0f, 3.0f, 4.0f };
	const auto expected_length = std::sqrt(1.0f * 1.0f + 2.0f * 2.0f + 3.0f * 3.0f + 4.0f * 4.0f);
	ASSERT_FLOAT_EQ(vec.length(), expected_length);
}

TEST(vector4, lengthSquared)
{
	const auto vec = Vector4{ 1.0f, 2.0f, 3.0f, 4.0f };
	const auto expected_length_squared = 1.0f * 1.0f + 2.0f * 2.0f + 3.0f * 3.0f + 4.0f * 4.0f;
	ASSERT_FLOAT_EQ(vec.lengthSquared(), expected_length_squared);
}

TEST(vector4, dot)
{
	const auto vec = Vector4{ 1.0f, 2.0f, 3.0f, 4.0f };
	const auto other = Vector4{ 2.0f, 0.5f, 0.5f, 0.25f };
	const auto expected_dot = 1.0f * 2.0f + 2.0f * 0.5f + 3.0f * 0.5f + 4.0f * 0.25f;
	ASSERT_FLOAT_EQ(vec.dot(other), expected_dot);
}

TEST(vector4, normalize)
{
	auto vec = Vector4{ 1.0f, 2.0f, 3.0f, 4.0f };
	const auto length = vec.length();
	const auto expected_x = 1.0f / length;
	const auto expected_y = 2.0f / length;
	const auto expected_z = 3.0f / length;
	const auto expected_w = 4.0f / length;
	vec.normalize();
	ASSERT_FLOAT_EQ(vec.getX(), expected_x);
	ASSERT_FLOAT_EQ(vec.getY(), expected_y);
	ASSERT_FLOAT_EQ(vec.getZ(), expected_z);
	ASSERT_FLOAT_EQ(vec.getW(), expected_w);
}

TEST(vector4, isNormalize)
{
	auto vec = Vector4{ 1.0f, 2.0f, 3.0f, 4.0f };
	ASSERT_FALSE(vec.isNormalize());
	vec.normalize();
	ASSERT_TRUE(vec.isNormalize());
}

TEST(vector4, clamp)
{
	auto vec = Vector4{ -2.0f, -0.7f, 2.8f, 3.5f };
	const auto min = Vector4{ -1.5f, -1.5f, 1.0f, -2.0f };
	const auto max = Vector4{ 1.5f, -1.0f, 2.0f, -1.0f };
	vec.clamp(min, max);
	ASSERT_FLOAT_EQ(vec.getX(), -1.5f);
	ASSERT_FLOAT_EQ(vec.getY(), -1.0f);
	ASSERT_FLOAT_EQ(vec.getZ(), 2.0f);
	ASSERT_FLOAT_EQ(vec.getW(), -1.0f);
}

TEST(vector4, operator_plus)
{
	const auto vec1 = Vector4{ 1.0f, 2.0f, 3.0f, 4.0f };
	const auto vec2 = Vector4{ 3.0f, 4.0f, 5.0f, 6.0f };
	const auto result = vec1 + vec2;
	ASSERT_FLOAT_EQ(result.getX(), 4.0f);
	ASSERT_FLOAT_EQ(result.getY(), 6.0f);
	ASSERT_FLOAT_EQ(result.getZ(), 8.0f);
	ASSERT_FLOAT_EQ(result.getW(), 10.0f);
}

TEST(vector4, operator_minus)
{
	const auto vec1 = Vector4{ 1.0f, 2.0f, 3.0f, 4.0f };
	const auto vec2 = Vector4{ 3.0f, 4.0f, 5.0f, 6.0f };
	const auto result = vec1 - vec2;
	ASSERT_FLOAT_EQ(result.getX(), -2.0f);
	ASSERT_FLOAT_EQ(result.getY(), -2.0f);
	ASSERT_FLOAT_EQ(result.getZ(), -2.0f);
	ASSERT_FLOAT_EQ(result.getW(), -2.0f);
}

TEST(vector4, operator_multiply)
{
	const auto vec1 = Vector4{ 1.0f, 2.0f, 3.0f, 4.0f };
	const auto vec2 = Vector4{ 3.0f, 4.0f, 5.0f, 6.0f };
	const auto result = vec1 * vec2;
	ASSERT_FLOAT_EQ(result.getX(), 3.0f);
	ASSERT_FLOAT_EQ(result.getY(), 8.0f);
	ASSERT_FLOAT_EQ(result.getZ(), 15.0f);
	ASSERT_FLOAT_EQ(result.getW(), 24.0f);
}

TEST(vector4, operator_multiply_scalar)
{
	const auto vec = Vector4{ 1.0f, 2.0f, 3.0f, 4.0f };

	const auto result_pre_multiply = 2.0f * vec;
	ASSERT_FLOAT_EQ(result_pre_multiply.getX(), 2.0f);
	ASSERT_FLOAT_EQ(result_pre_multiply.getY(), 4.0f);
	ASSERT_FLOAT_EQ(result_pre_multiply.getZ(), 6.0f);
	ASSERT_FLOAT_EQ(result_pre_multiply.getW(), 8.0f);

	const auto result_post_multiply = vec * 2.0f;
	ASSERT_FLOAT_EQ(result_post_multiply.getX(), 2.0f);
	ASSERT_FLOAT_EQ(result_post_multiply.getY(), 4.0f);
	ASSERT_FLOAT_EQ(result_post_multiply.getZ(), 6.0f);
	ASSERT_FLOAT_EQ(result_post_multiply.getW(), 8.0f);
}

TEST(vector4, operator_divide)
{
	const auto vec1 = Vector4{ 1.0f, 2.0f, 3.0f, 4.0f };
	const auto vec2 = Vector4{ 2.0f, 4.0f, 6.0f, 8.0f };
	const auto result = vec1 / vec2;
	ASSERT_FLOAT_EQ(result.getX(), 0.5f);
	ASSERT_FLOAT_EQ(result.getY(), 0.5f);
	ASSERT_FLOAT_EQ(result.getZ(), 0.5f);
	ASSERT_FLOAT_EQ(result.getW(), 0.5f);
}

TEST(vector4, operator_divide_scalar)
{
	const auto vec = Vector4{ 1.0f, 2.0f, 3.0f, 4.0f };

	const auto result_pre_multiply = vec / 2;
	ASSERT_FLOAT_EQ(result_pre_multiply.getX(), 0.5f);
	ASSERT_FLOAT_EQ(result_pre_multiply.getY(), 1.0f);
	ASSERT_FLOAT_EQ(result_pre_multiply.getZ(), 1.5f);
	ASSERT_FLOAT_EQ(result_pre_multiply.getW(), 2.0f);
}