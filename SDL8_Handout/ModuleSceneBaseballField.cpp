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
#include "ModuleAudio.h"
#include "ModuleEnemies.h"
#include "ModuleSceneBaseballField.h"
#include "ModuleSceneLevelSelector.h"
#include "ModuleAudio.h"
#include <time.h>
#include <stdlib.h>
#include "SDL_mixer/include/SDL_mixer.h"

ModuleSceneBaseballField::ModuleSceneBaseballField()
{}

ModuleSceneBaseballField::~ModuleSceneBaseballField()
{}

// Load assets
bool ModuleSceneBaseballField::Start()
{
	LOG("Loading space intro");

	respawn = App->audio->LoadFX("Audios/sound_effects/Sonrisa/FantasmasRespawn.wav");

	background = App->textures->Load("rtype/beisbol_1.png");
	background2 = App->textures->Load("rtype/beisbol_2.png");
	background3 = App->textures->Load("rtype/beisbol_3.png");
	//App->level_selector->lvlselector = false;

	App->player->Enable();
	App->particles->Enable();
	App->collision->Enable();
	App->enemies->Enable();

	App->render->camera.x = App->render->camera.y = 0;

	App->audio->LoadMusic("Audios/sound_effects/sonrisa/VidaAlta.ogg");

	// Colliders ---
	App->collision->AddCollider({ 153, 0, 800, 9 }, COLLIDER_WALL); //1
	App->collision->AddCollider({ 143, 0, 8, 160 }, COLLIDER_WALL);//2
	App->collision->AddCollider({ 26, 160, 127, 9 }, COLLIDER_WALL);//3
	App->collision->AddCollider({ 16, 184, 7, 608 }, COLLIDER_WALL);//4
	App->collision->AddCollider({ 23, 795, 127, 10 }, COLLIDER_WALL);//5
	App->collision->AddCollider({ 143, 795, 8, 186 }, COLLIDER_WALL);//6
	App->collision->AddCollider({ 153, 951, 800, 10 }, COLLIDER_WALL);//7
	App->collision->AddCollider({ 958, 795, 10, 186 }, COLLIDER_WALL);//8
	App->collision->AddCollider({ 955, 795, 127, 10 }, COLLIDER_WALL);//9
	App->collision->AddCollider({ 1082, 184, 10, 608 }, COLLIDER_WALL);//10
	App->collision->AddCollider({ 955, 160, 127, 9 }, COLLIDER_WALL);//11
	App->collision->AddCollider({ 954, 0, 10, 160 }, COLLIDER_WALL);//12

	App->collision->AddCollider({ 510,431,81,82 }, COLLIDER_TOWER);

	R.x = 0;
	R.y = 0;
	R.h = 1200;
	R.w = 1200;

	color = 0;
	cont = 0;

	// Enemies ---
	App->audio->PlayFX(respawn);
	App->enemies->AddEnemy(ENEMY_TYPES::LEFT_STRAIGHT, 27, 375);
	App->enemies->AddEnemy(ENEMY_TYPES::RIGHT_S, 1050, 375);
	App->enemies->AddEnemy(ENEMY_TYPES::UP_SPIRAL, 526, 8);
	App->enemies->AddEnemy(ENEMY_TYPES::DOWN_STRAIGHT, 526, 896);

	//App->enemies->AddEnemy(ENEMY_TYPES::DOWN_STRAIGHT, 526, 896);

	return true;
}

// UnLoad assets
bool ModuleSceneBaseballField::CleanUp()
{
	LOG("Unloading space scene");
	App->enemies->Disable();
	App->collision->Disable();
	App->particles->Disable();
	App->player->Disable();
	App->audio->UnloadMusic();
	App->textures->Unload(background);
	App->textures->Unload(background2);
	App->textures->Unload(background3);

	return true;
}

// Update: draw background
update_status ModuleSceneBaseballField::Update()
{

	if (cont < 100)
		cont++;
	if (cont == 100) {
		App->audio->PlayFX(respawn);
		App->enemies->AddEnemy(ENEMY_TYPES::LEFT_SPIRAL, 27, 375);
		App->enemies->AddEnemy(ENEMY_TYPES::RIGHT_STRAIGHT, 1050, 375);
		App->enemies->AddEnemy(ENEMY_TYPES::UP_S, 526, 8);
		App->enemies->AddEnemy(ENEMY_TYPES::DOWN_SPIRAL, 526, 896);
		cont++;
	}


	if (App->baseball_field->color <= 255 && App->baseball_field->color >= 150)
	{
		App->render->Blit(background3, 0, 0, NULL);
	}
	else if (App->baseball_field->color <= 149 && App->baseball_field->color >=80)
	{
		App->render->Blit(background2, 0, 0, NULL);
	}
	else
	{
		App->render->Blit(background, 0, 0, NULL);
	}

	

	if (color >= 200) {
		App->fade->FadeToBlack((Module*)App->baseball_field, (Module*)App->gameover);
		over = true;
	}

	if (App->input->keyboard[SDL_SCANCODE_P] == KEY_STATE::KEY_DOWN)
	{
		App->fade->FadeToBlack(this, (Module*)App->girl);
	}


	if (death >= 8  || App->input->keyboard[SDL_SCANCODE_E] == KEY_STATE::KEY_DOWN)  //Enemy respawn
	{
		death = 0;
		win++;
		
		App->audio->PlayFX(respawn);
		if (win == 11) {
			App->fade->FadeToBlack(this, (Module*)App->girl);
			win = 0;
		}

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

	//App->render->Blit(background, 0, 0, NULL);

	return UPDATE_CONTINUE;
}