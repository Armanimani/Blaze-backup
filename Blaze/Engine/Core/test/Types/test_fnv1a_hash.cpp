#include <gtest/gtest.h>
#include "Blaze/Engine/Core/Types/fnv1a_hash.hpp"

using namespace blaze;

TEST(fnv1a_Hasher, hashing_empty)
{
	const auto hash = fnv1a_Hasher<Char, UInt32>::hash(nullptr);
	const auto expected_hash = fnv1a_Hasher<Char, UInt32>::hash_trait::offset;

	ASSERT_EQ(hash, expected_hash);
}

TEST(fnv1a_Hasher, hashing_value)
{
	const auto hash = fnv1a_Hasher<Char, UInt32>::hash(static_cast<const char*>("test string"));
	const auto expected_hash = 0x96fc284a;

	ASSERT_EQ(hash, expected_hash);
}

TEST(fnv1a_Hasher, hashing_inequality)
{
	const auto hash1 = fnv1a_Hasher<Char, UInt32>::hash(static_cast<const char*>("test string"));
	const auto hash2 = fnv1a_Hasher<Char, UInt32>::hash(static_cast<const char*>("not a test string"));

	ASSERT_NE(hash1, hash2);
}