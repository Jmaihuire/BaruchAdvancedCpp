#ifndef SHAPE_COMPOSITE_H //Add these include headers so we can include the cpp file at the base of this template class. I know I should be using these type of headers instead of #pragma once, however I do not have time to correct all of the header and cpp files with this change.
#define SHAPE_COMPOSITE_H
#include "Shape.h"
//We need to make shape composite into template function for section 7.3 so it can take a generic container, we will do this with template template parameters
template<template<typename,typename> typename Container>
class ShapeComposite :
    public Shape
{
private:
    Container<std::shared_ptr<Shape>,std::allocator<std::shared_ptr<Shape>>> shapeList; //we now define shapelist with the template Container, we know that it will hold shape pointers so we define that here

public:
    ShapeComposite() {};
    void AddShape(std::shared_ptr<Shape> s);

    ShapeComposite(const ShapeComposite& s); //public copy constructor
    ShapeComposite& operator=(const ShapeComposite& pt);  // Assignment operator

    //Need to specify typename in iterator definition
    typename Container<std::shared_ptr<Shape>, std::allocator<std::shared_ptr<Shape>>>::iterator begin();
    typename Container<std::shared_ptr<Shape>, std::allocator<std::shared_ptr<Shape>>>::iterator end();
    typename Container<std::shared_ptr<Shape>, std::allocator<std::shared_ptr<Shape>>>::const_iterator begin() const;
    typename Container<std::shared_ptr<Shape>, std::allocator<std::shared_ptr<Shape>>>::const_iterator end() const;

    std::size_t count();

    std::ostream& out(std::ostream& o) const override; //print function 

    std::shared_ptr<Shape> Clone() override;


};

#ifndef SHAPE_COMPOSITE_CPP
#include "ShapeComposite.cpp"
#endif

#endif

