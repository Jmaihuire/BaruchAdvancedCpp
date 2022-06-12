#pragma once
#include "Observer.h"

class Counter;

class LongFormat :
    public Observer
{
private:
    Counter* counter_subject;
public:
    
    LongFormat(Counter* subject);

    // only called with change of subject 
    virtual void Update(Subject* subject);
};

