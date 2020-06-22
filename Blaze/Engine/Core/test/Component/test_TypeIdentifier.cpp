#include <gtest/gtest.h>
#include <Blaze/Engine/Core/Component/TypeIdentifier.hpp>

using namespace blaze;

TEST(TypeIdentifier, uniqueId_baseType)
{
	const auto id1 = TypeIdentifier::get<int>();
	const auto id2 = TypeIdentifier::get<int>();

	ASSERT_EQ(id1, id2);
}

TEST(TypeIdentifier, uniqueId_class)
{
	class DummyClass {};
	
	const auto id1 = TypeIdentifier::get<DummyClass>();
	const auto id2 = TypeIdentifier::get<DummyClass>();

	ASSERT_EQ(id1, id2);
}

TEST(TypeIdentifier, differentId)
{
	class DummyClass {};

	const auto id1 = TypeIdentifier::get<DummyClass>();
	const auto id2 = TypeIdentifier::get<int>();

	ASSERT_NE(id1, id2);
}