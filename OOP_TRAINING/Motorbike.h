#pragma once

#include"DynamicObject.h"

class Motorbike : public DynamicObject
{
public:
	Motorbike();
	Motorbike(int id, string name, int x, int y);
	~Motorbike();
};