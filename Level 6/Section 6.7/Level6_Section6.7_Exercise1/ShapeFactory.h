#pragma once
#include <memory>

class Circle;
class Line;
class Point;

class ShapeFactory {
 public:
  virtual std::shared_ptr<Circle> CreateCircle() = 0;  // Circle virtual
                                                       // function

  virtual std::shared_ptr<Line> CreateLine() = 0;  // Line virtual function

  virtual std::shared_ptr<Point> CreatePoint() = 0;  // Point virtual function
};
