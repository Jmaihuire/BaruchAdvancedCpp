#include "Point.h"
#include "OriginPoint.h"

Point::Point() {
  x_ = new double;  // initialize pointer for deep copy
  y_ = new double;
};  // Default constructor
Point::Point(double xs, double ys) {
  x_ = new double(xs);  // initialize pointer for deep copy
  y_ = new double(ys);

};  // Constructor with coordinates
Point::Point(const Point& pt) {
  x_ = new double(*(pt.x_));  // initialize pointer for deep copy
  y_ = new double(*(pt.y_));
};  // Copy constructor
Point& Point::operator=(const Point& pt) {
  Point p(pt);  // use copy constructor
  return p;
};                                  // Assignment operator
double Point::x() { return *x_; };  // Return x coordinate
double Point::y() { return *y_; };  // Return y coordinate
void Point::x(double xs) {
  delete x_;
  x_ = new double(xs);
};  // Set x coordinate
void Point::y(double ys) {
  delete y_;
  y_ = new double(ys);
};  // Set y coordinate

// 6.2.1 Using Singleton 
double Point::Distance() {
  double xdiff = *x_ - *OriginPoint::instance() ->x_; 
  double ydiff = *y_ - *OriginPoint::instance() ->y_;  
  // Part B: pythag theorom  from origin 
  double dist = std::sqrt(xdiff * xdiff + ydiff * ydiff);
  return dist;
}; // distance function 
