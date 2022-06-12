//Alex Moody: Decorator pattern base class
#pragma once
#include "Shape.h"
class ShapeDecorator :
	public Shape
{
	//Abstract class in used in decorator pattern
private:
	std::shared_ptr<Shape> decoratedShape; //private data-member holding shape to decorate
public:
	ShapeDecorator() {
		decoratedShape = nullptr;
	}//default constructor that sets the shape data member to null

	ShapeDecorator(std::shared_ptr<Shape> shape) {
		decoratedShape = shape;
	} //constructor with shape* as argument

	std::shared_ptr<Shape> GetShape() {
		return decoratedShape;
	} //return data member

	void SetShape(std::shared_ptr<Shape> shape) {
		decoratedShape = shape;
	}

};

