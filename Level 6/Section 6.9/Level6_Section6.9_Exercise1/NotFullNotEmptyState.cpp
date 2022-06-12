#include "NotFullNotEmptyState.h"
#include "Stack.h"
#include "EmptyState.h"
#include "FullState.h"

void NotFullNotEmptyState::Push(Stack* stack,const double& elem) {
	StackState::Push(stack,elem);
	if (stack->curr_index == stack->stack_.size() - 1) {
		stack->TransitionState(FullState::Instance());
	}
}; //empty state push function

double NotFullNotEmptyState::Pop(Stack* stack) {
	if (stack->curr_index == 1) {
		stack->TransitionState(EmptyState::Instance());
	}
	return StackState::Pop(stack);
}; //empty state pop function

NotFullNotEmptyState* NotFullNotEmptyState::Instance() {
	return Singleton<NotFullNotEmptyState>::instance();
} //return singleton for state transitions - this is acting in place of a smart pointer for this exercise