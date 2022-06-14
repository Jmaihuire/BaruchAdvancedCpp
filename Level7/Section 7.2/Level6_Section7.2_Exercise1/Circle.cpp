#include "Circle.h"

Circle::Circle(){
	c_ = new Point;
	r_ = new double; //constructor for deep copies
};  // Default constructor
Circle::Circle(const Point& c, double r) {
	c_ = new Point(c);
	r_ = new double(r); //constructor for deep copies
};  // Constructor point and radius
Circle::Circle(const Circle& pt) {
	c_ = new Point(*(pt.c_));
	r_ = new double(*(pt.r_)); //constructor for deep copies
};  // Copy constructor
Circle& Circle::operator=(const Circle& pt) {
	Circle c(pt); //use copy constructor
	return c;
};  // Assignment operator
Point Circle::CenterPoint() {
	return *c_;
};  // Return center point
double Circle::Radius(){
	return *r_;
};  // Return radius
void Circle::CenterPoint(Point centre) {
	delete c_;
	c_ = new Point(centre);
};  // Set center point
void Circle::Radius(double radius) {
	delete r_;
	r_ = new double(radius);
};  // Set radius

std::shared_ptr<Shape> Circle::Clone() {
	Circle s = *this;
	return std::make_shared<Circle>(s);
};