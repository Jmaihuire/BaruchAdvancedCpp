// Level7_Section7.5_Exercise1.cpp
// Fiona Ross 
// Next Generation Strategy Pattern/Mixins/Plugins

#include <iostream>
#include "Point.h"
#include "DistanceStrategy.h"
#include "ExactDistance.h"
#include "ApproximateDistance.h"

// Not much has changed in the code but code changes includes: 
// DistanceStrategy -> The Point class functionality didnt change but now using
// function wrapper (previously had derived clasS)

// Other side note is I interpreted Part D as optional and since so low on time did not do it

int main()
{
  // Initializatoin 
  Point p1(3.0, 4.0); //point 
  Point p2(1.0, 1.0); //point 
  DistanceStrategy exact(
      ExactDistance::Distance);  // pythagorus using static distance
                                 //  and is a strategy 
  DistanceStrategy approx(ApproximateDistance::Distance); 

  // Part B:
  p1.setStrat(&exact);
  std::cout << "Exact & state: " << p1.Distance(p2) << std::endl; // exact & state 
    // use exact strategy
  std::cout << "Exact & stateless: " << p1.Distance(p2, exact)
            << std::endl;                                         // exact & stateless
  p1.setStrat(&approx);
  std::cout << "Approx & state: " << p1.Distance(p2) << std::endl; // approx & state 

  std::cout << "Exact Distance stateless: " << p1.Distance(p2, approx) // approx & stateless
            << std::endl;

  // Part C
  // Now consider the case when the algorithm needs to hold data (for example, a static counter that is incremented each time the algorithm is called) in-between function calls. 
  // How would you combine OOP classes and universal function wrappers to solve this problem?

  // --> The counter does this for us! 
  std::cout << "Exact counter is: " << exact.getCounter() << std::endl; 
            
  std::cout << "Approx counter is: " << approx.getCounter() << std::endl;
}
