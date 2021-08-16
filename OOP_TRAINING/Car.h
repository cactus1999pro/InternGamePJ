#pragma once

#include "DynamicObject.h"

class Car : public DynamicObject
{
public:
	Car();
	Car(int id, string name, int x, int y);
	~Car();
};
