// Level3_Section3.1_Exercise5.cpp : 
// Atomics & Atomic Operations 

#include <atomic>
#include <chrono>
#include <iostream>
#include <syncstream>
#include <thread>

int main() {

  // Part A: create atomic long long; bool; int 
  std::atomic<long long> atomic_ll;
  std::atomic<bool> atomic_b;
  std::atomic<int> atomic_int;

  // Part B: Determine which atomic types are lock-free 
   printf("Atomic long long is lock free? %s\n",
         std::atomic_is_lock_free(&atomic_ll) ? "true" : "false");

   printf("Atomic bool is lock free? %s\n",
          std::atomic_is_lock_free(&atomic_b) ? "true" : "false");

   printf("Atomic int is lock free? %s\n",
          std::atomic_is_lock_free(&atomic_int) ? "true" : "false");
  // long long, bool & int are all lock free 

  // Part C: atomically replacing one atomic object with another 
  // Atomically replaces the underlying value with desired.The operation is read -
  // modify - write operation.Memory is affected according to the value of order. lambda as thread proc
   atomic_ll.store(atomic_b);  

   // Part D: Atomically load an atomic object and return its current value.
   atomic_b = false;
   std::cout << "Atomic bool return value is: ";
   std::cout << std::boolalpha << atomic_ll.load();
}

