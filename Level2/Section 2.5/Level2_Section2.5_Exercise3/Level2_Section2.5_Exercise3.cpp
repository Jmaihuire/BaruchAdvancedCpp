// Level2_Section2.5_Exercise3.cpp
/*
Fiona Ross - 03-06-2022
Machine Precission Issues 

Expirimenting with 
overflow_error
float_next
float_prior
float_advance
float_distance
std/boost::nextafter(x,y)

*/

#include <iostream>
#include <boost/math/special_functions/next.hpp>
#include <boost/math/special_functions/ulp.hpp>

int main()
{
    // Number gaps/bits/ULP between
    // 2 floating-point values a and b
    // Returns a signed value indicating whether a < b
    double a = 0.1; 
    double b = a + std::numeric_limits<double>::min();
    std::cout << boost::math::float_distance(a, b) << std::endl;
    float a1 = 1.0; float b1 = 0.0;
    //std::cout << boost::math::float_distance(a1, b1) << std::endl; // this last line is causing issues 

    // Float Next 
    // Equivalent to finding the next representable value after x (1.F) in direction y (999)
    double a_fnxt = 1.0;
    std::cout << "The nearest (exact) representation of double = 1.0 using ulp() is: " << boost::math::ulp(a_fnxt) << std::endl;
    std::cout << "The output of float_next is: " << boost::math::float_next(a_fnxt) << std::endl;
    //std::cout << "The output of float next of the max double is: " << boost::math::float_next(std::numeric_limits<double>::max()) << std::endl; //this actually causes overflow

    // Float Prior
    // Equivalent to finding the next representable value after x (1.F) in direction y (999)
    double a_fpri = 1.0;
    std::cout << "The output of float_prior is: " << boost::math::float_prior(a_fpri) << std::endl;
    //std::cout << "The output of float next of the max double is: " << boost::math::float_prior(std::numeric_limits<double>::min()) << std::endl; //this actually causes overflow


    // Float Distance 
    // Equivalent to finding the units of last place (ULP) between a & b
    float a_fadv = 0.00001;
    float b_fadv = 0.00002;
    std::cout << "Return of float distance: "<< boost::math::float_distance(a_fadv, b_fadv) << std::endl;
    float ulp_dist = (float) boost::math::ulp(a_fadv) -  (float) boost::math::ulp(b_fadv); 
    std::cout << "Checking the ulp(a-b) is: " << ulp_dist << std::endl; //these do not return the same thing so not sure what is different here... 

    // Float Advance
    //Advance a floating point number by specified number of ulp;
    float start = 1.0;
    std::cout << "Starting value: " << start << std::endl;
    std::cout << "Ending value after advance " << boost::math::float_advance(start, 999) << std::endl; //advance start by the distance between a and b

    // Float Distance
    //Return the next representable value of x in the direction of y:
    float direction = 3.0;
    std::cout << "Next representable value after " << start << " in direction of " << direction << " is " << boost::math::nextafter(start, direction) << std::endl;
}

