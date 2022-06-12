// Level6_Section6.8_Exercise1.cpp
// Fiona Ross 
// Decorator Pattern: Name decorator for the shape hierarchy

#include <iostream>

#include "Circle.h"
#include "NameDecorator.h"
#include "ShapeDecorator.h"

int main() {
  //Name Decorator 
  NameDecorator nd1;
  // testing the setter 
  nd1.SetName("Amanda");
  // testing the getter 
  std::cout << nd1.GetName() << std::endl;  

  // Another test but now inputting a shape 
  NameDecorator nd2(std::make_shared<Point>(), "Jim");
  std::cout << nd2.GetName();  // test name setting

  // Not going to work for Line 
  std::cout << std::endl;
  NameDecorator nd3(std::make_shared<Circle>(), "Jeremy");
  std::cout << nd3.GetName();  // test name setting
}
