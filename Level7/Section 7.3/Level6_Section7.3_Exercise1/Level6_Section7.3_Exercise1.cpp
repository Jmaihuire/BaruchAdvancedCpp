// Level6_Section7.3_Exercise1.cpp 
// Fiona Ross
// 

#include <iostream>
#include "Shape.h"
#include "ShapeFactory.h"
#include "ConsoleShapeFactory.h"


// Not a ton of changes from the code used in 6.7.1
// some of the changes include: 
// Deleting: std::shared_ptr<Line> CreateLine(); from ConsoleShapeFactory.h because template now so redundant 
// Included the template function in ShapeComposite.h so have generic container 
// Added a template method in ShapeFactory .h & .cpp 

int main() {
  // the testing is actually really simple and although not a lot of new code
  // challenging to make sure everything is in the right spot and include all
  // the changes so can impliment the template function

  ShapeFactory* factory = new ConsoleShapeFactory;  // chose console factory but
                                                    // can have any factor input
  factory
      ->CreatePolyLine();  // user now chooses how many points make up the line
};
