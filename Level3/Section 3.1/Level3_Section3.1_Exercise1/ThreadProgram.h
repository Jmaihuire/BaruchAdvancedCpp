#pragma once
//#include <boost/thread.hpp>
#include <functional>

// Function Pointer

void Iprint(const std::string& s, int count) {
  // print the string
  for (int i = 0; i < count; ++i) {
    std::thread::id curr_thread_id = std::this_thread::get_id(); //thread ID is PART E
    std::cout << "Thread: "<< s << "\t ID of: " << curr_thread_id << std::endl;
    // std::cout << s << std::endl;
  };
}

// free function declaration
void freeFunc() {
  // print the string
  Iprint("This is a free function", 3);
}

// stored lambda function
auto lFunction = []() { Iprint("Stored lambda thread: ", 3); };

// For Function Objects
class PrintClass {
 private:
  std::string m_s;
  int m_count;
 
 public:
  void operator()() {
    Iprint("Function Object ", 3);
  }

  // Static Member Function
  static void StaticFunction() { Iprint("This is a static function ", 3); }
}; 

// binder member function
auto boundFunc = std::bind(Iprint, "Bound member function thread: ", 3);
