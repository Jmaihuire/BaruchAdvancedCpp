#pragma once
#include "ShapeFactory.h"

class ConsoleShapeFactory :
    public ShapeFactory
{
	std::shared_ptr<Circle> CreateCircle(); //Circle virtual function

	std::shared_ptr<Line> CreateLine(); //Line virtual function

	std::shared_ptr<Point> CreatePoint(); //Point virtual function

	std::tuple<std::shared_ptr<Circle>, std::shared_ptr<Line>, std::shared_ptr<Point>> CreateTuple(); //7.1 Tuple function that packages all shapes into one output. This helps reduce the number of builders required.
};

