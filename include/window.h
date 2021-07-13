// A basic SDL Renderer+Window pair
// manages the SDL state and accepts simple inputs like points and colors to draw primitives



#pragma once



#include<math.h>
#include<SDL2/SDL.h>
#include<SDL2/SDL_ttf.h>



class Window
{
	public:
		Window (const char*, coord, coord);
	
		void clear ();
		void flip  ();
		
		void setColor (color);
		void setColor (colorA);
		
		void drawCircle (point, float);
		void drawLine (point, point);
		void drawRect (point, point, float);
		void drawRect (point, point);
		
		void drawPath (point);
		
		void drawText(const char*, coord where = coord(0,0));
		
		// public service announcement
		void psa (const char*, coord where = coord(0,0), int millis = 500);

	private:
		
		// SDL does the actual work 
		SDL_Renderer *_Render;
		SDL_Window   *_Window;
		
		// for drawing arbitrary closed figures conveniently as a sequence of drawPath() commands
		bool resetPath;
		point pathPoint;
		
		// for text!
		TTF_Font* font;
};