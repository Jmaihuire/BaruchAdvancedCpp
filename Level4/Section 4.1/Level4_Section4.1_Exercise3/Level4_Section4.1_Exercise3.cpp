// Level4_Section4.1_Exercise3.cpp 
// Fiona Ross 
// Compile Time Matrix Class 

#include <iostream>
#include "Matrix.h"

  int main() {
    // Part B: Create some instances of vector and print them
    int inM_1[4] = {2,4,6,8};  // make array to fill vector instance with
    Matrix<int, 4, 4> m1;        // make a default vector
    m1[0][0] = 3;
    m1[1][1] = 4;
    m1[2][2] = 6;
    m1[3][3] = 1;
    auto m2(m1);              // make a vector with copy constructor
    Matrix<int, 4, 4> m3(4);  // constructor with value
   
                              // Print values:
    m1.print();
    m2.print();
    m3.print();
    // Part C:
    // This is in the header file 

    // Part D: scalar multiplication
    m2 = 12 * m1;  
    m2.print();

    // Part E:
    m2.modify([](int& i) {
      return i * 2 + 1;
    });  // multiplying by 2 and then adding 1
    // Did not include parenthesis so pemdas will be interesting 
    m2.print();
  }
