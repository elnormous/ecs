#ifndef WORLD_HPP
#define WORLD_HPP

#include <tuple>
#include <vector>
#include <unordered_map>
#include "System.hpp"

inline namespace detail
{
    template<class Component> class WorldComponentHolder
    {
    public:
        WorldComponentHolder()
        {
            std::cout << "WorldComponentHolder<Item>\n";
        }

        uintptr_t create()
        {
            components.resize(lastId);

            return ++lastId;
        }

        void destroy(uintptr_t id)
        {
            // TODO: delete
        }

        std::vector<Component> components;
        // TODO: free list
        uintptr_t lastId = 0;
    };
}

template<class... Component> class World;

template<class HeadComponent, class... TailComponents>
class World<HeadComponent, TailComponents...>:
    public WorldComponentHolder<HeadComponent>,
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

    template<class Component> Component& get()
    {
        return WorldComponentHolder<Component>::value;
    }

    template<class Component> uintptr_t create()
    {
        return WorldComponentHolder<Component>::create();
    }
};

template<> class World<>
{
public:
    World()
    {
        std::cout << "World<>\n";
    }

    template <class... Components>
    std::tuple<Components&...> getComponents()
    {
        std::tuple<Components&...> result;
        return result;
    }

    void tick()
    {

    }

    std::unordered_map<uintptr_t, Entity> entities;
};

#endif // WORLD_HPP
