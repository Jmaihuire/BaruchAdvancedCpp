#pragma once
#include <memory>
#include <tuple>

class Circle;
class Line;
class Point;

class ShapeFactory
{
public:
	
	virtual std::tuple<std::shared_ptr<Circle>, std::shared_ptr<Line>, std::shared_ptr<Point>> CreateTuple() = 0; //7.1 Tuple function....
};

