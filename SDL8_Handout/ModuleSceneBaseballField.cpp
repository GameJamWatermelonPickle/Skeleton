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

ModuleSceneBaseballField::ModuleSceneBaseballField()
{}

ModuleSceneBaseballField::~ModuleSceneBaseballField()
{}

// Load assets
bool ModuleSceneBaseballField::Start()
{
	LOG("Loading space intro");

	background = App->textures->Load("rtype/beisbol_1.png");
	background2 = App->textures->Load("rtype/beisbol_2.png");
	background3 = App->textures->Load("rtype/beisbol_3.png");
	//App->level_selector->lvlselector = false;

	App->player->Enable();
	App->particles->Enable();
	App->collision->Enable();
	App->enemies->Enable();

	App->render->camera.x = App->render->camera.y = 0;

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

	// Enemies ---
	App->enemies->AddEnemy(ENEMY_TYPES::LEFT_STRAIGHT, 27, 375);

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
	if (App->baseball_field->color <= 255 && App->baseball_field->color >= 60)
	{
		App->render->Blit(background3, 0, 0, NULL);
	}
	else if (App->baseball_field->color <= 59 && App->baseball_field->color >=40)
	{
		App->render->Blit(background2, 0, 0, NULL);
	}
	else
	{
		App->render->Blit(background, 0, 0, NULL);
	}
	

	if (color >= 250) {
		App->fade->FadeToBlack((Module*)App->baseball_field, (Module*)App->gameover);
		over = true;
	}


	if (/*death == 4 ||*/ App->input->keyboard[SDL_SCANCODE_E] == KEY_STATE::KEY_DOWN)
	{

	}

	return UPDATE_CONTINUE;
}