#pragma once
#include "Shape.h"
class ShapeDecorator :
	public Shape
{
	//Abstract class in used in decorator pattern
private:
	std::shared_ptr<Shape> decoratedShape; 
public:
	ShapeDecorator() {
		decoratedShape = nullptr;
	}

	ShapeDecorator(std::shared_ptr<Shape> shape) {
		decoratedShape = shape;
	} 

	std::shared_ptr<Shape> GetShape() {
		return decoratedShape;
	} 

	void SetShape(std::shared_ptr<Shape> shape) {
		decoratedShape = shape;
	}

};

