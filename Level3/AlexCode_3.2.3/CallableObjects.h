// Alex Moody: ThreadClass.cpp
// Objective: File containing all of the callable objects for exercise 3.1.1

#include <functional>
#include <iostream>
#include <mutex>
#include <string>

// PART A:
std::mutex mtx;
//
// Iprint interface for all callable object to call
void Iprint(const std::string& s, int count) {
  mtx.lock();
  for (int i = 0; i < count; ++i)
    std::cout << s << std::this_thread::get_id() << std::endl;
  mtx.unlock();
};

// free function
void freeFunction() { Iprint("Free function thread: ", 10); };

// stored lambda function
auto lambdaFunction = []() { Iprint("Stored lambda thread: ", 10); };

// function object
class FunctionObject {
 public:
  void operator()() { Iprint("Function object thread: ", 10); };

  // static member function
  static void StaticFunction() { Iprint("Static Function thread: ", 10); };
};

// bound member function
auto boundFunction = std::bind(Iprint, "Bound member function thread: ", 10);
