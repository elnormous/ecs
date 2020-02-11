#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <unordered_map>

class Entity final
{
public:
    Entity()
    {
        std::cout << "Entity\n";
    }

    template <class T>
    void addComponent()
    {
    }

    std::unordered_map<uintptr_t, uintptr_t> components;
};

#endif // ENTITY_HPP
