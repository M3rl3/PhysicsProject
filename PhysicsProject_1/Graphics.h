#pragma once

#include <iostream>
#include <random>
#include <gdp/Engine.h>
#include <gdp/GameObject.h>

#include "Tank.h"
#include "ParticleAccelerator.h"


class Graphics {
		
	Vector3 pos;
	Vector3 pos1;
	Vector3 pos2;
	Vector3 target_crosshair;
	Vector3 temp;
	Tank_Ammo tank_ammo;
	Tank_Ammo sphere;
	gdp::GameObject* player_tank;
	gdp::GameObject* enemy_tank;
	gdp::GameObject* plane;
	ParticleAccelerator* pa;

public:
	Graphics();
	~Graphics();

	void Initialize();
	void Update();
	void Destroy();
	void GameBegin();
	float RandGen(float, float);
	gdp::GameObject* AssignRand(gdp::GameObject*);
	void CheckDist(gdp::GameObject*, Particle*);
	void TankFire();
	void Target(float x, float y, float z);
};