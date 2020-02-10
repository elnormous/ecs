#ifndef SYSTEM_HPP
#define SYSTEM_HPP

inline namespace detail
{
    template<typename Item> class SystemComponentHolder // TODO: hold component types
    {
    public:
        SystemComponentHolder()
        {
            std::cout << "SystemComponentHolder<Item>\n";
        }

        Item value;
    };
}

template<typename... Items> class System;

template<typename HeadItem, typename... TailItems>
class System<HeadItem, TailItems...>:
    public SystemComponentHolder<HeadItem>,
    public System<TailItems...>
{
public:
    System()
    {
        std::cout << "System<HeadItem, TailItems...>\n";
    }

    template <typename Component> Component& get()
    {
        return SystemComponentHolder<Component>::value;
    }
};

template<> class System<>
{
public:
    System()
    {
        std::cout << "System<>\n";
    }
};

#endif // SYSTEM_HPP
