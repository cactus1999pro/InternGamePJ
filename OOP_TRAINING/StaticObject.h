#pragma once
#include "BaseObject.h"
class StaticObject : public BaseObject
{
public:
	StaticObject();
	StaticObject(int id, string name, int x, int y);
	~StaticObject();
	void move(int x, int y);
};