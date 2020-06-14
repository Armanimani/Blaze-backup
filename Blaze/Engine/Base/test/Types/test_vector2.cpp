#include <gtest/gtest.h>
#include "Blaze/Engine/Base/Vector2.hpp"

using namespace blaze::base;

TEST(vector2, constructor_default)
{
	const auto vec = Vector2{};
	ASSERT_FLOAT_EQ(vec.getX(), 0.0f);
	ASSERT_FLOAT_EQ(vec.getY(), 0.0f);
}

TEST(vector2, constructor_uniform)
{
	const auto vec = Vector2{0.5f};
	ASSERT_FLOAT_EQ(vec.getX(), 0.5f);
	ASSERT_FLOAT_EQ(vec.getY(), 0.5f);
}

TEST(vector2, constructor_2values)
{
	const auto vec = Vector2{ 0.5f, 0.8f };
	ASSERT_FLOAT_EQ(vec.getX(), 0.5f);
	ASSERT_FLOAT_EQ(vec.getY(), 0.8f);
}

TEST(vector2, copy_constructor)
{
	const auto vec = Vector2{ 0.1f, 0.2f };
	const auto other{ vec };
	ASSERT_EQ(other, vec);
}

TEST(vector2, copy_assignment)
{
	const auto vec = Vector2{ 0.1f, 0.2f };
	const auto other = vec;
	ASSERT_EQ(other, vec);
}

TEST(vector2, move_constructor)
{
	auto vec = Vector2{ 0.1f, 0.2f };
	const auto other{ std::move(vec) };
	ASSERT_FLOAT_EQ(other.getX(), 0.1f);
	ASSERT_FLOAT_EQ(other.getY(), 0.2f);
}

TEST(vector2, move_assignment)
{
	auto vec = Vector2{ 0.1f, 0.2f };
	const auto other= std::move(vec);
	ASSERT_FLOAT_EQ(other.getX(), 0.1f);
	ASSERT_FLOAT_EQ(other.getY(), 0.2f);
}

TEST(vector2, operator_equal)
{
	const auto vec = Vector2{ 0.1f, 0.2f };
	const auto other = Vector2{ 0.1f, 0.2f };
	ASSERT_TRUE(other == vec);
}

TEST(vector2, operator_notEqual)
{
	const auto vec = Vector2{ 0.1f, 0.2f };
	const auto other = Vector2{ 5.5f, 5.9f };
	ASSERT_TRUE(other != vec);
}

TEST(vector2, operator_plusEqual)
{
	auto vec = Vector2{ 1.0f, 2.0f };
	const auto other = Vector2{ 0.5f, 0.5f };
	vec += other;
	ASSERT_FLOAT_EQ(vec.getX(), 1.5f);
	ASSERT_FLOAT_EQ(vec.getY(), 2.5f);
}

TEST(vector2, operator_minusEqual)
{
	auto vec = Vector2{ 1.0f, 2.0f };
	const auto other = Vector2{ 0.5f, 0.5f };
	vec -= other;
	ASSERT_FLOAT_EQ(vec.getX(), 0.5f);
	ASSERT_FLOAT_EQ(vec.getY(), 1.5f);
}

TEST(vector2, operator_multiplyEqual_vector)
{
	auto vec = Vector2{ 1.0f, 2.0f };
	const auto other = Vector2{ 0.5f, 0.5f };
	vec *= other;
	ASSERT_FLOAT_EQ(vec.getX(), 1.0f * 0.5f);
	ASSERT_FLOAT_EQ(vec.getY(), 2.0f * 0.5f);
}

TEST(vector2, operator_multiplyEqual_scaler)
{
	auto vec = Vector2{ 1.0f, 2.0f };
	const auto other = 0.5f;
	vec *= other;
	ASSERT_FLOAT_EQ(vec.getX(), 1.0f * 0.5f);
	ASSERT_FLOAT_EQ(vec.getY(), 2.0f * 0.5f);
}

TEST(vector2, operator_divideEqual_scaler)
{
	auto vec = Vector2{ 1.0f, 2.0f };
	const auto other = 0.5f;
	vec /= other;
	ASSERT_FLOAT_EQ(vec.getX(), 1.0f / 0.5f);
	ASSERT_FLOAT_EQ(vec.getY(), 2.0f / 0.5f);
}

TEST(vector2, operator_unaryPlus)
{
	const auto vec = Vector2{ 1.0f, 2.0f };
	const auto other = +vec;
	ASSERT_FLOAT_EQ(vec.getX(), other.getX());
	ASSERT_FLOAT_EQ(vec.getY(), other.getY());
}

TEST(vector2, operator_unaryMinus)
{
	const auto vec = Vector2{ 1.0f, 2.0f };
	const auto other = -vec;
	ASSERT_FLOAT_EQ(vec.getX(), -1.0f * other.getX());
	ASSERT_FLOAT_EQ(vec.getY(), -1.0f * other.getY());
}

TEST(vector2, get_x)
{
	const auto vec = Vector2{ 1.0f, 2.0f };
	ASSERT_FLOAT_EQ(vec.getX(), 1.0f);
}

TEST(vector2, get_y)
{
	const auto vec = Vector2{ 1.0f, 2.0f };
	ASSERT_FLOAT_EQ(vec.getY(), 2.0f);
}

TEST(vector2, set_x)
{
	auto vec = Vector2{};
	vec.setX(1.0f);
	ASSERT_FLOAT_EQ(vec.getX(), 1.0f);
}

TEST(vector2, set_y)
{
	auto vec = Vector2{};
	vec.setY(1.0f);
	ASSERT_FLOAT_EQ(vec.getY(), 1.0f);
}

TEST(vector2, set_values)
{
	auto vec = Vector2{};
	vec.setValues(1.0f, 2.0f);
	ASSERT_FLOAT_EQ(vec.getX(), 1.0f);
	ASSERT_FLOAT_EQ(vec.getY(), 2.0f);
}