#include <gtest/gtest.h>
#include "Blaze/Engine/Core/Types/HashedString.hpp"

using namespace blaze;

TEST(HashedString, constructor_default)
{
	const HashedString<Char, UInt32> string{};
	const auto expected_hash = fnv1a_Hasher<Char, UInt32>::hash(nullptr);
	
	ASSERT_EQ(string.getHash(), expected_hash);
}

TEST(HashedString, constructor_const_char)
{
	const HashedString<Char, UInt32> string{ "test" };
	const auto expected_hash = fnv1a_Hasher<Char, UInt32>::hash("test");

	ASSERT_EQ(string.getHash(), expected_hash);
	ASSERT_EQ(std::string_view(string), "test");
}

TEST(HashedString, same_string_equality)
{
	const HashedString<Char, UInt32> string1{ "test" };
	const HashedString<Char, UInt32> string2{ "test" };

	ASSERT_EQ(string1.getHash(), string2.getHash());
	ASSERT_EQ(string1.getString(), string2.getString());
}

TEST(HashedString, same_string_inEquality)
{
	const HashedString<Char, UInt32> string1{ "test" };
	const HashedString<Char, UInt32> string2{ "test the test" };

	ASSERT_NE(string1.getHash(), string2.getHash());
	ASSERT_NE(string1.getString(), string2.getString());
}