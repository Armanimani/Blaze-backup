#include <gtest/gtest.h>
#include "Blaze/Engine/Base/Vector3.hpp"

using namespace blaze::base;

TEST(vector3, constructor_default)
{
	const auto vec = Vector3{};
	ASSERT_FLOAT_EQ(vec.getX(), 0.0f);
	ASSERT_FLOAT_EQ(vec.getY(), 0.0f);
	ASSERT_FLOAT_EQ(vec.getZ(), 0.0f);
}

TEST(vector3, constructor_uniform)
{
	const auto vec = Vector3{ 0.5f };
	ASSERT_FLOAT_EQ(vec.getX(), 0.5f);
	ASSERT_FLOAT_EQ(vec.getY(), 0.5f);
	ASSERT_FLOAT_EQ(vec.getZ(), 0.5f);
}

TEST(vector3, constructor_2values)
{
	const auto vec = Vector3{ 0.5f, 0.8f, 1.1f };
	ASSERT_FLOAT_EQ(vec.getX(), 0.5f);
	ASSERT_FLOAT_EQ(vec.getY(), 0.8f);
	ASSERT_FLOAT_EQ(vec.getZ(), 1.1f);
}

TEST(vector3, copy_constructor)
{
	const auto vec = Vector3{ 0.1f, 0.2f, 0.4f };
	const auto other{ vec };
	ASSERT_EQ(other, vec);
}

TEST(vector3, copy_assignment)
{
	const auto vec = Vector3{ 0.1f, 0.2f, 0.4f };
	const auto other = vec;
	ASSERT_EQ(other, vec);
}

TEST(vector3, move_constructor)
{
	auto vec = Vector3{ 0.1f, 0.2f, 0.4f };
	const auto other{ std::move(vec) };
	ASSERT_FLOAT_EQ(other.getX(), 0.1f);
	ASSERT_FLOAT_EQ(other.getY(), 0.2f);
	ASSERT_FLOAT_EQ(other.getZ(), 0.4f);
}

TEST(vector3, move_assignment)
{
	auto vec = Vector3{ 0.1f, 0.2f, 0.4f };
	const auto other = std::move(vec);
	ASSERT_FLOAT_EQ(other.getX(), 0.1f);
	ASSERT_FLOAT_EQ(other.getY(), 0.2f);
	ASSERT_FLOAT_EQ(other.getZ(), 0.4f);
}

TEST(vector3, operator_equal)
{
	const auto vec = Vector3{ 0.1f, 0.2f, 0.4f };
	const auto other = Vector3{ 0.1f, 0.2f, 0.4f };
	ASSERT_TRUE(other == vec);
}

TEST(vector3, operator_notEqual)
{
	const auto vec = Vector3{ 0.1f, 0.2f, 0.8f };
	const auto other = Vector3{ 5.5f, 5.9f, 0.8f };
	ASSERT_TRUE(other != vec);
}

TEST(vector3, operator_plusEqual)
{
	auto vec = Vector3{ 1.0f, 2.0f, 3.0f };
	const auto other = Vector3{ 0.5f, 0.5f, 0.5f };
	vec += other;
	ASSERT_FLOAT_EQ(vec.getX(), 1.5f);
	ASSERT_FLOAT_EQ(vec.getY(), 2.5f);
	ASSERT_FLOAT_EQ(vec.getZ(), 3.5f);
}

TEST(vector3, operator_minusEqual)
{
	auto vec = Vector3{ 1.0f, 2.0f, 3.0f };
	const auto other = Vector3{ 0.5f, 0.5f, 0.5f };
	vec -= other;
	ASSERT_FLOAT_EQ(vec.getX(), 0.5f);
	ASSERT_FLOAT_EQ(vec.getY(), 1.5f);
	ASSERT_FLOAT_EQ(vec.getZ(), 2.5f);
}

TEST(vector3, operator_multiplyEqual_vector)
{
	auto vec = Vector3{ 1.0f, 2.0f, 3.0f };
	const auto other = Vector3{ 0.5f, 0.5f, 0.5f };
	vec *= other;
	ASSERT_FLOAT_EQ(vec.getX(), 1.0f * 0.5f);
	ASSERT_FLOAT_EQ(vec.getY(), 2.0f * 0.5f);
	ASSERT_FLOAT_EQ(vec.getZ(), 3.0f * 0.5f);
}

TEST(vector3, operator_multiplyEqual_scaler)
{
	auto vec = Vector3{ 1.0f, 2.0f, 3.0f };
	const auto other = 0.5f;
	vec *= other;
	ASSERT_FLOAT_EQ(vec.getX(), 1.0f * 0.5f);
	ASSERT_FLOAT_EQ(vec.getY(), 2.0f * 0.5f);
	ASSERT_FLOAT_EQ(vec.getZ(), 3.0f * 0.5f);
}

TEST(vector3, operator_divideEqual_scaler)
{
	auto vec = Vector3{ 1.0f, 2.0f, 3.0f };
	const auto other = 0.5f;
	vec /= other;
	ASSERT_FLOAT_EQ(vec.getX(), 1.0f / 0.5f);
	ASSERT_FLOAT_EQ(vec.getY(), 2.0f / 0.5f);
	ASSERT_FLOAT_EQ(vec.getZ(), 3.0f / 0.5f);
}

TEST(vector3, operator_unaryPlus)
{
	const auto vec = Vector3{ 1.0f, 2.0f, 3.0f };
	const auto other = +vec;
	ASSERT_FLOAT_EQ(vec.getX(), other.getX());
	ASSERT_FLOAT_EQ(vec.getY(), other.getY());
	ASSERT_FLOAT_EQ(vec.getZ(), other.getZ());
}

TEST(vector3, operator_unaryMinus)
{
	const auto vec = Vector3{ 1.0f, 2.0f, 3.0f };
	const auto other = -vec;
	ASSERT_FLOAT_EQ(vec.getX(), -1.0f * other.getX());
	ASSERT_FLOAT_EQ(vec.getY(), -1.0f * other.getY());
	ASSERT_FLOAT_EQ(vec.getZ(), -1.0f * other.getZ());
}

TEST(vector3, get_x)
{
	const auto vec = Vector3{ 1.0f, 2.0f, 3.0f };
	ASSERT_FLOAT_EQ(vec.getX(), 1.0f);
}

TEST(vector3, get_y)
{
	const auto vec = Vector3{ 1.0f, 2.0f, 3.0f };
	ASSERT_FLOAT_EQ(vec.getY(), 2.0f);
}

TEST(vector3, get_z)
{
	const auto vec = Vector3{ 1.0f, 2.0f, 3.0f };
	ASSERT_FLOAT_EQ(vec.getZ(), 3.0f);
}

TEST(vector3, set_x)
{
	auto vec = Vector3{};
	vec.setX(1.0f);
	ASSERT_FLOAT_EQ(vec.getX(), 1.0f);
}

TEST(vector3, set_y)
{
	auto vec = Vector3{};
	vec.setY(1.0f);
	ASSERT_FLOAT_EQ(vec.getY(), 1.0f);
}

TEST(vector3, set_z)
{
	auto vec = Vector3{};
	vec.setZ(1.0f);
	ASSERT_FLOAT_EQ(vec.getZ(), 1.0f);
}


TEST(vector3, set_values)
{
	auto vec = Vector3{};
	vec.setValues(1.0f, 2.0f, 3.0f);
	ASSERT_FLOAT_EQ(vec.getX(), 1.0f);
	ASSERT_FLOAT_EQ(vec.getY(), 2.0f);
	ASSERT_FLOAT_EQ(vec.getZ(), 3.0f);
}

TEST(vector3, length)
{
	const auto vec = Vector3{ 1.0f, 2.0f, 3.0f };
	const auto expected_length = std::sqrt(1.0f * 1.0f + 2.0f * 2.0f + 3.0f * 3.0f);
	ASSERT_FLOAT_EQ(vec.length(), expected_length);
}

TEST(vector3, lengthSquared)
{
	const auto vec = Vector3{ 1.0f, 2.0f, 3.0f };
	const auto expected_length_squared = 1.0f * 1.0f + 2.0f * 2.0f + 3.0f * 3.0f;
	ASSERT_FLOAT_EQ(vec.lengthSquared(), expected_length_squared);
}

TEST(vector3, dot)
{
	const auto vec = Vector3{ 1.0f, 2.0f, 3.0f };
	const auto other = Vector3{ 2.0f, 0.5f, 0.5f };
	const auto expected_dot = 1.0f * 2.0f + 2.0f * 0.5f + 3.0f * 0.5f;
	ASSERT_FLOAT_EQ(vec.dot(other), expected_dot);
}

TEST(vector3, cross)
{
	const auto vec = Vector3{ 1.0f, 2.0f, 3.0f };
	const auto other = Vector3{ 2.0f, 0.5f, 0.2f };
	const auto expected_cross = Vector3{
		vec.getY() * other.getZ() - vec.getZ() * other.getY(),
		vec.getZ() * other.getX() - vec.getX() * other.getZ(),
		vec.getX() * other.getY() - vec.getY() * other.getX(),
	};
	ASSERT_TRUE(vec.cross(other) == expected_cross);
}

TEST(vector3, normalize)
{
	auto vec = Vector3{ 1.0f, 2.0f, 3.0f };
	const auto length = vec.length();
	const auto expected_x = 1.0f / length;
	const auto expected_y = 2.0f / length;
	const auto expected_z = 3.0f / length;
	vec.normalize();
	ASSERT_FLOAT_EQ(vec.getX(), expected_x);
	ASSERT_FLOAT_EQ(vec.getY(), expected_y);
	ASSERT_FLOAT_EQ(vec.getZ(), expected_z);
}

TEST(vector3, isNormalize)
{
	auto vec = Vector3{ 1.0f, 2.0f, 3.0f };
	ASSERT_FALSE(vec.isNormalize());
	vec.normalize();
	ASSERT_TRUE(vec.isNormalize());
}

TEST(vector3, clamp)
{
	auto vec = Vector3{ -2.0f, -0.7f, 2.8f };
	const auto min = Vector3{ -1.5f, -1.5f, 1.0f };
	const auto max = Vector3{ 1.5f, -1.0f, 2.0f };
	vec.clamp(min, max);
	ASSERT_FLOAT_EQ(vec.getX(), -1.5f);
	ASSERT_FLOAT_EQ(vec.getY(), -1.0f);
	ASSERT_FLOAT_EQ(vec.getZ(), 2.0f);
}

TEST(vector3, operator_plus)
{
	const auto vec1 = Vector3{ 1.0f, 2.0f, 3.0f };
	const auto vec2 = Vector3{ 3.0f, 4.0f, 5.0f };
	const auto result = vec1 + vec2;
	ASSERT_FLOAT_EQ(result.getX(), 4.0f);
	ASSERT_FLOAT_EQ(result.getY(), 6.0f);
	ASSERT_FLOAT_EQ(result.getZ(), 8.0f);
}

TEST(vector3, operator_minus)
{
	const auto vec1 = Vector3{ 1.0f, 2.0f, 3.0f };
	const auto vec2 = Vector3{ 3.0f, 4.0f, 5.0f };
	const auto result = vec1 - vec2;
	ASSERT_FLOAT_EQ(result.getX(), -2.0f);
	ASSERT_FLOAT_EQ(result.getY(), -2.0f);
	ASSERT_FLOAT_EQ(result.getZ(), -2.0f);
}

TEST(vector3, operator_multiply)
{
	const auto vec1 = Vector3{ 1.0f, 2.0f, 3.0f };
	const auto vec2 = Vector3{ 3.0f, 4.0f, 5.0f };
	const auto result = vec1 * vec2;
	ASSERT_FLOAT_EQ(result.getX(), 3.0f);
	ASSERT_FLOAT_EQ(result.getY(), 8.0f);
	ASSERT_FLOAT_EQ(result.getZ(), 15.0f);
}

TEST(vector3, operator_multiply_scalar)
{
	const auto vec = Vector3{ 1.0f, 2.0f, 3.0f };

	const auto result_pre_multiply = 2.0f * vec;
	ASSERT_FLOAT_EQ(result_pre_multiply.getX(), 2.0f);
	ASSERT_FLOAT_EQ(result_pre_multiply.getY(), 4.0f);
	ASSERT_FLOAT_EQ(result_pre_multiply.getZ(), 6.0f);

	const auto result_post_multiply = vec * 2.0f;
	ASSERT_FLOAT_EQ(result_post_multiply.getX(), 2.0f);
	ASSERT_FLOAT_EQ(result_post_multiply.getY(), 4.0f);
	ASSERT_FLOAT_EQ(result_post_multiply.getZ(), 6.0f);
}

TEST(vector3, operator_divide)
{
	const auto vec1 = Vector3{ 1.0f, 2.0f, 3.0f };
	const auto vec2 = Vector3{ 2.0f, 4.0f, 6.0f };
	const auto result = vec1 / vec2;
	ASSERT_FLOAT_EQ(result.getX(), 0.5f);
	ASSERT_FLOAT_EQ(result.getY(), 0.5f);
	ASSERT_FLOAT_EQ(result.getZ(), 0.5f);
}

TEST(vector3, operator_divide_scalar)
{
	const auto vec = Vector3{ 1.0f, 2.0f, 3.0f };

	const auto result_pre_multiply = vec / 2;
	ASSERT_FLOAT_EQ(result_pre_multiply.getX(), 0.5f);
	ASSERT_FLOAT_EQ(result_pre_multiply.getY(), 1.0f);
	ASSERT_FLOAT_EQ(result_pre_multiply.getZ(), 1.5f);
}