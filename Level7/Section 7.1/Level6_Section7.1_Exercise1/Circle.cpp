#include "Circle.h"

Circle::Circle(){
	c_ = new Point;
	r_ = new double; 
}; //constructor 
Circle::Circle(const Point& c, double r) {
	c_ = new Point(c);
	r_ = new double(r); 
};  // Constructor 
Circle::Circle(const Circle& pt) {
	c_ = new Point(*(pt.c_));
	r_ = new double(*(pt.r_));
};  // Copy constructor
Circle& Circle::operator=(const Circle& pt) {
	Circle c(pt); 
	return c;
};  // Assignment
Point Circle::CenterPoint() {
	return *c_;
};  // gets the center point of circle
double Circle::Radius(){
	return *r_;
};  
void Circle::CenterPoint(Point centre) {
	delete c_;
	c_ = new Point(centre);
};  
void Circle::Radius(double radius) {
	delete r_;
	r_ = new double(radius);
};  

std::shared_ptr<Shape> Circle::Clone() {
	Circle s = *this;
	return std::make_shared<Circle>(s);
};