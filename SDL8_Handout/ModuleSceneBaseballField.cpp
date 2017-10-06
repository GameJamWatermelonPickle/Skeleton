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

	background = App->textures->Load("rtype/baseball_field.png");

	//App->level_selector->lvlselector = false;

	App->player->Enable();
	App->particles->Enable();
	App->collision->Enable();
	App->enemies->Enable();

	App->render->camera.x = App->render->camera.y = 0;

	// Colliders ---
	App->collision->AddCollider({ 0, 230, 500, 10 }, COLLIDER_WALL);
	App->collision->AddCollider({ 0, 0, 500, 10 }, COLLIDER_WALL);
	App->collision->AddCollider({ 374, 0, 10, 500 }, COLLIDER_WALL);
	App->collision->AddCollider({ 0, 0, 10, 500 }, COLLIDER_WALL);

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