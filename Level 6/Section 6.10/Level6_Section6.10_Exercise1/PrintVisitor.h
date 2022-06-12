#pragma once
#include "ShapeVisitor.h"
class PrintVisitor :
    public ShapeVisitor
{
    //Works with shapevisitor base class to print the shape information on the screen
public:

    virtual void Visit(Point& p);
    virtual void Visit(Circle& c) ;
    virtual void Visit(Line& l) ;
    virtual void Visit(ShapeComposite& sc) ; 

};

