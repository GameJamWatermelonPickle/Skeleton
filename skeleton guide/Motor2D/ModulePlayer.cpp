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
	idle.PushBack({ 6, 0, 17,31 });
	idle.PushBack({ 28, 0,17, 31});
	idle.PushBack({ 50,0,17,31 });
	idle.PushBack({ 72,0,17,31 });
	idle.PushBack({ 50,0,17,31 });
	idle.PushBack({ 28, 0,17, 31 });
	idle.speed = 0.03;
	//Right
	right.PushBack({2,43,23,29});
	right.PushBack({33,43,23,29});
	right.PushBack({63,43,23,29});
	right.PushBack({93,43,23,29});
	right.PushBack({123,43,23,29});
	right.PushBack({153,43,23,29});
	right.PushBack({183,43,23,29});
	right.PushBack({213,43,23,29});
	right.PushBack({243,43,23,29});
	right.speed = 0.03;
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
	position.x = 10.f;
	position.y = 10.f;

	playerCollider = App->colliders->AddCollider({ (int)position.x, (int)position.y, 12, 15 }, COLLIDER_PLAYER, this);
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
	current_animation = &idle;
	if (App->input->GetKey(SDL_SCANCODE_W) == KEY_REPEAT)
		position.y-=0.1;

	if (App->input->GetKey(SDL_SCANCODE_A) == KEY_REPEAT)
		position.x -=0.1;

	if (App->input->GetKey(SDL_SCANCODE_X) == KEY_REPEAT)
		position.y+=0.1;

	if (App->input->GetKey(SDL_SCANCODE_D) == KEY_REPEAT)
		position.x += 0.1, current_animation = &right;
	playerCollider->SetPos(position.x, position.y);
	playerCollider->rect.h = 10;
	playerCollider->rect.w = 10;
	App->render->Blit(graphics, position.x, position.y,&(current_animation->GetCurrentFrame()));


	return true;
}

