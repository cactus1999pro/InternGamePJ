#include "BaseObject.h"
#include "StaticObject.h"
#include "DynamicObject.h"
#include "Tree.h"
#include "House.h"
#include "Car.h"
#include "Motorbike.h"
#include<list>
#include<iostream>

using namespace std;
int main()
{
	list<BaseObject*> listObj;
	listObj.push_back(new Tree(1, "Apple", 1, 2));
	listObj.push_back(new House(2, "Wooden", 3, 4));
	listObj.push_back(new Car(3, "Posche", 5, 6));
	listObj.push_back(new Motorbike(4, "Yamaha", 7, 8));



	for(auto obj : listObj)
	{
		cout <<"obj id = " << obj->getId() <<" " << "obj name = " << obj->getName()<< " ";
		obj->printPosition();
		obj->move(13, 15);
	}
	
	for (auto obj : listObj) {
		delete obj;
	}
	listObj.clear();
	//Dump memory leaks
	_CrtDumpMemoryLeaks();
	return 0;
}


