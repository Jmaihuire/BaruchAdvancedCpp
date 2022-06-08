#pragma once
#include "Shape.h"
class Point : public Shape {
  double* x_;  // use pointers for deep copy
  double* y_;

 public:
  Point();                            // Default constructor
  Point(double xs, double ys);        // Constructor with coordinates
  Point(const Point& pt);             // Copy constructor
  Point& operator=(const Point& pt);  // Assignment operator
  double x();                         // Return x coordinate
  double y();                         // Return y coordinate
  void x(double xs);                  // Set x coordinate
  void y(double ys);                  // Set y coordinate
   double Distance();                  // 6.1.2 Part C: distance method 
                                   // print function
  inline friend std::ostream& operator<<(std::ostream& output, const Point& s) {
    output << "Point: " << *s.x_ << ", " << *s.y_ << std::endl;
    return output;
  }

  // destructor
  ~Point() {
    delete x_;
    delete y_;
  }

 
};
