#ifndef __ModuleInput_H__
#define __ModuleInput_H__

#include "Module.h"
#include "Globals.h"
#include "SDL\include\SDL_gamecontroller.h"
#include "SDL\include\SDL_scancode.h"


#define MAX_KEYS 300
#define MAX_BUTTONS 100

enum KEY_STATE
{
	KEY_IDLE = 0,
	KEY_DOWN,
	KEY_REPEAT,
	KEY_UP
};

class ModuleInput : public Module
{
public:
	
	ModuleInput();
	~ModuleInput();

	bool Init();
	update_status PreUpdate();
	bool CleanUp();

public:
	KEY_STATE keyboard[MAX_KEYS];
	SDL_GameController *controller = nullptr;
	SDL_GameController *controller2 = nullptr;
	SDL_Joystick *joy = nullptr;
	SDL_Joystick *joy2 = nullptr;

	KEY_STATE buttonA;
	KEY_STATE buttonB;
	KEY_STATE buttonY;
	KEY_STATE buttonStart;
	KEY_STATE dpadUp;
	KEY_STATE dpadDown;
	KEY_STATE dpadLeft;
	KEY_STATE dpadRight;
	KEY_STATE joy_up;
	KEY_STATE joy_down;
	KEY_STATE joy_left;
	KEY_STATE joy_right;

	KEY_STATE buttonA2;
	KEY_STATE buttonB2;
	KEY_STATE buttonStart2;
	KEY_STATE dpadUp2;
	KEY_STATE dpadDown2;
	KEY_STATE dpadLeft2;
	KEY_STATE dpadRight2;
	KEY_STATE joy_up2;
	KEY_STATE joy_down2;
	KEY_STATE joy_left2;
	KEY_STATE joy_right2;

};

#endif // __ModuleInput_H__