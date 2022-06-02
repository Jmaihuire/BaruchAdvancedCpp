// Level3_Section3.5_Exercise7.cpp 
// Fiona Ross 

#include <iostream>
#include <ratio>

int main() {
  // Part A: Instances of std::ratio and print
  typedef std::ratio<2,3> r1;
  typedef std::ratio<7,12> r2;
  std::cout << "2/3 = " << r1::num << "/" << r1::den
            << std::endl;
  std::cout << "7/12= " << r2::num << "/" << r2::den
            << std::endl;

  // Part B: using operators on ratios 
  typedef std::ratio_add<r1, r2> sum;        // add ratios
  typedef std::ratio_subtract<r1, r2> diff;  // subtract ratios
  typedef std::ratio_multiply<r1, r2> prod;  // multiply ratios
  typedef std::ratio_divide<r1, r2> quot;    // divide ratios
  
                                             // Print all of the results...
  std::cout << "add is= " << sum::num << "/" << sum::den << std::endl;


  std::cout << "multiply is= " << prod::num << "/" << prod::den << std::endl;


  std::cout << "subtract is= " << diff::num << "/" << diff::den << std::endl;


  std::cout << "divide is= " << quot::num << "/" << quot::den << std::endl;

}
