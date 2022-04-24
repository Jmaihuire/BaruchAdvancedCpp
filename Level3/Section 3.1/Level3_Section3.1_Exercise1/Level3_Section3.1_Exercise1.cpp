// Level3_Section3.1_Exercise1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <thread>
#include "ThreadProgram.h"
#include <chrono>
#include <ctime>
#include <time.h> // for ctime_s because ctime is considered "unsafe"
#include <system_error>

// Usually avoid using namespace because dangerous but applying it so can call chrono literals
using namespace std::chrono_literals;

void current_thread_task() { std::cout << "try: current_thread_task()\n"; }

//std::string timeToString(std::chrono::system_clock::time_point &t) {
//  std::time_t time = std::chrono::system_clock::to_time_t(t);
//  char str[26] = {};
//  std::string time_str = std::ctime_s(str,26,&time);
//  time_str.resize(time_str.size() - 1);
//  return time_str;
//}

int main()
{
    // PART A/B
    // Getting timing for threads 
    const auto start_time =
        std::chrono::duration_cast<std::chrono::microseconds>(
            std::chrono::system_clock::now().time_since_epoch())
            .count();

    // Making threads (need one detached thread)
    // Free function thread 
    std::thread t_freeFunc(freeFunc);
    t_freeFunc.detach(); // detaching does 

    // stored lambda function 
    std::thread t_lFunction(lFunction);

    // Function object 
    PrintClass pclass;
    std::thread t_funcObj(pclass);

    // Static Function 
    std::thread t_static(PrintClass::StaticFunction);

    // bound function 
    std::thread t_bound(boundFunc);

    // lambda 
    std::thread t_lambda([]() { Iprint("Bound member function thread: ", 3); });

    // clear that threads are in all different orders due to lack of synchronization 
    // program is also aborting because no using join 

    // PART C/D - Exception handling / Join 
    // free function 
    if (t_freeFunc.joinable()) {
      try {
        std::cout << "Free Function Try \t"; 
        current_thread_task();
        t_freeFunc.join();
      } catch (...) {
        std::cout << "catch(...)\n";
      }
    };

    // stored lambda 
    if (t_lFunction.joinable()) {
      try {
        std::cout << "Stored Lambda Try \t"; 
        current_thread_task();
        t_lFunction.join();
      } catch (...) {
        std::cout << "catch(...)\n";
      }
    };

    // Function Object 
    if (t_funcObj.joinable()) {
      try {
        std::cout << "Function Object Try \t"; 
        current_thread_task();
        t_funcObj.join();
      } catch (...) {
        std::cout << "catch(...)\n";
      }
    };

    //  Static Member Function
    if (t_static.joinable()) {
      try {
        std::cout << "Static Member Function Try \t";
        current_thread_task();
        t_static.join();
      } catch (...) {
        std::cout << "catch(...)\n";
      }
    };

    // bound function 
    if (t_bound.joinable()) {
      try {
        std::cout << "Bound Function Try \t";
        current_thread_task();
        t_bound.join();
      } catch (...) {
        std::cout << "catch(...)\n";
      }
    };

    // lambda 
        if (t_lambda.joinable()) {
      try {
        std::cout << "Lambda Try \t";
        current_thread_task();
        t_lambda.join();
      } catch (...) {
        std::cout << "catch(...)\n";
      }
    };

    // PART F: 
    // Computing program duration in milliseconds 
    const auto end_time = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now().time_since_epoch()).count();

    std::cout << "Elapsed time in milliseconds is: "
              << std::chrono::microseconds(end_time - start_time).count() << " ms";

    // Overview / Summary 
    /*
    The elapsed time of this program was 25690 ms. 
    The thread outputs are very random as I did not include any thread synchronization.
    Without the try/catch that uses join, the program does not run but throws an error. 

    Joining a thread makes one thread of execution wait for another thread to
    finish running. Since I did not use mutexes to protect shared resources there is a chance the program
    will not wait for all threads to finish before quitting itself.
    
    */


}



