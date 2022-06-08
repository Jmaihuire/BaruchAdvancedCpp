#pragma once
#include "DistanceStrategy.h"

class ExactDistance : public DistanceStrategy {
 public:
 // Part B: 
 // impliments distance method using exact algorithm (pythagoras)
 double Distance(const Point& p1, const Point& p2) override;
};
