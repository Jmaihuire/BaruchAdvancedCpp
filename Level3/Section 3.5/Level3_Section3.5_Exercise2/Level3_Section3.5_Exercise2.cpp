// Level3_Section3.5_Exercise2.cpp 
// Fiona Ross
// Exercise 2: Simple Single-Threaded Command Processor Pattern

#include <chrono>
#include <functional>
#include <iostream>
#include <queue>
#include <thread>

// From lecture but using std instead of boost 
using FunctionType = std::function<double(double)>;

class Command {
 private:
  long ID;  // The Id is priority 
  FunctionType algo;

 public:
  Command(const FunctionType& algorithm, long priority)
      : algo(algorithm), ID(priority) {}

  void Execute(double x) {
    // Introduce delay to simulate a heavy algorithm
    std::this_thread::sleep_for(std::chrono::milliseconds(2500));
    std::cout << algo(x) << '\n';
  }

  int priority() const { return ID; }
};

// Part A:
auto comparator = [](Command cleft, Command cright) -> bool {
  return (cleft.priority() < cright.priority());
};  // this lambda compares two inputs 

// Sample function to create commands:
std::function<double(double)> alg1 = [](double d_) { return d_ * 2; };

int main() {
  // Part B: Create several instances of Command
  Command c1(alg1, 2);
  Command c2(alg1, 4);
  Command c3(alg1, 6);
  Command c4(alg1, 8);
  auto cmdList = {c1, c2, c3, c4};

  // Part C: Create priority queue of commands and insert the objects from part
  // b into it
  std::priority_queue<Command, std::vector<Command>, decltype(comparator)> pq1(
      comparator);
  for (Command c : cmdList) pq1.push(c);


  // Part D: Ececute each command in priority queue until empty
  while (!pq1.empty()) {
    Command cTemp = pq1.top();
    cTemp.Execute(3);
    pq1.pop();
  }
  std::cout << "\n";
}