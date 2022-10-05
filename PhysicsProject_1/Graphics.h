#pragma once

#include <iostream>
#include <random>
#include <gdp/Engine.h>
#include <gdp/GameObject.h>

#include "ParticleAccelerator.h"
#include "MultiParticleAccelerator.h"
#include "Tank.h"

class Graphics {
	
	ParticleAccelerator pa;
	Vector3 pos;
	Vector3 pos1;
	Vector3 pos2;
	Vector3 target_crosshair;
	Vector3 temp;
	Tank_Ammo tank_ammo;
	Tank player_tank;
	Tank enemy_tank;
	bool grounded;
	bool gameOver;
	bool fire;


public:
	Graphics();
	~Graphics();

	void Initialize();
	void Update();
	void Destroy();
	void GameBegin();
	float RandGen(float, float);
	Vector3 AssignRand(Vector3&, Tank);
	void CheckDist(Tank&, Particle&);
	void TankFire();
	Vector3 Target(float x, float y, float z);
};