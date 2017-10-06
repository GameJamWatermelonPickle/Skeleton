#ifndef __MODULESCENEBASEBALLFIELD_H__
#define __MODULESCENEBASEBALLFIELD_H__

#include "Module.h"

struct SDL_Texture;

class ModuleSceneBaseballField : public Module
{
public:
	ModuleSceneBaseballField();
	~ModuleSceneBaseballField();

	bool Start();
	update_status Update();
	bool CleanUp();


public:

	SDL_Texture* background = nullptr;
	SDL_Rect R;
	uint fx = 0;
	uint color = 0;
	uint death = 0;
};

#endif // __MODULESCENEINTRO_H__