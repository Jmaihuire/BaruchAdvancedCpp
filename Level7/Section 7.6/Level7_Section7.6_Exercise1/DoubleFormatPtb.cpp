#include "DoubleFormatPtb.h"
#include "DoubleFormat.h"
#include "CounterPtb.h"
#include <iostream>


void DoubleFormatPtb::DoubleUpdate_b(SubjectPtb<std::deque>* subject) {
  std::cout << "Double format updated: "
            << ((CounterPtb<std::deque>*)subject)->GetCounter()
            << std::endl; 
 
};
