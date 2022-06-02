// Level4_Section4.3_Exercise1.cpp
// Fiona Ross
// Random Numbers 101

#include <iostream>
#include <random>

int main() {
  // Provided Code
  // Part A: different Engines
  std::default_random_engine eng1;
  // inputs are
  std::linear_congruential_engine<std::uint_fast32_t, 48271, 0, 2147483647>
      eng2;
  std::mt19937 eng3;
  std::mt19937_64 eng4;

  // Generate uniform random variates in interval [A, B]
  double A = 0.0;
  double B = 1.0;

  // Part B: Different distributions
  std::uniform_real_distribution<double> dist(A, B);
  std::chi_squared_distribution<double> dist2(B);
  std::normal_distribution<double> dist3(A, B);
  std::bernoulli_distribution dist4(
      1);  // this one is a bit weird where it doesnt take the interval
  std::cauchy_distribution<double> dist5(A, B);

  int nTrials = 5;  // the number of distributions

  // Trials
  // Produce a number of uniform variates
  std::cout << "uniform real with eng1\n";
  for (int i = 1; i <= nTrials; ++i) {
    std::cout << dist(eng1) << ", ";
  }
  std::cout << "end\n\n";

  std::cout << "chi squared with eng2\n";
  for (int i = 1; i <= nTrials; ++i) {
    std::cout << dist2(eng2) << ", ";
  }
  std::cout << "end\n\n";

  std::cout << "normal with eng3\n";
  for (int i = 1; i <= nTrials; ++i) {
    std::cout << dist3(eng3) << ", ";
  }
  std::cout << "end\n\n";

  std::cout << "bernouli with eng4\n";
  for (int i = 1; i <= nTrials; ++i) {
    std::cout << dist4(eng4) << ", ";
  }
  std::cout << "end\n\n";

  std::cout << "cauchy with eng1\n";
  for (int i = 1; i <= nTrials; ++i) {
    std::cout << dist5(eng1) << ", ";
  }
  std::cout << "end\n\n";
}
