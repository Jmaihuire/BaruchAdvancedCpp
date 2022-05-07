#pragma once
#include <atomic>
#include <ctime>
#include <iostream>
#include <string>

#include "SynchronisedQueue.h"

// Class that produces and puts objets in a queue
class Producer {
 private:
  int m_id;                                 // the ID of the producer
  SynchronisedQueue<std::string>* m_queue;  // the queue to use
  int m_nrChairs;

 public:
  // Constructor with ID and the queue to use
  Producer(int id, SynchronisedQueue<std::string>* queue, int nrChairs) {
    m_id = id;
    m_queue = queue;
    m_nrChairs = nrChairs;
  }

  // The thread function fills the queue with data

  void operator()(
      std::atomic<bool>& barberReady)  // include interrupt as input so we can
                                       // break function on user command
  {
    int data = 0;
    while (true) {
      // Check if there is an interupt
      if (barberReady.load()) {
        break;  // means we can break out of function
      }
      // Produce a string and store in the queue
      std::string str = "Customer: " + std::to_string(data++);
      std::cout << str << " - Taking chair \n" << std::endl;

      if (m_queue->numCustomers() >= m_nrChairs)  // chairs are all taken,
                                                  // customer should leave
      {
        std::cout << str << " - Chairs taken, customer leaving \n" << std::endl;
      } else {
        m_queue->Enqueue(str);
      }

      // Sleep one second
      std::this_thread::sleep_for(std::chrono::seconds(10));
    }
  }
};
