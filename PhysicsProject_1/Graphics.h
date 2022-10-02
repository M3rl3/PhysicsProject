#pragma once

#include <iostream>
#include <random>
#include <gdp/Engine.h>
#include <gdp/GameObject.h>

#include "ParticleAccelerator.h"
#include "MultiParticleAccelerator.h"
#include "Tank.h"

class Graphics {
	
	MultiParticleAccelerator mpa;
	Vector3 target_crosshair;
	Tank_Ammo tank_ammo;
	Tank player_tank;
	Tank enemy_tank;

public:
	Graphics();
	~Graphics();

	void Initialize();
	void Update();
	void Destroy();
	float RandGen(float, float);
	Vector3 AssignRand(Vector3&, Tank);
	void CheckDist(Tank, Particle);
	void Target(float x, float y, float z);
};