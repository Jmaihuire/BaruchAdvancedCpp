#ifndef SUBJECTPtB_CPP
#define SUBJECTPtB_CPP
#include "SubjectPtb.h"
#include <memory>

// Template template parameters for these! 
template<template<typename, typename> typename Container>
void SubjectPtb<Container>::Attach(Observer observer) {
	observers.push_back(observer);
};
template<template<typename, typename> typename Container>
void SubjectPtb<Container>::Detach(Observer observer) {
	auto it = std::remove_if(observers.begin(), observers.end(), [&observer](Observer o) {return observer == o; });
	observers.erase(it,observers.end());
};

//Notify observers
template<template<typename, typename> typename Container>
void SubjectPtb<Container>::Notify() {
  for (auto elem : observers) {
    (*elem)(this);
  }
};

#endif