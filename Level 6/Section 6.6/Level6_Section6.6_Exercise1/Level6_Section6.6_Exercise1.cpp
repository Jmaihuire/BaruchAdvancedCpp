// Level6_Section6.6_Exercise1.cpp 
// Fiona Ross 
//  Calculate point distance using a Strategy Pattern

#include <iostream>
#include "Point.h"
#include "ExactDistance.h"
#include "ApproximateDistance.h"
#include "OriginPoint.h"



int main()
{
    // Part F
    // Program calculating distance between two points using different strategies 
    // Strategies are: approximate & exact distance 

    // Step 1: Make points & origin
    Point pt1(1.0, 5.0);
    Point pt2(2.0, 6.0);
    auto orig = OriginPoint::instance();
    orig->x(1.0);
    orig->y(1.0);
    // have to set origin since no longer default to 0,0
    
    // Step 2: approximate 
    ApproximateDistance* approximate = new ApproximateDistance();
    pt1.setStrat(approximate);
    std::cout << "Distance: " << pt1.Distance(pt2) << std::endl;
    std::cout << "Distance from origin: " << pt1.Distance() << std::endl;

    // Step 2: exact
    ExactDistance* exact = new ExactDistance();
    pt1.setStrat(exact);
    std::cout << "Distance: " << pt1.Distance(pt2) << std::endl;
    std::cout << "Distance from origin: " << pt1.Distance() << std::endl;

    // Output Approx is 2
    // Output Exact is 1.41421
    // Difference is ~ 0.6

}

