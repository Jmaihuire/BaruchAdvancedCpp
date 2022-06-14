#include "ConsoleShapeFactory.h"
#include <iostream>
#include "Point.h"
#include "Circle.h"
#include "Line.h"

std::shared_ptr<Circle> ConsoleShapeFactory::CreateCircle() {
	double r; //radius
	double x; //center x coord
	double y; //center y coord

	//gather data
	std::cout << "Making Circle........\nEnter origin x coordinate: ";
	std::cin >> x;
	std::cout << "\nEnter origin y coordinate: ";
	std::cin >> y;
	std::cout << "\nEnter radius: ";
	std::cin >> r;

	//create shape and output pointer
	Point c(x,y); //center
	std::cout << "\nOutputting Circle pointer...\n";
	return std::make_shared<Circle>(c, r);
}; //Circle virtual function

std::shared_ptr<Point> ConsoleShapeFactory::CreatePoint() {
	double x; //x coord
	double y; //y coord

	//gather data
	std::cout << "Enter x and y coordinates (x y): ";
	std::cin >> x >> y;

	//create shape and output pointer
	std::cout << "\nPoint pointer...\n";
	return std::make_shared<Point>(x, y);
}; //Point virtual function