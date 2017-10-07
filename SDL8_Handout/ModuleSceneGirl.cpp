#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleAudio.h"
#include "ModuleRender.h"
#include "ModuleInput.h"
#include "ModulePlayer.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModuleFadeToBlack.h"
#include "ModuleEnemies.h"
#include "ModuleSceneGirl.h"
#include "ModuleSceneLevelSelector.h"
#include <time.h>
#include <stdlib.h>

// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA

ModuleSceneGirl::ModuleSceneGirl()
{}

ModuleSceneGirl::~ModuleSceneGirl()
{}

// Load assets
bool ModuleSceneGirl::Start()
{
	LOG("Loading space intro");

	background = App->textures->Load("rtype/restaurante_1.png");

	//App->level_selector->lvlselector = false;

	App->player->Enable();
	App->particles->Enable();
	App->collision->Enable();
	App->enemies->Enable();

	App->player->lvl = 2;

	App->render->camera.x = App->render->camera.y = 0;

	App->player->position.x = App->player->position.y = 210;

	// Colliders ---
	App->collision->AddCollider({ 173, 0, 800, 7 }, COLLIDER_WALL); //1
	App->collision->AddCollider({ 173, 0, 10, 157 }, COLLIDER_WALL);//2
	App->collision->AddCollider({ 16, 144, 167, 7 }, COLLIDER_WALL);//3
	App->collision->AddCollider({ 16, 184, 7, 750 }, COLLIDER_WALL);//4
	App->collision->AddCollider({ 23, 917, 127, 10 }, COLLIDER_WALL);//5
	App->collision->AddCollider({ 150, 917, 25, 186 }, COLLIDER_WALL);//6
	App->collision->AddCollider({ 153, 1077, 800, 10 }, COLLIDER_WALL);//7
	App->collision->AddCollider({ 918, 918, 9, 186 }, COLLIDER_WALL);//8
	App->collision->AddCollider({ 918, 917, 184, 10 }, COLLIDER_WALL);//9
	App->collision->AddCollider({ 1082, 184, 10, 720 }, COLLIDER_WALL);//10
	App->collision->AddCollider({ 918, 160, 184, 7 }, COLLIDER_WALL);//11
	App->collision->AddCollider({ 918, 0, 10, 160 }, COLLIDER_WALL);//12

	//Taules

	App->collision->AddCollider({ 282, 229, 61, 82 }, COLLIDER_WALL);
	App->collision->AddCollider({ 282, 741, 61, 82 }, COLLIDER_WALL);
	App->collision->AddCollider({ 730, 229, 61, 82 }, COLLIDER_WALL);
	App->collision->AddCollider({ 730, 741, 61, 82 }, COLLIDER_WALL);

	App->collision->AddCollider({ 510,431,81,82 }, COLLIDER_TOWER);


	App->enemies->AddEnemy(ENEMY_TYPES::LEFT_S, 27, 375);
	App->enemies->AddEnemy(ENEMY_TYPES::RIGHT_STRAIGHT, 1050, 375);
	App->enemies->AddEnemy(ENEMY_TYPES::UP_S, 526, 8);
	App->enemies->AddEnemy(ENEMY_TYPES::DOWN_SPIRAL, 526, 896);

	R.x = 0;
	R.y = 0;
	R.h = 1200;
	R.w = 1200;

	color = 0;
	cont = 0;

	// Enemies ---


	return true;
}

// UnLoad assets
bool ModuleSceneGirl::CleanUp()
{
	LOG("Unloading space scene");
	App->enemies->Disable();
	App->collision->Disable();
	App->particles->Disable();
	App->player->Disable();
	App->textures->Unload(background);


	return true;
}

// Update: draw background
update_status ModuleSceneGirl::Update()
{

	if (cont < 100)
		cont++;
	if (cont == 100) {
		App->enemies->AddEnemy(ENEMY_TYPES::LEFT_STRAIGHT, 27, 375);
		App->enemies->AddEnemy(ENEMY_TYPES::RIGHT_S, 1050, 375);
		App->enemies->AddEnemy(ENEMY_TYPES::UP_SPIRAL, 526, 8);
		App->enemies->AddEnemy(ENEMY_TYPES::DOWN_S, 526, 896);
		cont++;
	}

	App->render->Blit(background, 0, 0, NULL);

	if (color >= 250) {
		App->fade->FadeToBlack((Module*)App->baseball_field, (Module*)App->gameover);
		over = true;
	}


	if (death >= 4 || App->input->keyboard[SDL_SCANCODE_E] == KEY_STATE::KEY_DOWN)
	{
		death = 0;
		for (int i = 0; i < 4; i++)
		{
			random[i] = rand() % 3;
		}

		if (random[0] == 0)
			App->enemies->AddEnemy(ENEMY_TYPES::LEFT_STRAIGHT, 27, 375);
		else if (random[0] == 1)
			App->enemies->AddEnemy(ENEMY_TYPES::LEFT_S, 27, 375);
		else if (random[0] == 2)
			App->enemies->AddEnemy(ENEMY_TYPES::LEFT_SPIRAL, 27, 375);

		if (random[1] == 0)
			App->enemies->AddEnemy(ENEMY_TYPES::RIGHT_STRAIGHT, 1050, 375);
		else if (random[1] == 1)
			App->enemies->AddEnemy(ENEMY_TYPES::RIGHT_S, 1050, 375);
		else if (random[1] == 2)
			App->enemies->AddEnemy(ENEMY_TYPES::RIGHT_SPIRAL, 1050, 375);

		if (random[2] == 0)
			App->enemies->AddEnemy(ENEMY_TYPES::UP_STRAIGHT, 526, 8);
		else if (random[2] == 1)
			App->enemies->AddEnemy(ENEMY_TYPES::UP_S, 526, 8);
		else if (random[2] == 2)
			App->enemies->AddEnemy(ENEMY_TYPES::UP_SPIRAL, 526, 8);

		if (random[3] == 0)
			App->enemies->AddEnemy(ENEMY_TYPES::DOWN_STRAIGHT, 526, 896);
		else if (random[3] == 1)
			App->enemies->AddEnemy(ENEMY_TYPES::DOWN_S, 526, 896);
		else if (random[3] == 2)
			App->enemies->AddEnemy(ENEMY_TYPES::DOWN_SPIRAL, 526, 896);
	}

	return UPDATE_CONTINUE;
}