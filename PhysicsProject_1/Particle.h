#pragma once

#include <iostream>
#include "Vector3.h"

class Particle {
public:
    Vector3 position;
    Vector3 acceleration;
    Vector3 velocity;

    Particle();
    ~Particle();
    float damping;
    float mass;
    float age;

    void calculate(float);
    void print0(float);
    void print1();
    friend std::ostream& operator<<(std::ostream& out, Particle& p1) {
        out << p1.position << p1.velocity;
        return out;
    }
};