#pragma once
#include "ShapeFactory.h"

class ConsoleShapeFactory :
    public ShapeFactory
{
	std::shared_ptr<Circle> CreateCircle() override; //Circle virtual function

	std::shared_ptr<Point> CreatePoint() override; //Point virtual function
};

