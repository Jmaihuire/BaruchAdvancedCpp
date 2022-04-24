#include <chrono>
#include <ctime>
#include <iostream>
#include <mutex>
#include <system_error>
#include <thread>
#include "ThreadProgram.h"
#include <system_error>

// Level3_Section3.1_Exercise3.cpp :
// Fiona Ross - 03-27-2022

// Usually avoid using namespace because dangerous but applying it so can call
// chrono literals
using namespace std::chrono_literals;
void current_thread_task() { std::cout << "try: current_thread_task()\n"; }

int main() {
  // Starting counter clock
  const auto start_time =
      std::chrono::duration_cast<std::chrono::microseconds>(
          std::chrono::system_clock::now().time_since_epoch())
          .count();

  // two free functions threads
  std::thread t_freeFunc1(freeFuncA);  // Part A
  std::thread t_freeFunc2(freeFuncA);  // Part A

  std::thread t_freeFunc3(freeFuncB);  // Part B-G

  // free function 1 joining
  if (t_freeFunc1.joinable()) {
    try {
      t_freeFunc1.join();
    } catch (...) {
      std::cout << "catch(...)\n";
    }
  };

  // free function 2 joining
  if (t_freeFunc2.joinable()) {
    try {
      t_freeFunc2.join();

    } catch (...) {
      std::cout << "catch(...)\n";
    }
  };

  // free function 3 joining
  if (t_freeFunc3.joinable()) {
    try {
      t_freeFunc3.join();

    } catch (...) {
      std::cout << "catch(...)\n";
    }
  };

  // Computing program duration in milliseconds
  const auto end_time = std::chrono::duration_cast<std::chrono::microseconds>(
                            std::chrono::system_clock::now().time_since_epoch())
                            .count();

  std::cout << "Elapsed time in milliseconds is: "
            << std::chrono::microseconds(end_time - start_time).count()
            << " ms";
};

