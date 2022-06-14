#ifndef Point_hpp 
#define Point_hpp

#include "Shape.h"

class DistanceStrategy; //forward declare distance strat

class Point :
    public Shape
{
    double* x_; //use pointers for deep copy
    double* y_;
    static DistanceStrategy* strat_; //pointer to current distance strategy 
public:
    Point();  // Default constructor
    Point(double xs, double ys);  // Constructor with coordinates
    Point(const Point& pt);  // Copy constructor
    Point& operator=(const Point& pt);  // Assignment operator
    double x() const;  // Return x coordinate
    double y() const;  // Return y coordinate
    void x(double xs);  // Set x coordinate
    void y(double ys);  // Set y coordinate

    double Distance(const Point& p); //distance function

    //Stateless distance implementation
    double Distance(const Point& p, DistanceStrategy& strat); //distance function

    double Distance();

    std::shared_ptr<Shape> Clone();

    //print function
    std::ostream& out(std::ostream& output) const
    {
        output << "Point: " << *x_ << ", " << *y_ << std::endl;
        return output;
    }

    //destructor
    ~Point() {
        delete x_;
        delete y_;
    }

    static void setStrat(DistanceStrategy* strat);
};

#endif