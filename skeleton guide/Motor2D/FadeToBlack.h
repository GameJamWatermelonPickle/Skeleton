#ifndef __MODULEFADETOBLACK_H__
#define __MODULEFADETOBLACK_H__

#include "j1Module.h"
#include "SDL\include\SDL_rect.h"

class ModuleFadeToBlack : public j1Module
{
public:
	ModuleFadeToBlack();
	~ModuleFadeToBlack();

	bool Awake(pugi::xml_node&);
	bool Update(float);
	bool FadeToBlack(j1Module* module_off, j1Module* module_on, float time = 2.0f);
	bool IsFading() const;

private:

	enum fade_step
	{
		none,
		fade_to_black,
		fade_from_black
	} current_step = fade_step::none;

	Uint32 start_time = 0;
	Uint32 total_time = 0;
	SDL_Rect screen;

public:
	j1Module* moff;
	j1Module* mon;
};

#endif //__MODULEFADETOBLACK_H__#pragma once
