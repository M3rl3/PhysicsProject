#include <iostream>
#include <cmath>

#include "ParticleAccelerator.h"
#include "MultiParticleAccelerator.h"

class Tank {
public:
    Tank() /*: position(0.f), radius(1.f)*/ {
        this->position = 0.f;
        this->radius = 1.f;
    }
    ~Tank() {
    
    }

    Vector3 position;
    float radius;
};

void doshit(float x, float y) {
    //int xv, yv;
     //std::cin >> xv >> yv;

    Tank tank;
    tank.position = Vector3(100.f, 0.f, 0.f);
    tank.radius = 2.f;

    ParticleAccelerator pa;


    Particle& p = pa.initparticle(Vector3(0.f, 1.f, 0.f));
    p.velocity = Vector3(x, y, 0.f);
    //p.acceleration = Vector3(0.f, -9.8f, 0.f);
    p.print1();
    //std::cout << "\nAcceleration: " << p.acceleration << std::endl;

    for (int i = 0; i < 100; i++) {
        pa.calculate_pa(0.01f);
    }

    float dist_tar = abs(tank.position.x - p.position.x);

    if (dist_tar <= tank.radius) {
        std::cout << "\nBullseye! ";
    }
    else {
        std::cout << "\nMissed by " << dist_tar << " meters." << std::endl;
    }
}

//print new y coordinate
void printparticle(Particle p) {
    std::cout << "\nPosition && Velocity: " << p.position.y << " " << p.velocity.y << std::endl;
}

void vectorfunctions() {
    Vector3 vector(5, 6, 7);

    float f = vector.magnitude();
    std::cout << "\nMagnitude: " << f << std::endl;

    Vector3 v = vector.invert(vector);
    std::cout << "\nInvert: " << v << std::endl;

    vector.normal();
    std::cout << "\nNormal: " << vector.x << " " << vector.y << " " << vector.z << "\n" << std::endl;

}

void particlefunctions() {
    
    Particle p;
    p.position = Vector3(0.f);
    p.velocity = Vector3(0.f, 10.f, 0.f);
    p.acceleration = Vector3(0.f, -2.f, 0.f);

    //printing particle positions
    while (p.position.y >= 0) {
        p.calculate(0.1f);
        printparticle(p);
        //if (p.velocity.y <= 0) break;
    }
}

void accelerateparticles() {
    MultiParticleAccelerator mpa;

    Vector3 y_axis(0.f, 1.f, 0.f);

    for (int i = 0; i < 100; i++) {
        mpa.InitParticle(y_axis);
    }
    for (int i = 0; i < 100; i++) {
        mpa.Calculate_mpa(0.01f);
    }
}

//Main entry point
int main(int argc, char* argv) {
    
    srand(time(0));
    accelerateparticles();
    

    //doshit(98, 90);
    
    //particlefunctions();

    return 0;
}