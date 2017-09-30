#ifndef __ModulePlayer_H__
#define __ModulePlayer_H__

#include "j1Module.h"
#include "Animation.h"
#include "p2Point.h"

struct SDL_Texture;


class ModulePlayer : public j1Module
{
public:
	ModulePlayer();
	~ModulePlayer();

	bool Start();
	bool Update();
	bool CleanUp();
	

public:

	SDL_Texture* graphics = nullptr;
	/*int font_score = -1;
	char score_text[10];
	uint score = 0;
	Animation* current_animation = nullptr;
	Animation idle;
	Animation up;
	Animation down;
	iPoint position;*/
	bool destroyed = false;
};

#endif