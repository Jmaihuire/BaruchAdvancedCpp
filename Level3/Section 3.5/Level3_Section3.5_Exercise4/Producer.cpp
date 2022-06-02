// Queue Producer

#include <iostream>
#include <string>
#include <thread>

#include "SynchronizedQueue.h"

// Class that produces objects and puts them in a queue - (pulled from example
// code) - converted to STL implementation
class Producer {
 private:
  int m_id;                                 // The id of the producer
  SynchronizedQueue<std::string>* m_queue;  // The queue to use
 public:
  // Constructor with id and the queue to use
  Producer(int id, SynchronizedQueue<std::string>* queue) {
    m_id = id;
    m_queue = queue;
  }
  // The thread function fills the queue with data
  void operator()() {
    int data = 0;
    while (true) {
      // Produce a string and store in the queue
      std::string str = "Producer: " + std::to_string(m_id) +
                        " data: " + std::to_string(data++);
      m_queue->Enqueue(str);
      std::cout << str << std::endl;
      // Sleep one second
      std::this_thread::sleep_for(std::chrono::seconds(1));
    }
  }
};
