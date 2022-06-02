// Level3_Section3.5_Exercise4
// Fiona Ross 
// Objective: Queue Consumer
#include <iostream>
#include <string>
#include "SynchronizedQueue.h"

// Class that consumes objects from a queue - (pulled from lecture slides) -
// but converted from boost to stl 
class Consumer {
 private:
  int m_id;                                 // The id of the consumer
  SynchronizedQueue<std::string>* m_queue;  // The queue to use
 public:
  // Constructor with id and the queue to use
  Consumer(int id, SynchronizedQueue<std::string>* queue) {
    m_id = id;
    m_queue = queue;
  }
  // The thread function reads data from the queue
  void operator()() {
    while (true) {
      // Get the data from the queue and print it
      std::cout << "Consumer " << std::to_string(m_id).c_str() << " consumed: ("
                << m_queue->Dequeue().c_str() << ")" << std::endl;
      // Make sure we can be interrupted
      std::this_thread::yield();
    }
  }
};
