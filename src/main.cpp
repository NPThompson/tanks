/* TAG main executable */

// N.P.Thompson Spring 2021
// noahpthomp@gmail.com

// opens a controller, which opens a top view and default model state
// runs the controller until it tells us to stop

#include<controller.h>



int main (int argc, char** argv)
{	
	EditorController controller;
	
	while(controller.run()){};
	
	return 0;
}
