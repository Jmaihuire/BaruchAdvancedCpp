#pragma once
#include <memory>
class Circle;
class Line;
class Point;

class ConsoleShapeFactory
{
public:
		static std::shared_ptr<Circle> CreateCircle(); //Circle virtual function

	static std::shared_ptr<Line> CreateLine(); //Line virtual function

	static std::shared_ptr<Point> CreatePoint(); //Point virtual function
};

