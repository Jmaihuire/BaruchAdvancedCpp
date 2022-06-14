#pragma once
#include <functional>
#include <memory>

class Circle;
class Point;
class Line;

// the point of this class is to create a single class that is an explicit composition of factory methods 

class Factory
{
private:
	//made these private because these are the stored methods 
	std::function<std::shared_ptr<Circle>()> circleBuilder;
	std::function<std::shared_ptr<Point>()> pointBuilder;
	std::function<std::shared_ptr<Line>()> lineBuilder;

public:
	// chose to use std::function over boost 
	Factory(std::function<std::shared_ptr<Circle>()> crcle, std::function<std::shared_ptr<Point>()> pt, std::function<std::shared_ptr<Line>()> ln);
	void AssignPointBuilder(std::function < std::shared_ptr<Point>()> pt); // this allows assignment
	void AssignCircleBuilder(std::function < std::shared_ptr<Circle>()> crcle); //this allows assignment 
	void AssignLineBuilder(std::function < std::shared_ptr<Line>()> ln); //this allows assignment 
	std::shared_ptr<Point> CreatePoint(); //this essentially creates methods using the stored functions 
	std::shared_ptr<Circle> CreateCircle(); //this essentially creates methods using the stored functions 
	std::shared_ptr<Line> CreateLine();//this essentially creates methods using the stored functions 

};

