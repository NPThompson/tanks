// Paper Airplane
// audio.cpp



#include<audio.h>



Audio::Audio(int c, int b, int ch)
{
	for(int i = 0; i < snd::count; i ++)
		chunks[i] = NULL;

	channels = c;	
	Mix_Init(0);
	Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, ch, b);

	// chunks[snd::pew] = Mix_LoadWAV("assets/pew.wav");
	
}



Audio::Audio()
{	
}



void Audio::play(snd s)
{
	Mix_PlayChannel(-1,
					chunks[s],
					0);	
}



void Audio::playMusic(mus m)
{
	Mix_PlayMusic(music,-1);
}



Audio::~Audio()
{
	for(int i = 0; i < snd::count; i ++)
	{
		if(chunks[i] != NULL)
			Mix_FreeChunk(chunks[i]);
	}
	Mix_Quit();
}