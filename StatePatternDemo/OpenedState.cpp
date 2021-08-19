#include"OpenedState.h"
#include<iostream>
using namespace std;

void OpenedState::write_state(StateContext* context)
{
	cout << "the door is being opened" << endl;
	context->setNewState(new LockedState);
}