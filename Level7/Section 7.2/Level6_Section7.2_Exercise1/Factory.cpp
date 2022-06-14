#include "Factory.h"

// Part A: 
// this makes single class which is a composition of factory methods. This function in particular puts them all together 
// chose to use std::function over boost 
Factory::Factory(std::function<std::shared_ptr<Circle>()> c,
                 std::function<std::shared_ptr<Point>()> p,
                 std::function<std::shared_ptr<Line>()> l) {
  pointBuilder = p;
  circleBuilder = c;
  lineBuilder = l;
};


// this makes a new point builder. Its basically just an assignment method and 
// used after the object is already initiated 
void Factory::AssignPointBuilder(std::function < std::shared_ptr<Point>()> pt) {
	pointBuilder = pt;
}; 

// this makes a new circle builder. Its basically just an assignment method and
// used after the object is already initiated
void Factory::AssignCircleBuilder(std::function < std::shared_ptr<Circle>()> crcle) {
	circleBuilder = crcle;
}; 

// this makes a new line builder. Its basically just an assignment method and
// used after the object is already initiated
void Factory::AssignLineBuilder(std::function < std::shared_ptr<Line>()> ln) {
	lineBuilder = ln;
}; 

// Made the returns shared pointer 
// these methods essentially just access the stored methods 
std::shared_ptr<Point> Factory::CreatePoint() {
	return pointBuilder();
}; 
std::shared_ptr<Circle> Factory::CreateCircle() {
	return circleBuilder();
};
std::shared_ptr<Line> Factory::CreateLine() {
	return lineBuilder();
};