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
  // Part E / F Testing the Functions 
  
  // Grabbed Line / Point from 6.1.1 
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

  // Testing 
  std::cout << "Distance of Point 1 from Point 2" << pt1.Distance(pt2);
  std::cout << "Distance of Point 2 from origin " << pt2.Distance(); 
  std::cout << "Length of line 1 " << ln1.length() << std::endl;
  std::cout << "Length of line 2 " << ln2.length() << std::endl; 

}
