#ifndef WORLD_HPP
#define WORLD_HPP

#include <tuple>
#include <vector>
#include <unordered_map>
#include "System.hpp"


template<class... Component> class World;

template<class HeadComponent, class... TailComponents>
class World<HeadComponent, TailComponents...>:
    public World<TailComponents...>
{
public:
    World()
    {
        std::cout << "World<HeadComponent, TailComponents...>\n";
    }

    void update()
    {
        //WorldComponentHolder<HeadComponent>::value.tick();
        //World<TailComponents...>::tick();
    }

    template<class Component> uintptr_t createComponent(Entity& entity)
    {
        return World<Component>::create();
    }

    template <class... Components>
    std::tuple<Components&...> getComponents()
    {
        std::tuple<Components&...> result;
        return result;
    }

    uintptr_t create()
    {
        components.resize(lastComponentId);

        return ++lastComponentId;
    }

    void destroy(uintptr_t id)
    {
        // TODO: delete
    }

    std::vector<HeadComponent> components;
    // TODO: free list
    uintptr_t lastComponentId = 0;
};

template<> class World<>
{
public:
    World()
    {
        std::cout << "World<>\n";
    }

    template<class Component> uintptr_t createEntity()
    {
        entities.resize(lastEntityId);

        return ++lastEntityId;
    }

    std::vector<Entity> entities;
    // TODO: free list
    uintptr_t lastEntityId = 0;
};

#endif // WORLD_HPP
