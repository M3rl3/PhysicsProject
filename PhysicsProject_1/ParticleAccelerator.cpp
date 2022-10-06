#include <iostream>


#include "ParticleAccelerator.h"

ParticleAccelerator::ParticleAccelerator() {

}

ParticleAccelerator::~ParticleAccelerator() {
	particles.clear();
}

Particle* ParticleAccelerator::InitParticle(const Vector3& position) {
	Particle* part = new Particle(position);
	part->position = position;
	part->velocity = Vector3(-1.f, 1.f, -1.f);
	part->mass = 1.f;

	particles.push_back(part);
	return part;
}

Particle* ParticleAccelerator::calculate_pa(float dt) {
	
	for (int i = 0; i < particles.size(); i++) {
		if (particles[i]->position.y >= 0) {
			particles[i]->calculate(dt);
		}
	}
	for (int i = 0; i < particles.size(); i++) {
		Particle* p = particles[i];
		if (p->position.y >= 0) {
			p->ApplyForce(Vector3(1, -9.81f, 1));
		}
		return p;
	}
}