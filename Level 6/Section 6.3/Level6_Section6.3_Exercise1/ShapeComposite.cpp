#include "ShapeComposite.h"

// I know in the instructions it said to use Shape* s but in the
// forum questions it says to use shared_ptr and so going with that

void ShapeComposite::AddShape(std::shared_ptr<Shape> s) {
  shapeList.emplace_back(s);  // add shape to list
}

// Part F: creating iterators 
ShapeComposite::it ShapeComposite::begin() { return shapeList.begin(); }
ShapeComposite::it ShapeComposite::end() { return shapeList.end(); }

// Part G: returning size 
std::size_t ShapeComposite::count() { return shapeList.size(); }
