#pragma once
#include "ShapeFactory.h"

class ConsoleShapeFactory : public ShapeFactory {
  std::shared_ptr<Circle> CreateCircle();  // Circle virtual function

  std::shared_ptr<Line> CreateLine();  // Line virtual function

  std::shared_ptr<Point> CreatePoint();  // Point virtual function
};
