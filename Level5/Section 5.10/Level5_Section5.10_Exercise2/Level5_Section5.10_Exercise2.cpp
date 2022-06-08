// Level5_Section5.10_Exercise2.cpp : 
// Fiona Ross 
// Dense Matrices 101

#include <iostream>
#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>

using namespace boost::numeric::ublas;

int main()
{
 int r = 2; // 2 rows 
 int  c = 4; // 4 columns 
    
    // Part A: 
    matrix<double> mat1(r, c, 0);  
    matrix<double> mat2(r, c, 3);

    // Part B: 
    // modifying elements 
    // definitely could have made this a loop ... 
    mat1(0, 0) = 1;
    mat1(0, 1) = 2;
    mat1(0, 2) = 3;
    mat1(0, 3) = 4;
    mat1(1, 1) = 5;
    mat1(1, 2) = 6;
    mat1(1, 3) = 7;

    std::cout << "M1: " << mat1 << std::endl;

    // Part C: 
    matrix<double> mat3(r, c, 0);
    mat3 = mat2 + mat1;
    std::cout << "Mat3 after addition: " << mat3 << std::endl; 

    mat3 = mat2 - mat1;
    std::cout << "Mat3 after subtraction: " << mat3 << std::endl; 

    // Part D: 
    mat2.resize(5, 5);
    std::cout << "Mat2 after resize: " << mat2
              << std::endl;  

    // Part E: 
    zero_matrix<double> zero(3, 4);  // zero matrix
    identity_matrix<double> eye(3);  // identity matrix
    std::cout << "Zero mat: " << zero << std::endl;
    std::cout << "Eye mat: " << eye << std::endl;
}

