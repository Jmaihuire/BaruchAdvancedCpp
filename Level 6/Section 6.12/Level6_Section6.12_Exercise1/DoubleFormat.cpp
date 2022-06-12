#include "DoubleFormat.h"
#include "Counter.h"
#include <iostream>

//Cosntructor
DoubleFormat::DoubleFormat(Counter* subject) {
	//initiialize subject and attach to it
	counter_subject = subject;
};
//function called when subject has changed
void DoubleFormat::Update(Counter* subject) { // had to change this to Counter type
	//update function
	if (subject == counter_subject) {
		std::cout << "Double format updated: " << counter_subject->GetCounter() << std::endl;
	}
};