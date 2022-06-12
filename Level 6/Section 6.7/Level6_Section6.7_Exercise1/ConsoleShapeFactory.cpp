#include "ConsoleShapeFactory.h"

#include <iostream>
#include "Circle.h"
#include "Line.h"
#include "Point.h"

std::shared_ptr<Circle> ConsoleShapeFactory::CreateCircle() {
  double r;  // radius
  double x;  // center x coord
  double y;  // center y coord

  // gather data
  std::cout << "Making Circle........\nEnter origin x coordinate: ";
  std::cin >> x;
  std::cout << "\nEnter origin y coordinate: ";
  std::cin >> y;
  std::cout << "\nEnter radius: ";
  std::cin >> r;

  // create shape and output pointer
  Point c(x, y);  // center
  std::cout << "\nOutputting Circle pointer...\n";
  return std::make_shared<Circle>(c, r);
};  // Circle virtual function

std::shared_ptr<Line> ConsoleShapeFactory::CreateLine() {
  double x1;  // point 1 x
  double y1;  // point 1 y
  double x2;  // point 2 x
  double y2;  // point 2 y

  // gather data
  std::cout << "Making Line........\nEnter x and y of first point (x y): ";
  std::cin >> x1 >> y1;
  std::cout << "\nEnter x and y of second point (x y): ";
  std::cin >> x2 >> y2;

  // create shape and output pointer
  Point p1(x1, y1);  // first point
  Point p2(x2, y2);  // second point
  std::cout << "\nOutputting Line pointer...\n";
  return std::make_shared<Line>(p1, p2);
};  // Line virtual function

std::shared_ptr<Point> ConsoleShapeFactory::CreatePoint() {
  double x;  // x coord
  double y;  // y coord

  // gather data
  std::cout << "Making Point........\nEnter x and y coordinates (x y): ";
  std::cin >> x >> y;

  // create shape and output pointer
  std::cout << "\nOutputting Point pointer...\n";
  return std::make_shared<Point>(x, y);
};  // Point virtual function
