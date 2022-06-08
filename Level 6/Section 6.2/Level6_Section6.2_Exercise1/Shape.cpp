//Basic shape class for inheritance examples
//Shape is a base class

#ifndef _SHAPE_
#define _SHAPE_

#include <iostream>

class Shape {
 public:
  Shape() {}
  void draw() { std::cout << "drawing shape\n"; }
};

#endif
