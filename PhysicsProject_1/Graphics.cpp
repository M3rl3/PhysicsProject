#include "Graphics.h"
#include "Tank.h"

Graphics::Graphics() {

}

Graphics::~Graphics() {

}

void Graphics::Initialize() {
	//Init Models and Textures
	

	//Playing field
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
	ParticleAccelerator pa;
	tank_ammo.part = pa.initparticle(Vector3(10.f, 1.f, 10.f));
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
	
}

void Graphics::Update() {

	Vector3 pos = tank_ammo.part.GetPosition();
	tank_ammo.game_object->Position = glm::vec3(pos.x, pos.y, pos.z);
	
	Vector3 pos1 = player_tank.GetPosition();
	//player_tank.player->Position = glm::vec3(pos1.x, pos1.y, pos1.z);
	//tank_ammo.game_object->Position = glm::vec3(pos1.x, pos1.y, pos1.z);

	Vector3 pos2 = enemy_tank.GetPosition();
	//enemy_tank.enemy->Position = glm::vec3(pos2.x, pos2.y, pos2.z);

	
	if (gdp::GDP_IsKeyPressed('n')) {
		AssignRand(pos1, player_tank);
		AssignRand(pos2, enemy_tank);
		player_tank.player->Position = glm::vec3(pos1.x, pos1.y, pos1.z);
		player_tank.position = pos1;
		enemy_tank.enemy->Position = glm::vec3(pos2.x, pos2.y, pos2.z);
		enemy_tank.position = pos2;
		tank_ammo.game_object->Position = glm::vec3(pos1.x, pos1.y, pos1.z);
		tank_ammo.part.position = pos1;
		
		std::cout << "\nInitial Positions: " << std::endl;
		std::cout << "\nBullet: \nVector3(" << tank_ammo.game_object->Position.x << ", " << tank_ammo.game_object->Position.y << ", " << tank_ammo.game_object->Position.z << ")\n" << std::endl;
		std::cout << "Player: " << pos1 << std::endl;
		std::cout << "Enemy: " << pos2 << std::endl;
	}

	if (gdp::GDP_IsKeyPressed('f')) {
		
		
		tank_ammo.game_object->Position = player_tank.player->Position;
		while (tank_ammo.part.position.y >= 0) {
			tank_ammo.part.calculate(0.01f);

			tank_ammo.part.print1();

		}
		//target_crosshair = Vector3(0.f);
		tank_ammo.part.velocity = Vector3(0.f, 1.f, 0.f);
		
		/*tank_ammo.part.velocity.x = target_crosshair.x;
		tank_ammo.part.velocity.y = target_crosshair.y;
		tank_ammo.part.velocity.z = target_crosshair.z;*/
		tank_ammo.part.acceleration = Vector3(0.f, -9.8f, 0.f);
		//Target(-10, 0, -10);

		pos = tank_ammo.part.GetPosition();
		tank_ammo.game_object->Position = glm::vec3(pos.x, pos.y, pos.z);
		CheckDist(enemy_tank, tank_ammo.part); 
		/*float dist = distance(enemy_tank.position.x, tank_ammo.part.position.x, enemy_tank.position.z, tank_ammo.part.position.z);
		printf("Missed by %.2f meters", dist);*/
		
	}

	if (gdp::GDP_IsKeyHeldDown('w')) {

	} 
	if (gdp::GDP_IsKeyHeldDown('a')) {

	}
	if (gdp::GDP_IsKeyHeldDown('s')) {

	}
	if (gdp::GDP_IsKeyHeldDown('d')) {

	}
	if (gdp::GDP_IsKeyHeldDown('1')) {
		tank_ammo.part.velocity = Vector3(0.f, 1.f, 0.f);
	}
	if (gdp::GDP_IsKeyHeldDown('2')) {
		tank_ammo.part.velocity = Vector3(0.f, 2.f, 0.f);
	}
	if (gdp::GDP_IsKeyHeldDown('3')) {
		tank_ammo.part.velocity = Vector3(0.f, 3.f, 0.f);
	}
	if (gdp::GDP_IsKeyHeldDown('4')) {
		tank_ammo.part.velocity = Vector3(0.f, 4.f, 0.f);
	}
	if (gdp::GDP_IsKeyHeldDown('5')) {
		tank_ammo.part.velocity = Vector3(0.f, 5.f, 0.f);
	}

}

void Graphics::Target(float x, float y, float z) {
	target_crosshair = target_crosshair + Vector3((x, y, z) * 0.01f);
	target_crosshair.normal();
}

void Graphics::Destroy() {

}

void Graphics::CheckDist(Tank enemy, Particle p) {
	float dist_tar = sqrt(((enemy.position.x - p.position.x) * (enemy.position.x - p.position.x)) + ((enemy.position.z - p.position.z) * (enemy.position.z - p.position.z)));
	std::cout << enemy_tank.position;
	if (dist_tar <= enemy.radius /*&& dist_tar_y <= enemy.radius && dist_tar_z <= enemy.radius*/) {
		std::cout << "\nBullseye! " << std::endl;
	}
	else {
		std::cout << "\nMissed by " << dist_tar << " meters." << std::endl;
	}
}

float Graphics::RandGen(float min, float max) {
	if (min - max == 0) return 0.f;
	int difference = (max - min) * 1000;

	float result = min + (rand() % difference) / 1000.f;
	return result;
}

Vector3 Graphics::AssignRand(Vector3& pos, Tank tanktype) {
	Vector3 position = tanktype.GetPosition();
	pos.x = RandGen(-20, 20);
	pos.y = 1;
	pos.z = RandGen(-20, 20);
	return pos;
}