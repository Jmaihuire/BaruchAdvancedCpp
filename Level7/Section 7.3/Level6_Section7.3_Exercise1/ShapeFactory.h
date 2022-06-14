#pragma once
#include <memory>
#include <vector>

class Circle;
class Line;
class Point;
template<template<typename, typename> typename Container>
class PolyLine;

class ShapeFactory
{
public:
	virtual std::shared_ptr<Circle> CreateCircle() = 0; //Circle virtual function

	virtual std::shared_ptr<Line> CreateLine() final; // changed to have template function 

	virtual std::shared_ptr<Point> CreatePoint() = 0; //Point virtual function

	virtual std::shared_ptr<PolyLine<std::vector>> CreatePolyLine() final; 
};

