// Level5_Section5.3_Exercise2.cpp 
// Fiona Ross 
// Hash for User Defined Types 

#include <iostream>
#include <boost/functional/hash.hpp>
#include <functional>
#include <unordered_set>
#include "Point.h"

// creating linesegment type as between two points 
using LineSegment = std::pair<Point, Point>;

// pulling hash_value from lecture & modifying 
std::size_t hash_value(LineSegment& line) { 
    std::size_t seed = 0; 
    boost::hash_combine(seed, line.first.hash_value());
    boost::hash_combine(seed, line.second.hash_value());
    return seed;
}

// Adding this to the boost namespace so that boost can call it 
namespace boost {
template <>
struct hash<Point> {
  std::size_t operator()(const Point& p) { return Point::hash_value(p); }
};
}

// Part C: custom hash function 
struct PointHash : std::unary_function<Point, std::size_t>{
    
    std::size_t operator()(const Point & pt) const {
    // there was a tbd here but don't think it needed anything? 
    std::size_t seed = 0;
    boost::hash_combine(seed, pt.X());
    boost::hash_combine(seed, pt.Y());
    return seed;
    }
};
    
    int main()
{
    // Part B: List of Point instances and compute hash 
        std::list<Point> plist;
        // really should have just done this in a loop...
        Point p1 = Point(1, 2);
        plist.push_back(p1);
        Point p2 = Point(2, 3);
        plist.push_back(p2);
        Point p3 = Point(3,4);
        plist.push_back(p3);
        Point p4 = Point(4,5);
        plist.push_back(p4);
           

        // using hash_range 
        auto out_hash = boost::hash_range(plist.begin(), plist.end());
        std::cout << "Output of hash list is: " << out_hash;

        // Part C: 
        PointHash phash1;
        auto customHash = phash1(plist.front());
        std::cout << "\nOutput of hash list using custom hash: " << customHash; 

    }

