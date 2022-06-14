#pragma once

#include <iostream>

class Shape
{
public:

	//print function
	inline friend std::ostream& operator<<(std::ostream& output, const Shape& s)
	{
		return s.out(output);
	}

	virtual std::shared_ptr<Shape> Clone() = 0; //pure virtual
private:
	//virtual function
	virtual std::ostream& out(std::ostream& o) const { return o; };
};

