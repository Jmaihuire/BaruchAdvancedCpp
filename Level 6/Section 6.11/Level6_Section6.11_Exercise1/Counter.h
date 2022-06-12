#pragma once
#include "Subject.h"
class Counter :
    public Subject // counter derived from subject class 
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

};

