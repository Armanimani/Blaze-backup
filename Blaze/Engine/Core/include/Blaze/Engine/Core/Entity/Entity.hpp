#pragma once

#include "Blaze/Engine/Core/Types/base_types.hpp"

namespace blaze
{
	template<typename>
	struct entity_trait;


	template<>
	struct entity_trait<UInt32>
	{
		using entity_type = UInt32;
		using difference_type = std::size_t;
	};


	template<typename Type>
	struct Entity
	{
		using trait = entity_trait<Type>;
		using entity_type = Type;
		
		explicit Entity(entity_type identification);

		UInt32 identification{};
	};

	template <typename Type>
	Entity<Type>::Entity(const entity_type identification)
		: identification{ identification } {}
}
