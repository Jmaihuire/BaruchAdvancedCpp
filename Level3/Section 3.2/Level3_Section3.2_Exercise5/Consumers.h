#include <iostream>
#include <queue>
#include <string>

#include "SynchronisedQueue.h"
class Consumer {
 private:
  int m_id;                                 // the id of the consumer
  SynchronisedQueue<std::string>* m_queue;  // the queue to use

 public:
  // Constructor with id and the queue to use
  Consumer(int id, SynchronisedQueue<std::string>* queue) {
    m_id = id;
    m_queue = queue;
  }

  void operator()(std::atomic<bool>& barberReady) {
    while (true) {
      if (barberReady.load()) {
        break;  // break on user input
      }
      // Check if there are customers, if not sleep
      else if (m_queue->numCustomers() == 0) {
        std::cout << "Barber sleeping as no customers \n" << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::this_thread::yield();
      } else {
        // Get the data from the queue and print it
        std::string customerID = m_queue->Dequeue().c_str();
        std::cout << "\nBarber is working on: (" << customerID << ")"
                  << std::endl;
        // barber takes 12 seconds to serve client
        std::this_thread::sleep_for(std::chrono::seconds(
            12));  // client will run behind and clients will wait in chairs
        // Customer leaves
        std::cout << customerID << " leaving..." << std::endl;
        // Make sure we can be interrupted
        std::this_thread::yield();
      }
    }
  }
};