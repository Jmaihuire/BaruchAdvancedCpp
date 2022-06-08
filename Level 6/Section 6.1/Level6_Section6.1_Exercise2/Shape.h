#pragma once
#include <iostream>

class Shape {
 public:
  Shape(){};                  // Default constructor
  Shape(const Shape& shp){};  // Copy constructor
  Shape& operator=(const Shape& shp) {
    Shape s(shp);
    return s;
  };  // Assignment operator

  // print function
  inline friend std::ostream& operator<<(std::ostream& output, const Shape& s) {
    return s.out(output);  // call out function that will be overloaded by all
                           // child classes
  }

 private:
  // virtual function
  virtual std::ostream& out(std::ostream& o) const { return o; };
};
