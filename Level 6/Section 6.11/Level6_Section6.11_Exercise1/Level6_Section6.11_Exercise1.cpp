// Level6_Section6.11_Exercise1.cpp 
// Fiona Ross
// Observer Pattern 

#include <iostream>
#include <iostream>
#include "Counter.h"
#include "DoubleFormat.h"
#include "LongFormat.h"


int main()
{
  // Part D
  // creating the new counter object 
  Counter* cnt1 = new Counter();

  // Part L:
  // Testing by making several observers and trying to see if they all display counter value 
  // realistically they are showing the same format so im not 100% sure im testing thing right
  DoubleFormat db(cnt1);
  LongFormat lf(cnt1);

  // Increment counter and see appropriate console output
  cnt1->IncreaseCounter();
  cnt1->DecreaseCounter();
  cnt1->DecreaseCounter();
  std::cout << "Current counter value: " << cnt1->GetCounter();
}
