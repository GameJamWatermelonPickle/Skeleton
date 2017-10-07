#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleAudio.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleParticles.h"
#include "ModuleCollision.h"
#include "ModuleFadeToBlack.h"
#include "ModuleSceneIntro.h"

// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA

ModuleSceneIntro::ModuleSceneIntro()
{}

ModuleSceneIntro::~ModuleSceneIntro()
{}

// Load assets
bool ModuleSceneIntro::Start()
{
	LOG("Loading space intro");

	App->audio->LoadMusic("Audios/sound_effects/sonrisa/intro.ogg");

	App->collision->CleanUp();
	
	background = App->textures->Load("rtype/menu.png");
	point = App->textures->Load("rtype/point.png");


	App->render->camera.x = App->render->camera.y = 0;

	positionx = 110;
	positiony = 246;
	
	return true;
}

// UnLoad assets
bool ModuleSceneIntro::CleanUp()
{
	LOG("Unloading space scene");

	App->textures->Unload(background);
	
	return true;
}

// Update: draw background
update_status ModuleSceneIntro::Update()
{
	App->render->Blit(background, 0, 0, NULL);
	App->render->Blit(point, positionx, positiony, NULL);

	if (App->input->keyboard[SDL_SCANCODE_C] == KEY_DOWN && App->fade->IsFading() == false || App->input->buttonStart == KEY_DOWN && App->fade->IsFading() == false)
	{
		if (positionx == 110) {
			App->fade->FadeToBlack(this, (Module*)App->level_selector);
		}
		else {
			App->CleanUp();
			return update_status::UPDATE_STOP;
		}
	}



	if(App->input->keyboard[SDL_SCANCODE_UP] == KEY_DOWN && App->fade->IsFading() == false || App->input->buttonStart == KEY_DOWN && App->fade->IsFading() == false)
	{
		if (positiony == 246) {
			positionx = 139;
			positiony = 416;
		}
		else {
			positionx = 110;
			positiony = 246;
		}
		App->audio->PlayFX(App->audio->LoadFX("Audios/sound_effects/Sonrisa/menu.wav"));
	}
	if (App->input->keyboard[SDL_SCANCODE_DOWN] == KEY_DOWN && App->fade->IsFading() == false || App->input->buttonStart == KEY_DOWN && App->fade->IsFading() == false)
	{
		if (positiony == 416) {
			positionx = 110;
			positiony = 246;
		}
		else {
			positionx = 139;
			positiony = 416;
		}
		App->audio->PlayFX(App->audio->LoadFX("Audios/sound_effects/Sonrisa/menu.wav"));
	}

	return UPDATE_CONTINUE;
}