// Level4_Section4.3_Exercise5.cpp 
// Fiona Ross 
// Random Bitset 

#include <iostream>
#include <random>
#include <algorithm>
#include <chrono>
#include <bitset>

// Engine print function	
auto print = [](auto rem, auto engine, int count) {
  std::cout << rem << ": ";
  for (int i{}; i != count; ++i)
    std::cout << static_cast<unsigned>(engine()) << ' ';
  std::cout << '\n';
};

// print function from cppreference for outputting bits but essentially reproduces the engine 
template <typename engType, int Width>
auto print_bits(std::string rem, engType engine, int count) {
  std::cout << rem << ": ";
  int counter = 0;
  for (int i = 0; i != count; ++i) {
    auto b =
        std::bitset<Width>(engine());  // use the random number to create bitset
    std::cout << b << " ";             // print the random bits
    counter +=
        b.count();  // count bits set in this bitset and add to running counter
  }
  std::cout << '\n';
  std::cout << "Counter: " << counter << std::endl; // output the final count 
  std::cout << "Count %: "
            << 100 * counter / (count * Width);  // outputting percentage 
};


int main()
{
  // Part A : 
  auto seed = std::time(0);  // seed -> from clock 
  std::independent_bits_engine<std::default_random_engine, 4, unsigned long>
      indbit(seed);   // the 4 in this is the number of bits 
  print("Bitset 1", indbit, 4);  // display as integer

  // Part C: Printing percentage 
  print_bits<decltype(indbit), 2>("Bitset 1 in bits", indbit,
                                40);  // uses a width of 2 and has an output of 46-53% (not consistent)


  
	// Part C: Using different number of bits 
  // 8 bits 
  std::independent_bits_engine<std::default_random_engine, 8,
                               unsigned long>
      indbit2(seed);  // call independent bit engine constructor with 8 bits 
  
  print_bits<decltype(indbit2), 8>(
      "\nBitset 1 in bits", indbit2,
      30);  // width of 8 gave output of 48-53% (not super consistent) 
  
  // 16 Bits 
  std::independent_bits_engine<std::default_random_engine,16,
                               unsigned long>
      indbit3(seed);  // call independent bit engine constructor
  print_bits<decltype(indbit3), 16>(
      "\nBitset 1 in bits", indbit3,
      30);  // width of 16 gave output of 53% (more consistent)
  
  // 64 Bits 
  std::independent_bits_engine<std::default_random_engine,64,
                               unsigned long long>
     indbit4(seed);  // call independent bit engine constructor
  print_bits<decltype(indbit4), 64>(
      "\nBitset 1 in bits",indbit4,
      30);  // width of 64 gave output of 51% (very consistent)

  // Overall thoughts: the percentage got more consistent as there were more bits and the width increased 

}

