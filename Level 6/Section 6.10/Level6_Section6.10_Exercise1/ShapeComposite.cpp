#include "ShapeComposite.h"

void ShapeComposite::AddShape(std::shared_ptr<Shape> s) {
	shapeList.emplace_back(s); //add shape to list 
}

//part f
ShapeComposite::it ShapeComposite::begin() {
	return shapeList.begin();
}
ShapeComposite::it ShapeComposite::end() {
	return shapeList.end();
}
//Add constant iterators so we can use c++11 for loop
ShapeComposite::constit ShapeComposite::begin() const {
	return shapeList.begin();
}
ShapeComposite::constit ShapeComposite::end() const {
	return shapeList.end();
}

//Part g
std::size_t ShapeComposite::count() {
	return shapeList.size();
}

//Part C 6.4
std::shared_ptr<Shape> ShapeComposite::Clone() {
	ShapeComposite s(*this);
	return std::make_shared<ShapeComposite>(s);
}; //clone function calls copy constructor

//Part D 6.4
ShapeComposite::ShapeComposite(const ShapeComposite& s) {
	for ( std::shared_ptr<Shape> elem : s){
		this->AddShape(elem->Clone());
	}
}; //public copy constructor
ShapeComposite& ShapeComposite::operator=(const ShapeComposite& pt) {
	ShapeComposite newComposite(pt);
	return newComposite;
};  // Assignment operator

//Print function overload:
std::ostream& ShapeComposite::out(std::ostream& o) const
{
	for (std::shared_ptr<Shape> elem : *this) {
		o << *elem;
	}
	return o;
}

//NEW Shape composite accept function for visitor pattern example 6.10!!
void ShapeComposite::Accept(ShapeVisitor& sv) {
	sv.Visit(*this);
};