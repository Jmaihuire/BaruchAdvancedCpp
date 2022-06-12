#pragma once
#include "DistanceStrategy.h"

class ApproximateDistance :
    public DistanceStrategy
{ 

    double Distance(const Point& p1, const Point& p2) override;
};

