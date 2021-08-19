#include "StateContext.h"
#include"LockedState.h"
#include<string>

StateContext::StateContext()
{
	state = new LockedState();
}
void StateContext::setNewState(StateBase* newState)
{
	state = newState;
}
void StateContext::write_state()
{
	state->write_state(this);
}


