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
	idleMiddleRight.PushBack({ 0, 0, 49, 61 });
	idleMiddleRight.PushBack({ 61, 0, 49, 61 });
	idleMiddleRight.PushBack({ 123, 0, 49, 61 });
	idleMiddleRight.PushBack({ 184, 0, 49, 61 });

	idleMiddleLeft.PushBack({ 303, 0, 49, 61 });
	idleMiddleLeft.PushBack({ 364, 0, 49, 61 });
	idleMiddleLeft.PushBack({ 426, 0, 49, 61 });

	idleHappy.PushBack({ 1,207,49,61 });
	idleHappy.PushBack({ 62,207,49,61 });
	idleHappy.PushBack({ 124,207,49,61 });
	idleHappy.PushBack({ 185,207,49,61 });

	idleSad.PushBack({ 0,414,49,61 });
	idleSad.PushBack({ 61,414,49,61 });
	idleSad.PushBack({ 123,414,49,61 });
	idleSad.PushBack({ 184,414,49,61 });

	//Movimiento
	rigthMiddle.PushBack({ 0, 75, 49, 61 });
	rigthMiddle.PushBack({ 64,75, 49, 61 });
	rigthMiddle.PushBack({ 127, 75, 49, 61 });
	rigthMiddle.PushBack({ 193, 75, 49, 61 });
	rigthMiddle.PushBack({ 255, 75, 49, 61 });
	rigthMiddle.PushBack({ 316, 75, 49, 61 });
	rigthMiddle.PushBack({ 370, 75, 49, 61 });

	rigthHappy.PushBack({ 1,282,49,61 });
	rigthHappy.PushBack({ 65,282,49,61 });
	rigthHappy.PushBack({ 128,282,49,61 });
	rigthHappy.PushBack({ 194,282,49,61 });
	rigthHappy.PushBack({ 256,282,49,61 });
	rigthHappy.PushBack({ 317,282,49,61 });
	rigthHappy.PushBack({ 371,282,49,61 });

	rigthSad.PushBack({ 0,489,49,61 });
	rigthSad.PushBack({ 64,489,49,61 });
	rigthSad.PushBack({ 127,489,49,61 });
	rigthSad.PushBack({ 193,489,49,61 });
	rigthSad.PushBack({ 255,489,49,61 });
	rigthSad.PushBack({ 316,489,49,61 });
	rigthSad.PushBack({ 370,489,49,61 });

	leftMiddle.PushBack({ 369,142,49,61 });
	leftMiddle.PushBack({ 307,142,49,61 });
	leftMiddle.PushBack({ 246,142,49,61 });
	leftMiddle.PushBack({ 184,142,49,61 });
	leftMiddle.PushBack({ 123,142,49,61 });
	leftMiddle.PushBack({ 61,142,49,61 });
	leftMiddle.PushBack({ 0,142,49,61 });

	leftHappy.PushBack({ 370,349,49,61 });
	leftHappy.PushBack({ 308,349,49,61 });
	leftHappy.PushBack({ 247,349,49,61 });
	leftHappy.PushBack({ 185,349,49,61 });
	leftHappy.PushBack({ 124,349,49,61 });
	leftHappy.PushBack({ 62,349,49,61 });
	leftHappy.PushBack({ 0,349,49,61 });

	leftSad.PushBack({ 0,557,49,61 });
	leftSad.PushBack({ 61,557,49,61 });
	leftSad.PushBack({ 123,557,49,61 });
	leftSad.PushBack({ 184,557,49,61 });
	leftSad.PushBack({ 246,557,49,61 });
	leftSad.PushBack({ 307,557,49,61 });
	leftSad.PushBack({ 369,557,49,61 });

	downHappy.PushBack({ 486,138,43,61 });
	downHappy.PushBack({ 535,138,32,61 });
	downHappy.PushBack({ 577,138,30,61 });
	downHappy.PushBack({ 613,138,33,61 });
	downHappy.PushBack({ 649,138,44,61 });
	downHappy.PushBack({ 699,138,32,61 });

	downSad.PushBack({ 493,273,43,61 });
	downSad.PushBack({ 542,273,32,61 });
	downSad.PushBack({ 584,273,30,61 });
	downSad.PushBack({ 620,273,33,61 });
	downSad.PushBack({ 656,273,44,61 });
	downSad.PushBack({ 706,273,32,61 });

	downMiddle.PushBack({ 497,408,43,61 });
	downMiddle.PushBack({ 546,408,32,61 });
	downMiddle.PushBack({ 588,408,30,61 });
	downMiddle.PushBack({ 624,408,33,61 });
	downMiddle.PushBack({ 660,408,44,61 });
	downMiddle.PushBack({ 710,408,32,61 });

	Up.PushBack({ 481, 0, 36, 61 });
	Up.PushBack({ 532, 0, 36, 61 });
	Up.PushBack({ 578, 0, 36, 61 });
	Up.PushBack({ 622, 0, 36, 61 });
	Up.PushBack({ 661, 0, 36, 61 });
	Up.PushBack({ 712, 0, 36, 61 });


	idleMiddleRight.speed = idleMiddleLeft.speed = idleHappy.speed = idleSad.speed = 0.1;
	rigthMiddle.speed = rigthHappy.speed = rigthSad.speed = 0.1;
	leftMiddle.speed = leftHappy.speed = leftSad.speed = 0.1;
	downMiddle.speed = downHappy.speed = downSad.speed = 0.03;
	Up.speed = 0.1;
}

ModulePlayer::~ModulePlayer()
{}

// Load assets
bool ModulePlayer::Start()
{
	LOG("Loading player");

	graphics = App->textures->Load("rtype/Sprites_Big.png");

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
		current_animation = &idleMiddleRight;
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
			if (position.x < App->render->camera.x + SCREEN_WIDTH / 2) {
				if (App->render->camera.x > 0) {
					App->render->camera.x -= speed;
				}
			}
			current_animation = &leftMiddle;
			if (App->input->keyboard[SDL_SCANCODE_LSHIFT] == KEY_STATE::KEY_DOWN || App->input->buttonRB == KEY_STATE::KEY_DOWN)
			{
				position.x -= 20 * speed;
			}
		}

		if ((App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT || App->input->dpadRight == KEY_STATE::KEY_REPEAT || App->input->joy_right == KEY_STATE::KEY_REPEAT) && collD == false)
		{
			position.x += speed;
			if (position.x > SCREEN_WIDTH / 2) {
				if (App->render->camera.x < 398) {
					App->render->camera.x += speed;
				}
			}
			current_animation = &rigthMiddle;
			if (App->input->keyboard[SDL_SCANCODE_LSHIFT] == KEY_STATE::KEY_DOWN || App->input->buttonRB == KEY_STATE::KEY_DOWN)
			{
				if (position.x > SCREEN_WIDTH / 2) {
					if (App->render->camera.x < 398) {
						App->render->camera.x += 20 * speed;
					}
				}
				position.x += 20 * speed;
			}
		}

		if ((App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT || App->input->dpadDown == KEY_STATE::KEY_REPEAT || App->input->joy_down == KEY_STATE::KEY_REPEAT) && collS == false)
		{
			position.y += speed;
			if (position.y > SCREEN_HEIGHT / 2) {
				if (App->render->camera.y < 300) {
					App->render->camera.y += speed;
				}
			}

			if (App->input->keyboard[SDL_SCANCODE_LSHIFT] == KEY_STATE::KEY_DOWN || App->input->buttonRB == KEY_STATE::KEY_DOWN)
			{
				position.y += 20 * speed;
			}

		}

		if ((App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_REPEAT || App->input->dpadUp == KEY_STATE::KEY_REPEAT || App->input->joy_up == KEY_STATE::KEY_REPEAT) && collW == false)
		{
			position.y -= speed;
			if (position.y < 1000 / 2) {
				if (App->render->camera.y > 0) {
					App->render->camera.y -= speed;
				}
			}
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

		if (App->input->keyboard[SDL_SCANCODE_C] == KEY_STATE::KEY_DOWN && App->fade->IsFading() == false)
		{
			App->fade->FadeToBlack((Module*)App->baseball_field, (Module*)App->gameover);//que modulo se carga al morir
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