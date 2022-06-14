#include "ShapeFactory.h"
#include <iostream>
#include "ConsoleShapeFactory.h"
#include "PolyLine.h"
#include "Line.h"

std::shared_ptr<Line> ShapeFactory::CreateLine() {
	std::cout << "Selecting coordinates for Point 1 in line......\n";
	auto p1 = CreatePoint(); //this is an abstract function..making this a template method
	std::cout << "Selecting coordinates for Point 2 in line......\n";
	auto p2 = CreatePoint();
	return std::make_shared<Line>(*p1, *p2);
} 

std::shared_ptr<PolyLine<std::vector>> ShapeFactory::CreatePolyLine() {
  int size;
  std::cout << "Make polyline of ____ points (insert number) : ";
  std::cin >> size;
  PolyLine<std::vector> pl;
  for (int i = 0; i < size; i++) {
    auto tempPoint = CreatePoint();
    pl.AddPoint(tempPoint);
  };
  std::cout << "size of Polyline is: " << pl.count() << std::endl;
  std::cout << "Printing polyline elements: \n";
  std::cout << pl;  // using printing functionality developed in level 6

  return std::make_shared<PolyLine<std::vector>>(pl);
}