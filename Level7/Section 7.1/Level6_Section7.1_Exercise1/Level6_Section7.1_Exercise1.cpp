// Level6_Section7.1_Exercise1.cpp
// Fiona Ross 
// Re-engineering Factory Patterns I

#include <iostream>
#include "Shape.h"
#include "ShapeFactory.h"
#include "ConsoleShapeFactory.h"
#include "Line.h"
#include "Circle.h"
#include "ExactDistance.h"

int main() {
  /* Part A:
   * Changed the interface/function so can take any type of factory.
   * Benefit is that is pairs down the number of lines
   * testing using console type of factory.
   */
  ShapeFactory* factory = new ConsoleShapeFactory;
  auto tup = factory->CreateTuple();

  // Outputting so can chek the validity of the console output for Part B:
  std::cout << "Testing tuple output: \n"
            << *std::get<0>(tup) << *std::get<1>(tup) << *std::get<2>(tup)
            << std::endl;

  // Part C:
  // Benefit is the interface is more usable and pairs down the amount of code
  // so if you continue including shapes I think the old way could be a headache
  // for the user
}