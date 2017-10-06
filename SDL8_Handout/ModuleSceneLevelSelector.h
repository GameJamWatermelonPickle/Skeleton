#ifndef __MODULESCENELEVELSELECTOR_H__
#define __MODULESCENELEVELSELECTOR_H__

#include "Module.h"

struct SDL_Texture;

class ModuleSceneLevelSelector : public Module
{
public:
	ModuleSceneLevelSelector();
	~ModuleSceneLevelSelector();

	bool Start();
	update_status Update();
	bool CleanUp();

public:
	
	SDL_Texture* background = nullptr;
	SDL_Texture* stars = nullptr;
};

#endif // __MODULESCENESPACE_H__