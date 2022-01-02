// Level1_Section1.1_Exercise2.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Exercise 2: Comparing Lambda Functions with Function Objects and Free Functions)

#include <iostream>
#include <iostream>
#include <array>
#include <iterator>
#include <utility>
#include <functional>
#include <algorithm>
#include <vector>
#include <numeric>
#include <complex>

// General Lambda defined function
auto MyMultiply = [](auto x, auto y) { return x * y; };

// User defined Function 
struct FOMultiply
{
    template <typename T>
    T operator () (const T& x, const T& y)
    {
        return x * y;
    }
};

// initiating for Complex Numbers 
template <typename T>
T MyMultiply2(const T& x, const T& y) { return x * y; };
// Using complex numbers
using Complex = std::complex<double>;
// Accumilate tested with complex numbers 
std::vector<Complex> complexArray{ Complex(1.0, 1.0), Complex(2.0, 2.0) };
Complex initCVal(1.0, 1.0);

// Complex vector 
auto acc4 = std::accumulate(complexArray.begin(), complexArray.end(),
    initCVal, FOMultiply());

Complex acc6C = std::accumulate(complexArray.begin(), complexArray.end(),
    initCVal, MyMultiply2<Complex>);


int main()
{
// Part A) Implement and test the algorithm using the generic lambda:
// Can the algorithm also be used with complex numbers, for example? 
// Can we use function objects to multiply the elements of an array of 
// complex numbers?

    std::vector<int> vec{ 1,2,3,4,5 }; //standard vector 
    int initVal = 1;

    int acc2 = std::accumulate(vec.begin(), vec.end(), initVal,
        std::multiplies<int>());
    int accTemplate = std::accumulate(vec.begin(), vec.end(), initVal,
        FOMultiply());
    int accLambda = std::accumulate(vec.begin(), vec.end(), initVal,
        MyMultiply);

    // Printing Out Results 
    std::cout << "Sum of standard vector is:" << acc2 << std::endl;
    std::cout << "Sum 6, complex numbers: " << acc6C << std::endl;
    std::cout << "Sum 4, complex numbers: " << acc4 << std::endl;

    // Part B) Implement the accumulation algorithm using an embedded 
    // lambda function in combination with std::for_each() and 
    // captured variables.
    auto sumReal = 0;
    Complex sumComplex(0.0, 0.0);
    for_each(vec.begin(), vec.end(), [&](auto const& i) {sumReal += i; });
    for_each(complexArray.begin(), complexArray.end(), [&sumComplex](Complex& i) {sumComplex = sumComplex + std::real(i) + std::imag(i); });

    std::cout << "The sum of the vector elements is " << sumReal << std::endl;
    std::cout << "The sum of the vector elements is " << sumComplex << std::endl;
    // No, the accumulate function cannot handle complex numbers as it views vec.end() as the last complex part
    // of the element and does not seperate the real and complex 

    // Part C) Give an example of a stored lambda function that may be called from an STL algorithm (may be any relevant STL algorithm).
    // Demonstrate using the STL algorithm with your stored lambda.

    int thresh = 3;
    auto biThresh = [&thresh](int& i) {if (i < thresh) { i = 0; } else { i = 1; }; };
    std::for_each(vec.begin(), vec.end(), biThresh);

    std::cout << "Binary Vector = " ;

    for (int n : vec) {
        std::cout << n << ", ";
    }
    
    return 0;

}

