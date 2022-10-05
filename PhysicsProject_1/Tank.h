#pragma once

#include "Vector3.h"
#include "Particle.h"
#include "gdp/Engine.h"

class Tank_Ammo {
public:
    
    Particle* part;
    gdp::GameObject* game_object;
    //inline const Vector3& GetPosition() const { return position; }
};