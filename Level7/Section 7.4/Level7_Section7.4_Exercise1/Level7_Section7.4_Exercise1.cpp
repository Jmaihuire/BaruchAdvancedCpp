// Level7_Section7.4_Exercise1.cpp
// Fiona Ross 
// Template Method Pattern based on Universal Function Wrappers

#include <functional>
#include <future>
#include <iostream>
#include <thread>
#include "HelperFunc.h"


// Pulled from HW Exercises 
// function categories 
template <typename T>
using FactoryFunction = std::function<T()>;
template <typename T>
using ComputeFunction = std::function<T(const T& t)>;
template <typename T>
using DispatchFunction = std::function<void(T& t)>;

// Also pulled from HW exercises 
// Class with Input-Processing-Output
template <typename T>
class TmpProcessor {  // No inheritance used

 private:
  FactoryFunction<T> _factory;
  ComputeFunction<T> _compute;
  DispatchFunction<T> _dispatch;

 public:
  TmpProcessor(const FactoryFunction<T>& factory,
               const ComputeFunction<T>& compute,
               const DispatchFunction<T>& dispatch)
      : _factory(factory), _compute(compute), _dispatch(dispatch) {}

  // The template method pattern
  virtual void algorithm() final {
    T val = _factory();
    T val2 = _compute(val);
    _dispatch(val2);
  }
};

int main() {
  // Part A:
  // Simple testing
  // Just wanted to do one test for each function category 
  ComputeFunction<double> test1 = [](double in) { return 1.2; };
  DispatchFunction<double> test2 = [](double in) {
    std::cout << "Dispatch value: " << in << std::endl;
  };
  FactoryFunction<double> test3 = []() { return 1; };
  // really just struggled to get this to work but not sure why 
  /*TmpProcessor<double> tp(test1, test2, test3);
  tp.algorithm();*/

  // Part B:
  // Sequential example
  // Computes in a sequential order 
  ComputeFunction<double> sequential_test = [](double a) {
    auto b = F1(a);
    auto d = F3(a);
    auto f = F4(b, d);
    return std::get<0>(f);
  };

  //This is the asynchronous version 
  ComputeFunction<double> parallel_test = [](double a) {
    std::future<double> b(std::async(F3<double>, std::ref(a)));
    auto d = F3(a);
    auto bOut = b.get();
    auto f = F4(bOut, d);
    return std::get<0>(f);
  };

  // The above functions just call the same function 3 in parallel or
  // sequentially.

 // Added stopwatch to test the speed of running parallel vs sequential but 
  // ran out of time before i could impliment this. Thought it might be a good 
  // thing to include since did similar thing in Section 3
}
