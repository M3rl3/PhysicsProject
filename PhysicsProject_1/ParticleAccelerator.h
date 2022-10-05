#pragma once

#include <vector>
#include "Particle.h"


class ParticleAccelerator {

	std::vector<Particle> particles;

public:
	ParticleAccelerator();
	~ParticleAccelerator();

	Particle& InitParticle(const Vector3&);
	Particle& calculate_pa(float time);

};