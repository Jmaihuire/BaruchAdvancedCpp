#ifndef Point_cpp
#define Point_cpp

#include "Point.h"
#include "DistanceStrategy.h"
#include "OriginPoint.h"

DistanceStrategy* Point::strat_;
Point::Point(){ 
	x_ = new double; //initialize pointer for deep copy
	y_ = new double;
	//strat_ = new ExactDistance;
};  // Default constructor
Point::Point(double xs, double ys) {
	x_ = new double(xs); //initialize pointer for deep copy
	y_ = new double(ys);
	//strat_ = new ExactDistance;
};  // Constructor with coordinates
Point::Point(const Point& pt) {
	x_ = new double(*(pt.x_)); //initialize pointer for deep copy
	y_ = new double(*(pt.y_));
	//strat_ = new ExactDistance;
};  // Copy constructor
Point& Point::operator=(const Point& pt) {
	Point p(pt); //use copy constructor
	return p;
};  // Assignment operator
double Point::x() const {
	return *x_;
};  // Return x coordinate
double Point::y() const {
	return *y_;
};  // Return y coordinate
void Point::x(double xs) {
	delete x_;
	x_ = new double(xs);
};  // Set x coordinate
void Point::y(double ys) {
	delete y_;
	y_ = new double(ys);
};  // Set y coordinate

// 6.1.2 Part A
double Point::Distance(const Point& p) {
	double dist = strat_->Distance(std::ref( * this), std::ref(p));
	return dist;
}; //distance function

// 6.2.1 Part C 
double Point::Distance() {
	return strat_->Distance(std::ref(* this), std::ref( * OriginPoint::instance()));
}; 

//Part C 6.4
std::shared_ptr<Shape> Point::Clone() {
	Point s = *this;
	return std::make_shared<Point>(s);
};

// 6.6.1 
void Point::setStrat(DistanceStrategy* strat) {
	strat_ = strat;
}
#endif