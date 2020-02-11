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

    void update(const std::tuple<Components&...>& components)
    {

    }
};

#endif // SYSTEM_HPP
