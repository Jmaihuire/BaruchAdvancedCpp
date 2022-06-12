#pragma once
#include "DistanceStrategy.h"

class ExactDistance : public DistanceStrategy {
 public:
  // Part B - define distance method to compute distance exactly:
  double Distance(const Point& p1, const Point& p2) override;
};
