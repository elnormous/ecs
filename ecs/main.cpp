//
//  main.cpp
//  ecs
//
//  Created by Elviss Strazdiņš on 25/07/2019.
//  Copyright © 2019 Elviss Strazdiņš. All rights reserved.
//

#include <iostream>
#include <vector>

template <class ...Types>
class Entity
{
public:
};

template<typename Item> struct SystemLeaf
{
    SystemLeaf()
    {
        std::cout << "SystemLeaf<Item>\n";
    }

    Item value;
};

template<typename... Items> struct System;

template<> struct System<>
{
    System()
    {
        std::cout << "System<>\n";
    }
};

template<typename HeadItem, typename... TailItems> struct System<HeadItem, TailItems...>:
    public SystemLeaf<HeadItem>,
    public System<TailItems...>
{
    System()
    {
        std::cout << "System<HeadItem, TailItems...>\n";
    }

    void addComponent(const HeadItem& component)
    {
        components.push_back(component);
    }

    std::vector<HeadItem> components;
};

template<typename HeadItem, typename... TailItems> HeadItem& get(System<HeadItem, TailItems...>& tuple)
{
    return tuple.SystemLeaf<HeadItem>::value;
}

class Position
{
public:
    float position[4] = {1.0F, 2.0F, 3.0F , 1.0F};
};

class Controller
{
public:
    void update();

    float x = 3.0F;
};

class Sound
{
public:
    void update();
};

int main(int argc, const char * argv[])
{
    System<Position, Controller, Sound> system;

    auto c = get<Controller>(system);

    std::cout << c.x << "\n";
    return 0;
}
