#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleSceneBaseballField.h"
#include "ModuleSceneIntro.h"
#include "ModulePlayer.h"
#include "ModuleSceneLevelSelector.h"
#include "ModuleInput.h"
#include "ModuleAudio.h"
#include "SDL/include/SDL.h"
#include "ModuleFadeToBlack.h"
#include "ModuleEnd.h"
#include "ModuleCollision.h"
//#include"ModuleUI.h"

ModuleEnd::ModuleEnd()
{
}

ModuleEnd::~ModuleEnd()
{}

// Load assets
bool ModuleEnd::Start()
{
	App->player->Disable();
	App->collision->Disable();
	LOG("Loading end scene");
	graphics = App->textures->Load("rtype/game_over.png");
	App->render->camera.x = App->render->camera.y = 0;
	//App->audio->pause_music();

	return true;
}

// UnLoad assets
bool ModuleEnd::CleanUp()
{
	App->textures->Unload(graphics);
	LOG("Unloading END scene");
	return true;
}

// Update: draw background
update_status ModuleEnd::Update()
{
	update_status ret = UPDATE_CONTINUE;

	App->render->Blit(graphics, 50, 0, NULL);

	if (App->input->keyboard[SDL_SCANCODE_C] == KEY_DOWN && App->fade->IsFading() == false || App->input->buttonStart == KEY_DOWN && App->fade->IsFading() == false) {
		App->fade->FadeToBlack(this, (Module*)App->scene_intro);

	/*if (!App->render->Blit(graphics, 0, SCREEN_HEIGHT - 224, &background, 0.75f))
		ret = UPDATE_ERROR;*/

	}

	return ret;
}