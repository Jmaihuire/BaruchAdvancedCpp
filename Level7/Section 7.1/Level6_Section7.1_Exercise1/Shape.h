#pragma once

#include <iostream>

class Shape
{
public:

	inline friend std::ostream& operator<<(std::ostream& output, const Shape& s)
	{
		return s.out(output); //call out function that will be overloaded by all child classes
	}

	virtual std::shared_ptr<Shape> Clone() = 0; //pure virtual
private:
	virtual std::ostream& out(std::ostream& o) const { return o; };
};

