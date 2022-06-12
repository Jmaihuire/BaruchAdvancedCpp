#pragma once
#include <list>
#include <memory>

class Observer;

// subject class with functions used from diagram. Help from lecture & forum 

class Subject
{
private: 
	std::list<Observer*> observers;
public:
	
	virtual void Attach(Observer* observer);
	virtual void Detach(Observer* observer);
	virtual void Notify();
};

