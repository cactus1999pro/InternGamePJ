#pragma once

#include "BaseObject.h"

class DynamicObject : public BaseObject
{
public:
	DynamicObject();
	DynamicObject(int id, string name, int x, int i);
	~DynamicObject();
	void move(int x, int y);
};