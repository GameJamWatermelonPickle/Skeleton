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
#include "ModuleSceneGirl.h"
#include "ModuleAudio.h"
#include "Module.h"



ModulePlayer::ModulePlayer()
{
	rectLife.PushBack({ 0,0,39,38 });
	// idle animation (just the ship)
	idleMiddleRight.PushBack({ 0, 0, 49, 61 });
	idleMiddleRight.PushBack({ 61, 0, 49, 61 });
	idleMiddleRight.PushBack({ 123, 0, 49, 61 });
	idleMiddleRight.PushBack({ 184, 0, 49, 61 });

	idleMiddleLeft.PushBack({ 303, 0, 49, 61 });
	idleMiddleLeft.PushBack({ 364, 0, 49, 61 });
	idleMiddleLeft.PushBack({ 426, 0, 49, 61 });

	idleHappyRight2.PushBack({ 1,207,49,61 });
	idleHappyRight2.PushBack({ 62,207,49,61 });
	idleHappyRight2.PushBack({ 124,207,49,61 });
	idleHappyRight2.PushBack({ 185,207,49,61 });

	idleHappyLeft.PushBack({242,207,49,61});
	idleHappyLeft.PushBack({304,207,49,61});
	idleHappyLeft.PushBack({365,207,49,61});
	idleHappyLeft.PushBack({427,207,49,61});

	idleSadRight.PushBack({ 0,414,49,61 });
	idleSadRight.PushBack({ 61,414,49,61 });
	idleSadRight.PushBack({ 123,414,49,61 });
	idleSadRight.PushBack({ 184,414,49,61 });

	idleSadLeft.PushBack({241,414,49,61});
	idleSadLeft.PushBack({ 303,415,49,61 });
	idleSadLeft.PushBack({ 364,415,49,61 });
	idleSadLeft.PushBack({ 426,414,49,61 });

	//Movimiento
	rightMiddle.PushBack({ 370, 75, 49, 61 });
	rightMiddle.PushBack({ 316, 75, 49, 61 });
	rightMiddle.PushBack({ 255, 75, 49, 61 });
	rightMiddle.PushBack({ 193, 75, 49, 61 });
	rightMiddle.PushBack({ 127, 75, 49, 61 });
	rightMiddle.PushBack({ 64,75, 49, 61 });
	rightMiddle.PushBack({ 0, 75, 49, 61 });
	
	rightHappy.PushBack({ 371,282,49,61 });
	rightHappy.PushBack({ 317,282,49,61 });
	rightHappy.PushBack({ 256,282,49,61 });
	rightHappy.PushBack({ 194,282,49,61 });
	rightHappy.PushBack({ 128,282,49,61 });
	rightHappy.PushBack({ 65,282,49,61 });
	rightHappy.PushBack({ 1,282,49,61 });

	rightSad.PushBack({ 370,489,49,61 });
	rightSad.PushBack({ 316,489,49,61 });
	rightSad.PushBack({ 255,489,49,61 });
	rightSad.PushBack({ 193,489,49,61 });
	rightSad.PushBack({ 127,489,49,61 });
	rightSad.PushBack({ 64,489,49,61 });
	rightSad.PushBack({ 0,489,49,61 });

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

	idleSadDown.PushBack({499,274,31,60});
	idleSadDown.PushBack({663,274,31,60});
	idleSadDown.PushBack({ 499,274,31,60 });


	idleMiddleDown.PushBack({504,477,31,61});
	idleMiddleDown.PushBack({ 548, 477, 31,61});
	idleMiddleDown.PushBack({590,477,31,61});

	idleHappyDown.PushBack({493, 207, 31, 61});
	idleHappyDown.PushBack({ 537, 207, 31, 61 });
	idleHappyDown.PushBack({ 578, 207, 31, 61 });

	downHappy.PushBack({ 492,139,31,61 });
	downHappy.PushBack({ 536,138,31,61 });
	downHappy.PushBack({ 577,138,31,61 });
	downHappy.PushBack({ 614,138,31,61 });
	downHappy.PushBack({ 656,138,31,61 });
	downHappy.PushBack({ 699,138,31,61 });

	downSad.PushBack({ 500,342,31,61 });
	downSad.PushBack({ 543,273,31,61 });
	downSad.PushBack({ 584,273,31,61 });
	downSad.PushBack({ 620,273,31,61 });
	downSad.PushBack({ 656,273,31,61 });
	downSad.PushBack({ 706,274,31,61 });

	downMiddle.PushBack({ 503,409,31,61 });
	downMiddle.PushBack({ 547,408,31,61 });
	downMiddle.PushBack({ 588,408,31,61 });
	downMiddle.PushBack({ 626,408,31,61 });
	downMiddle.PushBack({ 668,409,31,61 });
	downMiddle.PushBack({ 710,408,31,61 });

	idleUp.PushBack({ 488, 69, 31, 61 });
	idleUp.PushBack({ 532, 68, 31, 61 });
	idleUp.PushBack({ 577, 68, 31, 61 });

	Up.PushBack({ 487, 0, 31, 61 });
	Up.PushBack({ 532, 0, 31, 61 });
	Up.PushBack({ 577, 0, 31, 61 });
	Up.PushBack({ 622, 0, 31, 61 });
	Up.PushBack({ 667, 0, 31, 61 });
	Up.PushBack({ 712, 0, 31, 61 });


	idleMiddleRight.speed = idleMiddleLeft.speed = idleHappyRight2.speed = idleHappyLeft.speed = idleSadRight.speed= idleSadLeft.speed = 0.15;
	rightMiddle.speed = rightHappy.speed = rightSad.speed = 0.15;
	leftMiddle.speed = leftHappy.speed = leftSad.speed = 0.15;
	downMiddle.speed = downHappy.speed = downSad.speed = 0.15;
	idleUp.speed = idleHappyDown.speed = idleMiddleDown.speed = idleSadDown.speed = 0.15;
	Up.speed = 0.15;
	

}

ModulePlayer::~ModulePlayer()
{}

// Load assets
bool ModulePlayer::Start()
{
	LOG("Loading player");

	graphics = App->textures->Load("rtype/Sprites_Big.png");
	graphicsLife = App->textures->Load("rtype/superPower.png");
	shootFX = App->audio->LoadFX("Audios/sound_effects/shoot.wav");

	destroyed = false;
	position.x = 150;
	position.y = 120;
	personality = 0;
	col = App->collision->AddCollider({position.x + 2, position.y - 5, 45,56}, COLLIDER_PLAYER, this);

	current_animation = &idleHappyRight2;
	Combocount = 0;

	lvl = 1;
	superpower = 3;

	shoot = 0;

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
	if (App->baseball_field->color >= 0 && App->baseball_field->color <= 39)
	{
		personality = 0;
	}
	else if (App->baseball_field->color >= 40 && App->baseball_field->color <= 59)
	{
		personality = 1;
	}
	else
	{
		personality = 2;
	}

	if (App->level_selector->lvlselector == true)
	{
		if (personality == 0)
			current_animation = &idleHappyRight2;
		else if (personality == 1)
			current_animation = &idleMiddleRight;
		else
			current_animation = &idleSadRight;
		if (lvl == 1) {
			position.x = 101;
			position.y = 370;
		}
		else if (lvl == 2) {
			position.x = 574;
			position.y = 370;
		}
		if (lvl == 1 && App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_DOWN || App->input->dpadRight == KEY_STATE::KEY_REPEAT || App->input->joy_right == KEY_STATE::KEY_REPEAT)
			lvl = 2;
		if (lvl == 2 && App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_DOWN || App->input->dpadLeft == KEY_STATE::KEY_REPEAT || App->input->joy_left == KEY_STATE::KEY_REPEAT)
			lvl = 1;

	}

	else {
		int speed = 4;

		//Dash
		if ((App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT || App->input->dpadLeft == KEY_STATE::KEY_REPEAT || App->input->joy_left == KEY_STATE::KEY_REPEAT) && collA == false)
		{
			if (personality == 0)
				current_animation = &leftHappy;
			else if (personality == 1)
				current_animation = &leftMiddle;
			else
				current_animation = &leftSad;
				
			position.x -= speed;
			if (position.x < App->render->camera.x + SCREEN_WIDTH / 2) {
				if (App->render->camera.x > 0) {
					App->render->camera.x -= speed;
				}
			}



		}

		if ((App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT || App->input->dpadRight == KEY_STATE::KEY_REPEAT || App->input->joy_right == KEY_STATE::KEY_REPEAT) && collD == false)
		{
			if (personality == 0)
				current_animation = &rightHappy;
			else if (personality == 1)
				current_animation = &rightMiddle;
			else
				current_animation = &rightSad;
		
			position.x += speed;
			if (position.x > SCREEN_WIDTH / 2) {
				if (App->render->camera.x < 398) {
					App->render->camera.x += speed;
				}

			}


		}
		if ((App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_UP || App->input->dpadRight == KEY_STATE::KEY_UP || App->input->joy_right == KEY_STATE::KEY_UP) && collD == false)
		{
			if (personality == 0)
				current_animation = &idleHappyRight2;
			else if (personality == 1)
				current_animation = &idleMiddleRight;
			else
				current_animation = &idleSadRight;

		}

		if ((App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT || App->input->dpadDown == KEY_STATE::KEY_REPEAT || App->input->joy_down == KEY_STATE::KEY_REPEAT) && collS == false)
		{
			position.y += speed;

			if (personality == 0)
				current_animation = &downHappy;
			else if (personality == 1)
				current_animation = &downMiddle;
			else
				current_animation = &downSad;
				


			if (position.y > SCREEN_HEIGHT / 2) {
				if (App->render->camera.y < 300 && lvl == 1) {
					App->render->camera.y += speed;
				}
				else if (App->render->camera.y < 380 && lvl == 2) {
					App->render->camera.y += speed;
				}
			}


		}
		if ((App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_UP || App->input->dpadDown == KEY_STATE::KEY_UP || App->input->joy_down == KEY_STATE::KEY_UP) && collS == false)
		{

			if (personality == 0)
				current_animation = &idleHappyDown;
			else if (personality == 1)
				current_animation = &idleMiddleDown;
			else
				current_animation = &idleSadRight;

		}

		if ((App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_REPEAT || App->input->dpadUp == KEY_STATE::KEY_REPEAT || App->input->joy_up == KEY_STATE::KEY_REPEAT) && collW == false)
		{
			position.y -= speed;

			current_animation = &Up;

			if (position.y < 1000 / 2) {
				if (App->render->camera.y > 0) {
					App->render->camera.y -= speed;
				}
			}

		}
		if ((App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_UP || App->input->dpadUp == KEY_STATE::KEY_UP || App->input->joy_up == KEY_STATE::KEY_UP) && collW == false)
		{
			current_animation = &idleUp;
		}


		if (App->input->keyboard[SDL_SCANCODE_UP] == KEY_STATE::KEY_REPEAT || App->input->buttonY == KEY_STATE::KEY_REPEAT) {
			if (shoot > 10) {
				App->particles->AddParticle(App->particles->laser_up, position.x + 4, position.y - 30, COLLIDER_PLAYER_SHOT);
				shoot = 0;
			}
			if (App->input->keyboard[SDL_SCANCODE_LCTRL] == KEY_STATE::KEY_DOWN && superpower > 0 || App->input->buttonRB == KEY_STATE::KEY_DOWN && superpower > 0 || App->input->buttonLB == KEY_STATE::KEY_DOWN && superpower > 0)
			{
				App->particles->AddParticle(App->particles->big_laser_up, position.x - 4, position.y - 30, COLLIDER_PLAYER_SHOT);
				superpower -= 1;
			}
			current_animation = &Up;
			App->audio->PlayFX(shootFX);
		}

		if (App->input->keyboard[SDL_SCANCODE_DOWN] == KEY_STATE::KEY_REPEAT || App->input->buttonA == KEY_STATE::KEY_REPEAT) {
			if (shoot > 10) {
				App->particles->AddParticle(App->particles->laser_down, position.x + 4, position.y + 30, COLLIDER_PLAYER_SHOT);
				shoot = 0;
			}
			if (App->input->keyboard[SDL_SCANCODE_LCTRL] == KEY_STATE::KEY_DOWN && superpower > 0 || App->input->buttonRB == KEY_STATE::KEY_DOWN && superpower > 0 || App->input->buttonLB == KEY_STATE::KEY_DOWN && superpower > 0)
			{
				App->particles->AddParticle(App->particles->big_laser_down, position.x - 4, position.y + 30, COLLIDER_PLAYER_SHOT);
				superpower -= 1;
			}
			if (personality == 0)
				current_animation = &idleHappyDown;
			else if (personality == 1)
				current_animation = &idleMiddleDown;
			else
				current_animation = &idleSadDown;
			App->audio->PlayFX(shootFX);
		}

		if (App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT || App->input->buttonB == KEY_STATE::KEY_REPEAT) {
			if (shoot > 10) {
				App->particles->AddParticle(App->particles->laser, position.x + 20, position.y + 15, COLLIDER_PLAYER_SHOT);
				shoot = 0;
			}
			if (App->input->keyboard[SDL_SCANCODE_LCTRL] == KEY_STATE::KEY_DOWN && superpower > 0 || App->input->buttonRB == KEY_STATE::KEY_DOWN && superpower > 0 || App->input->buttonLB == KEY_STATE::KEY_DOWN && superpower > 0)
			{
				App->particles->AddParticle(App->particles->big_laser, position.x + 20, position.y + 12, COLLIDER_PLAYER_SHOT);
				superpower -= 1;
			}
			if (personality == 0)
				current_animation = &idleHappyRight2;
			else if (personality == 1)
				current_animation = &idleMiddleRight;
			else
				current_animation = &idleSadRight;
			App->audio->PlayFX(shootFX);
		}

		if (App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_REPEAT || App->input->buttonX == KEY_STATE::KEY_REPEAT) {
			if (shoot > 10) {
				App->particles->AddParticle(App->particles->laser_left, position.x - 20, position.y + 15, COLLIDER_PLAYER_SHOT);
				shoot = 0;
			}
			if (App->input->keyboard[SDL_SCANCODE_LCTRL] == KEY_STATE::KEY_DOWN && superpower > 0 || App->input->buttonRB == KEY_STATE::KEY_DOWN && superpower > 0 || App->input->buttonLB == KEY_STATE::KEY_DOWN && superpower > 0)
			{
				App->particles->AddParticle(App->particles->big_laser_left, position.x - 20, position.y + 12, COLLIDER_PLAYER_SHOT);
				superpower -= 1;
			}
			if (personality == 0)
				current_animation = &idleHappyLeft;
			else if (personality == 1)
				current_animation = &idleMiddleLeft;
			else
				current_animation = &idleSadLeft;
			App->audio->PlayFX(shootFX);
		}



		/*if (App->input->keyboard[SDL_SCANCODE_LCTRL] == KEY_STATE::KEY_DOWN && superpower > 0 || App->input->buttonRB == KEY_STATE::KEY_DOWN && superpower > 0)
		{
			if (superpower != 0)
			{
				if (App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT)App->particles->AddParticle(App->particles->big_laser_left, position.x - 20, position.y + 12, COLLIDER_PLAYER_SHOT);
				if (App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT)	App->particles->AddParticle(App->particles->big_laser_down, position.x - 4, position.y + 30, COLLIDER_PLAYER_SHOT);
				if (App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT)	App->particles->AddParticle(App->particles->big_laser, position.x + 20, position.y + 12, COLLIDER_PLAYER_SHOT);
				if (App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_REPEAT)	App->particles->AddParticle(App->particles->big_laser_up, position.x - 4, position.y - 30, COLLIDER_PLAYER_SHOT);

				if (App->input->buttonB == KEY_STATE::KEY_REPEAT)
					App->particles->AddParticle(App->particles->big_laser, position.x + 20, position.y + 12, COLLIDER_PLAYER_SHOT);

				if (App->input->buttonX == KEY_STATE::KEY_REPEAT)
					App->particles->AddParticle(App->particles->big_laser_left, position.x - 20, position.y + 12, COLLIDER_PLAYER_SHOT);

				if (App->input->buttonA == KEY_STATE::KEY_REPEAT)
					App->particles->AddParticle(App->particles->big_laser_down, position.x - 4, position.y + 30, COLLIDER_PLAYER_SHOT);

				if (App->input->buttonY == KEY_STATE::KEY_REPEAT)
					App->particles->AddParticle(App->particles->big_laser_up, position.x - 4, position.y - 30, COLLIDER_PLAYER_SHOT);

				superpower -= 1;
			}
		}*/



		if (App->input->keyboard[SDL_SCANCODE_C] == KEY_STATE::KEY_DOWN && App->fade->IsFading() == false)
		{
			App->fade->FadeToBlack((Module*)App->baseball_field, (Module*)App->gameover);//que modulo se carga al morir
																							//death animation

		}

	}
	col->SetPos(position.x, position.y);

	// Draw everything --------------------------------------
	if (destroyed == false)
		App->render->Blit(graphics, position.x, position.y, &(current_animation->GetCurrentFrame()));

	collW = false;
	collA = false;
	collS = false;
	collD = false;

	for (int i = 0, x = 0; i < superpower; i++, x += 30)
	{
		App->render->Blit(graphicsLife, App->render->camera.x + x, App->render->camera.y + 650, &rectLife.GetCurrentFrame());
	}

	if (App->particles->Combo >= 15) {
		App->particles->Combo = 0;
		if (superpower <= 3) {
			superpower += 1;
		}
		App->baseball_field->color -= 10;
		Combocount++;
	}
	shoot += 1;
	return UPDATE_CONTINUE;
}


void ModulePlayer::OnCollision(Collider* c1, Collider* c2)
{
	if (c1->type == COLLIDER_PLAYER && (c2->type == COLLIDER_WALL || c2->type == COLLIDER_TOWER)) {
	
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