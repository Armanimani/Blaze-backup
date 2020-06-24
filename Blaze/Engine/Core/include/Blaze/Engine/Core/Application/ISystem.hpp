#pragma once

#include "Blaze/Engine/Core/Types/base_types.hpp"
#include "Blaze/Engine/Core/Types/TypeIdentifier.hpp"
#include <array>

namespace blaze
{
	class ISystem
	{
	public:
		virtual ~ISystem() = default;
		
		virtual void initialize() noexcept = 0;
		virtual void update(Float delta_time) noexcept = 0;
		virtual void finalize() noexcept = 0;
	};

	template<typename...Component>
	struct ComponentPack
	{
		static std::array<UInt32, sizeof...(Component)> identification()
		{
			std::array<UInt32, sizeof...(Component)> result{};
			const std::initializer_list<UInt32> list = { TypeIdentifier::get<Component>()... };

			auto counter = 0;
			for (auto i = list.begin(); i != list.end(); ++i)
			{
				result[counter] = *i;
				counter++;
			}

			return result;
		}
	};

	template<typename MutableComponents, typename ImmutableComponents>
	class DescriptiveSystem: ISystem
	{
	public:
		using mutable_components = MutableComponents;
		using immutable_components = ImmutableComponents;
	};
}