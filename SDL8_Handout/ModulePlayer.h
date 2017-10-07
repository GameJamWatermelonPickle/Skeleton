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
	int life= 3;
public:
	Animation rectLife;
	SDL_Texture* graphics = nullptr;
	SDL_Texture* graphicsLife = nullptr;
	Animation* current_animation = nullptr;

	Animation idleHappyRight2;
	Animation idleHappyLeft;

	Animation idleMiddleRight;
	Animation idleMiddleLeft;
	

	Animation idleSadRight;
	Animation idleSadLeft;
	Animation leftHappy;
	Animation leftMiddle;
	Animation leftSad;
	Animation rightHappy;
	Animation rightMiddle;
	Animation rightSad;
	Animation downHappy;
	Animation downMiddle;
	Animation downSad;
	Animation idleHappyDown;
	Animation idleMiddleDown;
	Animation idleSadDown;
	Animation idleUp;
	Animation Up;
	iPoint position;
	Collider* col;
	bool destroyed = false;
	uint personality; // 0 happy, 1 neutral, 2 sad
	uint superpower;
	uint Combocount;
	uint shoot;
	uint step;
};

#endif