#pragma once
#include "Observerable.h"

class Counter :
    // public Subject // counter derived from subject class 
    // Section 6.12 
    public Observable  // now setting derived class from observer
{
private: 
    long double Value;
public:
    Counter() {
   // if this was just zero wouldnt see the difference between printing out a
   // long and double 
        Value = 0.000001; 
    }
    // returns curent counter value 
    double GetCounter(); 
    // increase count value then calls notify
    void IncreaseCounter(); 
    // decrease count value then calls notify 
    void DecreaseCounter(); 

    // Realized needed declaration of observers in counter too 
    virtual void AddObserver(Observable* observer);
    virtual void DeleteObserver(Observable* observer);

    // Notify observables
    virtual void NotifyObservers();

    // Update function we will use to print counter values
    virtual void Update(Observable* observer);

};

