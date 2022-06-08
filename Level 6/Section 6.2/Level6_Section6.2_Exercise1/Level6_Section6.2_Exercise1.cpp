// Level6_Section6.1_Exercise1.cpp
// Fiona Ross 
// Fundamental Patterns 


#include <iostream>
#include "Shape.h"
#include "Circle.h"
#include "Line.h"
#include "Point.h"
#include "OriginPoint.h"

int main()
{
  // Testing OriginPoint 
  Point pt1(1.0, 1.0);

  // Testing if no originpoint set
  // gives random output 
  std::cout << "Distance to non set origin " << pt1.Distance() << std::endl;

  // Making origin 
  auto orig = OriginPoint::instance();

  // Setting origin 
  orig->x(1.0); 
  orig->y(3.0);

  std::cout << "Distance to  set origin " << pt1.Distance() << std::endl;

}
