#include "p2Defs.h"
#include "p2Log.h"
#include "ModulePlayer.h"
#include "j1App.h"
#include "j1Module.h"
#include "j1Textures.h"
#include "j1Input.h"
#include "j1Render.h"
#include<stdio.h>
#include "ModuleCollision.h"



ModulePlayer::ModulePlayer()
{
	position.x = 10;
	position.y = 10;
	
	//idle
	idle.PushBack({ 3, 0, 8, 15 });
	idle.PushBack({ 14, 0, 8, 15});
	idle.PushBack({ 25,0,8,15 });
	idle.PushBack({ 36,0,8,15 });

	//Right
	right.PushBack({1,21,12,15});
	right.PushBack({16,21,12,15});
	right.PushBack({31,21,12,15});
	right.PushBack({46,21,12,15});
	right.PushBack({61,21,12,15});
	right.PushBack({76,21,12,15});
	right.PushBack({91,21,12,15});
	right.PushBack({106,21,12,15});
	right.PushBack({121,21,12,15});
}

ModulePlayer::~ModulePlayer()
{}

// Load assets
bool ModulePlayer::Start()
{
	LOG("Loading player");

	graphics = App->tex->Load("Sprites/character.png");
	current_animation = &idle;
	destroyed = false;
	position.x = 10;
	position.y = 10;

	playerCollider = App->colliders->AddCollider({ position.x, position.y, 12, 15 }, COLLIDER_PLAYER, this);
	rectPlayer.x = 10;
	rectPlayer.y = 10;
	rectPlayer.h = 12;
	rectPlayer.w = 15;


	return true;
}

// Unload assets
bool ModulePlayer::CleanUp()
{
	LOG("Unloading player");
	
	
	App->tex->UnLoad(graphics);
	App->colliders->deleteCollider(playerCollider);
	

	return true;
}

// Update: draw background
bool ModulePlayer::Update(float dt)
{

	if (App->input->GetKey(SDL_SCANCODE_W) == KEY_REPEAT)
		position.y-=1;

	if (App->input->GetKey(SDL_SCANCODE_A) == KEY_REPEAT)
		position.x -=1;

	if (App->input->GetKey(SDL_SCANCODE_X) == KEY_REPEAT)
		position.y+=2;

	if (App->input->GetKey(SDL_SCANCODE_D) == KEY_REPEAT)
		position.x += 1, current_animation = &right;
	playerCollider->SetPos(position.x, position.y);
	playerCollider->rect.h = 10;
	playerCollider->rect.w = 10;
	App->render->Blit(graphics, position.x, position.y,&(current_animation->GetCurrentFrame()));


	return true;
}

