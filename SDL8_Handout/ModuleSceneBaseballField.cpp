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
	App->collision->AddCollider({ 0, 224, 3930, 16 }, COLLIDER_WALL);
	App->collision->AddCollider({ 1375, 0, 111, 96 }, COLLIDER_WALL);
	App->collision->AddCollider({ 1375, 145, 111, 96 }, COLLIDER_WALL);


	// Enemies ---

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


	return UPDATE_CONTINUE;
}