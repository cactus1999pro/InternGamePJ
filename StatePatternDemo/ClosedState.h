#pragma once
#include"StateBase.h"
#include"OpenedState.h"

class ClosedState : public StateBase
{
public:
	 void write_state(StateContext* state);
};