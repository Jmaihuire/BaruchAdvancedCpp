#include "NameDecorator.h"

NameDecorator::NameDecorator() : ShapeDecorator() {
	name_ = "";
} //call base constructor and set name to empty

NameDecorator::NameDecorator(std::shared_ptr<Shape> shape, std::string name): ShapeDecorator(shape) {
	name_ = name;
}; //constructor with shape and name as args

NameDecorator::NameDecorator(const NameDecorator& nd) {
	name_ = nd.name_;
}//Copy constructor

std::string NameDecorator::GetName() {
	return name_;
} //return data member

void NameDecorator::SetName(std::string name) {
	name_ = name;
}//set the name

std::shared_ptr<Shape> NameDecorator::Clone() {
	NameDecorator nd = *this;
	return std::make_shared<NameDecorator>(nd);
}; //clone function

