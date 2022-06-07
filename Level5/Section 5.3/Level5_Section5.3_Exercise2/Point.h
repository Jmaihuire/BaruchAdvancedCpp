#pragma once
// Pulled from Section 4.2 
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
  double X() const { return x_; }

  double Y() const { return y_; }

  void X(double x) {  // reset x coordinate
    x_ = x;
  };

  void Y(double y) {  // reset y coordinate
    y_ = y;
  };

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

  // Section 5.3.2 Additions: 
  
  // compute hash value no input
  std::size_t hash_value() {
    std::size_t seed = 0;
    boost::hash_combine(seed, x_);
    boost::hash_combine(seed, y_);
    return seed;
  }

  // static hash value function with point as input 
  static std::size_t hash_value(const Point& p) {
    std::size_t seed = 0;
    boost::hash_combine(seed, p.X());
    boost::hash_combine(seed, p.Y());
    return seed;
  }

  ~Point() {
    // std::cout << "Point object deleted from memory" << std::endl;
  }
};
