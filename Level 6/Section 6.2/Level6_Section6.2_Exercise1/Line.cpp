#include "Line.h"
Line::Line() {
  p1_ = new Point;
  p2_ = new Point;  // constructor for deep copies
};                  // Default constructor
Line::Line(const Point& pt1s, const Point& pt2s) {
  p1_ = new Point(pt1s);  // use point constructor
  p2_ = new Point(pt2s);
};  // Constructor with points
Line::Line(const Line& pt) {
  p1_ = new Point(*pt.p1_);
  p2_ = new Point(*pt.p2_);
};  // Copy constructor
Line& Line::operator=(const Line& pt) {
  Line l(pt);  // use copy constructor
  return l;
};                                  // Assignment operator
Point Line::p1() { return *p1_; };  // Return point 1
Point Line::p2() { return *p2_; };  // Return point 2
void Line::p1(const Point& ps) {
  delete p1_;
  p1_ = new Point(ps);
};  // Set point 1
void Line::p2(const Point& ps) {
  delete p2_;
  p2_ = new Point(ps);
};  // Set point 2
