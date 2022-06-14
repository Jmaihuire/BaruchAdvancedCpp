#include "ConsoleShapeFactory.h"
#include <iostream>
#include <tuple>
#include "Point.h"
#include "Circle.h"
#include "Line.h"

std::shared_ptr<Circle> ConsoleShapeFactory::CreateCircle() {
	double r; //radius
	double x; //center x coord
	double y; //center y coord

	//gather data
	std::cout << "Origin x coordinate input: ";
	std::cin >> x;
	std::cout << "\nOrigin y coordinate input: ";
	std::cin >> y;
	std::cout << "\nRadius input: ";
	std::cin >> r;

	//create shape and output pointer
	Point c(x,y); //center
	std::cout << "\nOutputting Circle pointer...\n";
	return std::make_shared<Circle>(c, r);
}; 

std::shared_ptr<Line> ConsoleShapeFactory::CreateLine() {
	double x1; //point 1 x 
	double y1; //point 1 y
	double x2; //point 2 x 
	double y2; //point 2 y

	//gather data
	std::cout << "Making Line........\nEnter x and y of first point (x y): ";
	std::cin >> x1 >> y1;
	std::cout << "\nEnter x and y of second point (x y): ";
	std::cin >> x2 >> y2;

	//create shape and output pointer
	Point p1(x1, y1); //first point
	Point p2(x2, y2); //second point
	std::cout << "\nOutputting Line pointer...\n";
	return std::make_shared<Line>(p1, p2);
}; 

std::shared_ptr<Point> ConsoleShapeFactory::CreatePoint() {
	double x; //x coord
	double y; //y coord

	//gather data
	std::cout << "Input x and y coordinates for Point(x y): ";
	std::cin >> x >> y;

	//create shape and output pointer
	std::cout << "\nPoint pointer...\n";
	return std::make_shared<Point>(x, y);
};

std::tuple<std::shared_ptr<Circle>, std::shared_ptr<Line>, std::shared_ptr<Point>> ConsoleShapeFactory::CreateTuple() {
	auto pnt = CreatePoint();
	auto ln = CreateLine();
	auto cir = CreateCircle();
	return std::make_tuple(cir, ln, pnt);
}; 