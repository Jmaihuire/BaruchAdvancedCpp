#pragma once
class Point; 

class DistanceStrategy
{
public:

	virtual double Distance(const Point& p1, const Point& p2) = 0;
};

