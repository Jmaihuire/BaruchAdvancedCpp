#pragma once
#include <functional>
#include <iostream>
#include <mutex>

// global variables to keep track of mutex try_lock results:
int not_successful_job = 0;
int successful_job = 0;
std::mutex m_mutex; 

// Function Pointer

void Iprint(const std::string& s, int count) {
     // print the string
     for (int i = 0; i < count; ++i) {
       std::thread::id curr_thread_id =
           std::this_thread::get_id();  // thread ID is PART E
       std::cout << "Thread: " << s << "\t ID of: " << curr_thread_id
                 << std::endl;
     };
}

// free function declaration
void freeFunc() {
  // print the string
  // m_mutex.lock();
  // Iprint("This is a free function", 3);
  // m_mutex.unlock(); // Part A
  while (true) {
    if (m_mutex.try_lock()) {
      increment_count();
      Iprint("This is a free function", 3);
      m_mutex.unlock();
      return; // without the return, the function will run continuously 
    } else {
      not_successful_job++;
      std::cout << "freeFunc job unsuccessful. Total unscessful jobs "
                << not_successful_job;
    }
  }
}


// For Function Objects
class PrintClass {
 private:
  std::string m_s;
  int m_count;

 public:
  void operator()() { 
    // m_mutex.lock();
    // Iprint("This is a free function", 3);
    // m_mutex.unlock(); // Part A
   while (true) {
      if (m_mutex.try_lock()) {
       increment_count();
        Iprint("This is a free function", 3);
        m_mutex.unlock();
        return; // without the return, the function will run continuously 
      } else {
        not_successful_job++;
        std::cout << "freeFunc job unsuccessful. Total unscessful jobs "
                  << not_successful_job;
      }
    }
    }

  // Static Member Function
  static void StaticFunction() { 
    // m_mutex.lock(); // Part A
    // Iprint("This is a free function", 3);
    // m_mutex.unlock(); //Part A
    while (true) {
      if (m_mutex.try_lock()) {
        increment_count();
        Iprint("This is a free function", 3);
        m_mutex.unlock();
        return; // without the return, the function will run continuously 
      } else {
        not_successful_job++;
        std::cout << "freeFunc job unsuccessful. Total unscessful jobs "
                  << not_successful_job;
      }
    }
  }
};
