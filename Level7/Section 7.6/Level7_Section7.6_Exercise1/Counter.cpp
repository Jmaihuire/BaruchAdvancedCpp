#include "Counter.h"
double Counter::GetCounter() {
	return Value;
}; //return private value
void Counter::IncreaseCounter() {
	Value++;
	Notify();
}; //increases counter value then calls notify()
void Counter::DecreaseCounter() {
	Value--;
	Notify();
}; //decreases counter then notifies observers