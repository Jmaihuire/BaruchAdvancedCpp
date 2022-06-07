#pragma once
#include <boost/functional/hash.hpp>
#include <functional>
#include <iostream>

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

  // compute hash value (ADDED FOR EXERCISE 5.4.2
  std::size_t hash_value() {
    std::size_t seed = 0;
    boost::hash_combine(seed, x_);
    boost::hash_combine(seed, y_);
    return seed;
  }
  // static hash value function
  static std::size_t hash_value(const Point& p) {
    std::size_t seed = 0;
    boost::hash_combine(seed, p.X());
    boost::hash_combine(seed, p.Y());
    return seed;
  }


  //Missing an == operator....this was not easy to figure out 
  bool operator==(const Point& p) const {
    if ((p.X() == x_) && (p.Y() == y_)) {
      return true;
    }
    return false;
  }


  ~Point() {
    // std::cout << "Point object deleted from memory" << std::endl;
  }
};
