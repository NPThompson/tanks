#pragma once



#include<SDL2/SDL_events.h>

typedef SDL_Event Event;
 

Event PollEvent();

Event WaitEvent();



#define KeyDown(_KEY_) isKeyPressed(SDL_SCANCODE_##_KEY_)



#define DoUntilEvent( _ENDEVENT_ ) for(Event _POLLEVENT_ = PollEvent(); _POLLEVENT_ != _ENDEVENT_; _POLLEVENT_ = PollEvent())
#define PollLoop for(Event event = PollEvent(); ; event = PollEvent())
#define WaitLoop for(Event event = WaitEvent(); ; event = WaitEvent())
#define OnEvent(EVENT)	if(event == SDL_##EVENT)


	
	
	
bool operator==(Event ev, SDL_EventType et);
bool operator==(Event ev, SDL_Scancode sc);
bool operator==(Event ev, SDL_WindowEventID wev);
// not equals implies unequals
template<typename e> bool operator!=(Event ev, e whatever)
{
	return !(ev == whatever);
}
	
bool isKeyPressed(SDL_Scancode);