#pragma once

#include <iostream>
#include "Vector3.h"

class Particle {
public:
    Vector3 position;
    Vector3 acceleration;
    Vector3 velocity;
    Vector3 force;
  

    Particle();
    ~Particle();
    float damping;
    float mass;
    float inv_mass;
    float age;

    void calculate(float);
    void Gravity(const Vector3&);
    void InvMass(float);
    void print0(float);
    void print1();
    friend std::ostream& operator<<(std::ostream& out, Particle& p1) {
        out << p1.position << p1.velocity;
        return out;
    }
    inline const Vector3& GetPosition() const { return position; }
    inline const Vector3& GetVelocity() const { return velocity; }
    inline const Vector3& GetAcceleration() const { return acceleration; }
};