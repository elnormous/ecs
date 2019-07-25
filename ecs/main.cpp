//
//  main.cpp
//  ecs
//
//  Created by Elviss Strazdiņš on 25/07/2019.
//  Copyright © 2019 Elviss Strazdiņš. All rights reserved.
//

#include <iostream>
#include <vector>

template<typename... Items> class System
{
public:
};

template<typename Item> class ComponentHolder
{
public:
    ComponentHolder()
    {
        std::cout << "ComponentHolder<Item>\n";
    }

    Item value;
};

template<typename... Items> class Entity;

template<typename HeadItem, typename... TailItems> class Entity<HeadItem, TailItems...>:
    public ComponentHolder<HeadItem>,
    public Entity<TailItems...>
{
public:
    Entity()
    {
        std::cout << "Entity<HeadItem, TailItems...>\n";
    }

    template<typename Component> Component& get()
    {
        return ComponentHolder<Component>::value;
    }
};

template<> class Entity<>
{
public:
    Entity()
    {
        std::cout << "Entity<>\n";
    }
};

class Position final
{
public:
    float position[4] = {1.0F, 2.0F, 3.0F , 1.0F};
};

class Controller final
{
public:
    void update();

    float x = 3.0F;
};

class Sound final
{
public:
    void update();
};

int main(int argc, const char * argv[])
{
    System<Position, Controller, Sound> system;

    Entity<Position, Controller> entity;

    auto& c = entity.get<Controller>();
    auto& p = entity.get<Position>();

    std::cout << c.x << " " << p.position[0] << "\n";
    return 0;
}
