// Level4_Section4.3_Exercise2.cpp 
// Fiona Ross 
// Categories of Distributions 

#include <iostream>
#include <vector>
#include <random>
#include <map>
#include <iomanip>
#include <string>

// Print Map:

template <typename Map>
void print_map(Map& m) {
  std::cout << '{';
  for (auto& it : m) {
    std::cout << it.first << ' ' << it.second;
  }
  std::cout << "}\n";
}


template <typename Dist, typename Eng>
void GenerateRandomNumbers(Dist d, Eng eng, int NTrials, const std::string& s) {
  // Key = bucket/value; Value = number of occurrences
  std::map<long long, int> counter;

  // Produce a number of uniform variates
  for (int i = 1; i <= NTrials; ++i) {
    ++counter[d(eng)];
  }
  std::cout << s << ":\n";
  print_map(counter);
}


int main()
{
  // Generate uniform random variates in interval [A, B]
  double A = 0.0;
  double B = 1.0;

  // ntrials
  int NTrials = 10;

  // Part B: Test code with distributions
  // make engine 
  std::mt19937_64 eng4;

  // make distributions 
  std::uniform_real_distribution<double> dist(A, B);  // uniform
  std::geometric_distribution<> dist2;                // geometric
  std::poisson_distribution<> dist3(3);               // poisson


  // output histograms
  GenerateRandomNumbers(dist, eng4, NTrials, "UNIFORM");
  GenerateRandomNumbers(dist2, eng4, NTrials, "GEOMETRIC");
  GenerateRandomNumbers(dist3, eng4, NTrials, "POISSON");
  
  // Part C: These probabilities look right based on the outputs and where each of the mean is. 
}

