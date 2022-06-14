#pragma once
#include "Subject.h"
class Counter :
    public Subject
{
private: 
    long double Value;
public:
    Counter() { Value = 0.000001; }
    double GetCounter(); //return private value
    void IncreaseCounter(); //increases counter value then calls notify()
    void DecreaseCounter(); //decreases counter then notifies observers

};

