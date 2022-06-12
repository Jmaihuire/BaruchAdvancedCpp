#pragma once
#include "DistanceStrategy.h"

class ApproximateDistance :
    public DistanceStrategy
{ 
    // Part B: Approximate Distance Calc
    double Distance(const Point& p1, const Point& p2) override;
};

