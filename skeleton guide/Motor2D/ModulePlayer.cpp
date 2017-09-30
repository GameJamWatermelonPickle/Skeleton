#include "p2Defs.h"
#include "p2Log.h"
#include "ModulePlayer.h"
#include "j1App.h"
#include "j1Module.h"
#include "j1Textures.h"
#include "j1Input.h"
#include "j1Render.h"
#include<stdio.h>



ModulePlayer::ModulePlayer()
{
	/*// idle animation (just the ship)
	idle.PushBack({ 66, 1, 32, 14 });

	// move upwards
	up.PushBack({ 100, 1, 32, 14 });
	up.PushBack({ 132, 0, 32, 14 });
	up.loop = false;
	up.speed = 0.1f;

	// Move down
	down.PushBack({ 33, 1, 32, 14 });
	down.PushBack({ 0, 1, 32, 14 });
	down.loop = false;
	down.speed = 0.1f;*/
}

ModulePlayer::~ModulePlayer()
{}

// Load assets
bool ModulePlayer::Start()
{
	/*LOG("Loading player");

	graphics = App->textures->Load("rtype/ship.png");

	destroyed = false;
	position.x = 150;
	position.y = 120;
	score = 0;

	col = App->collision->AddCollider({ position.x, position.y, 32, 16 }, COLLIDER_PLAYER, this);

	// TODO 0: Notice how a font is loaded and the meaning of all its arguments 
	font_score = App->fonts->Load("fonts/rtype_font.png", "! @,_./0123456789$;<&?abcdefghijklmnopqrstuvwxyz", 1);

	// TODO 4: Try loading "rtype_font3.png" that has two rows to test if all calculations are correct*/

	return true;
}

// Unload assets
bool ModulePlayer::CleanUp()
{
	LOG("Unloading player");
	
	
	/*App->textures->Unload(graphics);
	App->collision->EraseCollider(col);
	App->fonts->UnLoad(font_score);*/

	return true;
}

// Update: draw background
bool ModulePlayer::Update()
{
	/*position.x += 1; // Automatic movement

	int speed = 1;

	if (App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT)
	{
		position.x -= speed;
	}

	if (App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT)
	{
		position.x += speed;
	}

	if (App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT)
	{
		position.y += speed;
		if (current_animation != &down)
		{
			down.Reset();
			current_animation = &down;
		}
	}

	if (App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_REPEAT)
	{
		position.y -= speed;
		if (current_animation != &up)
		{
			up.Reset();
			current_animation = &up;
		}
	}

	if (App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN)
	{
		App->particles->AddParticle(App->particles->laser, position.x + 20, position.y, COLLIDER_PLAYER_SHOT);
		score += 13;
	}

	if (App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_IDLE
		&& App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_IDLE)
		current_animation = &idle;

	col->SetPos(position.x, position.y);

	// Draw everything --------------------------------------
	if (destroyed == false)
		App->render->Blit(graphics, position.x, position.y, &(current_animation->GetCurrentFrame()));

	// Draw UI (score) --------------------------------------
	sprintf_s(score_text, 10, "%7d", score);

	// TODO 3: Blit the text of the score in at the bottom of the screen

	return UPDATE_CONTINUE;*/
	return true;
}

