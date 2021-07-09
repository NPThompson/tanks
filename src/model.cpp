// TAG
// model.cpp

#include<model.h>
#include<algorithm>



using namespace std;




// deletes pointers!
// the return value is to let the list<> know what to exclude when resizing
// but when the list resizes, it doesn't destroy pointers, so this procedure 
// does that before those pointers are lost

// bool isDead(Object* O)
// {
	// if(O->dead())
	// {	
		// delete O;
		// return true;
	// }else 
		// return false;
// }



void Model::update (int df){

		// list<Object* > newObjs;
		// update all object state, collect newly made objects 
		// map([&](Object* O){ newObjs.splice( newObjs.end(), O->tick(df));});
		// add newly created objects to the Model
		// splice(end(), newObjs);

		forEach ([&](Object* O){O->update (df);});
		
		// remove dead objects
		
		// filter(elements, isDead);
		
		// To test collisions and make things react, we use the...
		// Handshake algorithm:
		// 		compute some F(i,j) for every i,j in collection, s.t:
		//			i != j
		//  		if F(i,j) has been computed, don't compute F(j,i)
		
		/*
		for(auto i = elements.begin(); i != elements.end(); i ++)
		{
			auto j = i;
			for(++j; j != end(); j ++)
				Object::react(*i, *j);
		}
		*/
}





void Model::spawn (Object* newObject)
{
	elements.push_front (newObject);
}