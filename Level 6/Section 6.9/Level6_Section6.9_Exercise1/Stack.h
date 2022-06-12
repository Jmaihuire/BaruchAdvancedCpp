#pragma once
#include <vector>
#include <iostream>

class StackState;

class Stack
{
private:
	friend class StackState; //make stack state a friend so it can modify the stack state and modify stack member variables
	friend class EmptyState;
	friend class NotFullNotEmptyState;
	friend class FullState;

	std::vector<double> stack_; //stack array to store elements - I choose double type
	int curr_index; //current index
	StackState* curr_state; //current state
    void init(int size); //initialization

	//make some private functions for the states to call
	void TransitionState(StackState* new_state);

public:
	Stack();//default constructor with size 1

	Stack(int size);//constructor with size arg

	void Push(const double& elem); //calls push on current state

	void Pop(); //calls pop on current state
};



