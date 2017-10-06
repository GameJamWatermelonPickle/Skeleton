#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleParticles.h"
#include "ModuleRender.h"
#include "ModuleCollision.h"
#include "ModuleFadeToBlack.h"
#include "ModulePlayer.h"
#include "ModuleSceneLevelSelector.h"
#include "ModuleSceneBaseballField.h"

// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA

ModulePlayer::ModulePlayer()
{
	// idle animation (just the ship)
	idle.PushBack({66, 1, 32, 14});

	// move upwards
	up.PushBack({100, 1, 32, 14});
	up.PushBack({132, 0, 32, 14});
	up.loop = false;
	up.speed = 0.1f;

	// Move down
	down.PushBack({33, 1, 32, 14});
	down.PushBack({0, 1, 32, 14});
	down.loop = false;
	down.speed = 0.1f;
}

ModulePlayer::~ModulePlayer()
{}

// Load assets
bool ModulePlayer::Start()
{
	LOG("Loading player");

	graphics = App->textures->Load("rtype/ship.png");

	destroyed = false;
	position.x = 150;
	position.y = 120;

	col = App->collision->AddCollider({position.x, position.y, 32, 16}, COLLIDER_PLAYER, this);

	lvl = 1;

	return true;
}

// Unload assets
bool ModulePlayer::CleanUp()
{
	LOG("Unloading player");

	App->textures->Unload(graphics);
	if (col != nullptr)
		col->to_delete = true;

	return true;
}

// Update: draw background
update_status ModulePlayer::Update()
{
	
	if (App->level_selector->lvlselector == true)
	{
		current_animation = &idle;
		if (lvl == 1) {
			position.x = 54;
			position.y = 95;
		}
		else if (lvl == 2) {
			position.x = 251;
			position.y = 104;
		}
		if (lvl == 1 && App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_DOWN || App->input->dpadRight == KEY_STATE::KEY_REPEAT || App->input->joy_right == KEY_STATE::KEY_REPEAT)
			lvl = 2;
		if (lvl == 2 && App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_DOWN || App->input->dpadLeft == KEY_STATE::KEY_REPEAT || App->input->joy_left == KEY_STATE::KEY_REPEAT)
			lvl = 1;
		
	}

	else {
		int speed = 1;
		//Dash
		if ((App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT || App->input->dpadLeft == KEY_STATE::KEY_REPEAT || App->input->joy_left == KEY_STATE::KEY_REPEAT) && collA == false)
		{
			position.x -= speed;

			if (App->input->keyboard[SDL_SCANCODE_LSHIFT] == KEY_STATE::KEY_DOWN || App->input->buttonRB == KEY_STATE::KEY_DOWN)
			{
				position.x -= 20 * speed;
			}
		}

		if ((App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT || App->input->dpadRight == KEY_STATE::KEY_REPEAT || App->input->joy_right == KEY_STATE::KEY_REPEAT) && collD == false)
		{
			position.x += speed;

			if (App->input->keyboard[SDL_SCANCODE_LSHIFT] == KEY_STATE::KEY_DOWN || App->input->buttonRB == KEY_STATE::KEY_DOWN)
			{
				position.x += 20 * speed;
			}
		}

		if ((App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT || App->input->dpadDown == KEY_STATE::KEY_REPEAT || App->input->joy_down == KEY_STATE::KEY_REPEAT) && collS == false)
		{
			position.y += speed;

			if (App->input->keyboard[SDL_SCANCODE_LSHIFT] == KEY_STATE::KEY_DOWN || App->input->buttonRB == KEY_STATE::KEY_DOWN)
			{
				position.y += 20 * speed;
			}
			if (current_animation != &down)
			{
				down.Reset();
				current_animation = &down;
			}
		}

		if ((App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_REPEAT || App->input->dpadUp == KEY_STATE::KEY_REPEAT || App->input->joy_up == KEY_STATE::KEY_REPEAT) && collA == false)
		{
			position.y -= speed;
			if (App->input->keyboard[SDL_SCANCODE_LSHIFT] == KEY_STATE::KEY_DOWN || App->input->buttonRB == KEY_STATE::KEY_DOWN)
			{
				position.y -= 20 * speed;
			}
			if (current_animation != &up)
			{
				up.Reset();
				current_animation = &up;
			}
		}

		if (App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN || App->input->buttonA == KEY_STATE::KEY_DOWN)
		{
			App->particles->AddParticle(App->particles->laser, position.x + 20, position.y, COLLIDER_PLAYER_SHOT);
		}

		if (App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_IDLE
			&& App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_IDLE)
			current_animation = &idle;

		if (App->input->keyboard[SDL_SCANCODE_C] == KEY_STATE::KEY_DOWN)
		{
			App->fade->FadeToBlack((Module*)App->baseball_field, (Module*)App->scene_intro);//que modulo se carga al morir
																							//death animation
			App->particles->AddParticle(App->particles->explosion, position.x, position.y, COLLIDER_NONE, 150);
			App->particles->AddParticle(App->particles->explosion, position.x + 8, position.y + 11, COLLIDER_NONE, 220);
			App->particles->AddParticle(App->particles->explosion, position.x - 7, position.y + 12, COLLIDER_NONE, 670);
			App->particles->AddParticle(App->particles->explosion, position.x + 5, position.y - 5, COLLIDER_NONE, 480);
			App->particles->AddParticle(App->particles->explosion, position.x - 4, position.y - 4, COLLIDER_NONE, 350);
			destroyed = true;
		}

	}
		col->SetPos(position.x, position.y);
	
	// Draw everything --------------------------------------
	if(destroyed == false)
		App->render->Blit(graphics, position.x, position.y, &(current_animation->GetCurrentFrame()));

	collW = false;
	collA = false;
	collS = false;
	collD = false;

	return UPDATE_CONTINUE;
}


void ModulePlayer::OnCollision(Collider* c1, Collider* c2)
{
	if (c1->type == COLLIDER_PLAYER && c2->type == COLLIDER_WALL) {
		if ((c1->rect.x + c1->rect.w) - c2->rect.x != 1 && (c2->rect.x + c2->rect.w) - c1->rect.x != 1 && (c2->rect.y + c2->rect.h) - c1->rect.y == 1 && (c1->rect.y + c1->rect.h) - c2->rect.y != 1)

			collW = true;

		if ((c1->rect.x + c1->rect.w) - c2->rect.x != 1 && (c2->rect.x + c2->rect.w) - c1->rect.x == 1 && (c2->rect.y + c2->rect.h) - c1->rect.y != 1 && (c1->rect.y + c1->rect.h) - c2->rect.y != 1)

			collA = true;

		if ((c1->rect.x + c1->rect.w) - c2->rect.x != 1 && (c2->rect.x + c2->rect.w) - c1->rect.x != 1 && (c2->rect.y + c2->rect.h) - c1->rect.y != 1 && (c1->rect.y + c1->rect.h) - c2->rect.y == 1)

			collS = true;

		if ((c1->rect.x + c1->rect.w) - c2->rect.x == 1 && (c2->rect.x + c2->rect.w) - c1->rect.x != 1 && (c2->rect.y + c2->rect.h) - c1->rect.y != 1 && (c1->rect.y + c1->rect.h) - c2->rect.y != 1)

			collD = true;
	}

	if (c1->type == COLLIDER_PLAYER && c2->type == COLLIDER_ENEMY)
		App->baseball_field->color += 20;

	/*if (c1 == col && destroyed == false && App->fade->IsFading() == false)
	{
		App->fade->FadeToBlack((Module*)App->baseball_field, (Module*)App->scene_intro);//que modulo se carga al morir
		//death animation
		App->particles->AddParticle(App->particles->explosion, position.x, position.y, COLLIDER_NONE, 150);
		App->particles->AddParticle(App->particles->explosion, position.x + 8, position.y + 11, COLLIDER_NONE, 220);
		App->particles->AddParticle(App->particles->explosion, position.x - 7, position.y + 12, COLLIDER_NONE, 670);
		App->particles->AddParticle(App->particles->explosion, position.x + 5, position.y - 5, COLLIDER_NONE, 480);
		App->particles->AddParticle(App->particles->explosion, position.x - 4, position.y - 4, COLLIDER_NONE, 350);
		
	}
		destroyed = true;*/
}