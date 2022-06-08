// Level5_Section5.10_Exercise1.cpp
// Fiona Ross 
// Dense Vectors 101
//
#include <iostream>
#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/io.hpp>


 using namespace boost::numeric::ublas;

// learned to just include print as functions ... 
template <typename T>
void print(T v) {
  for (auto el : v) {
    std::cout << el << " ";
  }
  std::cout << std::endl;
};


int main() {
  // Part A:
   vector<double> v1(5, 0);
   v1[3] = 23;
   v1(4) = 10;  // use different operators to access vector elements
   print(v1);

  // Part B:
   vector<double> v2(5, 2);
   v2[3] = 4;
   v2(4) = 5;  // use different operators to access vector elements

   vector<double> v3(5, 4);
   v3[3] = 12;
   v3(4) = 8;  // use different operators to access vector elements

  // operations
   v1 += v2;
   std::cout << "v1 output after addition is: " << std::endl;
   print(v1);

   v1 *= 2.5;
   std::cout << "v1 output after multiplication is: " << std::endl;
   print(v1);

   v1 -= v3;
   std::cout << "v1 output after subtraction is: " << std::endl;
   print(v1);

   // Part C: 
   vector<double> v4(5, 1);
   vector<double> v5(5, 2); 
   vector<double> v6(5, 1); 
   std::transform(v4.begin(), v4.end(), v5.begin(), v6.begin(),
                  std::multiplies<double>());
   std::cout << "output of v6 is: " << std::endl; 
   print(v6);

   // Pard D:
   // Part D:
   scalar_vector<double> v7(100, 5.0);  
}

