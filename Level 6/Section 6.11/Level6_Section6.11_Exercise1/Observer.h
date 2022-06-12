#pragma once
#include <memory>
class Subject;
class Observer
{
public: 
	// this is only called if change of subject 
	virtual void Update(Subject* subject) = 0;
};

