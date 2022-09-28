#include "MultiParticleAccelerator.h"

MultiParticleAccelerator::MultiParticleAccelerator() : MultiParticleAccelerator(Vector3(0.f))
{
	particlebuffer.resize(69000);
}

MultiParticleAccelerator::MultiParticleAccelerator(const Vector3& position) :
	min_velocity(Vector3(0.f)),
	max_velocity(Vector3(0.f, 1.f, 0.f)),
	min_age(1000.f),
	max_age(2000.f) 
{
	this->position = position;
}

MultiParticleAccelerator::~MultiParticleAccelerator() {

}


void MultiParticleAccelerator::InitParticle(const Vector3& velocity) {
	
	bool created = false;
	
	for (int i = 0; i < particlebuffer.size(); i++) {
		Particle& part = particlebuffer[i];
		
		if (part.age <= 0.f) {
			
			part.position = this->position;
			part.velocity = part.position;
			part.velocity.x = RandNum(min_velocity.x, max_velocity.x);
			part.velocity.y = RandNum(min_velocity.y, max_velocity.y);
			part.velocity.z = RandNum(min_velocity.z, max_velocity.z);


			int age_difference = max_age - min_age;

			part.age = (min_age + (rand() % age_difference)) / 1000.f;

			std::cout << "\nPatricle: " << i;
			std::cout << "\nParticle age: " << part.age;
			std::cout << "\nParticle velocity: " << part.velocity;
			
			created = true;
			break;
		}
	}

	if (!created) {
		std::cout << "\nAborted: Max limit reached." << std::endl;
		return;
	}
}

void MultiParticleAccelerator::Calculate_mpa(float dt) {
	for (int i = 0; i < particlebuffer.size(); i++) {
		Particle& p = particlebuffer[i];
		if (p.age > 0.f) {
			p.calculate(dt);
			/*p.print1();*/
		}
	}
	int breakpoint = 7;
}

float MultiParticleAccelerator::RandNum(float min, float max) {
	if (min - max == 0) return 0.f;
	int difference = (max - min) * 1000;

	float result = min + (rand() % difference) / 1000.f;
	return result;
}