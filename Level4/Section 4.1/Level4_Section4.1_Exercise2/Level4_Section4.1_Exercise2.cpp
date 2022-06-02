// Level4_Section4.1_Exercise2.cpp :
// Fiona Ross 
// Compile-Time Vector Class 
#include <iostream>
#include "Vector.h"

int main() {
  // Part A:

  // Part B: Instances of Vector and printing them

  int vin_1[4] = {4, 5, 6, 7};
  Vector<int, 4> v1(vin_1);  // using array as copy input

  Vector<int, 4> v2;
  v2[0] = 2;
  v2[1] = 23;
  v2[2] = 12;
  v2[3] = 11;

  Vector<int, 4> v3(std::move(vin_1));

  // printing values
  v1.print();
  v2.print();
  v3.print();

  // Part C: Vector Space (in header file)

  // Part D: Multiplication (in hearder but tested here)
  v1 = v1 * 2;
  v1.print();

  // Part E: modifying (using transform to do this)
  v1.modify([](int& i) { return i * 2 + 1; });
  // using lamda to multiply by 2 and add 1.
  // Not using pareenthesis so interesting if pemdas works out
  v2.print();
}


