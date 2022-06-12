#include "PrintVisitor.h"
#include "Point.h"
#include "Circle.h"
#include "Line.h"
#include "ShapeComposite.h"

#include <iostream>

// printing functions 
void PrintVisitor::Visit(Point& p) {
	std::cout << p;
};
void PrintVisitor::Visit(Circle& c) {
	std::cout << c;
};
void PrintVisitor::Visit(Line& l) {
	std::cout << l;
};
void PrintVisitor::Visit(ShapeComposite& sc) {
	for (std::shared_ptr<Shape> elem : sc) {
		// this will output all elements in composite  
		// For composites of composites output function is in shapecomposite class  
		std::cout << *elem;
	}
};