#pragma once
#include "Point.h"
#include <iostream>
/*
Fiona Ross - 02-20-2022
Point Class : this is a 2D point class
*/
// Was getting "redefinition of class header" error without #ifndef 
#ifndef Point_HEADER
#define Point_HEADER

class Point
{

private:

	double x_;
	double y_;


public:
	Point() {};

	Point(double d1, double d2) : x_(d1), y_(d2) {};

	void X(double x)
	{
		// reset x coordinate 
		x_ = x;
	};

	void Y(double y)
	{
		// reset y coordinate 
		y_ = y;
	};


	// destructor 
	~Point() {
		std::cout << "Point object deleted from memory" << std::endl;
	}

};

#endif

