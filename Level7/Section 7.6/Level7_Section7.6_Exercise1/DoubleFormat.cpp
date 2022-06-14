#include "DoubleFormat.h"
#include "Counter.h"
#include <iostream>

//function called when subject has changed
void DoubleFormat::Update(Subject* subject) {
	// No more local members! 
	// implimented a weird cast ptr but really kinda confused 
	std::cout << "Double format updated: " << ((Counter*)subject)->GetCounter() << std::endl; 

};