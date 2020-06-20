#pragma once

#include <memory>
#include <cassert>

namespace blaze
{
	template<typename IService>
	class Locator
	{
	public:
		static void provide(std::unique_ptr<IService>&& service) noexcept;
		static IService* get() noexcept;
	private:
		inline static std::unique_ptr<IService> s_service{ nullptr };
	};


	template <typename IService>
	void Locator<IService>::provide(std::unique_ptr<IService>&& service) noexcept
	{
		if (s_service)
			s_service.reset();

		s_service = std::move(service);
	}

	template <typename IService>
	IService* Locator<IService>::get() noexcept
	{
		assert(s_service);

		return s_service.get();
	}
}
