#include "Graphics.h"
#include "Tank.h"

Graphics::Graphics() :pos(Vector3(10.f, 1.f, 10.f)) {
	/*tank_ammo.part = new Particle(pos);*/
}

Graphics::~Graphics() {

}

void Graphics::Initialize() {
	//Init Models and Textures
	

	//Playing Field
	unsigned int model_id_plane = 1;
	gdp::GDP_LoadModel(model_id_plane, "assets/models/plane.obj");
	
	unsigned int texture_id_plane = 1;
	gdp::GDP_LoadTexture(texture_id_plane, "assets/textures/grid.png");

	unsigned int mat_id_plane = 1;
	gdp::GDP_CreateMaterial(mat_id_plane, texture_id_plane, glm::vec3(1, 1, 1));

	plane = gdp::GDP_CreateGameObject();
	plane->Renderer.ShaderId = -1;
	plane->Renderer.MeshId = model_id_plane;
	plane->Renderer.MaterialId = mat_id_plane;
	plane->Position = glm::vec3(0, 0, 0);
	plane->Scale = glm::vec3(20, 1, 20);


	//Tank Bullet
	unsigned int model_id_ammo = 2;
	gdp::GDP_LoadModel(model_id_ammo, "assets/models/tankbullet.obj");

	unsigned int texture_id_ammo = 2;
	gdp::GDP_LoadTexture(texture_id_ammo, "asstes/textures/White.png");
	
	unsigned int mat_id_ammo = 2;
	gdp::GDP_CreateMaterial(mat_id_ammo, texture_id_ammo, glm::vec3(0, 0, 0));
	
	//for (int i = 0; i < 2; i++) { tank_ammo.part = pa->InitParticle(Vector3(10.f, 1.f, 10.f)); }
	//tank_ammo.part = pa.InitParticle(Vector3(10.f, 1.f, 10.f));
	tank_ammo.game_object = gdp::GDP_CreateGameObject();
	tank_ammo.game_object->Renderer.ShaderId = 2;
	tank_ammo.game_object->Renderer.MeshId = model_id_ammo;
	tank_ammo.game_object->Renderer.MaterialId = mat_id_ammo;
	tank_ammo.game_object->Scale = glm::vec3(1, 1, 1);

	
	//Player Tank
	unsigned int model_id_player = 3;
	gdp::GDP_LoadModel(model_id_player, "assets/models/tank.obj");
	
	unsigned int texture_id_player = 3;
	gdp::GDP_LoadTexture(texture_id_player, "assets/textures/tanktexture.png");

	unsigned int mat_id_player = 3;
	gdp::GDP_CreateMaterial(mat_id_player, texture_id_player, glm::vec3(0, 255, 0));

	
	player_tank = gdp::GDP_CreateGameObject();
	player_tank->Renderer.MeshId = model_id_player;
	player_tank->Renderer.MaterialId = mat_id_player;
	player_tank->Renderer.ShaderId = 3;
	player_tank->Scale = glm::vec3(1, 1, 1);
	player_tank->Position = glm::vec3(10, 0, 10);
	//player_tank.player->Rotation = glm::vec3(0, 90, 0);


	//Enemy Tank	
	unsigned int mat_id_enemy = 4;
	gdp::GDP_CreateMaterial(mat_id_player, texture_id_player, glm::vec3(255, 0, 0));

	enemy_tank = gdp::GDP_CreateGameObject();
	enemy_tank->Renderer.MeshId = model_id_player;
	enemy_tank->Renderer.MaterialId = mat_id_player;
	enemy_tank->Renderer.ShaderId = 4;
	enemy_tank->Scale = glm::vec3(1, 1, 1);
	enemy_tank->Position = glm::vec3(-10, 0, -10);
	//enemy_tank.enemy->Rotation = glm::vec3(0, 90, 0);
	
	GameBegin();
}

void Graphics::Update() {

	//New Game
	if (gdp::GDP_IsKeyPressed('n')) {
		AssignRand(player_tank);
		AssignRand(enemy_tank);

		//Vector3 pos1 = Vector3(player_tank->Position.x, player_tank->Position.y, player_tank->Position.z);
		//pos2 = Vector3(enemy_tank->Position.x, enemy_tank->Position.y, enemy_tank->Position.z);

		////tank_ammo.part->velocity = Vector3(-1, 1, -1);
		//tank_ammo.part->position = pos1;
		//tank_ammo.game_object->Position = glm::vec3(pos1.x, pos1.y, pos1.z);
		
		//pos1 = Vector3(player_tank->Position.x, player_tank->Position.y, player_tank->Position.z);
		///*ParticleAccelerator parAcc;
		//tank_ammo.part = new Particle(pos1);
		//
		//tank_ammo.part = parAcc.InitParticle(pos1);*/
		////yes.push_back(parAcc);
		//tank_ammo.part->position = pos1;
		//tank_ammo.game_object->Position = glm::vec3(pos1.x, pos1.y, pos1.z);
	
		GameBegin();

		std::cout << "\nInitial Positions: " << std::endl;
		std::cout << "\nBullet: \nVector3(" << tank_ammo.game_object->Position.x << ", " << tank_ammo.game_object->Position.y << ", " << tank_ammo.game_object->Position.z << ")\n" << std::endl;
		std::cout << "Player: " << pos1 << std::endl;
		std::cout << "Enemy: " << pos2 << std::endl;
	}
	
	//Fire
	if (gdp::GDP_IsKeyHeldDown('f')) {
		//grounded = false;
		//fire = true;
		TankFire();

	}

	//Change firing direction
	if (gdp::GDP_IsKeyHeldDown('w')) {
		Target(0.f, 0.f, 1.f);
	} 
	if (gdp::GDP_IsKeyHeldDown('a')) {
		Target(1.f, 0.f, 0.f);
	}
	if (gdp::GDP_IsKeyHeldDown('s')) {
		Target(0.f, 0.f, -1.f);
	}
	if (gdp::GDP_IsKeyHeldDown('d')) {
		Target(-1.f, 0.f, 0.f);
	}
	if (gdp::GDP_IsKeyHeldDown('q')) {
		Target(0.f, 1.f, 0.f);
	}
	if (gdp::GDP_IsKeyHeldDown('e')) {
		Target(0.f, -1.f, 0.f);
	}

	//Change firing velocity
	if (gdp::GDP_IsKeyPressed('1')) {
		target_crosshair = Vector3(1.f, 1.f, 1.f);
		std::cout << "\nVelocity set to: " << tank_ammo.part->velocity;
	}
	if (gdp::GDP_IsKeyPressed('2')) {
		tank_ammo.part->velocity = target_crosshair * 2;
		std::cout << "\nVelocity set to: " << tank_ammo.part->velocity;
	}
	if (gdp::GDP_IsKeyPressed('3')) {
		tank_ammo.part->velocity = target_crosshair * 3;
		std::cout << "\nVelocity set to: " << tank_ammo.part->velocity;
	}
	if (gdp::GDP_IsKeyPressed('4')) {
		tank_ammo.part->velocity = target_crosshair * 4;
		std::cout << "\nVelocity set to: " << tank_ammo.part->velocity;
	}
	if (gdp::GDP_IsKeyPressed('5')) {
		tank_ammo.part->velocity = target_crosshair * 5;
		std::cout << "\nVelocity set to: " << tank_ammo.part->velocity;
	}

}

void Graphics::GameBegin() {
	
	pos1 = Vector3(player_tank->Position.x, player_tank->Position.y, player_tank->Position.z);
	pos2 = Vector3(enemy_tank->Position.x, enemy_tank->Position.y, enemy_tank->Position.z);

	tank_ammo.part = new Particle(Vector3(pos1));
	pa = new ParticleAccelerator();
	tank_ammo.part = pa->InitParticle(Vector3(pos1));

	tank_ammo.part->position = pos1;
	tank_ammo.game_object->Position = glm::vec3(pos1.x, pos1.y, pos1.z);

	target_crosshair = tank_ammo.part->velocity;
	
	std::cout << "\nInitial Velocity: " << target_crosshair;
	//gameOver = false;
	//fire = false;
}

void Graphics::TankFire() {
	if (tank_ammo.part->position.y >= 0) {
		/*if (fire)
			std::cout << "yesnt";
			return;
		fire = true;*/

		tank_ammo.part->velocity = target_crosshair * 6.0f;
		tank_ammo.game_object->Position = player_tank->Position;
		tank_ammo.part = pa->calculate_pa(0.001f);
		
		pos = tank_ammo.part->GetPosition();
		tank_ammo.game_object->Position = glm::vec3(pos.x, pos.y, pos.z);
		
		//grounded = true;
		if (tank_ammo.part->position.y <= 0) {
			//fire = false;
			
			CheckDist(enemy_tank, tank_ammo.part);
			GameBegin();
		}
	}
}

void Graphics::Target(float x, float y, float z) {
	//target_crosshair = tank_ammo.part->velocity;
	
	target_crosshair = target_crosshair + (Vector3(x, y, z) * 0.01f);

	glm::vec3 temp = glm::vec3(target_crosshair.x, target_crosshair.y, target_crosshair.z);
	glm::normalize(temp);

	target_crosshair = Vector3(temp.x, temp.y, temp.z);
	tank_ammo.part->velocity = target_crosshair;

	std::cout << "\nFiring Line: "  << target_crosshair;
	//return target_crosshair;
}

void Graphics::Destroy() {
	                                        
}

//Distance between two points
void Graphics::CheckDist(gdp::GameObject* enemy, Particle* p) {
	
	std::cout << "\n\nBullet Landed at: " << p->position;
	std::cout << "\nEnemy Position: \nVector3(" << enemy_tank->Position.x << ", " << enemy_tank->Position.y << ", " << enemy_tank->Position.z << ")\n" << std::endl;
	
	float dist_tar = glm::distance(tank_ammo.game_object->Position, enemy_tank->Position);
	
	if (dist_tar < 2.f) {
		std::cout << "\nBullseye! " << std::endl;
		//gameOver = true;
	}
	else {
		std::cout << "\nMissed by " << dist_tar << " meters." << std::endl;
	}
}

//Generating random numbers
float Graphics::RandGen(float min, float max) {
	if (min - max == 0) return 0.f;
	int difference = (max - min) * 1000;

	float result = min + (rand() % difference) / 1000.f;
	return result;
}

//Assign random numbers to positions of tanks
gdp::GameObject* Graphics::AssignRand(gdp::GameObject* tank_type) {
	tank_type->Position = glm::vec3(RandGen(-18, 18), 1, RandGen(-18, 18));
	
	return tank_type;
}