#pragma once
#include<math.h>
#include<list>
#include<algorithm>
#include<object.h>



using namespace std;



// a collection of objects that exist in the same space
class Model 
{
	public:
		// update the model for df number of frames
		void update(int df=1);
		
		// do something to each element
		template<typename F> void forEach(F procedure)
		{
			for_each(elements.begin(), elements.end(), procedure);
		}
		
		// create a new object
		void spawn(Object*);
	
		// remove an object
		void remove(Object*);
	
	private:
		list<Object*> elements;
};



template<typename T, typename F> void filter(T &collection, F procedure)
{
	auto end = std::remove_if(collection.begin(), collection.end(), procedure);
	collection.resize(std::distance(collection.begin(), end));
}