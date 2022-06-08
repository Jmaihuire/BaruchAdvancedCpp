#pragma once
// Have to forward declare point because 
// distance relies on it but don't need full def

class Point;  
class DistanceStrategy {
 public:
  virtual double Distance(const Point& p1, const Point& p2) = 0;
};
