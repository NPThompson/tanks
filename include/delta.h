// delta.h
#pragma once



#include<chrono>



// two procedures for determining elapsed time or frames
class delta
{
	private:
		static constexpr double framesPerSecond = 40.0;
		static constexpr double millisPerFrame  = 1000.0/framesPerSecond;

		

	public:
		static double time();
		static int frames();
};