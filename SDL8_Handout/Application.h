#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include "Globals.h"

#define NUM_MODULES 16



class ModuleWindow;
class ModuleRender;
class ModuleInput;
class ModuleTextures;
class ModuleAudio;
class ModuleParticles;
class ModuleSceneIntro;
class ModuleSceneLevelSelector;
class ModuleSceneBaseballField;
class ModuleSceneGirl;
class ModulePlayer;
class ModuleFadeToBlack;
class ModuleCollision;
class ModuleEnemies;
class ModuleEnd;
class ModuleWin;
class Module;


class Application
{
public:

	Module* modules[NUM_MODULES];
	ModuleWindow* window;
	ModuleRender* render;
	ModuleInput* input;
	ModuleTextures* textures;
	ModuleAudio* audio;
	ModuleSceneIntro* scene_intro;
	ModuleSceneLevelSelector* level_selector;
	ModuleSceneBaseballField* baseball_field;
	ModuleSceneGirl* girl;
	ModuleCollision* collision;
	ModulePlayer* player;
	ModuleFadeToBlack* fade;
	ModuleParticles* particles;
	ModuleEnemies* enemies;
	ModuleWin* win;
	ModuleEnd* gameover;

public:

	Application();
	~Application();

	bool Init();
	update_status Update();
	bool CleanUp();

};

// Global var made extern for Application ---
extern Application* App;

#endif // __APPLICATION_H__