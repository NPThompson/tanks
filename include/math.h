// math.h
#pragma once



#include<glm/glm.hpp>



static const double pi = 3.1415926535897;



typedef glm::vec<2, int>   coord;
typedef glm::vec<2, float> point;
typedef glm::vec<3, float> color;  // keep in range [0,1]
typedef glm::vec<4, float> colorA; // with alpha channel



static const color green(0,1,0);
static const color red  (1,0,0);
static const color blue (0,0,1);
static const color black(0,0,0);
static const color white(1,1,1);

#define EXPAND_POINT(POINT) POINT.x, POINT.y
#define EXPAND_COORD(COORD) EXPAND_POINT(POINT)
#define EXPAND_COLOR(COLOR) COLOR.x, COLOR.y, COLOR.z
#define EXPAND_COLOR_A(COLOR_A) COLOR_A.x, COLOR_A.y, COLOR_A.z, COLOR_A[3]



float signum(float f);



point polarToCartesian(float,float);


// brings 'current' closer to 'stable' by step (linear) 
float stepConverge(float current, float step, float stable = 0.0);
 
 
 
point rotate(point p, float theta);


 
struct rect
{
	rect(point,point);
	
	point position,size;
	
	// for collisions, negative w or h means that 
	// two hboxes do not overlap
	bool overlaps(); 
};



int trinary(float input, float tolerance = 0.0);



float calcAngle (point);