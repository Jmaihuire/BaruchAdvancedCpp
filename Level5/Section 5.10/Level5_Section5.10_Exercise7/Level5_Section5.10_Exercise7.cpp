// Level5_Section5.10_Exercise7.cpp 
// Fiona Ross
// Vector and Matrix Expressions

#include <iostream>
#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>

using namespace boost::numeric::ublas;

int main()
{
    // creating vectors 
    vector<double> vec1(3);
    vector<double> vec2(3);
    for (int i = 0; i < vec1.size(); i++) {
    vec1[i] = i + 1;
    vec2[i] = vec2.size() - i;
    }
    
    //creating matrixes 
    matrix<double> mat1(3,3);
    for (int row = 0; row < mat1.size1(); row++) {
      for (int column = 0; column < mat1.size1(); column++) {
        mat1(row, column) = (row , column);
      }
    }

    // Printing Results 
    std::cout << "Vec1: " << vec1 << std::endl;
    std::cout << "Vec2: " << vec2 << std::endl;
    std::cout << "Mat1: " << mat1 << std::endl;
    std::cout << std::endl;

    // Part A: 
    // Inner and outer products of two vectors 
    auto inner = inner_prod(vec1, vec2);
    auto outer = outer_prod(vec1, vec2);
    std::cout << "Outputs of Inner Product for Vectors: " << std::endl;
    std::cout << inner << std::endl;
    std::cout << "Outputs of Outer Product for Vectors: " << std::endl;
    std::cout << outer << std::endl;
    std::cout << std::endl; 

    // Part B:
    // Adding and subtracting two vectors.
    auto sum = vec1 + vec2;
    auto sub = vec1 - vec2;
    std::cout << "Output of summing vectors: " << std::endl;
    std::cout << sum << std::endl;
    std::cout << "Output of subtracting vectors: " << std::endl;
    std::cout << sub << std::endl;


    // Part C:
    // The Euclidean, L1 and max norm of a vector.
    auto euclid1 = norm_2(vec1);
    auto l1 = norm_1(vec1);
    auto infnorm1 = norm_inf(vec1);  // same thing as max norm
    std::cout << "Euclidean, L1 & max norm for Vec 1: " << std::endl;
    std::cout << euclid1 << std::endl;
    std::cout << l1 << std::endl;
    std::cout << infnorm1 << std::endl;
    std::cout << std::endl; 

    auto euclid2 = norm_2(vec2);
    auto l1_2 = norm_1(vec2);
    auto infnorm2 = norm_inf(vec2);  // same thing as max norm 
    std::cout << "Euclidean, L1 & max norm for Vec 2: " << std::endl;
    std::cout << euclid2 << std::endl;
    std::cout << l1_2 << std::endl;
    std::cout << infnorm2 << std::endl;
    std::cout << std::endl; 

    // Part D:
    // L1 and max norms of a matrix.
    auto l1_mat = norm_1(mat1);
    auto inf_mat = norm_inf(mat1);
    std::cout << "L1 & max norm for Matrix: " << std::endl;
    std::cout << l1_mat << std::endl;  // just print one for example

    // Part E: 
    // The product of a matrix and a vector.
    auto out_prod = prod(mat1, vec1);
    std::cout << "Product of mat1 & vec1:  " << out_prod;

}

