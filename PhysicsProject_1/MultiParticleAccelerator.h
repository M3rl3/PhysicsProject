#pragma once

#include <iostream>
#include <vector>
#include <random>

#include "Particle.h"


class MultiParticleAccelerator {

	std::vector<Particle> particlebuffer;
	Vector3 position;

public:
	MultiParticleAccelerator();
	MultiParticleAccelerator(const Vector3&);

	~MultiParticleAccelerator();

	Particle InitParticle(const Vector3&);
	void Calculate(float);
	void Gravity(const Vector3&);
	float RandNum(float, float);

	Vector3 min_velocity;
	Vector3 max_velocity;
	float min_age;
	float max_age;
};