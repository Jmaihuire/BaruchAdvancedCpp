#ifndef COUNTERPtB_H  
#define COUNTERPtB_H

#include "SubjectPtb.h"
template<template<typename, typename> typename Container>
class CounterPtb : public SubjectPtb<Container>

{
private: 
    long double Value;
public:
    CounterPtb() {
        Value = 0.000001; //initialize counter with small offset from zero - this demonstrates the different types of print precision for long and double.
    }
    double GetCounter(); //return private value
    void IncreaseCounter(); //increases counter value then calls notify()
    void DecreaseCounter(); //decreases counter then notifies observers

};

#ifndef COUNTERPtBCPP
#include "CounterPtb.cpp"
#endif

#endif