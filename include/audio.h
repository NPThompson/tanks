#pragma once



#include<SDL2/SDL.h>
#include<SDL2/SDL_mixer.h>



enum snd
{
	pew = 0,
    count
};



enum mus
{
	rick = 0,
};



extern void play(snd s);



class Audio
{
	public:
		Audio();
		Audio(int c, int b = 1024, int ch = 2);
		
		void play(snd s);
		
		void playMusic(mus m);
		
		~Audio();
		
	private:
		int channels;
		Mix_Chunk* chunks[snd::count];
		Mix_Music* music;
};