#pragma once
#include "DistanceStrategy.h"

class ApproximateDistance : public DistanceStrategy {
  // Part B - define distance method to compute approximate distance:
  double Distance(const Point& p1, const Point& p2) override;
};
