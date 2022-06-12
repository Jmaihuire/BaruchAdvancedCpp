#pragma once
class Stack;

class StackState
{
private:
	//StackState();
	//StackState(const StackState& source);
	//StackState& operator = (const StackState& source);

public:
	virtual void Push(Stack* stack, const double& elem);

	virtual double Pop(Stack* stack);
};

