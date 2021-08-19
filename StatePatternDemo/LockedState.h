#pragma once

#include"StateBase.h"
#include"ClosedState.h"
class LockedState : public StateBase
{
public:
	void write_state(StateContext* context);
};