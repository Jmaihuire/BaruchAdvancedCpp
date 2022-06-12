#pragma once

#include <iostream>
#include "ShapeVisitor.h"

class Shape
{
public:

	//print function
	inline friend std::ostream& operator<<(std::ostream& output, const Shape& s)
	{
		return s.out(output); //call out function that will be overloaded by all child classes
	}

	//6.4 prototype pattern
	virtual std::shared_ptr<Shape> Clone() = 0; //pure virtual

	//6.10 accept method
	virtual void Accept(ShapeVisitor& v) = 0; //visitor
private:
	//virtual function
	virtual std::ostream& out(std::ostream& o) const { return o; };
};

