// Level5_Section5.10_Exercise3.cpp 
// Fiona Ross 
// Sparse Matrices, Triangular Matrices 101
#include <iostream>
#include <algorithm>
#include <functional>
#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/triangular.hpp>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>
#include <boost/numeric/ublas/matrix_proxy.hpp>

using namespace boost::numeric::ublas;


int main()
{
    // Part A: 
    // Sparse matrix with complex numbers 
    matrix<std::complex<double>> mat1(2,3);
    matrix<std::complex<double>, column_major, bounded_array<std::complex<double>, 6>> mat2(2,3);

    // fill the matrix (ie. insertation)
    for (int row = 0; row < mat1.size1(); row++) {
      for (int column = 0; column < mat1.size2(); column++) {
        mat1(row, column) = std::complex<double> (row + column);
        mat2(row, column) = std::complex<double> (row - column); 

      }  
    }
    std::cout << "After Insertation" << std::endl;
    std::cout << "Matrix 1: " << mat1 << std::endl;
    std::cout << "Matrix 2: " << mat2 << std::endl;

    // erasing & setting to zero 
    mat1.erase_element(1,1);
    mat1.erase_element(1, 2);
    mat2.erase_element(1, 2);

    std::cout << "After Erasing" << std::endl;
    std::cout << "Matrix 1: " << mat1 << std::endl;
    std::cout << "Matrix 2: " << mat2 << std::endl;

    // clearing
    mat1.clear();
    std::cout << "After Clearing" << std::endl;
    std::cout << "Matrix 1: " << mat1 << std::endl;
    std::cout << "Matrix 2: " << mat2 << std::endl;


    //Part B: 
    // Upper triangular matrix 
    triangular_matrix<std::complex<double>, upper, column_major> mat3(
        3, 3);  
    std::cout << "Upper Triangular:\n" << mat3 << std::endl;

    // lower triangular matrix 
    triangular_matrix<std::complex<double>, lower> mat4(3, 3);
    std::cout << "Lower Triangular:\n" << mat4 << std::endl;

    // Part C: 
    // Boost dense matrix upper triangular 
    matrix<double> mat5(3, 3, 3);
    triangular_adaptor<matrix<double>, upper> mat6(mat5);  // make a upper triangular view of m3;
    std::cout << "Mat6 triangular upper: " << mat6
              << std::endl;  // print upper matrix view
    
    // Boost dense matrix lower triangular 
    triangular_adaptor<matrix<double>, lower> mat7(
        mat5);  // make a lower triangular view of m3;
    std::cout << "Mat7 triangular lower: " << mat7
              << std::endl;  // print lower matrix view
}

