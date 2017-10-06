#ifndef __MODULEEND_H__
#define __MODULEEND_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"

struct SDL_Texture;

class ModuleEnd : public Module
{
public:
	ModuleEnd();
	~ModuleEnd();

	bool Start();
	update_status Update();
	bool CleanUp();

public:

	SDL_Texture* graphics = nullptr;
	SDL_Rect background;
	bool check = true;


};
#endif
