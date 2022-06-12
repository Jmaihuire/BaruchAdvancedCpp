#pragma once
#include "DistanceStrategy.h"

class ExactDistance :
    public DistanceStrategy
{
public:
    //Part B: Exact Distance Calc
    double Distance(const Point& p1, const Point& p2) override;
    
};

