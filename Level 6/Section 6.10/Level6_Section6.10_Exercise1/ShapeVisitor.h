#pragma once

//forward declare shapes
class Point;
class Circle;
class Line;
class ShapeComposite;

class ShapeVisitor
{
public:	
	
	virtual void Visit(Point& p) = 0;
	virtual void Visit(Circle& c)  = 0;
	virtual void Visit(Line& l)  = 0;
	virtual void Visit(ShapeComposite& sc)  = 0; 
};

