//Alex Moody: Subject Class for Counter Observer exercise 7.6
#ifndef SUBJECTPtB_H //Add these include headers so we can include the cpp file at the base of this template class. I know I should be using these type of headers instead of #pragma once, however I do not have time to correct all of the header and cpp files with this change.
#define SUBJECTPtB_H

#include <list>
#include <memory>
#include <functional>

// Function wrappers & template template parameters 
template<template<typename, typename> typename Container>
class SubjectPtb
{
public:
	using Observer = std::shared_ptr<std::function<void(SubjectPtb*)>>; 
	//controlling observer list 
	virtual void Attach(Observer observer);
	virtual void Detach(Observer observer);

	//Notify observers
	virtual void Notify();
private:
		Container<Observer, std::allocator<Observer>> observers; 
};

#ifndef SUBJECTPtB_CPP
#include "SubjectPtb.cpp"
#endif

#endif