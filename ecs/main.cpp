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
    void update(std::tuple<Position&>& components)
    {
        std::cout << "GravitySystem::tick\n";

        // this is wrong of course
        std::get<Position&>(components).y -= gravity;
    }

    float gravity = 9.8f;
};

class RenderSystem: public System<Position, Mesh>
{
public:
    void update(const std::tuple<Position&, Mesh&>& components)
    {
        std::cout << "RenderSystem::tick\n";

        auto mesh = std::get<Mesh&>(components);
        auto position = std::get<Position&>(components);

        std::cout << "Rendering " << mesh.meshId << " at " << position.x << "," << position.y << "," << position.z << "\n";
    }
};

class Actor
{
    uintptr_t entityId;
};

int main(int argc, const char * argv[])
{
    World<Position, Mesh> world;

    //world.create<Position>();
    world.update();
    RenderSystem renderSystem;
    renderSystem.System::update(world);

    Entity entity;
    entity.addComponent<Position>();
    entity.addComponent<Mesh>();

    return 0;
}
