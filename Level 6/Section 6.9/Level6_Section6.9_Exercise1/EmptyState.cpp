#include "EmptyState.h"
#include "Stack.h"
#include "FullState.h"
#include "NotFullNotEmptyState.h"

void EmptyState::Push(Stack* stack, const double& elem) {
	StackState::Push(stack,elem);
	if (stack->curr_index == stack->stack_.size()) {
		stack->TransitionState(FullState::Instance()); //transition state by providing the private transitionstate function a fullstate instance
	}
	else {
		stack->TransitionState(NotFullNotEmptyState::Instance()); //switch to not full not empty 
	}
}; //empty state push function

double EmptyState::Pop(Stack* stack) {
	throw std::runtime_error("Error: Cannot pop from an empty stack!\n");
	return 1.0;
}; //empty state pop function

EmptyState* EmptyState::Instance() {
	return Singleton<EmptyState>::instance();
} //return singleton for state transitions - this is acting in place of a smart pointer for this exercise