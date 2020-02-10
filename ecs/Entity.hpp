#ifndef ENTITY_HPP
#define ENTITY_HPP

inline namespace detail
{
    template<typename Item> class EntityComponentHolder // TODO: hold component ids
    {
    public:
        EntityComponentHolder():
            componentId(0) // TODO: create component in world
        {
            std::cout << "EntityComponentHolder<Item>\n";
        }

        uintptr_t componentId;
    };
}

template<typename... Items> class Entity;

template<typename HeadItem, typename... TailItems>
class Entity<HeadItem, TailItems...>:
    public EntityComponentHolder<HeadItem>,
    public Entity<TailItems...>
{
public:
    Entity()
    {
        std::cout << "Entity<HeadItem, TailItems...>\n";
    }

    /*template<typename Component> Component& get()
    {
        return EntityComponentHolder<Component>::value;
    }*/
};

template<> class Entity<>
{
public:
    Entity()
    {
        std::cout << "Entity<>\n";
    }
};

#endif // ENTITY_HPP
