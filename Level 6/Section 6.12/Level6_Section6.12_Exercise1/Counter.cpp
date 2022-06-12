#include "Counter.h"
#include "LongFormat.h" // have to include these beause no longer have subject class
#include "DoubleFormat.h" // have to include these beause no longer have subject class
#include <iostream>
#include "Observerable.h"
// derived from subject class 

double Counter::GetCounter() {
	return Value;
}; //outputs counter value 

void Counter::IncreaseCounter() {
	Value++;
	// Notify(); // No longer needed as including update & notifyObserver
        Update(this);
        NotifyObservers();
	
}; //increases counter value then calls notify()

void Counter::DecreaseCounter() {
	Value--;
	//Notify();// No longer needed as including update & notifyObserver
        Update(this);
        NotifyObservers(); 
}; //decreases counter then notifies observers

// Section 6.12
// these are the dependents 
void Counter::AddObserver(Observable* observer) {
  observerlist.push_back(observer);
};
void Counter::DeleteObserver(Observable* observer) {
  observerlist.remove(observer);
};

// I know this needs to exist but I could not figure it out...
void Counter::Update(Observable* observer) {
  //std::cout << "Updating Counter: \n" << std::endl;
  //LongFormat lf(this);
  //DoubleFormat df(this);
  //lf.Update(this);
  //df.Update(this);  // call update functions of observers
}

void Counter::NotifyObservers() {
  std::list<Observable*>::iterator it;
  for (it = observerlist.begin(); it != observerlist.end(); it++) {
    (*it)->Update(this);
    (*it)->NotifyObservers();  // recursively notify observers
  }
};


