#include "Globals.h"
#include "Application.h"
#include "ModuleRender.h"
#include "Audio.h"

#include "SDL/include/SDL.h"
#include "SDL_mixer/include/SDL_mixer.h"
#pragma comment( lib, "SDL_mixer/libx86/SDL2_mixer.lib" )

ModuleAudio::ModuleAudio() : Module()
{
}

// Destructor
ModuleAudio::~ModuleAudio()
{
}

// Called before render is available
bool ModuleAudio::Init()
{
	bool ret = true;
	SDL_Init(0);
	SDL_InitSubSystem(SDL_INIT_AUDIO);
	Mix_Init(MIX_INIT_OGG);
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
	Mix_AllocateChannels(MAX_FX);

	return ret;
}


// Called before q	uitting
bool ModuleAudio::CleanUp()
{
	UnloadMusic();
	Mix_CloseAudio();
	Mix_ChannelFinished(0);
	Mix_Quit();
	SDL_QuitSubSystem(SDL_INIT_AUDIO);
	return true;
}

bool ModuleAudio::LoadMusic(const char* path) {

	music = Mix_LoadMUS(path);	
	Mix_PlayMusic(music, -1);

	return true;
}

bool ModuleAudio::UnloadMusic() {
	Mix_FreeMusic(music);
	music = nullptr;
	Mix_HaltMusic();
	return true;
}

bool ModuleAudio::UnloadFX(uint FXname)
{
	bool ret = false;

	if (fx[FXname] != nullptr) {
		Mix_FreeChunk(fx[FXname]);
		fx[FXname] = nullptr;
		ret = true;
		last_fx--;
	}
	return true;
}



uint ModuleAudio::LoadFX(const char* path) {

	uint ret = 0;

	Mix_Chunk* audio = Mix_LoadWAV(path);

	if (audio == nullptr) {
		LOG("Cannot load WAV.")
	}
	else {
		fx[last_fx] = audio;
		ret = last_fx++;
		if (last_fx == MAX_FX) {
			last_fx = 0;
			ret = last_fx;
		}
	}

	return ret;


}


bool ModuleAudio::PlayFX(uint FXname) {

	if (fx[FXname] != nullptr) {
		Mix_PlayChannel(-1, fx[FXname], 0);
		if (Mix_PlayChannel(-1, fx[FXname], 0) == -1) {
			LOG("Mix_PlayChannel: %s\n", Mix_GetError());
		}
		ret = true;
	}
	return true;
}