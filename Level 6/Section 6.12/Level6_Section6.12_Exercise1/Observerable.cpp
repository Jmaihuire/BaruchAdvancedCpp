#include <iostream>
#include "Observerable.h"

// this is how we add / delete observers from the list 
void Observable::AddObserver(Observable* observer) {
  observerlist.push_back(observer);
};
void Observable::DeleteObserver(Observable* observer) {
  observerlist.remove(observer);
};

// Notify observers
void Observable::NotifyObservers() {
  std::list<Observable*>::iterator it;
  for (it = observerlist.begin(); it != observerlist.end(); it++) {
    (*it)->Update(this);
    (*it)->NotifyObservers();  // notify the dependents of dependents
  }
};