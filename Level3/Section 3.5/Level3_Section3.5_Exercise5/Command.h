#pragma once
#include <iostream>
#include <functional>
#include <thread>

// Code pulled from prior exercise using commands
using FunctionType = std::function<double(double)>;

class Command {
 private:
  long ID;  // priority of command
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

  // Sample function to create comm ands:
  static double alg1(double d_) { return d_ * 2; };

  bool operator<(const Command& c1) const {
    return this->priority() < c1.priority();
  };
};
