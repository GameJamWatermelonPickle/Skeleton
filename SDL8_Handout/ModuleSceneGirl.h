#ifndef __MODULESCENEGIRL_H__
#define __MODULESCENEGIRL_H__

#include "Module.h"

struct SDL_Texture;

class ModuleSceneGirl: public Module
{
public:
	ModuleSceneGirl();
	~ModuleSceneGirl();

	bool Start();
	update_status Update();
	bool CleanUp();


public:

	SDL_Texture* background = nullptr;
	SDL_Texture* background2 = nullptr;
	SDL_Texture* background3 = nullptr;
	SDL_Rect R;
	uint fx = 0;
	uint respawn;
	uint cont;
	uint random[4];
	uint death = 0;
};

#endif
