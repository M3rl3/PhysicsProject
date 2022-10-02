#pragma once

#include "Vector3.h"
#include "Particle.h"
#include "gdp/Engine.h"

class Tank {
public:
    Tank();
    ~Tank();

    gdp::GameObject* player;
    gdp::GameObject* enemy;
    Vector3 position;
    float radius;
    
    inline const Vector3& GetPosition() const { return position; }
};

class Tank_Ammo {
public:
    
    Particle part;
    gdp::GameObject* game_object;
    //inline const Vector3& GetPosition() const { return position; }
};