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
#include "ModuleSceneLevelSelector.h"
#include "ModuleSceneGirl.h"

// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA

ModuleSceneLevelSelector::ModuleSceneLevelSelector()
{}

ModuleSceneLevelSelector::~ModuleSceneLevelSelector()
{}

// Load assets
bool ModuleSceneLevelSelector::Start()
{
	LOG("Loading level selector");
	

	background = App->textures->Load("rtype/Transicion_prueba.png");

	App->player->Enable();
	lvlselector = true;
	
	// TODO 1: Add a new wave of red birds
	
	return true;
}

// UnLoad assets
bool ModuleSceneLevelSelector::CleanUp()
{
	LOG("Unloading level selector");

 	App->textures->Unload(background);

	App->player->Disable();
	lvlselector = false;

	return true;
}

// Update: draw background
update_status ModuleSceneLevelSelector::Update()
{
	// Move camera forward -----------------------------
	//App->render->camera.x += 1 * SCREEN_SIZE;

	// Draw everything --------------------------------------
	App->render->Blit(background, 0, 0, NULL);

	if ((App->input->keyboard[SDL_SCANCODE_C] == KEY_DOWN && App->fade->IsFading() == false || App->input->buttonA == KEY_DOWN && App->fade->IsFading() == false) && App->player->lvl == 1)
		App->fade->FadeToBlack(this, (Module*)App->baseball_field);
	if ((App->input->keyboard[SDL_SCANCODE_C] == KEY_DOWN && App->fade->IsFading() == false || App->input->buttonA == KEY_DOWN && App->fade->IsFading() == false) && App->player->lvl == 2)
		App->fade->FadeToBlack(this, (Module*)App->girl);
	
	return UPDATE_CONTINUE;
}