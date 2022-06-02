// Level3_Section3.5_Exercise4.cpp :
// Fiona Ross - Synchronizing Queue 

#include <iostream>
#include <thread>
#include "SynchronizedQueue.h"
#include "Producer.cpp"
#include "Consumer.cpp"

// This is primarily using prior work but now using priority queue. 
int main() {
  // Want to test this new class using priority queue instead of standard 
  // Test is also pulled from prior work 

  SynchronizedQueue<std::string> queue;
  // Create producer
  Producer p(1, &queue);
  std::thread p1(p);

  // Create consumer
  Consumer c(1, &queue);
  std::thread c1(c);

  // this will interupt threads and basically stop them 
  if (p1.joinable()) {
    try {
      p1.join();
    } catch (...) {
    };
  }
  if (c1.joinable()) {
    try {
      c1.join();
    } catch (...) {
    };
  }
}
