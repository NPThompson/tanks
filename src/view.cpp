//tanks
// draw.cpp



#include<SDL2/SDL_image.h>


#include<stdio.h>
#include<view.h>
#include<list>
#include<math.h>
#include<tank.h>





View::View(const char* title, coord size, float scale):
	mainWindow (title, size, point(scale,scale))
{
}
		

// shows the data in a minimalist style, using only lines
void View::showOutlines (Object* theObject)
{
	Tank* theTank = (Tank*)theObject;

	mainWindow.setColor (green);
	
	// draw turret
	mainWindow.drawCircle (theTank->getPosition(), 10);
	mainWindow.drawLine (theTank->getPosition() + polarToCartesian(theTank->getTurretHeading(), 10),
						 theTank->getPosition() + polarToCartesian(theTank->getTurretHeading(), 20));
	
	// draw tracks
	mainWindow.drawRect (theTank->getPosition(), point(10,35), theTank->getTrackHeading());
}


// shows the model using animated sprite graphics, loaded from file
void View::showAnimated (Object* theObject)
{
	// mainWindow.drawSprite (...)
}



void View::show (Model& theModel)
{
	mainWindow.setColor (black);
	mainWindow.clear ();
	
	theModel.forEach([&](Object* o){show(o);});
	
	mainWindow.flip ();
}