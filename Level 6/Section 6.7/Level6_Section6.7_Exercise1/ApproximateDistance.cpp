#pragma once

#include "ApproximateDistance.h"

#include "Point.h"  //include point because we need full type def here

double ApproximateDistance::Distance(const Point& p1, const Point& p2) {
  double xdiff = std::abs(p1.x() - p2.x());
  double ydiff = std::abs(p1.y() - p2.y());
  double dist = xdiff + ydiff;
  return dist;
};
