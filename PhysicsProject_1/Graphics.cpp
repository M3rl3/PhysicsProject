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
	plane->Scale = glm::vec3(20, 1, 20);


	//Tank Bullet
	unsigned int model_id_ammo = 2;
	gdp::GDP_LoadModel(model_id_ammo, "assets/models/tankbullet.obj");

	unsigned int texture_id_ammo = 2;
	gdp::GDP_LoadTexture(texture_id_ammo, "asstes/textures/White.png");
	
	unsigned int mat_id_ammo = 2;
	gdp::GDP_CreateMaterial(mat_id_ammo, texture_id_ammo, glm::vec3(0, 0, 0));
	
	//gdp::GameObject* tankammo = gdp::GDP_CreateGameObject();
	tank_ammo.part = mpa.InitParticle(Vector3(0.f, 10.f, 0.f));
	tank_ammo.game_object = gdp::GDP_CreateGameObject();
	tank_ammo.game_object->Renderer.ShaderId = 2;
	tank_ammo.game_object->Renderer.MeshId = model_id_ammo;
	tank_ammo.game_object->Renderer.MaterialId = mat_id_ammo;
	tank_ammo.game_object->Scale = glm::vec3(1, 1, 1);
	tank_ammo.game_object->Position = glm::vec3(0, 2, 0);


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

	mpa.Calculate_mpa(0.01f);
	Vector3 pos = tank_ammo.part.GetPosition();
	tank_ammo.game_object->Position = player_tank.player->Position;
	
	Vector3 pos1 = player_tank.GetPosition();
	//player_tank.player->Position = glm::vec3(pos1.x, pos1.y, pos1.z);

	Vector3 pos2 = enemy_tank.GetPosition();
	//enemy_tank.enemy->Position = glm::vec3(pos2.x, pos2.y, pos2.z);

	if (gdp::GDP_IsKeyPressed('n')) {
		AssignRand(pos1, player_tank);
		AssignRand(pos2, enemy_tank);
		player_tank.player->Position = glm::vec3(pos1.x, pos1.y, pos1.z);
		enemy_tank.enemy->Position = glm::vec3(pos2.x, pos2.y, pos2.z);
		tank_ammo.game_object->Position = player_tank.player->Position;
	}

}

void Graphics::Destroy() {

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
	pos.y = RandGen(1, 1);
	pos.z = RandGen(-20, 20);
	return pos;
}