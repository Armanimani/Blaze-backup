#pragma once

#include <memory>

#include "Blaze/Engine/Core/Types/base_types.hpp"
#include "Blaze/Engine/Core/DataStructures/SparseSet.hpp"

namespace blaze
{
	struct PoolDataBase
	{};


	template<typename T>
	struct PoolData: public PoolDataBase
	{
		std::unique_ptr<SparseSet<T>> sparse_set{};
	};
}
