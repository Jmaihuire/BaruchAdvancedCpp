// Level4_Section4.3_Exercise4.cpp 
// Fiona Ross 
// Computing Pi 

#include <iostream>
#include <vector>
#include <random>
#include <chrono>

int main() {
  // Part A: Create a random number engine and set its seed
  int seed = std::chrono::system_clock::now().time_since_epoch().count();
  std::random_device rd;
  std::mt19937 g(rd());  // set seed using random device

  // Part B: Create 2 instances of uniform dist on unit intervals (ie. -1 to 1) 
  std::uniform_real_distribution<double> dist(-1.0, 1.0);
  std::uniform_real_distribution<double> dist2(-1.0, 1.0);

  // Par C: Create loop to generate values
  int nTrials = 100000000;
  double counter = 0; 
  std::cout << "calc pi:" << std::endl;

  for (int i = 0; i < nTrials; i++) {
    double x = dist(g);
    double y = dist2(g);
    double rad = std::sqrt((x * x) + (y * y)); //pythagorean distance 
    if (rad < 1) {
      counter++; // only incrementing if greater than 1 
    }
  }

  // Part D: Compute pi
  double pi = 4 * counter / nTrials;
  std::cout << "Pi = " << pi;

  // Attemps: 
  // 100 trials was very unreliable giving 2.92
  // 100000 trials was more reliable giving 3.14392
  // 100000000 trials took too long...think 100000 was good enough 
}
