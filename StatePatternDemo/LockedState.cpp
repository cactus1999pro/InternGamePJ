#include"LockedState.h"
#include<iostream>
#include"StateContext.h"
using std::cout;
using std::endl;


void LockedState::write_state(StateContext* context)
{
	cout << "the door is being locked" << endl;
	context->setNewState(new ClosedState);
}
