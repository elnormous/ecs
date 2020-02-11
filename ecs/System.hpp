#ifndef SYSTEM_HPP
#define SYSTEM_HPP

#include <tuple>

template<class... Components>
class System
{
public:
    System()
    {
        std::cout << "System\n";
    }

    template <class World>
    void update(World& world)
    {
        //update(world.template getComponents<Components...>());
    }
};

#endif // SYSTEM_HPP
