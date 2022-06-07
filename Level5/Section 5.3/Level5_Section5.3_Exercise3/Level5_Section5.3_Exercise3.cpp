// Level5_Section5.3_Exercise3.cpp 
// Fiona Ross 
// Unordered Collections 

#include <iostream>
#include "StopWatch.h" // pulled in from 3.5.6
#include "Point.h" // pulled in from 4.3.2
#include <boost/unordered_set.hpp>
#include <functional>
#include <unordered_set>
#include <boost/functional/hash.hpp>

// Pulled from lecture 
struct PointHash : std::unary_function<Point, std::size_t> {
  std::size_t operator()(const Point& pt) const {
    // TBD by student
    std::size_t seed = 0;
    boost::hash_combine(seed, pt.X());
    boost::hash_combine(seed, pt.Y());
    return seed;
  }
};


// Part B: Custom Hash
struct PointHashCustom : std::unary_function<Point, std::size_t> {
  std::size_t operator()(const Point& pt) const {
    // custom function that does not use boost/stl hash
    std::size_t hash_value = pt.X() * pt.X() * pt.X() - pt.Y(); // really random function
    return hash_value;
  }  
};

int main()
{
    // This is all time comparison so pulled in the stopwatch from 3.5.6 to make 
    // this easier 

    // Part A: 
    boost::unordered_multiset<Point, PointHash> p_multiset;  // initialize map
    int n = 8; // size of list 

    // adding timing 
    StopWatch s1; 
    s1.StartStopWatch();

    // using loop 
    for (int i = 0; i < n; i++) {
      p_multiset.emplace(Point(i, i));
    }

    // erase all points
    for (auto pcur = p_multiset.begin(); pcur != p_multiset.end();) {
      pcur = p_multiset.erase(pcur);
      ++pcur;
    }

    // stopping and outputting time 
    s1.StopStopWatch();
    std::cout << "Part A took: " << s1.GetTime();

    // Part B: Custom hash
    // Essentially same thing as above but using unordered_multiset
    // making number of ponts the same so can compare 

    s1.Reset();
    s1.StartStopWatch();
    boost::unordered_multiset<Point, PointHashCustom> p_custmultiset;
    // create a list of points
    for (int i = 0; i < n; i++) {
      p_custmultiset.emplace(Point(i, i));
    }
    ////erase all points
    for (auto it = p_custmultiset.begin(); it != p_custmultiset.end();) {
      it = p_custmultiset.erase(it);
      ++it;
    }

    s1.StopStopWatch();
    std::cout
        << "\nPart B took : " << s1.GetTime()
        << std::endl;  // this method has shorter processing time than part A,
                       // perhaps due to the simplistic hash function

    // Part C: use std::unordered_multiset
    s1.Reset();
    s1.StartStopWatch();
    std::unordered_multiset<Point, PointHashCustom>
        p_stdmultiset;  
    // create a list of points
    for (int i = 0; i < n; i++) {
      p_stdmultiset.emplace(Point(i, (i + 1)));
    }
    // erase all points
    for (auto it = p_stdmultiset.begin(); it != p_stdmultiset.end();) {
      it = p_stdmultiset.erase(it);
      ++it;
    }
    s1.StopStopWatch();
    std::cout << "Part C took: " << s1.GetTime()
              << std::endl;  // STL is typically shorter than boost, but longer
                             // than simple custom hash function
}



