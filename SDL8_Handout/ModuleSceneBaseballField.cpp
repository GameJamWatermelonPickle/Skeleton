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
#include "ModuleSceneBaseballField.h"
#include "ModuleSceneLevelSelector.h"

// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA

ModuleSceneBaseballField::ModuleSceneBaseballField()
{}

ModuleSceneBaseballField::~ModuleSceneBaseballField()
{}

// Load assets
bool ModuleSceneBaseballField::Start()
{
	LOG("Loading space intro");

	background = App->textures->Load("rtype/beisbol_1.png");

	//App->level_selector->lvlselector = false;

	App->player->Enable();
	App->particles->Enable();
	App->collision->Enable();
	App->enemies->Enable();

	App->render->camera.x = App->render->camera.y = 0;

	// Colliders ---
	App->collision->AddCollider({ 153, 0, 800, 10 }, COLLIDER_WALL); //1
	App->collision->AddCollider({ 143, 0, 10, 186 }, COLLIDER_WALL);//2
	App->collision->AddCollider({ 26, 174, 127, 10 }, COLLIDER_WALL);//3
	App->collision->AddCollider({ 16, 184, 10, 608 }, COLLIDER_WALL);//4
	App->collision->AddCollider({ 26, 792, 127, 10 }, COLLIDER_WALL);//5
	App->collision->AddCollider({ 143, 792, 10, 186 }, COLLIDER_WALL);//6
	App->collision->AddCollider({ 153, 951, 800, 10 }, COLLIDER_WALL);//7
	App->collision->AddCollider({ 953, 792, 10, 186 }, COLLIDER_WALL);//8
	App->collision->AddCollider({ 953, 792, 127, 10 }, COLLIDER_WALL);//9
	App->collision->AddCollider({ 1080, 184, 10, 608 }, COLLIDER_WALL);//10
	App->collision->AddCollider({ 953, 174, 127, 10 }, COLLIDER_WALL);//11
	App->collision->AddCollider({ 953, 0, 10, 186 }, COLLIDER_WALL);//12

	App->collision->AddCollider({ 513,440,80,80 }, COLLIDER_TOWER);

	R.x = 0;
	R.y = 0;
	R.h = 1000;
	R.w = 1000;

	color = 0;

	// Enemies ---
	App->enemies->AddEnemy(ENEMY_TYPES::REDBIRD, 400, 30);
	App->enemies->AddEnemy(ENEMY_TYPES::REDBIRD, 400, 80);
	App->enemies->AddEnemy(ENEMY_TYPES::REDBIRD, 400, 130);
	App->enemies->AddEnemy(ENEMY_TYPES::REDBIRD, 400, 180);

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
	App->textures->Unload(background);


	return true;
}

// Update: draw background
update_status ModuleSceneBaseballField::Update()
{
	App->render->Blit(background, 0, 0, NULL);

	if (color >= 250) {
		App->fade->FadeToBlack((Module*)App->baseball_field, (Module*)App->gameover);
		over = true;
	}


	if (/*death == 4 ||*/ App->input->keyboard[SDL_SCANCODE_E] == KEY_STATE::KEY_DOWN)
	{
		death = 0;
		App->enemies->AddEnemy(ENEMY_TYPES::REDBIRD, 500, 30);
		App->enemies->AddEnemy(ENEMY_TYPES::REDBIRD, 500, 80);
		App->enemies->AddEnemy(ENEMY_TYPES::REDBIRD, 500, 130);
		App->enemies->AddEnemy(ENEMY_TYPES::REDBIRD, 500, 180);
	}

	return UPDATE_CONTINUE;
}