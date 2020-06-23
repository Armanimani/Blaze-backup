#pragma once

#include "Blaze/Engine/Core/Types/base_types.hpp"
#include <atomic>

namespace blaze
{
	class TypeIdentifier
	{
	public:
		template<typename T>
		static UInt32 get()
		{
			return id<std::decay_t<T>>;
		}
	private:
		inline static std::atomic<UInt32> counter{ 0 };
		
		template<typename T>
		inline static const UInt32 id = counter++;
	};
}