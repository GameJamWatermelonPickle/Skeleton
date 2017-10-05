#include <math.h>
#include "j1Module.h"
#include "j1App.h"
#include "FadeToBlack.h"
#include "j1Render.h"
#include "ModulePlayer.h"
#include "SDL/include/SDL_render.h"
#include "SDL/include/SDL_timer.h"
#include "j1Window.h"
#include "p2Defs.h"
#include "p2Log.h"
#include "j1Textures.h"
#include "j1Input.h"
#include<stdio.h>
#include "j1Map.h"


ModuleFadeToBlack::ModuleFadeToBlack()
{
	screen = { 0, 0, 640 , 480  };
	
	
}

ModuleFadeToBlack::~ModuleFadeToBlack()
{}

// Load assets
bool ModuleFadeToBlack::Awake(pugi::xml_node& config)
{
	
	SDL_SetRenderDrawBlendMode(App->render->renderer, SDL_BLENDMODE_BLEND);
	return true;
}

// Update: draw background
bool ModuleFadeToBlack::Update(float dt)
{
	if (App->input->GetKey(SDL_SCANCODE_M) == KEY_REPEAT)
	{
		current_step = fade_to_black;
	}
	
	if (current_step == fade_step::none)
		return true;

	Uint32 now = SDL_GetTicks() - start_time;
	float normalized = MIN(1.0f, (float)now / (float)total_time);

	switch (current_step)
	{
	case fade_step::fade_to_black:
	{
		if (now >= total_time)
		{
			/*moff->Disable();
			mon->Enable();
			App->render->camera.y = 0;
			App->player->camera_limits.y = 0;
			App->player2->camera_limits2.y = 0;
			App->player->position.x = SCREEN_WIDTH / 2 - 10;
			App->player->position.y = 0 + SCREEN_HEIGHT;*/
			App->map->CleanUp();
			App->map->Load("hello2.tmx"); 
			App->map->Draw();

			// ---
			total_time += total_time;
			start_time = SDL_GetTicks();
			current_step = fade_step::fade_from_black;
		}
	} break;

	case fade_step::fade_from_black:
	{
		normalized = 1.0f - normalized;

		if (now >= total_time)
			current_step = fade_step::none;
	} break;
	}

	// Finally render the black square with alpha on the screen
	SDL_SetRenderDrawColor(App->render->renderer, 0, 0, 0, (Uint8)(normalized * 255.0f));
	SDL_RenderFillRect(App->render->renderer, &screen);

	return true;
}

// Fade to black. At mid point deactivate one module, then activate the other
bool ModuleFadeToBlack::FadeToBlack(j1Module *module_off, j1Module *module_on, float time)
{
	bool ret = false;



	if (current_step == fade_step::none)
	{
		current_step = fade_step::fade_to_black;
		start_time = SDL_GetTicks();
		total_time = (Uint32)(time  *0.5f  *1000.0f);
		mon = module_on;
		moff = module_off;
		ret = true;
	}

	return ret;
}

bool ModuleFadeToBlack::IsFading() const
{
	return current_step != fade_step::none;
}