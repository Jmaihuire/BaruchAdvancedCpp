// Level4_Section4.3_Exercise3.cpp 
// Fiona Ross 
// STL Shuffle 

#include <iostream>
#include <random>
#include <vector>
#include <algorithm>

int make_rand(int size) { return std::rand() % size; }

int main()
{
 // Part A: Creating a large vector of integers 
	std::vector<int> v1;
	int largeNum = 100;
	for (int i = 0; i < largeNum; i++) {
	 v1.push_back(i);  // create large vector
	}

	// shuffle order of integers 
	std::random_shuffle(v1.begin(), v1.end()); 
	std::random_shuffle(v1.begin(), v1.end(), make_rand);

	// Shuffle using specified engine 
	std::random_device rd2;
    std::mt19937 g2(rd2());
    std::shuffle(v1.begin(), v1.end(), g2);  // mt19937
    std::shuffle(v1.begin(), v1.end(), std::default_random_engine(std::rand()));  // default_random_engine
    std::shuffle(v1.begin(), v1.end(), std::linear_congruential_engine<std::uint_fast32_t, 16807, 0, 2147483647>(std::rand()));  // linear_congruential

}
