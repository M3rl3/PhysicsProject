#pragma once

#include <vector>
#include "Particle.h"


class ParticleAccelerator {

	std::vector<Particle> particles;

public:
	ParticleAccelerator();
	~ParticleAccelerator();

	Particle& initparticle(const Vector3&);
	void calculate_pa(float time);

};