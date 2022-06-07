// Level5_Section5.2_Exercise5.cpp
// Fiona Ross 
// Extracting Name Value Pairs 

#include <iostream>
#include <regex>
#include <map>
#include <boost/algorithm/string.hpp>

// print functions for map 
template <typename K, typename V>
void print_map(std::map<K, V> const& m) {
  for (auto const& pair : m) {
    std::cout << "{" << pair.first << ": " << pair.second << "}\n";
  }
}


int main()
{
  // constructing provided examples 
  std::string sA("a = 1, b = 2, c = 3");
  
  // Part A:
  std::regex delim(", ?");  // regex created by deliminator 

  std::vector<std::string> pairs;  // holds the date values
  std::copy(std::sregex_token_iterator(sA.begin(), sA.end(), delim, -1),
            std::sregex_token_iterator(), std::back_inserter(pairs));

  // printing to check work 
  for (auto el : pairs) {
    std::cout << el << " ";
  }

  // Part B: 
  // generate map 
  std::map<std::string, int> out_map;

  // loop through to insert key and value into map
  for (auto& str : pairs) {
    std::vector<std::string> strVec;  // create vector for split to fill
    boost::split(strVec, str,
                 boost::is_any_of("="));  // split left and right side of equals
    out_map[strVec[0]] =
        std::stoi(strVec[1]);  // add strings to map - cast to int
  }

  std::cout << "\n"; 
  print_map(out_map); 
}
