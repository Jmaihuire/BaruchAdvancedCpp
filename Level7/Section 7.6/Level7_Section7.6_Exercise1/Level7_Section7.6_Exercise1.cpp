// Level7_Section7.6_Exercise1.cpp 
// Fiona Ross 
// Observer Pattern using Universal Function Wrappers

#include <iostream>

// Changes: 
// Now have a counter for part B: (template template parameters) 
// Updated the Subject (DoubleFormat.cpp)
// Subject got rid of observer class 

#include <iostream>
#include <deque>
#include "Counter.h"
#include "DoubleFormat.h"
#include "LongFormat.h"
#include "CounterPtb.h"
#include "SubjectPtb.h"
#include "DoubleFormatPtb.h"


 // Double format and long format are written for original Counter and subject
 // classes so including another set of functions here:

// Originally tried to make these each their own classes but was getting weird errors so gave up and just included them here
// function called when subject has changed
void DoubleUpdatePtb(SubjectPtb<std::deque>* subject) {
  std::cout << "Double format updated: "
            << ((CounterPtb<std::deque>*)subject)->GetCounter() << std::endl;
};

// function called when subject has changed
void LongUpdatePtb(SubjectPtb<std::deque>* subject) {
  std::cout << "Long format updated: "
            << ((CounterPtb<std::deque>*)subject)->GetCounter()
            << std::endl;  
};

int main() {
  // Part A 
  // steps are: create counter, attach, check by looking at counter 
  Counter* cnt1 = new Counter();
  cnt1->Attach(std::make_shared<std::function<void(Subject * subject)>>(
      DoubleFormat::Update));
  cnt1->Attach(std::make_shared<std::function<void(Subject * subject)>>(
      LongFormat::Update));

  cnt1->IncreaseCounter();
  cnt1->DecreaseCounter();
  cnt1->DecreaseCounter();

  // Part B: 
  // impliment list of observers 
  // create, attach, increment counter, check output... (same process)
  std::cout << "\n\n\nPart B: using std::deque: \n";
  CounterPtb<std::deque>* cnt2 = new CounterPtb<std::deque>();
  cnt2->Attach(
      std::make_shared<std::function<void(SubjectPtb<std::deque> * subject)>>(
          DoubleUpdatePtb));
  cnt2->Attach(
      std::make_shared<std::function<void(SubjectPtb<std::deque> * subject)>>(
          LongUpdatePtb));
  cnt2->IncreaseCounter();
  cnt2->DecreaseCounter();
  cnt2->DecreaseCounter();
}
