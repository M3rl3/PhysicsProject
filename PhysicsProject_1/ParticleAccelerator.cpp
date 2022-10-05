#include <iostream>


#include "ParticleAccelerator.h"

ParticleAccelerator::ParticleAccelerator() {
	//particles.resize(100000);
}

ParticleAccelerator::~ParticleAccelerator() {

}

Particle& ParticleAccelerator::InitParticle(const Vector3& position) {
	//for (int i = 0; i < particles.size(); i++) {
		Particle part;
		part.position = position;
		part.velocity = Vector3(-100.f, 50.f, -50.f);
		part.acceleration = Vector3(-100.f, -98.0f, -100.f); //acceleration due to gravity
		//part.mass = 0.01f;

		particles.push_back(part);
		return particles[particles.size() - 1];
	//}
}

Particle& ParticleAccelerator::calculate_pa(float dt) {
	for (int i = 0; i < particles.size(); i++) {
		Particle& p = particles[i];
		if (p.position.y >= 0) {
			p.calculate(dt);
			//particles[i].print1();
		}
		return p;
	}
}