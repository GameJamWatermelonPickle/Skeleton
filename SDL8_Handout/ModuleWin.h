#ifndef __MODULEWIN_H__
#define __MODULEWIN_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"

struct SDL_Texture;

class ModuleWin : public Module
{
public:
	ModuleWin();
	~ModuleWin();

	bool Start();
	update_status Update();
	bool CleanUp();

public:

	SDL_Texture* graphics = nullptr;
	SDL_Rect background;
	bool check = true;


};
#endif

