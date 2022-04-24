// Level3_Section3.1_Exercise2.cpp :
// Fiona Ross - 03-26-2022

#include <chrono>
#include <ctime>
#include <iostream>
#include <system_error>
#include <thread>
#include <mutex>
#include "ThreadProgram.h"

// Usually avoid using namespace because dangerous but applying it so can call
// chrono literals
using namespace std::chrono_literals;

void current_thread_task() { std::cout << "try: current_thread_task()\n"; }
// int not_successful_job = 0;
// int successful_job = 0;

int main() {
  // PART A/B
  // Getting timing for threads
  const auto start_time =
      std::chrono::duration_cast<std::chrono::microseconds>(
          std::chrono::system_clock::now().time_since_epoch())
          .count();

  // Making threads (need one detached thread)
  // Free function thread
  std::thread t_freeFunc(freeFunc);
  t_freeFunc.detach();  // detaching does

  // Function object
   PrintClass pclass;
   std::thread t_funcObj(pclass);

  // Static Function
  std::thread t_static(PrintClass::StaticFunction);


  // lambda
  std::thread t_lambda([]() {
    //  m_mutex.lock(); Part A
    // Iprint("This is a free function", 3);
    // m_mutex.unlock();
    while (true) {
      if (m_mutex.try_lock()) {
      //if (m_mutex.try_lock()) {
        // std::unique_lock<std::mutex> lock(m_mutex);
        Iprint("This is a free function", 3);
        m_mutex.unlock();
        return;  // without the return, the function will run continuously 
      } else {
        not_successful_job++;
        std::cout << "\n freeFunc job unsuccessful. Total unscessful jobs "
                  << not_successful_job << "\n";
      }
    }
   });

  // clear that threads are in all different orders due to lack of
  // synchronization program is also aborting because no using join

  // PART C/D - Exception handling / Join
  // free function
  if (t_freeFunc.joinable()) {
    try {
      std::cout << "Free Function ";
      // current_thread_task();
      t_freeFunc.join();

    } catch (...) {
      std::cout << "catch(...)\n";
    }
  };

  // Function Object
   if (t_funcObj.joinable()) {
    try {
      std::cout << "Function Object ";
      current_thread_task();
      t_funcObj.join();
    } catch (...) {
      std::cout << "catch(...)\n";
    }
  };

  //  Static Member Function
   if (t_static.joinable()) {
    try {
      std::cout << "Static Member Function ";
      current_thread_task();
      t_static.join();
    } catch (...) {
      std::cout << "catch(...)\n";
    }
  };

  // lambda
   if (t_lambda.joinable()) {
    try {
      std::cout << "Lambda ";
      current_thread_task();
      t_lambda.join();
    } catch (...) {
      std::cout << "catch(...)\n";
    }
  };

  //// PART F:
  // Computing program duration in milliseconds
   const auto end_time =
   std::chrono::duration_cast<std::chrono::microseconds>(
                            std::chrono::system_clock::now().time_since_epoch())
                            .count();

   std::cout << "Elapsed time in milliseconds is: "
            << std::chrono::microseconds(end_time - start_time).count()
            << " ms";

  // Overview / Summary
  /*
    PART A: 
    With mutex.lock() the elapsed time is milliseconds: 57754 ms

    PART B:
    using mutex.try_lock() and mutex.unlock() get a running time of
    Elapsed time in milliseconds around: 1085495 ms 
    The number of failed attempts to unlock has reached above 320 attempts. 

    // Part C: 
    When in deadlock (for example, a thread that never unlocks a mutex) by
     commenting out unlock() in your code the unsucessful job count continues increasing 
     until we need to ctrl+C to exit the code 
  */
}
