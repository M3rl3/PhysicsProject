#include "Particle.h"

Particle::Particle() : Particle(Vector3()) {
   /* this->position = Vector3(0.f);
    this->velocity = Vector3(0.f);
    this->acceleration = Vector3(0.f);
    this->force = Vector3(0.f);
    this->damping = .99f;
    this->mass = 1.f;
    this->age = -1.f;*/
}

Particle::Particle(const Vector3& position) {
    this->position = position;
    this->velocity = Vector3(0.f);
    this->acceleration = Vector3(0.f);
    this->force = Vector3(0.f);
    this->damping = .99f;
    this->mass = 1.f;
    this->age = -1.f;
}

Particle::~Particle() {
    
}

//Calculate particle position and velocity
void Particle::calculate(float dt) {
    
    acceleration = force * InvMass(mass);
    velocity.scalevector(acceleration, dt);
    velocity = velocity * damping;
    position.scalevector(velocity, dt);
    
   /* velocity = velocity + acceleration * dt;
    velocity = velocity * damping;
    position = position + velocity * dt;*/
    //age = age - dt;
}

void Particle::ApplyForce(const Vector3& direction) {
    force = force + direction;
}

float Particle::InvMass(float mass) {
    return mass /= 1;
}

void Particle::print() {
    std::cout << "\nPosition: (" << position.x << ", " << position.y << ", " << position.z << ") " << std::endl;
    std::cout << "\nVelocity: (" << velocity.x << ", " << velocity.y << ", " << velocity.z << ") " << std::endl;

}