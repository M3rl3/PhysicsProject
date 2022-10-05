#include "Graphics.h"
#include "Tank.h"

Graphics::Graphics() {

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

	gdp::GameObject* plane = gdp::GDP_CreateGameObject();
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
	
	//gdp::GameObject* tankammo = gdp::GDP_CreateGameObject();
	
	//for (int i = 0; i < 100; i++)
	//tank_ammo.part = pa.InitParticle(Vector3(10.f, 1.f, 10.f));
	tank_ammo.game_object = gdp::GDP_CreateGameObject();
	tank_ammo.game_object->Renderer.ShaderId = 2;
	tank_ammo.game_object->Renderer.MeshId = model_id_ammo;
	tank_ammo.game_object->Renderer.MaterialId = mat_id_ammo;
	tank_ammo.game_object->Scale = glm::vec3(1, 1, 1);
	//tank_ammo.game_object->Position = glm::vec3(0, 5, 0);

	

	//Player Tank
	unsigned int model_id_player = 3;
	gdp::GDP_LoadModel(model_id_player, "assets/models/tank.obj");
	
	unsigned int texture_id_player = 3;
	gdp::GDP_LoadTexture(texture_id_player, "assets/textures/tanktexture.png");

	unsigned int mat_id_player = 3;
	gdp::GDP_CreateMaterial(mat_id_player, texture_id_player, glm::vec3(0, 255, 0));

	player_tank.player = gdp::GDP_CreateGameObject();
	player_tank.player->Renderer.MeshId = model_id_player;
	player_tank.player->Renderer.MaterialId = mat_id_player;
	player_tank.player->Renderer.ShaderId = 3;
	player_tank.player->Scale = glm::vec3(1, 1, 1);
	player_tank.player->Position = glm::vec3(10, 0, 10);
	//player_tank.player->Rotation = glm::vec3(0, 90, 0);

	pos1 = player_tank.GetPosition();

	//Enemy Tank
	unsigned int mat_id_enemy = 4;
	gdp::GDP_CreateMaterial(mat_id_player, texture_id_player, glm::vec3(255, 0, 0));

	enemy_tank.enemy = gdp::GDP_CreateGameObject();
	enemy_tank.enemy->Renderer.MeshId = model_id_player;
	enemy_tank.enemy->Renderer.MaterialId = mat_id_player;
	enemy_tank.enemy->Renderer.ShaderId = 4;
	enemy_tank.enemy->Scale = glm::vec3(1, 1, 1);
	enemy_tank.enemy->Position = glm::vec3(-10, 0, -10);
	//enemy_tank.enemy->Rotation = glm::vec3(0, 90, 0);
	
	GameBegin();
}

void Graphics::Update() {

	
	//Vector3 vel = tank_ammo.part.GetVelocity();
	//Vector3 accn = tank_ammo.part.GetAcceleration();
	
	
	//player_tank.player->Position = glm::vec3(pos1.x, pos1.y, pos1.z);

	
	//enemy_tank.enemy->Position = glm::vec3(pos2.x, pos2.y, pos2.z);

	//New Game
	if (gdp::GDP_IsKeyPressed('n')) {
		AssignRand(pos1, player_tank);
		AssignRand(pos2, enemy_tank);

		player_tank.player->Position = glm::vec3(pos1.x, pos1.y, pos1.z);
		player_tank.position = pos1;
		
		enemy_tank.enemy->Position = glm::vec3(pos2.x, pos2.y, pos2.z);
		enemy_tank.position = pos2;

		//tank_ammo.part = pa.initparticle(Vector3(10.f, 1.f, 10.f));
		tank_ammo.part.position = pos1;
		tank_ammo.game_object->Position = glm::vec3(pos1.x, pos1.y, pos1.z);
		target_crosshair = Vector3(1.f, 1.f, 1.f);
		//tank_ammo.part = pa.InitParticle(pos1);
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
		
		//tank_ammo.part.position.y = 0.f;
		//target_crosshair = Vector3(0.f);
		/*tank_ammo.part.velocity.x = target_crosshair.x;
		tank_ammo.part.velocity.y = target_crosshair.y;
		tank_ammo.part.velocity.z = target_crosshair.z;*/
		//Target(-10, 0, -10);
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
		std::cout << "\nVelocity set to: " << tank_ammo.part.velocity;
	}
	if (gdp::GDP_IsKeyPressed('2')) {
		tank_ammo.part.velocity = target_crosshair * 2;
		std::cout << "\nVelocity set to: " << tank_ammo.part.velocity;
	}
	if (gdp::GDP_IsKeyPressed('3')) {
		tank_ammo.part.velocity = target_crosshair * 3;
		std::cout << "\nVelocity set to: " << tank_ammo.part.velocity;
	}
	if (gdp::GDP_IsKeyPressed('4')) {
		tank_ammo.part.velocity = target_crosshair * 4;		
		std::cout << "\nVelocity set to: " << tank_ammo.part.velocity;
	}
	if (gdp::GDP_IsKeyPressed('5')) {
		tank_ammo.part.velocity = target_crosshair * 5;
		std::cout << "\nVelocity set to: " << tank_ammo.part.velocity;
	}

}

void Graphics::GameBegin() {
	
	pos1 = player_tank.GetPosition();
	pos1 = Vector3(player_tank.player->Position.x, player_tank.player->Position.y, player_tank.player->Position.z);
	tank_ammo.part = pa.InitParticle(Vector3(pos1));
	/*tank_ammo.part.position = pos;
	tank_ammo.game_object->Position = glm::vec3(pos.x, pos.y, pos.z);*/
	tank_ammo.game_object->Position = player_tank.player->Position;
	tank_ammo.part.position = pos1;
	tank_ammo.game_object->Position = glm::vec3(pos1.x, pos1.y, pos1.z);
	target_crosshair = Vector3(1.f, 1.f, 1.f);
	target_crosshair = tank_ammo.part.GetVelocity();
	pos2 = enemy_tank.GetPosition();
	std::cout << "\nInitial Velocity: " << target_crosshair;
	gameOver = false;
	//fire = false;
}

void Graphics::TankFire() {
	if (tank_ammo.part.position.y >= 0) {
		/*if (fire)
			std::cout << "yesnt";
			return;
		fire = true;*/
		
		tank_ammo.part.velocity = target_crosshair * 6.0f;

		tank_ammo.game_object->Position = player_tank.player->Position;

		enemy_tank.position.x = enemy_tank.enemy->Position.x;
		enemy_tank.position.y = enemy_tank.enemy->Position.y;
		enemy_tank.position.z = enemy_tank.enemy->Position.z;

		tank_ammo.part = pa.calculate_pa(0.001f);
		pos = tank_ammo.part.GetPosition();
		tank_ammo.game_object->Position = glm::vec3(pos.x, pos.y, pos.z);
		//grounded = true;
		if (tank_ammo.part.position.y <= 0) {
			/*pos = tank_ammo.part.GetPosition();
			tank_ammo.game_object->Position = glm::vec3(pos.x, pos.y, pos.z);*/
			//fire = false;
			CheckDist(enemy_tank, tank_ammo.part);
			GameBegin();
		}
	}
}

Vector3 Graphics::Target(float x, float y, float z) {
	//target_crosshair = tank_ammo.part.GetVelocity();
	target_crosshair = target_crosshair + Vector3((x, y, z) * 0.01f);

	glm::vec3 temp = glm::vec3(target_crosshair.x, target_crosshair.y, target_crosshair.z);
	glm::normalize(temp);
	target_crosshair = Vector3(temp.x, temp.y, temp.z);
	std::cout << "\nFiring Line: "  << target_crosshair;
	return target_crosshair;
}

void Graphics::Destroy() {
	                                        
}

//Distance between two points
void Graphics::CheckDist(Tank& enemy, Particle& p) {
	
	//std::cout << "\n\nFinal Bullet Velocity: " << p.velocity;
	std::cout << "\n\nBullet Landed at: " << p.position;
	std::cout << "\nEnemy Position: " << enemy_tank.position << std::endl;
	
	float dist_tar = glm::distance(tank_ammo.game_object->Position, enemy_tank.enemy->Position);
	/*if (enemy.position.z > p.position.z || enemy.position.x > p.position.x) {		//Distance Formula
		dist_tar = sqrt(((enemy.position.x - p.position.x) * (enemy.position.x - p.position.x)) + ((enemy.position.z - p.position.z) * (enemy.position.z - p.position.z)));
	}
	else if (p.position.z > enemy.position.z || p.position.x > enemy.position.x) {
		dist_tar = sqrt(((p.position.x - enemy.position.x) * (p.position.x - enemy.position.x)) + ((enemy.position.z - p.position.z) * (enemy.position.z - p.position.z)));
	}*/
	if (dist_tar <= enemy.radius /*&& dist_tar_y <= enemy.radius && dist_tar_z <= enemy.radius*/) {
		std::cout << "\nBullseye! " << std::endl;
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
Vector3 Graphics::AssignRand(Vector3& pos, Tank tanktype) {
	Vector3 position = tanktype.GetPosition();
	pos.x = RandGen(-20, 20);
	pos.y = 1;
	pos.z = RandGen(-20, 20);
	return pos;
}