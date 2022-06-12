#include "StackState.h"
#include "Stack.h"

void StackState::Push(Stack* stack, const double& elem) {
	//Stack::init(1);
	stack->stack_[stack->curr_index] = elem;
	stack->curr_index++;
}; //abstract class push function

double StackState::Pop(Stack* stack) {
	stack->curr_index--;
	return stack->stack_[stack->curr_index];
}; //abstract class pop function
