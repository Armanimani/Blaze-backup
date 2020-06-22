#pragma once

#include "Blaze/Engine/Core/Types/base_types.hpp"
#include <atomic>

namespace blaze
{
	class TypeIdentifier
	{
	public:
		template<typename T>
		static UInt64 get()
		{
			return id<std::decay_t<T>>;
		}
	private:
		inline static std::atomic<UInt64> counter{ 0 };
		
		template<typename T>
		inline static const UInt64 id = counter++;
	};
}