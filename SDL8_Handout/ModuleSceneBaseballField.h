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
	SDL_Texture* background2 = nullptr;
	SDL_Texture* background3 = nullptr;
	SDL_Rect R;
	uint fx = 0;
	uint color = 0;
	bool over = false;
	uint death = 0;
	uint random[4];
	uint cont = 0;
	bool check_audio = true;
	bool check_audio2 = true;
};

#endif // __MODULESCENEINTRO_H__