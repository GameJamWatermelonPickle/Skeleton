#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include "Globals.h"

#define NUM_MODULES 15



class ModuleWindow;
class ModuleInput;
class ModuleTextures;
class ModuleRender;
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
class ModuleAudio;
class Module;


class Application
{
public:

	Module* modules[NUM_MODULES];
	ModuleWindow* window;
	ModuleRender* render;
	ModuleInput* input;
	ModuleTextures* textures;
	ModuleSceneIntro* scene_intro;
	ModuleSceneLevelSelector* level_selector;
	ModuleSceneBaseballField* baseball_field;
	ModuleSceneGirl* girl;
	ModuleCollision* collision;
	ModulePlayer* player;
	ModuleFadeToBlack* fade;
	ModuleParticles* particles;
	ModuleEnemies* enemies;
	ModuleEnd* gameover;
	ModuleAudio* audio;

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