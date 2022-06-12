#pragma once
#include "Observerable.h"
class Counter;

class LongFormat : public Observable {
 private:
    Counter* counter_subject;
public:
    
    LongFormat(Counter* subject);

    // only called with change of subject 
    // had to change this to counter type 
    virtual void Update(Counter* subject);
};

