// Level1_Section1.5_Exercise2.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*
Exercise 2: Application I, Numeric Algorithms with Tuples

Part A) 
 Create a template class with static member functions to compute 
 the maximum, sum and average of the elements in the tuple

 Part B) 
 Test the code on tuples with two and three elements whose underlying 
 type is double.

 Part C) 
  Compute the sum and average of a tuple whose element type is 
  std::complex<int>

  Exercise Used Resources:
  https://dzone.com/articles/variadic-template-c-implementing-unsophisticated-t
*/ 

#include <iostream>
#include <tuple>
#include <complex>

template <typename T, typename Tuple, std::size_t N>
struct Calculator
{
    // Max 
    static T max(const Tuple& inTuple)
    {
        if (std::get<N - 1>(inTuple) > Calculator<T, Tuple, N - 1>::max(inTuple))
        {
            T max = std::get<N - 1>(inTuple) ;
            return max;
        }
        else {
            T max = Calculator<T, Tuple, N - 1>::max(inTuple);
            return max;
        }  

    }

    // Sum
    static T sum(const Tuple& inTuple)
    {
        T sum = std::get<N - 1>(inTuple) + Calculator<T, Tuple, N - 1>::sum(inTuple);
        return sum;
    }

    // Average 
    static T avg(const Tuple& inTuple)
    {
        T total = sum(inTuple);
        T avg = total / (static_cast<T>(N));
        return avg;
    }

};

// Ending function for recursion purposes 
template <typename T, typename Tuple>
struct Calculator<T,Tuple,1>
{
    // Max 
    static T max(const Tuple& input) 
{
        T max = std::get<0>(input);
        return max;
}  // end max for recursion 

    static T sum(const Tuple& input)
    {
        T sum = std::get<0>(input);
        return sum;
    } // end sum for recursion 

}; // end calc struct for recursion 


  
int main()
{
    // Part B: Test code on tuples with two and three elements whose underlying 
    //         type is double

    // Two Element Tuple
    std::cout << "Two element tuple: \n";

    using dblTupType2 = std::tuple <double, double>;
    dblTupType2 b2 = {102.1 , 1021.0 };
    const std::size_t tupleSize_b2 = std::tuple_size<dblTupType2>();

    // Max 
    double maxVal_b2 = Calculator<double, dblTupType2, tupleSize_b2>::max(b2);

    // Sum 
    double sumVal_b2 = Calculator<double, dblTupType2, tupleSize_b2>::sum(b2);

    // Average 
    double avgVal_b2 = Calculator<double, dblTupType2, tupleSize_b2>::avg(b2);

    // Outputting values
    std::cout << "Max is: " << maxVal_b2 << std::endl;
    std::cout << "Sum is: " << sumVal_b2 << std::endl;
    std::cout << "Average is: " << avgVal_b2 << std::endl;

    // Three element tuple 
    std::cout << "\nThree element tuple\n";
    using dblTupType3 = std::tuple <double, double, double>;
    dblTupType3 b3 = {10.2, 102.1 , 1021.0 };
    const std::size_t tupleSize_b3 = std::tuple_size<dblTupType3>();

    // Max 
    double maxVal_b3 = Calculator<double, dblTupType3, tupleSize_b3>::max(b3);
    
    // Sum 
    double sumVal_b3 = Calculator<double, dblTupType3, tupleSize_b3>::sum(b3);

    // Average 
    double avgVal_b3 = Calculator<double, dblTupType3, tupleSize_b3>::avg(b3);

    // Outputting values
    std::cout << "Max is: " << maxVal_b3 << std::endl;
    std::cout << "Sum is: " << sumVal_b3 << std::endl;
    std::cout << "Average is: " << avgVal_b3 << std::endl;

    // Part C: Sum and average of tuple using complex numbers 
    std::cout << "\nComplex Elements: \n"; // Three elements 
    using cplxTupType = std::tuple<std::complex<int>, std::complex<int>>;
    std::complex<int> cplx1(1, 6);
    std::complex<int> cplx2(3, 2);
    cplxTupType c2 = { cplx1, cplx2 };
    const std::size_t tupleSize_c2 = std::tuple_size <cplxTupType>();

    // outputting values 
    std::complex<int> sumCplxVal_c2 = Calculator<std::complex<int>, cplxTupType, tupleSize_c2>::sum(c2);
    std::complex<int> avgCplxVal_c2 = Calculator<std::complex<int>, cplxTupType, tupleSize_c2>::avg(c2);
    std::cout << "Complex sum is: " << sumCplxVal_c2 << std::endl;
    std::cout << "Complex avg is: " << avgCplxVal_c2 << std::endl;
    
}