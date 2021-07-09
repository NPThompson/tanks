#include<hitbox.h>



rect rect_overlap(rect A, rect B)
{
	rect overlap(point(0,0), point(0,0));
	
	double  x0 = 0.0, 
			x1 = B.position.x - A.position.x,
			w0 = A.size.x,
			w1 = B.size.x + (B.position.x - A.position.x);
	
	if(x1 > x0){
		overlap.position.x = x1;
		overlap.size.x = w0 - x1;
	}
	else{ 
		overlap.position.x = x0;
		overlap.size.x = w1 - x0;
	}
	
	
	x0 = 0.0;
	x1 = B.position.y - A.position.y;
	w0 = A.size.y;
	w1 = B.size.y + (B.position.y - A.position.y);

	if(x1 > x0){
		overlap.position.y = x1;
		overlap.size.y = w0 - x1;
	}
	else{ 
		overlap.position.y = x0;
		overlap.size.y = w1 - x0;
	}

	overlap.position = overlap.position + A.position;
	
	return overlap;
}



hbox::hbox(coord sz)
{
	type = hbox_t::rectangle;
	rect_size = sz;
}



bool hbox::touching(hbox other, point offset){
	rect _overlap = overlap(other,offset);
	return _overlap.size.x > 0 && _overlap.size.y > 0;
}



rect hbox::overlap(hbox other, point offset)
{	
	point p = point(0,0) - (rect_size/2.0f);
	rect A = {p, rect_size};
	
	p = offset - (other.rect_size/2.0f);
	rect B = {p, other.rect_size};
	
	return rect_overlap(A,B);
}
		