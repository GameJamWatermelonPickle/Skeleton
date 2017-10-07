#ifndef __ModuleAudio_H__
#define __ModuleAudio_H__

#include "Module.h"
#include "Globals.h"
#include "SDL\include\SDL_audio.h"
#include "SDL_mixer/include/SDL_mixer.h"
#pragma comment( lib, "SDL_mixer/libx86/SDL2_mixer.lib" )


#define MAX_FX 100


class ModuleAudio : public Module
{
public:
	ModuleAudio();
	~ModuleAudio();

	bool Init();
	bool CleanUp();

	bool LoadMusic(const char* musicName);
	bool UnloadMusic();
	bool UnloadFX(uint FXname);
	uint LoadFX(const char* path);
	bool PlayFX(uint FXname);

private:

	Mix_Music* music = nullptr;
	Mix_Chunk* fx[MAX_FX];
	uint ret = 0;
	uint last_fx = 1;
};

#endif
