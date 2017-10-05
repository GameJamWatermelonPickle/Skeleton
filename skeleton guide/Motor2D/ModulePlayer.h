#ifndef __ModulePlayer_H__
#define __ModulePlayer_H__

#include "j1Module.h"
#include "Animation.h"
#include "p2Point.h"
#include "SDL\include\SDL.h"

struct SDL_Texture;
struct Collider;


class ModulePlayer : public j1Module
{
public:
	ModulePlayer();
	~ModulePlayer();

	bool Start();
	bool Update(float);
	bool CleanUp();
	

public:
	Collider* playerCollider;
	SDL_Texture* graphics = nullptr;
	SDL_Rect rectPlayer;
	Animation* current_animation = nullptr;
	Animation idle;
	Animation right;
	Animation left;
	Animation up;
	Animation down;
	fPoint position;

	bool destroyed = false;
};

#endif