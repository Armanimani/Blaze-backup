#include <gtest/gtest.h>
#include "Blaze/Engine/Core/DesignPatterns/ServiceLocator.hpp"

using namespace blaze;

TEST(Locator, provide_and_get)
{
	struct DummyService
	{
		int value{};
	};

	auto service = std::make_unique<DummyService>();
	service->value = 10;
	Locator<DummyService>::provide(std::move(service));


	ASSERT_TRUE(Locator<DummyService>::get());
	const auto registered_service = Locator<DummyService>::get();

	ASSERT_EQ(registered_service->value, 10);
}
