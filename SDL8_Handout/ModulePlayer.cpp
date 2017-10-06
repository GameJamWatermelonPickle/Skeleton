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
	idleMidle.PushBack({0, 0, 33, 41});
	idleMidle.PushBack({ 41, 0, 33, 41 });
	idleMidle.PushBack({ 82, 0, 33, 41 });
	idleMidle.PushBack({ 123, 0, 33, 41 });
	

	idleHappy.PushBack({0,152,33,41});
	idleHappy.PushBack({41,152,33,41});
	idleHappy.PushBack({82,152,33,41});
	idleHappy.PushBack({123,152,33,41});

	idleSad.PushBack({0,305,33,41});
	idleSad.PushBack({41,305,33,41});
	idleSad.PushBack({82,305,33,41});
	idleSad.PushBack({123,305,33,41});

	// rigth upwards
	rigthMidle.PushBack({0, 51, 33, 41});
	rigthMidle.PushBack({41,51, 33, 41});
	rigthMidle.PushBack({ 82, 51, 33, 41 });
	rigthMidle.PushBack({ 123, 51, 33, 41 });
	rigthMidle.PushBack({ 164, 51, 33, 41 });
	rigthMidle.PushBack({ 205, 51, 33, 41 });
	rigthMidle.PushBack({ 246, 51, 33, 41 });

	rigthHappy.PushBack({0,203,33,41});
	rigthHappy.PushBack({41,203,33,41});
	rigthHappy.PushBack({82,203,33,41});
	rigthHappy.PushBack({123,203,33,41});
	rigthHappy.PushBack({ 164,203,33,41 });
	rigthHappy.PushBack({ 205,203,33,41 });
	rigthHappy.PushBack({ 246,203,33,41 });

	rigthSad.PushBack({0,356,33,41});
	rigthSad.PushBack({41,356,33,41});
	rigthSad.PushBack({82,356,33,41});
	rigthSad.PushBack({123,356,33,41});
	rigthSad.PushBack({ 164,356,33,41 });
	rigthSad.PushBack({ 205,356,33,41 });
	rigthSad.PushBack({ 246,356,33,41 });

	leftMidle.PushBack({ 246,95,33,41 });
	leftMidle.PushBack({ 205,95,33,41 });
	leftMidle.PushBack({ 164,95,33,41 });
	leftMidle.PushBack({ 123,95,33,41 });
	leftMidle.PushBack({ 82,95,33,41 });
	leftMidle.PushBack({ 41,95,33,41 });
	leftMidle.PushBack({0,95,33,41});

	leftHappy.PushBack({0,247,33,41});
	leftHappy.PushBack({41,247,33,41});
	leftHappy.PushBack({82,247,33,41});
	leftHappy.PushBack({123,247,33,41});
	leftHappy.PushBack({ 164,247,33,41 });
	leftHappy.PushBack({ 205,247,33,41 });
	leftHappy.PushBack({ 246,247,33,41 });

	leftSad.PushBack({0,400,33,41});
	leftSad.PushBack({ 41,400,33,41 });
	leftSad.PushBack({ 82,400,33,41 });
	leftSad.PushBack({ 123,400,33,41 });
	leftSad.PushBack({ 164,400,33,41 });
	leftSad.PushBack({ 205,400,33,41 });
	leftSad.PushBack({ 246,400,33,41 });

	idleMidle.speed = idleHappy.speed = idleSad.speed = 0.06;
	rigthMidle.speed = rigthHappy.speed = rigthSad.speed = 0.06;
	leftMidle.speed = leftHappy.speed = leftSad.speed = 0.06;
}

ModulePlayer::~ModulePlayer()
{}

// Load assets
bool ModulePlayer::Start()
{
	LOG("Loading player");

	graphics = App->textures->Load("rtype/Sprites.png");

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
		current_animation = &idleMidle;
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
			current_animation = &leftMidle;
			if (App->input->keyboard[SDL_SCANCODE_LSHIFT] == KEY_STATE::KEY_DOWN || App->input->buttonRB == KEY_STATE::KEY_DOWN)
			{
				position.x -= 20 * speed;
			}
		}

		if ((App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT || App->input->dpadRight == KEY_STATE::KEY_REPEAT || App->input->joy_right == KEY_STATE::KEY_REPEAT) && collD == false)
		{
			position.x += speed;
			current_animation = &rigthMidle;
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
			
		}

		if ((App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_REPEAT || App->input->dpadUp == KEY_STATE::KEY_REPEAT || App->input->joy_up == KEY_STATE::KEY_REPEAT) && collA == false)
		{
			position.y -= speed;
			if (App->input->keyboard[SDL_SCANCODE_LSHIFT] == KEY_STATE::KEY_DOWN || App->input->buttonRB == KEY_STATE::KEY_DOWN)
			{
				position.y -= 20 * speed;
			}
		
		}

		if (App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN || App->input->buttonA == KEY_STATE::KEY_DOWN)
		{
			App->particles->AddParticle(App->particles->laser, position.x + 20, position.y, COLLIDER_PLAYER_SHOT);
		}

		if (App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_IDLE
			&& App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_IDLE)

//			current_animation = &idleMidle;

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

	if (c1->type == COLLIDER_PLAYER && c2->type == COLLIDER_ENEMY && App->baseball_field->over == false)
		App->baseball_field->color += 10;

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