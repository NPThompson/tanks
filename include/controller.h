// Controller.h



#pragma once
#include<view.h>
#include<model.h>



class EditorController
{
	public:
		EditorController();		
		bool run();
		
	private:
		View 	topView;
		Model 	state;
	
		// the Editor can do things directly to the selected Object
		Object* selectedObject;
		
		// if true, the user is 'playing' as the selected Object
		bool    playing;
};