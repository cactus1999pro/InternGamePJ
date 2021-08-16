#include "BaseObject.h"
#include<iostream>
using namespace std;


BaseObject::BaseObject()
{
	this->id = 0;
	this->name = "none";
	this->x = 0;
	this->y = 0;
}

BaseObject::BaseObject(int id, string name, int x, int y)
{
	this->id = id;
	this->name = name;
	this->x = x;
	this->y = y;
}
BaseObject::~BaseObject()
{

}
void BaseObject::setId(int id)
{
	this->id = id;
}
int BaseObject::getId()
{
	return this->id;
}
void BaseObject::setName(string name)
{
	this->name = name;
}
string BaseObject::getName()
{
	return name;
}
void BaseObject::setX(int x)
{
	this->x = x;
}
int BaseObject::getX()
{
	return x;
}
void BaseObject::setY(int y)
{
	this->y = y;
}
int BaseObject::getY()
{
	return y;
}
void BaseObject::move(int x, int y)
{
	this->x = x;
	this->y = y;
}

void BaseObject::printPosition()
{
	cout << "Position" << this->x << " " << this->y << endl;
}
