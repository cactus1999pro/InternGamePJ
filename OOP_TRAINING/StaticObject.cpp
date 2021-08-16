#include"StaticObject.h"
#include<iostream>
using namespace std;

StaticObject::StaticObject()
{
}

StaticObject::StaticObject(int id, string name, int x, int y) : BaseObject(id, name, x, y)
{
}
StaticObject::~StaticObject()
{
}


void StaticObject::move(int x, int y)
{
	cout << "This object can not be moved" << endl;
}