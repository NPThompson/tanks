#include<math.h>
#include<glm/gtx/vector_angle.hpp>



int trinary(float input, float tolerance)
{
	if(input < -tolerance)
		return -1;
	if(input > tolerance)
		return 1;
	else return 0;
}



point polarToCartesian(float angle, float length)
{
	return point (sin(angle) * length, cos(angle) * length);
}



rect::rect(point a, point b)
{
	position = a;
	size = b;
}



float stepConverge(float current, float step, float stable)
{
	if(current > step)
		current -= step;
	else
		if(current < -step)
		current += step;
	else
		current = stable;
	
	return current;
}



point rotate(point p, float radians)
{
	float angle = atan(p.y/p.x);
	
	float magnitude = sqrt( p.x * p.x + p.y * p.y );
	angle += radians;
	return polarToCartesian(angle, magnitude);
}



float signum(float f)
{
	if(f > 1.0)
		return 1.0;
	if(f < -1.0)
		return -1.0;
	return f;
}



bool rect::overlaps()
{
	return size.x > 0 && size.y > 0;
}



float calcAngle (point P)
{
	return atan(P.y/P.x);
}