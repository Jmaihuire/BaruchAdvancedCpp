// Level6_Section6.1_Exercise1.cpp
// Fiona Ross 
// Fundamental Patterns 


#include <iostream>
#include "Shape.h"
#include "Circle.h"
#include "Line.h"
#include "Point.h"
#include "OriginPoint.h"
#include "ShapeComposite.h"

// Part H print function recursively printing composites 
void PrintComposite(ShapeComposite& sc) {
  for (std::shared_ptr<Shape> elem : sc) {
    std::cout << *elem; 
  }
}

int main() {
  // Part H testing shape composite 

  Point pt1(1, 4);
  Point pt2 = pt1;
  Point pt3(2, 5);


  Line ln1(pt1, pt2);
  Line ln2(pt2, pt3);
  Line ln3(pt1, pt3);

  Circle c1(pt1, 1.0);
  Circle c2(pt2, 2.0);
  Circle c3(pt3, 3.0);

  // Putting them all together into composite
  ShapeComposite sc;
  std::shared_ptr<Point> sp1 = std::make_shared<Point>(pt1);
  std::shared_ptr<Point> sp2 = std::make_shared<Point>(pt3);
  std::shared_ptr<Line> sp3 = std::make_shared<Line>(ln1);
  std::shared_ptr<Line> sp4 = std::make_shared<Line>(ln2);
  std::shared_ptr<Line> sp5 = std::make_shared<Line>(ln3);
  std::shared_ptr<Circle> sp6 = std::make_shared<Circle>(c1);
  std::shared_ptr<Circle> sp7 = std::make_shared<Circle>(c2);
  std::shared_ptr<Circle> sp8 = std::make_shared<Circle>(c3);

  sc.AddShape(sp1);
  sc.AddShape(sp2);
  sc.AddShape(sp3);
  sc.AddShape(sp4);
  sc.AddShape(sp5);
  sc.AddShape(sp6);
  sc.AddShape(sp7);
  sc.AddShape(sp8);

  std::cout << "First Composite" << std::endl; 
  PrintComposite(sc);
  
  // the addshape needs a shared pointer so to place shape composite into another shape composite
  // need to change to shared pointer 
  std::shared_ptr<ShapeComposite> sc1 (new ShapeComposite());  // make a composite pointer

  sc.AddShape(sc1);  // add composite to composite
  PrintComposite(sc);

}
