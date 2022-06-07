// Level5_Section5.7_Exercise4.cpp 
// Fiona Ross 
// Colletion Types 
#include <iostream>
#include <tuple>
#include <boost/bimap/bimap.hpp>
#include <boost/bimap/multiset_of.hpp>
#include <boost/bimap/list_of.hpp>
#include <boost/bimap/unordered_set_of.hpp>

using namespace boost::bimaps;

// Part A: different Bimaps with differnt domain/ranges
// 3 Domains & 3 Ranges giving 9 options 
using biMap1 = bimap < set_of<std::string>, list_of<int>>; //Domain = set ; Range = list
using biMap2 = bimap < multiset_of<std::string>, set_of<int>>; //Domain = multiset_of; Range = set_of
using biMap3 = bimap < unordered_set_of<std::string>, unordered_set_of<int>>; // Domain = unordered_set ; Range = unordered_set
using biMap4 = bimap < set_of<std::string>, set_of<int>>;  // Domain = set of ; Range = set of
using biMap5 = bimap < set_of<std::string>, unordered_set_of<int>>; // Domain = set of ; Range = unordered set of 
using biMap6 = bimap < multiset_of<std::string>, list_of<int>>; // Domain = multiset of ; Range = list of
using biMap7 = bimap < multiset_of<std::string>, unordered_set_of<int>>; // Domain = multiset of ; Range = unordered set of 
using biMap8 = bimap < unordered_set_of<std::string>, list_of<int>>; // Domain = unordered set of ; Range = list of 
using biMap9 = bimap<unordered_set_of<std::string>, set_of<int>>; // Domain unordered set of ; Range = set of 

// Pulling in print function from lecture slides / previous exercise 
template <typename BMType>
void print(BMType& bimap) {
  for (auto iter = bimap.begin(), iend = bimap.end(); iter != iend; ++iter) {
    std::cout << iter->left << " <--> " << iter->right << std::endl;
  }
}

template <typename BMType>
int main()
{
	// Part B: Making instance of bimaps and printing values 
    // Looking back definitely should have made this a function somehow ...lot of copy & paste 
	std::cout << "BiMap1: \n";
        biMap1 bm1;
        bm1.insert(biMap1::value_type("Anne", 1));
        bm1.insert(biMap1::value_type("Bill", 2));
        print(bm1);

        std::cout << "BiMap2: \n";
        biMap2 bm2;
        bm2.insert(biMap2::value_type("Anne", 1));
        bm2.insert(biMap2::value_type("Bill", 2));
        print(bm2);

        std::cout << "BiMap3: \n";
        biMap3 bm3;
        bm3.insert(biMap3::value_type("Anne", 1));
        bm3.insert(biMap3::value_type("Bill", 2));
        print(bm3);

        std::cout << "BiMap4: \n";
        biMap4 bm4;
        bm4.insert(biMap4::value_type("Anne", 1));
        bm4.insert(biMap4::value_type("Bill", 2));
        print(bm4);

        std::cout << "BiMap5: \n";
        biMap5 bm5;
        bm5.insert(biMap5::value_type("Anne", 1));
        bm5.insert(biMap5::value_type("Bill", 2));
        print(bm5);

        std::cout << "BiMap6: \n";
        biMap6 bm6;
        bm6.insert(biMap6::value_type("Anne", 1));
        bm6.insert(biMap6::value_type("Bill", 2));
        print(bm6);

        std::cout << "BiMap7: \n";
        biMap7 bm7;
        bm7.insert(biMap7::value_type("Anne", 1));
        bm7.insert(biMap7::value_type("Bill", 2));
        print(bm7);

        std::cout << "BiMap8: \n";
        biMap8 bm8;
        bm8.insert(biMap8::value_type("Anne", 1));
        bm8.insert(biMap8::value_type("Bill", 2));
        print(bm8);

        std::cout << "BiMap9: \n";
        biMap9 bm9;
        bm9.insert(biMap9::value_type("Anne", 1));
        bm9.insert(biMap9::value_type("Bill", 2));
        print(bm9);

   
}

