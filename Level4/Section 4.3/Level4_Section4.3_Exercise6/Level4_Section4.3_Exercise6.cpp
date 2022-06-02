// Level4_Section4.3_Exercise6.cpp
// Fiona Ross 
// Boost Random 101 

#include <iostream>
#include <vector>
#include <random>
#include <boost/random.hpp>
#include <boost/random/generate_canonical.hpp>
#include <boost/multiprecision/cpp_bin_float.hpp>
#include <chrono>

// had to rename from generate_conical to g_conical becaues function already defined in <random> 
template <typename RealType, std::size_t bits> //, typename URNG> // not quite sure what to do with URNG
auto g_canonical(RealType eng){ return boost::random::generate_canonical<float, bits>(eng); };

int main()
{
	  // Part A: 
    boost::random::lagged_fibonacci607 eng;  // fibonacci engine
    boost::triangle_distribution<> triDis;   // triangle distribution
    boost::variate_generator<boost::random::lagged_fibonacci607,
                             boost::triangle_distribution<>>triRng(eng, triDis);
    std::cout << "variate generator output: " << triRng() << std::endl;

    // Part B: 
    // generating engine
    //auto seed = std::chrono::high_resolution_clock::now(); // using clock seed was throwing errors
    std::mt19937 eng1(4);

    // Using random device 
    // 8 bit canonical:
    std::cout << "8 bits: " << g_canonical<decltype(eng1), 8>(eng1)
              << std::endl;
    // 16 bit canonical:
    std::cout << "16 bits: " << g_canonical<decltype(eng1), 16>(eng1)
              << std::endl;
    // 32 bit canonical:
    std::cout << "32 bits: " << g_canonical<decltype(eng1), 32>(eng1)
              << std::endl;

  }
