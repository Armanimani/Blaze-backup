#include <gtest/gtest.h>
#include "Blaze/Engine/Math/Types/base_types.hpp"

using namespace blaze;

constexpr int k_size_1_byte = 1;
constexpr int k_size_2_byte = 2;
constexpr int k_size_4_byte = 4;
constexpr int k_size_8_byte = 8;

TEST(types, size_int)
{
	ASSERT_TRUE(sizeof(Int8) >= k_size_1_byte);
	ASSERT_TRUE(sizeof(Int16) >= k_size_2_byte);
	ASSERT_TRUE(sizeof(Int32) >= k_size_4_byte);
	ASSERT_TRUE(sizeof(Int64) >= k_size_8_byte);
}

TEST(types, size_unsigned_int)
{
	ASSERT_TRUE(sizeof(UInt8) >= k_size_1_byte);
	ASSERT_TRUE(sizeof(UInt16) >= k_size_2_byte);
	ASSERT_TRUE(sizeof(UInt32) >= k_size_4_byte);
	ASSERT_TRUE(sizeof(UInt64) >= k_size_8_byte);
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