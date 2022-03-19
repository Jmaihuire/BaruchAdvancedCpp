// Level2_Section2.5_Exercise2.cpp
// Fiona Ross - 03-06-2022
/*
Exercise 2: Machine Epsilon

Machine epsilon gives an upper bound on the relative error due to rounding
in floating point arithmetic. In C++11, epsilon is the difference between 
1.0 and the next representable value of the given floating-point type.

*/
#include <iostream>
#include <cmath>
#include <type_traits>

// epsilon function re-defined to take different types 
template <typename T> 
T CreateElipson()
{
    T epsilon = (T) 1.0;
    while (((T) 1.0 + (T) 0.5 * epsilon) != (T) 1.0)
    {
       epsilon *= (T) 0.5; // casting so that no type promotion occurs
    }
    return epsilon;
}

int main()
{ 
    /*
    Epsilon Explanation:
        Returns the machine epsilon, that is,
        the difference between 1.0 and the next value
        representable by the floating-point type T.
    */

    // Testing INT  
    // Epsilon is expected to break down for integers and return one 
    int epsilon_in = 1;
    std::cout << "Defined INT Epsilon created is: " << std::numeric_limits<int>::epsilon() << std::endl; // The function epsilon returns a value to the e-16 but not zero 
    std::cout << "Homemade INT Epsilon created is: " << CreateElipson<int>() << std::endl; // The homemade version of epsilon returns a zero value 

     // Testing FLOAT 
    // Epsilon is expected to break down for integers and return one 
    float epsilon_in1 = 1.00;
    std::cout << "Defined FLOAT Epsilon created is: " << std::numeric_limits<float>::epsilon() << std::endl; // The function epsilon returns a value to the e-16 but not zero 
    std::cout << "Homemade FLOAT Epsilon created is: " << CreateElipson<float>() << std::endl; // The homemade version of epsilon returns a zero value 

    // Testing DOUBLE
    // Epsilon is expected to break down for integers and return one 
    double epsilon_in2 = 1.00;
    std::cout << "Defined Epsilon created is: " << std::numeric_limits<double>::epsilon() << std::endl; // The function epsilon returns a value to the e-16 but not zero 
    std::cout << "Homemade Epsilon created is: " << CreateElipson<double>() << std::endl; // The homemade version of epsilon returns a zero value 

     // Testing LONG DOUBLE 
    // Epsilon is expected to break down for integers and return one 
    long double epsilon_in3 = 1.00;
    std::cout << "Defined Epsilon created is: " << std::numeric_limits<long double>::epsilon() << std::endl; // The function epsilon returns a value to the e-16 but not zero 
    std::cout << "Homemade Epsilon created is: " << CreateElipson<long double>() << std::endl; // The homemade version of epsilon returns a zero value 

}
