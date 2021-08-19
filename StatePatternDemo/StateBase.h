#pragma once
#include<string>
#include"StateContext.h"
using namespace std;
class StateContext;
class StateBase
{
public:
	virtual void write_state(StateContext* state);
};