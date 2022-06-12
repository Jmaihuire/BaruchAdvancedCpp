#include "Stack.h"
#include "FullState.h"
#include "EmptyState.h"
#include "NotFullNotEmptyState.h"

void FullState::Push(Stack* stack,const double& elem) {
	throw std::runtime_error("Error: Cannot push to full stack!\n");
}; //empty state push function

double FullState::Pop(Stack* stack) {
	if (stack->curr_index == 1) {
		stack->TransitionState(EmptyState::Instance());
	}
	else {
		stack->TransitionState(NotFullNotEmptyState::Instance());
	}
	return StackState::Pop(stack);
}; //empty state pop function

FullState* FullState::Instance() {
	return Singleton<FullState>::instance();
} //return singleton for state transitions - this is acting in place of a smart pointer for this exercise