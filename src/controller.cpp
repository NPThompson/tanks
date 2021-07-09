// controller.cpp



#include<delta.h>
#include<controller.h>
#include<tank.h>

#include<input.h>



EditorController::EditorController()
{
	Object *p1 = new Tank();
	
	state.spawn(p1);

	selectedObject = p1;
} 



bool EditorController::run()
{
	int df = delta::frames ();

	if(df > 0)
	{
		state.update(delta::frames());
		topView.show(state);
	}

	if(playing)
	{
		Tank *selectedTank = (Tank*)selectedObject;
		
		if(KeyDown(RIGHT))
			selectedTank->turnTrack(-1.0);

		if(KeyDown(LEFT))
			selectedTank->turnTrack(1.0);

		if(KeyDown(A))
			selectedTank->turnTurret(-1.0);

		if(KeyDown(D))
			selectedTank->turnTurret(1.0);
		
		if(KeyDown(UP))
			selectedTank->move(1.0);
	}
	
	SDL_Event ev;
	SDL_PollEvent(&ev);
	if(ev.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
		return false;
	
	return true;
}