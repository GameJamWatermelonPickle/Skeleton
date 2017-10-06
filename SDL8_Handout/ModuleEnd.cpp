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
	background.x = 70;
	background.y = 50;
	background.w = 280;
	background.h = 250;
}

ModuleEnd::~ModuleEnd()
{}

// Load assets
bool ModuleEnd::Start()
{
	App->player->Disable();
	App->collision->Disable();
	LOG("Loading end scene");
	graphics = App->textures->Load("highscore.png");
	//App->audio->pause_music();

	return true;
}

// UnLoad assets
bool ModuleEnd::CleanUp()
{
	LOG("Unloading END scene");
	return true;
}

// Update: draw background
update_status ModuleEnd::Update()
{
	update_status ret = UPDATE_CONTINUE;

	

	if (App->input->keyboard[SDL_SCANCODE_SPACE] == 1 && KEY_DOWN) {
		App->fade->FadeToBlack(this, App->scene_intro, 3);

	/*if (!App->render->Blit(graphics, 0, SCREEN_HEIGHT - 224, &background, 0.75f))
		ret = UPDATE_ERROR;*/

	}

	return ret;
}