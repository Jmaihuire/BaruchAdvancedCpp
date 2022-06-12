// Level6_Section6.7_Exercise1.cpp 
// Fiona Ross 
// Factory Patterns : Adding shape factories to the shape hierarchy


#include <iostream>
#include "Shape.h"
#include "ShapeFactory.h"
#include "ConsoleShapeFactory.h"
#include "Line.h"
#include "Circle.h"
#include "ExactDistance.h"


int main()
{

    // Part E: Testing
    ShapeFactory* factory = new ConsoleShapeFactory;

    // Point
    std::shared_ptr<Point> point = factory->CreatePoint();

    // Line 
    std::shared_ptr<Line> line = factory->CreateLine();

    // Circle
    std::shared_ptr<Circle> circle = factory->CreateCircle();
    ;

    // Checks 
    std::cout << "Point x" << point->x() << std::endl;
    std::cout << "Point y" << point->y() << std::endl;
    std::cout << "Line distance: " << line->length() << std::endl;
    std::cout << "Circle Radius: " << circle->Radius() << std::endl;
    std::cout << "Circle Center Point " << circle->CenterPoint() << std::endl;

    //Its running but not sure I am setting the values correctly...
}

