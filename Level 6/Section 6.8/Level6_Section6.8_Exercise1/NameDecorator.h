#pragma once
#include "ShapeDecorator.h"
#include <string>

class NameDecorator :
    public ShapeDecorator
{
    //Name decorator for the decorator pattern
private:
    std::string name_;
public:
    NameDecorator(); //default constructor
    NameDecorator(std::shared_ptr<Shape> shape, std::string name); //constructor with shape and name as args
    NameDecorator(const NameDecorator& nd); //copy constructor
    std::string GetName(); //return data member
    void SetName(std::string name); //set name

    std::shared_ptr<Shape> Clone(); //clone message since it is a member of shape
};

