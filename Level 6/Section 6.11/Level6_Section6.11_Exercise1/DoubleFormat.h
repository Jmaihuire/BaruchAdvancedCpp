#pragma once
#include "Observer.h"

class Counter;

class DoubleFormat :
    public Observer
{
private: 
    //add private pointer to subject base class
    Counter* counter_subject;
public:
    //Cosntructor
    DoubleFormat(Counter* subject);
    //function called when subject has changed
    virtual void Update(Subject* subject);
};

