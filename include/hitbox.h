// hitbox.h
#pragma once



#include<math.h>



enum hbox_t
{
	rectangle = 0
};



class hbox
{
	public:
		hbox(coord);
		
		bool touching(hbox, point);
		rect overlap(hbox,point);
		
	private:
		hbox_t type;

		union{
			point rect_size;		
		};
};