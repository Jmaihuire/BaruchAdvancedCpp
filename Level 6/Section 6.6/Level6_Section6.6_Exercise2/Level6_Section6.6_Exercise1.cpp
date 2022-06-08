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
    // Step 1: Make points & origin
    Point pt1(1.0, 5.0);
    Point pt2(2.0, 6.0);
    
    // Don't have to do this... 
    /*auto orig = OriginPoint::instance();
    orig->x(1.0);
    orig->y(1.0);*/
    // have to set origin since no longer default to 0,0
    
    // Step 2: approximate 
    ApproximateDistance approximate;
    std::cout << "Distance: " << pt1.Distance(pt2, approximate);
    
    std::cout << std::endl; 

    // Step 2: exact
    ExactDistance exact;
    std::cout << "Distance: " << pt1.Distance(pt2, exact) << std::endl;

    // Thoughts: 
    // this approach seems much simpler and fewer steps, so usability is a huge bonus. 
    // downside (ie. benefit of prior approach), is there is probabilty more control. 
    // you could use a specific state with a specific object. 
}

