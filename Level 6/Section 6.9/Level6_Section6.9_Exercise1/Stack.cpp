#include "Stack.h"
#include "EmptyState.h"

void Stack::init(int size) {
	if (!size >= 1) {
		size = 1;
	}
	stack_ = std::vector<double>(size); //create array for the elements with the given size
	curr_index = 0;
	curr_state = EmptyState::Instance(); //use instance() since states are singletons
}

Stack::Stack() {
	init(1);
}//default constructor with size 1

Stack::Stack(int size) {
	init(size);
}//constructor with size arg

void Stack::Push(const double& elem) {
	curr_state->Push(this, elem);
} //calls push on current state

void Stack::Pop() {
	curr_state->Pop(this);
}

void Stack::TransitionState(StackState* new_state) {
	std::cout << "Transitioning stack to " << typeid(*new_state).name() << std::endl;
	curr_state = new_state; //just set the state equal to the new state - memory should be taken care of because these are singletons
}