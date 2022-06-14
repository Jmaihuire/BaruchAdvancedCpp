#include "LongFormat.h"
#include "Counter.h"
#include <iostream>
#include <iomanip>


// Same thing as DoubleFormat! 
// ie. // No more local members! 
	// implimented a weird cast ptr but really kinda confused 
void LongFormat::Update(Subject* subject) {
  std::cout << "Long format updated: " << ((Counter*)subject)->GetCounter()
            << std::endl;
}