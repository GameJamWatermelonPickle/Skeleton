#include <math.h>
#include "Globals.h"
#include "Application.h"
#include "ModuleAudio.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModuleInput.h"
#include "ModuleSceneBaseballField.h"
#include "ModulePlayer.h"
#include "ModuleSceneGirl.h"

#include "SDL/include/SDL_timer.h"

ModuleParticles::ModuleParticles()
{
	for(uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
		active[i] = nullptr;

	laser.anim.PushBack({1, 2, 39, 21});
	laser.anim.PushBack({52, 2, 39, 21 });
	laser.anim.PushBack({ 104, 2, 39, 21 });
	laser.anim.speed = 0.2f;
	laser.speed.x = 7.5;
	laser.life = 3000;

	laser_left.anim.PushBack({ 1, 29, 39, 21 });
	laser_left.anim.PushBack({ 52, 29, 39, 21 });
	laser_left.anim.PushBack({ 104, 29, 39, 21 });
	laser_left.anim.speed = 0.2f;
	laser_left.speed.x = -7.5;
	laser_left.life = 3000;

	laser_up.anim.PushBack({ 37, 62, 21, 39 });
	laser_up.anim.PushBack({ 37, 113, 21, 39 });
	laser_up.anim.PushBack({ 37, 167, 21, 39 });
	laser_up.anim.speed = 0.2f;
	laser_up.speed.y = -7.5;
	laser_up.life = 3000;

	laser_down.anim.PushBack({ 3, 62, 21, 39 });
	laser_down.anim.PushBack({ 3, 113, 21, 39 });
	laser_down.anim.PushBack({ 3, 167, 21, 39 });
	laser_down.anim.speed = 0.2f;
	laser_down.speed.y = 7.5;
	laser_down.life = 3000;


	big_laser.anim.PushBack({ 250, 0, 64, 47 });
	big_laser.anim.PushBack({ 318, 2, 64, 47 });
	big_laser.anim.speed = 0.1f;
	big_laser.speed.x = 5;
	big_laser.life = 3000;

	big_laser_left.anim.PushBack({ 318, 50, 64, 47 });
	big_laser_left.anim.PushBack({ 250, 50, 64, 47 });
	big_laser_left.anim.speed = 0.1f;
	big_laser_left.speed.x = -5;
	big_laser_left.life = 3000;

	big_laser_up.anim.PushBack({ 242, 171, 47, 64 });
	big_laser_up.anim.PushBack({ 242, 103, 47, 64 });
	big_laser_up.anim.speed = 0.1f;
	big_laser_up.speed.y = -5;
	big_laser_up.life = 3000;

	big_laser_down.anim.PushBack({ 317, 103, 47, 64 });
	big_laser_down.anim.PushBack({ 317, 171, 47, 64 });
	big_laser_down.anim.speed = 0.1f;
	big_laser_down.speed.y = 5;
	big_laser_down.life = 3000;

	ghost_dead.anim.PushBack({112,278,46,46});
	ghost_dead.anim.PushBack({ 239,278,46,46 });
	ghost_dead.anim.PushBack({ 47,342,46,46});
	ghost_dead.anim.PushBack({ 176,341,46,46 });
	ghost_dead.anim.PushBack({ 304,342,46,46 });
	ghost_dead.anim.PushBack({ 111,406,46,46 });
	ghost_dead.life = 300;
	ghost_dead.anim.speed = 0.2f;



}

ModuleParticles::~ModuleParticles()
{}

// Load assets
bool ModuleParticles::Start()
{
	LOG("Loading particles");
	graphics = App->textures->Load("rtype/particles2.png");
	Combo = 0;
	// Load particles fx particle

	return true;
}

// Unload assets
bool ModuleParticles::CleanUp()
{
	LOG("Unloading particles");
	App->textures->Unload(graphics);

	// Unload fx

	for(uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
	{
		if(active[i] != nullptr)
		{
			delete active[i];
			active[i] = nullptr;
		}
	}

	return true;
}

// Update: draw background
update_status ModuleParticles::Update()
{
	for(uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
	{
		Particle* p = active[i];

		if(p == nullptr)
			continue;

		if(p->Update() == false)
		{
			delete p;
			active[i] = nullptr;
		}
		else if(SDL_GetTicks() >= p->born)
		{
			App->render->Blit(graphics, p->position.x, p->position.y, &(p->anim.GetCurrentFrame()));
			if(p->fx_played == false)
			{
				p->fx_played = true;
			}
		}
	}

	App->render->DrawQuad(App->baseball_field->R, 27, 27, 101, App->baseball_field->color);
	App->render->DrawQuad(App->girl->R, 27, 27, 101, App->baseball_field->color);

	if (App->input->keyboard[SDL_SCANCODE_Q] == KEY_DOWN && App->baseball_field->over == false)
		App->baseball_field->color += 10;
	

	return UPDATE_CONTINUE;
}

void ModuleParticles::AddParticle(const Particle& particle, int x, int y, COLLIDER_TYPE collider_type, Uint32 delay)
{
	for(uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
	{
		if(active[i] == nullptr)
		{
			Particle* p = new Particle(particle);
			p->born = SDL_GetTicks() + delay;
			p->position.x = x;
			p->position.y = y;
			if(collider_type != COLLIDER_NONE)
				p->collider = App->collision->AddCollider(p->anim.GetCurrentFrame(), collider_type, this);
			active[i] = p;
			break;
		}
	}
}

void ModuleParticles::OnCollision(Collider* c1, Collider* c2)
{
   	for(uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
	{
		// Always destroy particles that collide
		if(active[i] != nullptr && active[i]->collider == c1 && c1->type == COLLIDER_PLAYER_SHOT)
		{
			if (c2->type == COLLIDER_ENEMY)
				App->particles->AddParticle(App->particles->ghost_dead, c2->rect.x, c2->rect.y, COLLIDER_NONE, NULL);
			
			
	if (App->player->Combocount < 400) {
				Combo++;
				App->player->Combocount = 0;
			}
			
			delete active[i];
			active[i] = nullptr;
			break;
		}
	}
}

// -------------------------------------------------------------
// -------------------------------------------------------------

Particle::Particle()
{
	position.SetToZero();
	speed.SetToZero();
}

Particle::Particle(const Particle& p) : 
anim(p.anim), position(p.position), speed(p.speed),
fx(p.fx), born(p.born), life(p.life)
{}

Particle::~Particle()
{
	if (collider != nullptr)
		collider->to_delete = true;
}

bool Particle::Update()
{
	bool ret = true;

	if(life > 0)
	{
		if((SDL_GetTicks() - born) > life)
			ret = false;
	}
	else
		if(anim.Finished())
			ret = false;

	position.x += speed.x;
	position.y += speed.y;

	if(collider != nullptr)
		collider->SetPos(position.x, position.y);

	return ret;
}

