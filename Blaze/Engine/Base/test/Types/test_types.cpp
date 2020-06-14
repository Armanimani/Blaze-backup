#include <gtest/gtest.h>
#include "Blaze/Engine/Base/types.hpp"

using namespace blaze::base;

constexpr int k_size_1_byte = 1;
constexpr int k_size_2_byte = 2;
constexpr int k_size_4_byte = 4;
constexpr int k_size_8_byte = 8;

TEST(types, size_int)
{
	ASSERT_EQ(sizeof(Int8), k_size_1_byte);
	ASSERT_EQ(sizeof(Int16), k_size_2_byte);
	ASSERT_EQ(sizeof(Int32), k_size_4_byte);
	ASSERT_EQ(sizeof(Int64), k_size_8_byte);
}

TEST(types, size_unsigned_int)
{
	ASSERT_EQ(sizeof(UInt8), k_size_1_byte);
	ASSERT_EQ(sizeof(UInt16), k_size_2_byte);
	ASSERT_EQ(sizeof(UInt32), k_size_4_byte);
	ASSERT_EQ(sizeof(UInt64), k_size_8_byte);
}

TEST(types, size_float)
{
	ASSERT_EQ(sizeof(Float), k_size_4_byte);
}

TEST(types, size_double)
{
	ASSERT_EQ(sizeof(Double), k_size_8_byte);
}

TEST(types, size_boolean)
{
	ASSERT_EQ(sizeof(Bool), k_size_1_byte);
}