#include<Window.h>
#include<stdio.h>



Window::Window  (const char* title, coord size, coord scale)
{	
	_Window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, size.x, size.y, SDL_WINDOW_SHOWN);
	_Render = SDL_CreateRenderer(_Window,-1,SDL_RENDERER_ACCELERATED);
		SDL_RenderSetScale(_Render, scale.x, scale.y);
		SDL_RenderSetIntegerScale(_Render,SDL_TRUE);
		
	TTF_Init();
	
	const char* fontPath = "assets/font.ttf";
	printf("loading font: %s\n", fontPath);
	font = TTF_OpenFont(fontPath, 16);
	if(font == NULL)
		printf("failed to load font: %s\n", TTF_GetError());
}	



void Window::drawRect (point center, point size)
{
	
}



void Window::drawPath (point p)
{
	if(!resetPath)
		drawLine (pathPoint, p);

	pathPoint = p;
	resetPath = false;
}



void Window::drawRect (point center, point size, float angle)
{
	resetPath = true;
	
	drawPath (rotate( size/2.0f, angle - pi/4)     + center);
	drawPath (rotate( point(size.x/2.0f, -size.y/2.0f), angle + pi/4)       + center);
	drawPath (rotate( point(-size.x/2.0f, -size.y/2.0f), angle + pi * 3/4) + center);
	drawPath (rotate( point(-size.x/2.0f,size.y/2.0f), angle + pi * 5/4)   + center);
	drawPath (rotate( size/2.0f, angle - pi/4)     + center);
}



void Window::drawCircle (point position, float radius)
{
	point a,b;
	
	int arcs = 13;
	float quotient = (2 * pi) / arcs;
	
	int arc = 0;
	
	a.x = cos(arc * quotient);
	a.y = sin(arc * quotient);
		
	for(; arc <= arcs; arc++)
	{
		b = a;

		a.x = cos(arc * quotient);
		a.y = sin(arc * quotient);

		drawLine(position + a * radius, position + b * radius);		
	}
	
}



void Window::drawLine (point a, point b)
{
	SDL_RenderDrawLine (_Render, a.x, a.y, b.x, b.y);
}



void Window::flip ()
{	
	SDL_RenderPresent (_Render);
}



void Window::setColor (color c)
{
	c = c * 255.0f;
	SDL_SetRenderDrawColor (_Render, EXPAND_COLOR(c), 255);
}



void Window::setColor (colorA c)
{
	c = c * 255.0f;
	SDL_SetRenderDrawColor (_Render, EXPAND_COLOR_A(c));
}


void Window::clear ()
{
	SDL_RenderClear (_Render);
}



void Window::drawText(const char* text, coord where)
{
	SDL_Color c = {255,255,255};
	
	SDL_Surface* printSurf = TTF_RenderText_Solid (font, text, c);

	SDL_Texture* printTex  = SDL_CreateTextureFromSurface (_Render, printSurf);

	SDL_Rect dest = {where.x - printSurf->w/2, where.y - printSurf->h/2,printSurf->w, printSurf->h};
	
	SDL_RenderCopy(_Render, printTex, NULL, &dest); 

	SDL_FreeSurface (printSurf);
	SDL_DestroyTexture (printTex);
}