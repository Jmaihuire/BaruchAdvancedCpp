#pragma once
#include "Shape.h"
#include "Point.h"
class Circle :
    public Shape
{
    Point* c_;
    double* r_;
public:
    Circle();  //default
    Circle(const Point& c, double r);  //constructor 
    Circle(const Circle& pt);  // Copy
    Circle& operator=(const Circle& pt);  // Assignment
    Point CenterPoint();  

    double Radius();
    void CenterPoint(Point centre);
    void Radius(double radius);

    std::shared_ptr<Shape> Clone();


    std::ostream& out(std::ostream& o) const
    {
        o << "Center: " << c_->x() << ", " << c_->y() << "; Radius: " << *r_ << std::endl;
        return o;
    }
};

