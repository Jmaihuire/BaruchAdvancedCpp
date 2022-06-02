#pragma once
// Part A:
#include <functional>
#include <iostream>

// Grabbed components of this from Level 2
class Point {
  double x_;
  double y_;

 public:
  Point(){};

  Point(double d1, double d2) : x_(d1), y_(d2){};

  // access coordinates
  double X() { return x_; }

  double Y() { return y_; }

  void X(double x) {  // reset x coordinate
    x_ = x;
  };

  void Y(double y) {  // reset y coordinate
    y_ = y;
  };

  // Expanded on these functions for Level 4 
  // distance between two points
  static double distance(Point& p1, Point& p2) {
    double xdiff = p1.X() - p2.X();
    double ydiff = p1.Y() - p2.Y();
    return std::sqrt(xdiff * xdiff + ydiff * ydiff);
  }

  bool equal(Point& p1, Point& p2) {
    return (p1.X() == p2.X() && p1.Y() == p2.Y());
  }

  void print() { std::cout << "(" << x_ << ", " << y_ << ")\n"; }

  ~Point() {
    // std::cout << "Point object deleted from memory" << std::endl;
  }
};
