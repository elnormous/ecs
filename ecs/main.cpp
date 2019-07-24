//
//  main.cpp
//  ecs
//
//  Created by Elviss Strazdiņš on 25/07/2019.
//  Copyright © 2019 Elviss Strazdiņš. All rights reserved.
//

#include <iostream>
#include <vector>

template<typename Item> struct ComponentHolder
{
    ComponentHolder()
    {
        std::cout << "ComponentHolder<Item>\n";
    }

    Item value;
};

template<typename... Items> struct Entity;

template<> struct Entity<>
{
    Entity()
    {
        std::cout << "Entity<>\n";
    }
};

template<typename HeadItem, typename... TailItems> struct Entity<HeadItem, TailItems...>:
    public ComponentHolder<HeadItem>,
    public Entity<TailItems...>
{
    Entity()
    {
        std::cout << "Entity<HeadItem, TailItems...>\n";
    }
};

template<typename HeadItem, typename... TailItems> HeadItem& get(Entity<HeadItem, TailItems...>& entity)
{
    return entity.ComponentHolder<HeadItem>::value;
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
    Entity<Position, Controller, Sound> entity;

    auto c = get<Controller>(entity);

    std::cout << c.x << "\n";
    return 0;
}
