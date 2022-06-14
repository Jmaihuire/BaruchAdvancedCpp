//Alex Moody: Subject Class for Counter Observer exercise 7.6
#pragma once
#include <list>
#include <memory>
#include <functional>

class Subject
{
public:
	// used lecture videos to do most of this 
	using Observer = std::shared_ptr<std::function<void(Subject*)>>;
	virtual void Attach(Observer observer);
	virtual void Detach(Observer observer);

	//Notify observers
	virtual void Notify();
private:
	// couldnt really figure out how to use template template parameter for this one... ran out of time debuggin but this runs 
	std::list<Observer> observers; 
};
