// Level4_Section4.1_Exercise5.cpp
// Fiona Ross 
// Numeric Algorithms for Vectors and Matrices 

#include <iostream>
#include "Vector.h"
#include <functional>
#include <numeric>
#include <complex>
#include "Matrix.h"


// Adding functionality to Vector class using friend functions 
// Had to include begin() / end() to vector class to make these work
template <typename T, int N>
T inner_product(const Vector<T, N>& v1, const Vector<T, N>& v2, T initValue) {
  return std::inner_product(v1.begin(), v1.end(), v2.begin(), initValue); 
};

// overloading inner_product function
// Had to include begin() / end() to vector class to make these work 
template <typename T>
using BinaryFunction = std::function<T(const T& t1, const T& t2)>;

template <typename T, int N>
T inner_product(const Vector<T, N>& v1, const Vector<T, N>& v2, T initValue,
    const BinaryFunction<T>& op1, const BinaryFunction<T>& op2) {
   return std::inner_product(v1.begin(), v1.end(), v2.begin(), initValue,op1,op2);
}

int main()
{
    // Part B: Testing the inner_product Vector variant
    // creating vector instances 
    int arr[7] = {1,2,3,4,5,6,7}; 
    Vector<int, 7> vIn(arr); 
    
    std::cout << "Inner Product Results are: " << inner_product(vIn, vIn, 0)
              << std::endl;

    // Part C: Checking the addition and multiplication operators 
   BinaryFunction<int> ADD = [](const int& in1, const int& in2) {
      return in1 + in2;
    };

   BinaryFunction<int> MUL = [](const int& in1, const int& in2) {
     return in1 * in2;};


    std::cout << "Inner Product Result with ADD is: "
             << inner_product(vIn, vIn, 0, ADD, ADD) << std::endl;

    std::cout << "Inner Product Result with ADD,MULT is: "
              << inner_product(vIn, vIn, 0, ADD, MUL) << std::endl;

    // these both have to have 1 to have non-zero answer
    std::cout << "Inner Product Result with MULT,ADD is: "
              << inner_product(vIn, vIn, 1, MUL, ADD) << std::endl;

    std::cout << "Inner Product Result with MUL is: "
              << inner_product(vIn, vIn, 1, MUL, MUL) << std::endl;

    // Part D: testing the outer_product matrix variant 
    Matrix<int, 7, 7>::outer_product(vIn, vIn).print();

    // Part E: complex number test (complex conjugate transpose)
    // making complex numbers 
    std::complex<int> c1(1, 2);
    std::complex<int> c2(3,4);
    std::complex<int> c3(5,6);
    
    // putting complex numbers into an array 
    std::complex<int> inArr[3] = {c1, c2, c3};
    Vector<std::complex<int>, 3> vcIn(inArr); 
    Vector<std::complex<int>, 3> vcOut; 

    vcOut = vcIn * 22; 

    // making a complex matrix 
    Matrix<std::complex<int>, 3, 3>::outer_product(vcIn, vcOut).print(); 
}

