#include "ShapeComposite.h"

// I know in the instructions it said to use Shape* s but in the
// forum questions it says to use shared_ptr and so going with that

void ShapeComposite::AddShape(std::shared_ptr<Shape> s) {
  shapeList.emplace_back(s);  // add shape to list
}

// Part F: creating iterators 
ShapeComposite::it ShapeComposite::begin() { return shapeList.begin(); }
ShapeComposite::it ShapeComposite::end() { return shapeList.end(); }

// adding to access for loops 
ShapeComposite::constit ShapeComposite::begin() const {
  return shapeList.begin();
}
ShapeComposite::constit ShapeComposite::end() const { return shapeList.end(); }


// Part G: returning size 
std::size_t ShapeComposite::count() { return shapeList.size(); }

// Part C 6.4
std::shared_ptr<Shape> ShapeComposite::Clone() {
  ShapeComposite s(*this);
  return std::make_shared<ShapeComposite>(s);
};  // clone function calls copy constructor

// Part D 6.4
ShapeComposite::ShapeComposite(const ShapeComposite& s) {
  for (std::shared_ptr<Shape> elem : s) {
    this->AddShape(elem->Clone());
  }
};  // public copy constructor
ShapeComposite& ShapeComposite::operator=(const ShapeComposite& pt) {
  ShapeComposite newComposite(pt);
  return newComposite;
};  // Assignment operator
