#include <iostream>


#include "ParticleAccelerator.h"

ParticleAccelerator::ParticleAccelerator() {

}

ParticleAccelerator::~ParticleAccelerator() {

}

Particle& ParticleAccelerator::initparticle(const Vector3& position) {

	Particle part;
	part.position = position;
	part.acceleration = Vector3(0.f, -9.8f, 0.f); //acceleration due to gravity
	part.mass = 0.01f;
	//particles.reserve(100);
	particles.push_back(part);
	return particles[particles.size() - 1];
}

void ParticleAccelerator::calculate_pa(float dt) {
	for (int i = 0; i < particles.size(); i++) {
		if (particles[i].position.y >= 0) {
			particles[i].calculate(dt);
			particles[i].print1();
		}
	}
}