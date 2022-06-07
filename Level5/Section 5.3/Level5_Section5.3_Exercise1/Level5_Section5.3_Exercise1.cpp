// Level5_Section5.3_Exercise1.cpp 
// Fiona Ross 
// Hash 101 

#include <iostream>
#include <string>
#include <functional>   
#include <unordered_set>
#include <boost/functional/hash.hpp>
#include <limits>

// Hash Value templates: 
// I think this is overkill for now... 

//template <typename T>
//void CreateHashValue(const T& t) {
//  boost::hash<T> hasher; 
//  std::size_t hashValue = hasher(t); 
//  std::cout << hashValue << std::endl; 
//}
//
//template<typename T> 
//void hash_value(std:size_t & seed, const T& val) {
//  boost::hash_combine(seed, val);
//}
//
//template<typename T, typename... Types>
//void hash_value(std::size_t& seed, const T& val, const Type&... args) {
//  boost::hash_combine(seed, val); 
//  hash_value(seed, args...); 
//}
    
//class SHash // Hash for class S
//{
// public: 
//     std::size_t operator()(const S& s) const { return hash_value(s.f, s.s);
//     }
//};
 
//// Part A: Generic Hash Tables 
// Boost Hash Format 
template<typename T>
std::size_t boost_htable(T key) {
  return boost::hash<T>{}(key);
}

// STD Hash Format 
template<typename T>
std::size_t std_htable(T key) {
  return std::hash<T>{}(key);
}


int main()
{
    // Part B: tests  
    int itest = 23; 
    std::string str1 = "Meet the neighbours"; //string test 
    std::string* str2 =&str1;                 // string point test
    auto constexpr numlim = std::numeric_limits<float>::max();

    // Testing 
    auto htest1a = std_htable(itest);
    auto htest1b = boost_htable(itest);
    std::cout << "Integer Hash Result: " << htest1a << std::endl;
    std::cout << "Integer Hash Result: " << htest1b << std::endl;
    
    auto htest2a = std_htable(str1);
    auto htest2b = boost_htable(str1);
    std::cout << "Integer Hash Result: " << htest2a << std::endl;
    std::cout << "Integer Hash Result: " << htest2b << std::endl;
    
    auto htest3a = std_htable(str2);
    auto htest3b = boost_htable(str2);
    std::cout << "Integer Hash Result: " << htest3a << std::endl;
    std::cout << "Integer Hash Result: " << htest3b << std::endl;

    auto htest4a = std_htable(numlim);
    auto htest4b = boost_htable(numlim);
    std::cout << "Integer Hash Result: " << htest4a << std::endl;
    std::cout << "Integer Hash Result: " << htest4b << std::endl;
    // outputs are difficult to discern but I think they seem right 

    // Part C: 
    std::string s1 = "In the middle of the night";
    std::string s2 = "sleeping soundly in the woods"; 

    std::size_t h1 = std::hash<std::string>{}(s1);
    std::size_t h2 = std::hash<std::string>{}(s2);

    // computing h1 ^ (h2 << 1)
    auto hashCombine = h1 ^ (h2 << 1);
    std::cout << "\nHashed: " << hashCombine << std::endl; 
}

