// Paper Airplane
// delta.cpp



#include<delta.h>



using namespace std::chrono;



double delta::time()
{
  static time_point<high_resolution_clock> prev;
	auto     cur  = high_resolution_clock::now();
	long int rv   = (cur - prev).count();
			 prev = cur;
  return rv/1000000.0;
}	



int delta::frames()
{
  static bool firstTime = true;
  static double time_bank = 0.0;

  time_bank += time();
  
  if(time_bank < 0)
	  time_bank = 0;
  
  int ret = 0;
  while(time_bank > millisPerFrame)
	{
	  time_bank -= millisPerFrame;
	  ret ++;
	}
  
  return ret;
}
