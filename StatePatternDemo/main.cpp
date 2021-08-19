#include"StateBase.h"
#include "StateContext.h"
#include"LockedState.h"
#include"ClosedState.h"
#include"OpenedState.h"
#include<iostream>
using namespace std;

int main()
{
	StateContext *context = new StateContext;
	context->write_state();
	context->write_state();
	context->write_state();
	context->write_state();

}