#pragma once
#include "DistanceStrategy.h"

class ExactDistance :
    public DistanceStrategy
{
public:
     double Distance(const Point& p1, const Point& p2) override;
    
};

