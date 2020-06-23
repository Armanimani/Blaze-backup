#include <gtest/gtest.h>
#include "Blaze/Engine/Core/Entity/EntityManager.hpp"

using namespace blaze;

struct Dummy
{
	int int_value{};
	float float_value{};
};

TEST(EntityManager, construction)
{
	EntityManager manager{};
}

TEST(EntityManager, createEntity)
{
	EntityManager manager{};
	const auto entity1 = manager.createEntity();
	ASSERT_EQ(entity1.identification, 0u);

	const auto entity2 = manager.createEntity();
	ASSERT_EQ(entity2.identification, 1u);
}

TEST(EntityManager, addComponent)
{
	EntityManager manager{};
	const auto entity = manager.createEntity();
	manager.addComponent<Dummy>(entity);
	manager.addComponent<Dummy>(entity);
}

TEST(EntityManager, addComponent_passArguments)
{
	EntityManager manager{};
	const auto entity = manager.createEntity();
	manager.addComponent<Dummy>(entity, 1, 10.0f);
	ASSERT_EQ(manager.getComponent<Dummy>(entity)->int_value, 1);
	ASSERT_FLOAT_EQ(manager.getComponent<Dummy>(entity)->float_value, 1.0f);
}