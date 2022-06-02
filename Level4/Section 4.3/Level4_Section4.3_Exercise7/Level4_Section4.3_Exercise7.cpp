// Level4_Section4.3_Exercise7.cpp
// Fiona Ross 
// Chi Squared Test 

#include <iostream>
#include <random>

// Part A: Computing the Chi2 statistic
int N(int k, int* fo)  // (d)
{
  int n = 0;

  for (int i = 0; i < k; i++) n += fo[i];

  return n;
}

double chi2(int k, int fo[]) {
  double fe = double(N(k, fo)) / k;  // (e)

  int sum = 0;  // (f)
  for (int i = 0; i < k; i++) sum += (fo[i] - fe) * (fo[i] - fe);

  return sum / fe;
}

int main() {
  // Part A: Computing Chi2
  int fo[100];
  int k = 0;

  std::cout << "Enter the observed frequencies for each category, -1 to stop:"
            << std::endl;

  for (k = 0; k < 100 && (std::cin >> fo[k]) && (fo[k] != -1);
       k++)  // data input - using user input but could probably do this as a
             // random generator
    ;

  std::cout << "Chi-square = " << chi2(k, fo) << std::endl;  // print chi-square

  // Part B:
  // From visual and quick math, the output appears to be correct.
  // Could probably generate statistics to get a more in depth check

  // Part C: Using uniform distribution
  int fo2[100];
  int k2 = 10;

  std::cout << "frequencies being created based on uniform random generator"
            << std::endl;

  std::random_device rd;
  std::uniform_int_distribution<int> dist(0,
                                          k2);  // uniform distribution from 0:k

  for (int i = 0; i < k2; i++) {  // generate N draws
    fo2[i] = dist(rd);
    std::cout << fo2[i] << std::endl;
  }

  std::cout << "Chi-square = " << chi2(k, fo2)
            << std::endl;  // print chi-square
}
