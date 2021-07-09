// input.cpp
#include<input.h>



bool isKeyPressed(SDL_Scancode key)
{
	static const Uint8* kbd = NULL;
	if(kbd == NULL)
		kbd = SDL_GetKeyboardState(NULL);

	return kbd[key];
}



Event PollEvent()
{
	SDL_Event ev;
	SDL_PollEvent(&ev);
	return ev;
}



Event WaitEvent()
{
	SDL_Event ev;
	SDL_WaitEvent(&ev);
	return ev;
}


	
bool operator==(SDL_Event ev, SDL_EventType et)
{
	return ev.type == et;
}


	
bool operator==(Event ev, SDL_WindowEventID wev)
{
	return ev.type == SDL_WINDOWEVENT && ev.window.event == wev;
}



bool operator==(Event ev, SDL_Scancode sc)
{
	return (ev.type == SDL_KEYDOWN || ev.type == SDL_KEYUP) && ev.key.keysym.scancode == sc;
}
