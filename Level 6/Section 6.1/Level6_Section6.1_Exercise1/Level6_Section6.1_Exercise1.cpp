// Level6_Section6.1_Exercise1.cpp
// Fiona Ross 
// Fundamental Patterns 


#include <iostream>
#include "Shape.h"
#include "Circle.h"
#include "Line.h"
#include "Point.h"


int main()
{
    // Want to examine shape hierarchy 
    // so creating each element 
 
    
  Shape shape1;  // default constructor

  // you really need to create points first in order to create 
  // lines or circles 
  Point pt1(1.0, 1.0);
  Point pt2 = pt1;
  std::cout << "Pt 1 x & y: " << pt1.x() << ", " << pt1.y() << std::endl;
  
  // testing changing point elements 
  pt2.x(1.0);
  pt2.y(2.0);
  
  // testing output 
  std::cout << pt1;
  std::cout << pt2;

 
  // making line from points 
  Line ln1(pt1, pt2);
  // making line from another line 
  Line ln2 = ln1;
  // returning points from a line 
  ln2.p1(pt1);
  ln2.p2(pt2);
  // testing output 
  std::cout << ln2;

  // making circle from pt 
  Circle c1(pt1, 12.0);

  // making circle from another circle (2 ways)
  Circle c2 = c1;
  Circle c3(c2);

  // getting circle elements 
  c3.CenterPoint(pt2);
  c3.Radius(3.0);
  
  // testing output 
  std::cout << "circle 1: " << c1;
  std::cout << "circle 2: " << c2;
  std::cout << "circle 3: " << c3;
}
