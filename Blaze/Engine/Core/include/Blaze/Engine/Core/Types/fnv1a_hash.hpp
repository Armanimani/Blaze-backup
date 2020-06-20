#pragma once

#include "Blaze/Engine/Core/Types/base_types.hpp"

namespace blaze
{
	template<typename>
	struct fnv1a_traits;

	template<>
	struct fnv1a_traits<UInt32>
	{
		using type = UInt32;
		static constexpr UInt32 offset = 2166136261;
		static constexpr UInt32 prime = 16777619;
	};

	template<>
	struct fnv1a_traits<UInt64>
	{
		using type = UInt64;
		static constexpr UInt64 offset = 14695981039346656037ull;
		static constexpr UInt64 prime = 1099511628211ull;
	};

	template <typename ValueType, typename HashType>
	class fnv1a_Hasher
	{
	public:
		using hash_trait = fnv1a_traits<HashType>;
		using value_type = ValueType;

		static HashType hash(const ValueType* value)
		{
			return hashImpl(hash_trait::offset, value);
		}

	private:
		static HashType hashImpl(const HashType offset, const ValueType* value)
		{
			if (value == nullptr || *value == '\0')
				return offset;

			const auto new_offset = (offset ^ value[0]) * hash_trait::prime;
			const ValueType* new_value = value + 1;
			return hashImpl(new_offset, new_value);
		}
	};
}