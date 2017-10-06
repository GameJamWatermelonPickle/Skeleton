#ifndef __ModulePlayer_H__
#define __ModulePlayer_H__

#include "Module.h"
#include "Animation.h"
#include "p2Point.h"

struct SDL_Texture;
struct Collider;

class ModulePlayer : public Module
{
public:
	ModulePlayer();
	~ModulePlayer();

	bool Start();
	update_status Update();
	bool CleanUp();
	void OnCollision(Collider* c1, Collider* c2);
	uint lvl;

	//colisions wall

	bool collW = false;
	bool collA = false;
	bool collS = false;
	bool collD = false;

public:

	SDL_Texture* graphics = nullptr;
	Animation* current_animation = nullptr;
	Animation idleHappy;
	Animation idleMiddleRight;
	Animation idleMiddleLeft;
	Animation idleMiddleDown;
	Animation idleSad;
	Animation leftHappy;
	Animation leftMiddle;
	Animation leftSad;
	Animation rigthHappy;
	Animation rigthMiddle;
	Animation rigthSad;
	Animation downHappy;
	Animation downMiddle;
	Animation downSad;
	Animation Up;
	iPoint position;
	Collider* col;
	bool destroyed = false;
};

#endif