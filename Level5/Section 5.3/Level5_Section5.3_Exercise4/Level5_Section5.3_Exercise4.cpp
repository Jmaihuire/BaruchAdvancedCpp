// Level5_Section5.3_Exercise4.cpp 
// Fiona Ross 
// 

#include <iostream>
#include <iomanip>
#include <functional>
#include <string>
#include <unordered_set>
#include <boost/functional/hash.hpp>
#include <boost/unordered_set.hpp>


// Pulling from lecture slides 
// Part A: 
template <typename T>
void hash_value(std::size_t& seed, const T& val) {
    boost::hash_combine(seed,val); 
}
 
template <typename T, typename... Types>
void hash_value(std::size_t& seed, const T& val, const Types&... args) {
  boost::hash_combine(seed, val);
  hash_value(seed, args...);
}

// Part B: 
template <typename... Types>
std::size_t hash_value(const Types&... args) {
  std::size_t seed = 0; 
  hash_value(seed, args...);
  return seed;
}

struct S {
  std::string f;
  std::string s;
  S(const std::string& s1, const std::string& s2) : f(s1), s(s2){};
};
struct SHash {
 public:
  std::size_t operator()(const S& s) const { return hash_value(s.f, s.s); };
};
struct SEqual {
 public:
  bool operator()(const S& lhs, const S& rhs) const {
    return (rhs.f == lhs.f && rhs.s == lhs.s);
  };
};

int main()
{

    // Part A: Variadic hashes
    std::string str1 = "In the middle of the night";
    std::string str2 = "sleeping in the woods"; 
    std::size_t h1 = std::hash<std::string>{}(str1);
    std::size_t h2 = std::hash<std::string>{}(str2);
    auto hashCombine = h1 ^ (h2 << 1); 
    std::cout << "\nHashed: " << hashCombine << std::endl; 

    // I ran into issues implimenting the S structure. I understand 
    // that for hash_value to work on user defined points i need to 
    // create a specific function, but usually this is done for a class.
    // I didn't know how to do this for a common class like a string

    S s = {"string 1", "string2"};
    std::size_t seed;  
    hash_value(seed, str1);
    std::cout << "\nVariadic 1: " << seed << std::endl; 
    std::size_t seed2;
    hash_value(seed2,str1, str2);
    std::cout << "\nVariadic 2: " << seed2 << std::endl; 

    // Part B: Heterogenous test case 
    // createing different types to feed in
    int in1 = 3;
    float in2 = 23.02;
    
    std::size_t h_out = hash_value(in1, in2, str1);
    std::cout << "Part B hash result: " << h_out << std::endl;  

}

