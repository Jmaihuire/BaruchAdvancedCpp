#pragma once
class Point; 
class DistanceStrategy
{
public:
	//Abstract Distance Strategy class
	//pure virtual Distance function:
	virtual double Distance(const Point& p1, const Point& p2) = 0;
};

