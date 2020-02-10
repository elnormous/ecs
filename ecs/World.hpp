#ifndef WORLD_HPP
#define WORLD_HPP

#include <vector>
#include <unordered_map>

inline namespace detail
{
    template<typename Component> class WorldComponentHolder
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

template<typename... Component> class World;

template<typename HeadComponent, typename... TailComponents>
class World<HeadComponent, TailComponents...>:
    public WorldComponentHolder<HeadComponent>,
    public World<TailComponents...>
{
public:
    World()
    {
        std::cout << "World<HeadComponent, TailComponents...>\n";
    }

    void tick()
    {
        //WorldComponentHolder<HeadComponent>::value.tick();
        //World<TailComponents...>::tick();
    }

    template<typename Component> Component& get()
    {
        return WorldComponentHolder<Component>::value;
    }

    template<typename Component> uintptr_t create()
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

    void tick()
    {

    }

    //std::unordered_map<uintptr_t, Entity> entities;
};

#endif // WORLD_HPP
