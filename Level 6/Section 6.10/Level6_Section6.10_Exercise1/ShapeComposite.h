#pragma once
#include "Shape.h"
#include <list>
class ShapeComposite :
    public Shape
{
private:
    std::list<std::shared_ptr<Shape>> shapeList; 

public:
    ShapeComposite() {};
    void AddShape(std::shared_ptr<Shape> s); //Part D

    //Part E typedefs
    typedef std::list<std::shared_ptr<Shape>>::iterator it; //list iterator
    typedef std::list<std::shared_ptr<Shape>>::const_iterator constit; //constant list iterator

    //Part F begin and end
    it begin();
    it end();
    constit begin() const;
    constit end() const;

    //Part G:
    std::size_t count();

    std::shared_ptr<Shape> Clone();

    //6.4 Part D
    ShapeComposite(const ShapeComposite& s); //private copy constructor
    ShapeComposite& operator=(const ShapeComposite& pt);  // Assignment operator

    //Print support:
    std::ostream& out(std::ostream& o) const;

    // 6.10 
    void Accept(ShapeVisitor& sv);

};

