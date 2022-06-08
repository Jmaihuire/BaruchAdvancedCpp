#pragma once
#include "Point.h"
#include "Shape.h"
class Line : public Shape {
  Point* p1_;  // use pointers for deep copy
  Point* p2_;

 public:
  Line();                                      // Default constructor
  Line(const Point& pt1s, const Point& pt2s);  // Constructor with points
  Line(const Line& pt);                        // Copy constructor
  Line& operator=(const Line& pt);             // Assignment operator
  Point p1();                                  // Return point 1
  Point p2();                                  // Return point 2
  void p1(const Point& ps);                    // Set point 1
  void p2(const Point& ps);                    // Set point 2
  double length();                             // 6.1.2 Part D

   // Part C 6.4
  std::shared_ptr<Shape> Clone();

  // print function:
  inline friend std::ostream& operator<<(std::ostream& output, const Line& s) {
    output << "Line Points: \n" << *s.p1_ << *s.p2_ << std::endl;
    return output;
  }

  // destructor
  ~Line() {
    delete p1_;
    delete p2_;
  }
};
