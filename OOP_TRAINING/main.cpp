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
	listObj.push_back(new Tree(1, "apple", 1, 2));
	listObj.push_back(new House(2, "wooden", 3, 4));
	listObj.push_back(new Car(3, "posche", 5, 6));
	listObj.push_back(new Motorbike(4, "Yamaha", 7, 8));

	return 0;
}


