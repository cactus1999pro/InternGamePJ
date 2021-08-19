#include"ClosedState.h"
#include <iostream>
using namespace std;
void ClosedState::write_state(StateContext* context)
{
	cout << "the door is being closed" << endl;
	context->setNewState(new OpenedState);
}