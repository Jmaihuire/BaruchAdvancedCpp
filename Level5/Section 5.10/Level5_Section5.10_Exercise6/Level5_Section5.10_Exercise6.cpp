// Level5_Section5.10_Exercise6.cpp
// Fiona Ross 
// 

#include <iostream>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/matrix_proxy.hpp>
#include <boost/numeric/ublas/io.hpp>

using namespace boost::numeric::ublas;

int main()
{
    // Matrix Row 
    matrix<double> mat(3, 3);
    for (unsigned i = 0; i < mat.size1(); ++i)
      for (unsigned j = 0; j < mat.size2(); ++j) mat(i, j) = 3 * i + j;
    matrix_row<matrix<double>> mat_r(mat, 1);
    std::cout << "Mat Row: " << mat_r << std::endl;

    // Matrix Column 
    matrix_column<matrix<double>> mat_c(mat, 1);
    std::cout << "Mat col: " << mat_c << std::endl;

    // Matrix Range 
    matrix_range<matrix<double>> mat_rng(mat, range(0, 2), range(0, 2));
    std::cout << "Mat range: " << mat_rng << std::endl;

    // Matrix Slice 
    matrix_slice<matrix<double>> mat_s(mat, slice(0, 1, 2), slice(0, 1, 3));
    std::cout << "Mat Slice: " << mat_s << std::endl;

    // Part B: Slicing
    matrix<double> mat2(3, 3);
    matrix_slice<matrix<double>> mat_s2(mat2, slice(0, 1, 3), slice(0, 1, 3));
    std::cout << "Part B: " << std::endl;
    std::cout << "Mat Slice: " << mat_s2;

}
