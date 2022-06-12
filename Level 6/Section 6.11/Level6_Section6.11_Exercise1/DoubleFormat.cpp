#include "DoubleFormat.h"
#include "Counter.h"
#include <iostream>

//Cosntructor
DoubleFormat::DoubleFormat(Counter* subject) {
	//initiialize subject and attach to it
	counter_subject = subject;
	counter_subject->Attach(this);
};
//function called when subject has changed
void DoubleFormat::Update(Subject* subject) {
	//update function
	if (subject == counter_subject) {
		std::cout << "Double format updated: " << counter_subject->GetCounter() << std::endl;
	}
};