#pragma once
// this class basically completely had to change 
#include <list>
class Observable {
 public:
  // all the observers can be put in this list
  // had this in private but causing issues so moved to public
  std::list<Observable*> observerlist;

  // controlling observer list 
  virtual void AddObserver(Observable* observer);
  virtual void DeleteObserver(Observable* observer);

  // Notify observables
  virtual void NotifyObservers();

  // pure virtual Update()
  virtual void Update(Observable* observer) = 0;
};
