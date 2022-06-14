#pragma once
#include "SubjectPtb.h"
#include <deque>

class Subject;

// Updated to fit the UML diagram
class DoubleFormatPtb {
 public: 
     void DoubleUpdate_b(
      SubjectPtb<std::deque>* subject);  // only gets called if theres a
                                         // change...hence the name update :)
};
