#include "DynamicObject.h"

DynamicObject::DynamicObject()
{

}
DynamicObject::DynamicObject(int id, string name, int x, int y) :BaseObject(id, name, x, y)
{

}
DynamicObject::~DynamicObject()
{

}
void DynamicObject::move(int x, int y)
{
	this->x = x;
	this->y = y;
	cout << "the object have been moved to (" << this->x << "," << this->y << ")" << endl;
}





