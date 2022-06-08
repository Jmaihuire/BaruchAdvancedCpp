#pragma once
#include <list>
#include "Shape.h"

// I know in the instructions it said to use Shape* s but in the
// forum questions it says to use shared_ptr and so going with that

class ShapeComposite : public Shape {
 private:
 // Part B: private std::list data members 
  std::list<std::shared_ptr<Shape>>
      shapeList;
  
  // Part C: copy & assignment operators 
  ShapeComposite(const ShapeComposite& s);  
  ShapeComposite& operator=(const ShapeComposite& pt);  

 public:
  ShapeComposite(){};
  // I know in the instructions it said to use Shape* s but in the 
  // forum questions it says to use shared_ptr and so going with that 
  void AddShape(std::shared_ptr<Shape> s);  // Part D

  // Part E:
  typedef std::list<std::shared_ptr<Shape>>::iterator it;  // list iterator
  typedef std::list<std::shared_ptr<Shape>>::const_iterator
      constit;  // constant list iterator

  // Part F: 
  it begin();
  it end();

  // Part G:
  std::size_t count();
};
