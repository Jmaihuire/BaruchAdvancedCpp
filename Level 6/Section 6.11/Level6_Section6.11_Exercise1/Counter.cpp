#include "Counter.h"
// derived from subject class 

double Counter::GetCounter() {
	return Value;
}; //outputs counter value 

void Counter::IncreaseCounter() {
	Value++;
	Notify();
}; //increases counter value then calls notify()

void Counter::DecreaseCounter() {
	Value--;
	Notify();
}; //decreases counter then notifies observers