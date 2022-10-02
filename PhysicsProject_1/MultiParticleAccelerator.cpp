#include "MultiParticleAccelerator.h"

MultiParticleAccelerator::MultiParticleAccelerator() : MultiParticleAccelerator(Vector3(0.f))
{
	particlebuffer.resize(69000);
}

MultiParticleAccelerator::MultiParticleAccelerator(const Vector3& position) :
	min_velocity(Vector3(0.f)),
	max_velocity(Vector3(0.f, 1.f, 0.f))
{
	this->position = position;
}

MultiParticleAccelerator::~MultiParticleAccelerator() {
	particlebuffer.clear();
	/*for (int i = 0; i < particlebuffer.size(); i++) {
		delete particlebuffer[i];
	}*/
}


Particle MultiParticleAccelerator::InitParticle(const Vector3& position) {
	Particle part;
	part.position = position;
	part.acceleration = Vector3(0.f, -9.8f, 0.f); //acceleration due to gravity
	part.velocity = Vector3(0.f, 1.f, 0.f);
	part.mass = 0.01f;
	/*part.velocity.x = RandNum(min_velocity.x, max_velocity.x);
	part.velocity.y = RandNum(min_velocity.y, max_velocity.y);
	part.velocity.z = RandNum(min_velocity.z, max_velocity.z);*/
	particlebuffer.push_back(part);
	
	std::cout << "\nParticle velocity: " << part.velocity;
	std::cout << "\nParticle position: " << part.position;
	std::cout << "\nParticle acceleration: " << part.acceleration;
	return part;
}

void MultiParticleAccelerator::Calculate_mpa(float dt) {
	for (int i = 0; i < particlebuffer.size(); i++) {
		//if (p.velocity.y >= 0) {
			particlebuffer[i].calculate(dt);
			
			//particlebuffer[i].print1();
	}
	int breakpoint = 7;
}

void MultiParticleAccelerator::Update(float dt) {

}

float MultiParticleAccelerator::RandNum(float min, float max) {
	if (min - max == 0) return 0.f;
	int difference = (max - min) * 1000;

	float result = min + (rand() % difference) / 1000.f;
	return result;
}