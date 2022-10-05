#include <iostream>


#include "ParticleAccelerator.h"

ParticleAccelerator::ParticleAccelerator() {
	//particles.resize(100000);
}

ParticleAccelerator::~ParticleAccelerator() {
	particles.clear();
}

Particle* ParticleAccelerator::InitParticle(const Vector3& position) {
	//for (int i = 0; i < particles.size(); i++) {
		Particle* part = new Particle(position);
		part->position = position;
		part->velocity = Vector3(-1.f, 1.f, -1.f);
		//part->acceleration = Vector3(0.f, -9.8f, 0.f); //acceleration due to gravity
		part->mass = 1.f;

		particles.push_back(part);
		return part;
	//}
}

Particle* ParticleAccelerator::calculate_pa(float dt) {
	
	for (int i = 0; i < particles.size(); i++) {
		//Particle* p = particles[i];
		if (particles[i]->position.y >= 0) {
			particles[i]->calculate(dt);
			//particles[i].print1();
		}
	}
	for (int i = 0; i < particles.size(); i++) {
		Particle* p = particles[i];
		if (p->position.y >= 0) {
			p->ApplyForce(Vector3(1, -9.81f, 1));
			//particles[i].print1();
		}
		return p;
	}
}