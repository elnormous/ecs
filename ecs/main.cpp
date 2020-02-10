//
//  main.cpp
//  ecs
//
//  Created by Elviss Strazdiņš on 25/07/2019.
//  Copyright © 2019 Elviss Strazdiņš. All rights reserved.
//

#include <iostream>
#include <vector>
#include "Entity.hpp"
#include "System.hpp"
#include "World.hpp"

/*template<typename... Items> class System
{
public:
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
};*/

struct Component
{
};

struct Position: Component
{
    float x = 0.0F;
    float y = 0.0F;
    float z = 0.0F;
};

struct Mesh: Component
{
    uintptr_t meshId = 0;
};

class GravitySystem: public System<Position>
{
public:
    void tick()
    {
        std::cout << "GravitySystem::tick\n";
        // TODO: go through every position component and reduce y position
    }

    float gravity = 9.8f;
};

class RenderSystem: public System<Position, Mesh>
{
public:
    void tick()
    {
        std::cout << "RenderSystem::tick\n";
        // TODO: go through all position, mesh pairs and render them
    }
};

int main(int argc, const char * argv[])
{
    /*System<Position, Controller, Sound> system;

    Entity<Position, Controller> entity;

    auto& c = entity.get<Controller>();
    auto& p = entity.get<Position>();

    std::cout << c.x << " " << p.position[0] << "\n";*/

    World<Position, Mesh> world;

    world.create<Position>();

    world.tick();

    Entity<Position, Mesh> entity;

    return 0;
}
