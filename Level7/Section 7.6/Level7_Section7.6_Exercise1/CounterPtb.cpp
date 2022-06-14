#ifndef COUNTERPtB_CPP
#define COUNTERPtB_CPP

#include "CounterPtB.h"
template<template<typename, typename> typename Container>
double CounterPtb<Container>::GetCounter() {
	return Value;
}; //return private value

template<template<typename, typename> typename Container>
void CounterPtb<Container>::IncreaseCounter() {
	Value++;
	SubjectPtb<Container>::Notify();
}; //increases counter value then calls notify()

template<template<typename, typename> typename Container>
void CounterPtb<Container>::DecreaseCounter() {
	Value--;
	SubjectPtb<Container>::Notify();
}; //decreases counter then notifies observers

#endif