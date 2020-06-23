#pragma once

#include "Blaze/Engine/Core/Entity/Entity.hpp"
#include "Blaze/Engine/Core/Configuration/EngineConfiguration.hpp"
#include "Blaze/Engine/Core/DataStructures/SparseSet.hpp"
#include "Blaze/Engine/Core/Types/TypeIdentifier.hpp"
#include "Blaze/Engine/Core/Entity/PoolData.hpp"
#include <unordered_map>

namespace blaze
{
	template<typename Entity = Entity<UInt32>>
	class EntityManager
	{
	public:
		using entity_type = typename Entity::entity_type;
		using size_type = std::size_t;

		explicit EntityManager(std::size_t capacity = k_max_number_of_entities);
		
		[[nodiscard]] Entity createEntity() noexcept;

		[[nodiscard]] std::size_t capacity() const noexcept;
		[[nodiscard]] std::size_t size() const noexcept;

		template<typename Component, typename... Args>
		void addComponent(Entity entity, Args&&...args) noexcept;

		template<typename Component>
		Component* getComponent(Entity entity) noexcept;

		template<typename Component>
		const Component* getComponent(Entity entity) const noexcept;
	private:
		std::vector<Entity> entities{};
		std::vector<Entity> deleted_entities{};
		std::unordered_map<UInt32, std::unique_ptr<PoolDataBase>> pools{};
		
		template<typename Component>
		SparseSet<Component>* getPool() noexcept;
	};

	
	template <typename Entity>
	EntityManager<Entity>::EntityManager(const std::size_t capacity)
	{
		entities.reserve(capacity);
		deleted_entities.reserve(capacity);
	}

	template <typename Entity>
	Entity EntityManager<Entity>::createEntity() noexcept
	{
		const auto id = [=]()
		{
			if (!deleted_entities.empty())
				return deleted_entities.back().identification;
			
			return static_cast<entity_type>(entities.size());
		}();
		
		entities.emplace_back(id);
		return entities.back();
	}

	template <typename Entity>
	std::size_t EntityManager<Entity>::capacity() const noexcept
	{
		return entities.capacity();
	}

	template <typename Entity>
	std::size_t EntityManager<Entity>::size() const noexcept
	{
		return entities.size();
	}

	template <typename Entity>
	template <typename Component, typename ... Args>
	void EntityManager<Entity>::addComponent(const Entity entity, Args&&... args) noexcept
	{
		auto pool = getPool<Component>();
		pool->construct(entity.identification, std::forward<Args>(args)...);
	}

	template <typename Entity>
	template <typename Component>
	Component* EntityManager<Entity>::getComponent(const Entity entity) noexcept
	{
		auto memory_pool = getPool<Component>();
		return memory_pool->getElementPointer(entity.identification);
	}

	template <typename Entity>
	template <typename Component>
	const Component* EntityManager<Entity>::getComponent(const Entity entity) const noexcept
	{
		auto memory_pool = getPool<Component>();
		return memory_pool->getElementPointer(entity.identification);
	}

	template <typename Entity>
	template <typename Component>
	SparseSet<Component>* EntityManager<Entity>::getPool() noexcept
	{
		const auto id = TypeIdentifier::get<Component>();
		auto it = pools.find(id);
		if (it == pools.end())
		{
			auto new_pool = std::make_unique<PoolData<Component>>();
			auto sparse_set = std::make_unique<SparseSet<Component>>(capacity());
			new_pool->sparse_set = std::move(sparse_set);
			pools[id] = std::move(new_pool);
		}

		auto pool = pools[id].get();
		auto typed_pool = static_cast<PoolData<Component>*>(pool);
		return typed_pool->sparse_set.get();
	}
}
