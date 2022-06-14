#pragma once
#include "ShapeComposite.h"
#include "Point.h"
class Point;

// Polyline is a collection of points
// the implementation should use template template parameter
// ie, its now a template class 
template<template<typename, typename> typename Container> //template definition 
class PolyLine : public ShapeComposite<Container> {
 public:
  // used for adding points to the multi point line
  void AddPoint(std::shared_ptr<Point> p) {
    ShapeComposite<Container>::AddShape(
        p);  // pulling in methods from base class
  };
};

