#pragma once
#include "Observerable.h"

class Counter;

class DoubleFormat : public Observable {
private: 
    //add private pointer to subject base class
    Counter* counter_subject;
public:
    //Cosntructor 
    DoubleFormat(Counter* subject);
    //function called when subject has changed
    virtual void Update(Counter* subject); //had to change this to Counter type
};

