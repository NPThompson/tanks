// TAG
// view.h


#pragma once
#include<model.h>
#include<window.h>
#include<SDL2/SDL.h>
#include<SDL2/SDL_ttf.h>
#include<list>
#include<math.h>



class View
{
	public:
		View (const char* title = ""
			   ,coord size  = coord(320,240)
			   ,float scale = 1.0);
		
		void show(Model&);
		
	private:
		void show (Object*);
		
		Window mainWindow;
};

