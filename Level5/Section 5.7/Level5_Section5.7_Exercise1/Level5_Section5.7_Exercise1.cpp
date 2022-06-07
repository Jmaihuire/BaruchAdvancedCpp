// Level5_Section5.7_Exercise1.cpp
// Fiona Ross 
// Boost Bimap 


#include <iostream>
#include <boost/bimap/bimap.hpp>
#include <boost/bimap.hpp>

// Grabbed from Boost Documenation 
// http :  // boost.cowic.de/rc/pdf/bimap.pdf
typedef boost::bimap<std::string, double> bm_type; 
bm_type bm; 

using value_type = boost::bimaps::bimap<std::string, double>::value_type;

typedef bm_type::left_map::const_iterator left_const_iterator;

void PrintLeft(bm_type biMap) {
  std::cout << "\nPrinting Left Map: " << std::endl;
  for (left_const_iterator left_iter = biMap.left.begin(), iend = biMap.left.end();
       left_iter != iend; ++left_iter) {
    // left_iter->first : key : int
    // left_iter->second : data : std::string
    std::cout << left_iter->first << " --> " << left_iter->second << std::endl;
  }
}

typedef bm_type::right_map::const_iterator right_const_iterator;

void PrintRight(bm_type biMap) {
  std::cout << "\nPrinting Right Map: " << std::endl;
  for (right_const_iterator right_iter = biMap.right.begin(), iend = biMap.right.end();
       right_iter != iend; ++right_iter) {
    // right_iter->first : key : int
    // right_iter->second : data : std::string
    std::cout << right_iter->first << " --> " << right_iter->second << std::endl;
  }
}

int main()
{
    // Creating bimap instance 
    boost::bimaps::bimap<std::string, double> bimap; 

    bimap.insert(value_type("Anna", 74)); 
    bimap.insert(value_type("Mary", 22)); 
    bimap.insert(value_type("Kyle", 12)); 
    bimap.insert(value_type("James", 89)); 

    // Part B: Printing 
    std::cout << "Part B:" << std::endl; 
    PrintLeft(bimap);
    PrintRight(bimap);

    // Part C: Search based on age 
    std::cout << "Part C:" << std::endl; 
    try {
      std::cout << bimap.left.at("Anna") << std::endl;
    } catch (...) {
      std::cout << "Nobody has that name" << std::endl;
    }
    // search for name based on age
    try {
      std::cout << bimap.right.at(21) << std::endl;
    } catch (...) {
      std::cout << "Nobody is that age" << std::endl;
    }


    // Part D: 
    // Iterate in the bimap using the third view (that is, a set of relations).
    std::cout << "Part D: " << std::endl; 
       for (auto iter = bimap.begin(), iend = bimap.end(); iter != iend; ++iter) {
      std::cout << iter->left << " <--> " << iter->right << std::endl;
    }



}
