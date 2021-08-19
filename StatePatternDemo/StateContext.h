#pragma once
#include"StateBase.h"
#include<string>
class StateBase;
class StateContext
{
private:
	StateBase* state;
public:
	StateContext();
	void setNewState(StateBase* newState);
	void write_state();
};