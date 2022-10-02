#pragma once

#include <gdp/Engine.h>
#include <gdp/GameObject.h>

#include "MultiParticleAccelerator.h"
#include "Tank.h"

class Graphics {
	
	MultiParticleAccelerator mpa;
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
};