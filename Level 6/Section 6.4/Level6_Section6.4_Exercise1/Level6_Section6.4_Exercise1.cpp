// Level6_Section6.1_Exercise1.cpp
// Fiona Ross 
// Fundamental Patterns 


#include <iostream>
#include "OriginPoint.h"
#include "Point.h"
#include "Circle.h"
#include "Line.h"
#include "ShapeComposite.h"


// Part H print function - just use iterators and prior cout functionality
void PrintComposite(ShapeComposite& sc) {
  for (std::shared_ptr<Shape> elem : sc) {
    // loop through composite and call the overloaded ostream operator for each
    // element. an implementation of "out" has been written in the shapecomposite
    // class so this function works on composites of composites
    std::cout << *elem;
  }
}

int main() {
  // Part H make shapes and add them to composite
  // Make Point
  Point p1(3.0, 4.0);
  Point p2 = p1;
  Point p3(p2);

  // Make Line
  Line l1(p1, p3);

  // Make Circle
  Circle c1(p1, 3.0);

  // Add to composite
  ShapeComposite sc;
  std::shared_ptr<Point> sp1 = std::make_shared<Point>(p1);
  std::shared_ptr<Point> sp2 = std::make_shared<Point>(p3);
  std::shared_ptr<Line> sp3 = std::make_shared<Line>(l1);
  std::shared_ptr<Circle> sp4 = std::make_shared<Circle>(c1);

  sc.AddShape(sp1);
  sc.AddShape(sp2);
  sc.AddShape(sp3);
  sc.AddShape(sp4);

  PrintComposite(sc);
  std::cout << "----------------------------------" << std::endl;
  // Make another composite copy
  ShapeComposite sc2(sc);
  sc2.AddShape(sp3);  // add line
  std::shared_ptr<ShapeComposite> sp5 =
      std::make_shared<ShapeComposite>(sc2);  // make a composite pointer

  sc.AddShape(sp5);  // add composite to composite
  PrintComposite(sc);
  // Note: Now that the copy constructor is added, we are able to easily add
  // composites to composites and print them.
}
