// Level3_Section3.5_Exercise1.cpp 
// Fiona Ross 
#include <iostream>
#include <queue>
#include <vector>

// Doing the priority queue in main instead of making it a class. 
// Making it a class would be a good design 
int main() {

  // PART A - Push, Print, Pop, Iterate elements 
  std::priority_queue<int> priqueue;     // initialization 
  const auto input = {66, 22, 44};   // data set 1
  const auto input_2 = {11, 22, 33};  // data set 2
  for (int n : input) priqueue.push(n);   // push values  66 22 44
  std::cout << "Output of priqueue_1: " << priqueue.top()
            << std::endl;           // print top elelment
  priqueue.pop();                        // pop element
  for (int n : input_2) priqueue.push(n);  // push values 11 22 33
  priqueue.pop();                        // pop element
  while (!priqueue.empty()) {
    std::cout << priqueue.top() << ' ';
    priqueue.pop();
  }
  std::cout << '\n';
  // Output was as expected. We pop off the two largest values before
  // printing so the result should be 33 22 22 11.

  // Part B - using long long instead of default template parameters 
  std::priority_queue<long long, std::deque<long long>, std::greater<long long>>
      priqueue_2;                         // initialize using long long 
  for (int n : input) priqueue_2.push(n);  // push values  66 22 44
  std::cout << "Output of priqueue_2: " << priqueue_2.top()
            << std::endl;           // print top elelment
  priqueue_2.pop();                          // pop element
  for (int n : input_2) priqueue_2.push(n);  // push values 11 22 33
  priqueue_2.pop();                   // pop element
  while (!priqueue_2.empty()) {
    std::cout << priqueue_2.top() << ' ';
    priqueue_2.pop();
  }
  std::cout << '\n';
  // Output checks out because the priority is flipped so should get 11 & 22 back
  // which are the smallest values 


  // Part C - using lambda function instead of std::greater
  auto compare_lambda = [](long long left, long long right) {
    return (left > right);
  };  // define greater comparison function as lambda function
  std::priority_queue<long long, std::deque<long long>,
                      decltype(compare_lambda)>
      priqueue_3(
      compare_lambda);                        // initialize priority queue
  for (int n : input) priqueue_3.push(n);  // push values  66 22 44
  std::cout << "Output of priqueue_3: " << priqueue_3.top()
            << std::endl;           // print top elelment
  priqueue_3.pop();                 // pop element
  for (int n : input) priqueue_3.push(n);  // push values 11 22 33
  priqueue_3.pop();                        // pop element
  while (!priqueue_3.empty()) {
    std::cout << priqueue_3.top() << ' ';
    priqueue_3.pop();
  }
  std::cout << '\n';
  // Got the same output as Part B which is good! 
}
