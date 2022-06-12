// Level6_Section6.12_Exercise1.cpp 
// Fiona Ross 
// Propagator Pattern 

#include <iostream>
#include "Counter.h"
#include "Observerable.h"

int main()
{
    // Really not a lot of description on what the test should look lik
    // Think its just to show the list of observers and new functions we included 

    Counter* c1 = new Counter; 
    std::cout << "Counter 1 is: " << c1->GetCounter() << std::endl;

    Counter* c2 = new Counter; 
    std::cout << "Counter 2 is: " << c2->GetCounter() << std::endl;

    Counter* c3 = new Counter; 
    std::cout << "Counter 3 is: " << c3->GetCounter() << std::endl;

    // Adding them to a list 
    c1->AddObserver(c2);
    c1->AddObserver(c3); 

    // Updating them when in list 
    c1->IncreaseCounter();
    c1->IncreaseCounter(); 
    c1->DecreaseCounter(); 

    std::cout << "Printing List: " << c1->GetCounter() << std::endl;

    // Showing other way to increase or decrease single counter 
    Counter* c4 = new Counter; 
    c4->IncreaseCounter();
    std::cout << c4->GetCounter() << std::endl;
}
