#pragma once
#include"StateBase.h"
#include"LockedState.h"

class OpenedState : public StateBase
{
public:
	void write_state(StateContext* context);
};