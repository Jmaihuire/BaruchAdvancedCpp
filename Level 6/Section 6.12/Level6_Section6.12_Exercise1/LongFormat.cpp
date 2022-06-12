#include "LongFormat.h"
#include "Counter.h"
#include <iostream>
#include <iomanip>

// This is a constructor 
LongFormat::LongFormat(Counter* subject) {
	// using attach after initialization of subject 
	counter_subject = subject;
};

// Called when subject changes 
void LongFormat::Update(Counter* subject) {
	if (subject == counter_subject) {
	std::cout << "Long format updated: " << counter_subject->GetCounter() << std::endl; // I think this shows the proper format? Low on time so need to look into some possible precision issues.
	}
};