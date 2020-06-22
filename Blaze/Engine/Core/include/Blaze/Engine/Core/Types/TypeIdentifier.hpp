#pragma once

#include "Blaze/Engine/Core/Types/base_types.hpp"

namespace blaze
{
	class TypeIdentifier
	{
	public:
		template<typename>
		static UInt64 get()
		{
			static const auto k_id = getId();
			return k_id;
		}
	private:
		static UInt64 getId()
		{
			static UInt64 counter = 0;
			return counter++;
		}
	};
}