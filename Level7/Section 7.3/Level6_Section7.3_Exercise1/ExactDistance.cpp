#pragma once 
#include "ExactDistance.h"
#include "Point.h"

double ExactDistance::Distance(const Point& p1, const Point& p2) {
    double xdiff = p1.x() - p2.x();
    double ydiff = p1.y() - p2.y();
    double dist = std::sqrt(xdiff * xdiff + ydiff * ydiff);
    return dist;
}