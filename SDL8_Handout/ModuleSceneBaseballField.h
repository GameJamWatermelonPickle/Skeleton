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
	uint fx = 0;
};

#endif // __MODULESCENEINTRO_H__